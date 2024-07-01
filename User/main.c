
/********************************** (C) COPYRIGHT *******************************
* File Name          : main.c
* Author             : WCH
* Version            : V1.0.0
* Date               : 2021/06/06
* Description        : Main program body.
*********************************************************************************
* Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
* Attention: This software (modified or not) and binary are used for 
* microcontroller manufactured by Nanjing Qinheng Microelectronics.
*******************************************************************************/

/*
 *@Note
 task1 and task2 alternate printing
*/

#include "debug.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include "CH9141.h"
#include "lcd.h"
#include "string.h"
#include "semphr.h"
#include "esp8266.h"
#include "JFC103.h"
#include "timers.h"
#include "Droplet.h"
#include "cJSON.h"
#include "key.h"
#include "PWM.h"
#include "timer.h"
#include "DHT11.h"
#include "motor.h"��

#include "lvgl.h"
#include "lv_port_indev_template.h"
#include "lv_port_disp_template.h"
#include "ui.h"
#include "ui_helpers.h"
/* Global define */
#define Deafult_TASK_PRIO     1
#define Deafult_STK_SIZE      128

TaskHandle_t StartTask_Handler;
TaskHandle_t OnenetSend_Handler;
TaskHandle_t OnenetRestr_Handler;
TaskHandle_t LVGL_Handler;
TaskHandle_t CH9141_Handler;
TaskHandle_t DHT11_Handler;
TaskHandle_t userScreen_Handler;

QueueHandle_t Droplet_queue_handler;
TimerHandle_t Droplet_timer_handle = 0;

/*�������������*/
SemaphoreHandle_t onenet_mutex_handler,dht11_mutex_handler,lvgl_mutex_handler;
void (*Delay_ms_set)(uint32_t);
MQTT_Heart_struct MQTT_Buffer ;
lv_group_t *group;
extern int COUNT;
uint8_t temp, humi;                 //�¶ȣ�ʪ��

void start_task(void *pvParameters);
void OnenetSend_task(void *pvParameters);
void LVGL_task(void *pvParameters);
void Droplet_timer_callback(TimerHandle_t pxTimer);
//��ȡ���Ƕ�ֵ�ź������������⺯���򻯻�ȡ���ͷŵĲ�����code��Ҫ�ɵĹ���
#define mutex(mutex_handler, wait_ms, code)                               \
    if (xSemaphoreTake(mutex_handler, pdMS_TO_TICKS(wait_ms)) == pdPASS) \
    {                                                                    \
        code                                                             \
            xSemaphoreGive(mutex_handler);                               \
    }


/*********************************************************************
 * @fn      OnenetSend_task
 * @brief   OnenetSend_task program.
 * @param  �л����������������ݸ���ƽ̨(ÿʮ��)
 * @return  none
 */
void OnenetSend_task(void *pvParameters)
{

    ESP8266_MQTTPUB_Create(NULL);

    while(1)
    {
        Delay_Ms(10000);
        mutex(onenet_mutex_handler,100,
        ESP8266_MQTTPUB_Send(MQTT_Buffer.BloodOxygen , MQTT_Buffer.Droplet_speed,MQTT_Buffer.PulseFrequency);
        );
        printf("���Է���һ����ƽ̨\r\n");
    }
}
/*********************************************************************
 * @fn      OnenetRestr_task
 * @brief   OnenetRestr_task
 * @param   ����Һ���ٶȷ���������Ϣ���У���ʹ��onenet_mutex_handlerд��ȫ�ֽṹ����
 * @return  none
 */
void OnenetRestr_task(void *pvParameters)
{
    uint16_t speed;

    while(1)
    {
        int err = xQueueReceive(Droplet_queue_handler,&speed,pdMS_TO_TICKS(1000)); //portMAX_DELAY
        if(err ==pdFALSE);/* printf("Һ����Ϣ���ж�ȡʧ��\n");*/
        else printf("Һ����Ϣ����ֵ��%d\n",(int)speed);

        mutex(onenet_mutex_handler,100,
                MQTT_Buffer.Droplet_speed = (int)speed;
        );
        if(MQTT_Buffer.Droplet_speed > 40)
        {
            Motor_Run(1,10,3);
        }
        else ;
        vTaskDelay(1000);
    }
}
/*********************************************************************
 * @fn      OnenetRestr_task
 * @brief   OnenetRestr_task
 * @param   ������������������Ϣ���У����ʣ�Ѫ��������ʹ��onenet_mutex_handlerд��ȫ�ֽṹ����
 * @return  none
 */
void CH9141_RX_task(void *pvParameters)
{
    CH9141_Init();
    char buffer[1024];

    uint8_t Pulse, bloodOxygen;
    while(1)
    {
        int num1 = CH9141_uartAvailableBLE();
        if (num1 > 0 ){
             memset(buffer,'\0',1024);
            CH9141_uartReadBLE(buffer , num1);      //��ȡ�����������������
            printf("buffer:%d\r\n",buffer);

            Pulse =buffer[1];
            bloodOxygen = buffer[0];
            if((Pulse>200)||(Pulse<40)||(bloodOxygen<90))
            {}
            else{
            mutex(onenet_mutex_handler,100,
                    MQTT_Buffer.PulseFrequency = buffer[1];
                    MQTT_Buffer.BloodOxygen = buffer[0];);
                }

//        printf("Pulse:%d  BloodOxygen:%d\r\n",buffer[1],buffer[0]);
                       }
        Delay_Ms(500);
    }
}

void dht11_task(void *pvParameters)
{

    DHT11_Init();
    while (1)
    {
        mutex(dht11_mutex_handler, 100,
              DHT11_Read_Data(&temp, &humi);)
        Delay_Ms(2000);
    }
}

/*
 * �����û�������¶Ⱥ�ʪ����ʾ�������룩
 */
void userScreen_task(void *pvParameters){
    while (1)
    {
        mutex(dht11_mutex_handler, 100,
        mutex(lvgl_mutex_handler,100,
                printf("text:3\r\n");
//                      lv_timer_create(update_value1, 20000, NULL);//�¶�
//                      lv_timer_create(update_value2, 20000, NULL);//ʪ��
                        update_value2(MQTT_Buffer.PulseFrequency);
        ))
        vTaskDelay(2000);
    }

}


void LVGL_task(void *pvParameters)
{
    while(1)
    {
        lv_timer_handler(); /* LVGL ��ʱ�� */
        Delay_Ms(5);
    }
}

void start_task(void *pvParameters)
{
    taskENTER_CRITICAL();

    onenet_mutex_handler = xSemaphoreCreateMutex();                  //�ȴ�������������
    dht11_mutex_handler = xSemaphoreCreateMutex();
    lvgl_mutex_handler = xSemaphoreCreateMutex();
    Droplet_queue_handler= xQueueCreate(1,sizeof(uint16_t));         //���г���һ����Сu16
    if (Droplet_queue_handler == NULL) printf("���д���ʧ��\n");
//    xTaskCreate(OnenetSend_task,"OnenetSend_task",1024,NULL,5,&OnenetSend_Handler);
    xTaskCreate(OnenetRestr_task,"OnenetRestr_task",256,NULL,10,&OnenetRestr_Handler);
    xTaskCreate(LVGL_task,"LVGL_task",2*1024,NULL,5,&LVGL_Handler);
    xTaskCreate(dht11_task, "dht11_task", 128, NULL, 6, &DHT11_Handler);
    xTaskCreate(CH9141_RX_task,"CH9141_RX_task",1024,NULL,6,&CH9141_Handler);
    xTaskCreate(userScreen_task,"userScreen_task",1024,NULL,7,&userScreen_Handler);
    Droplet_timer_handle = xTimerCreate( "Droplet_timer", 10000, pdTRUE, (void *)1,Droplet_timer_callback );     //���ؾ��


//    int err = xTimerStart(Droplet_timer_handle,(TickType_t)1000);
//    if(err ==pdFALSE) printf("Һ�������ʱ������ʧ��\n");
    taskEXIT_CRITICAL();
    vTaskDelete(StartTask_Handler);
}


/*********************************************************************
 * @fn      main
 *
 * @brief   Main program.
 *
 * @return  none
 */
int main(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_3);
    SystemCoreClockUpdate();
    Delay_Init();
    TIM3_Init();
    MOTOR_Init();
    USART_Printf_Init(115200);

    printf("SystemClk:%d\r\n",SystemCoreClock);
    printf( "ChipID:%08x\r\n", DBGMCU_GetCHIPID() );
    printf("FreeRTOS Kernel Version:%s\r\n",tskKERNEL_VERSION_NUMBER);

    //change cjosn malloc and free
    cJSON_Hooks hooks;
    hooks.malloc_fn = pvPortMalloc;
    hooks.free_fn = vPortFree;
    cJSON_InitHooks(&hooks);

    ESP8266_Init();
    PWM_Init();
    EXTI1_INT_INIT();

    lv_init();
    group = lv_group_create();
    lv_group_set_default(group);
    lv_port_disp_init();
    lv_port_indev_init();
    ui_init();

    Delay_ms_set= &RTOS_Delay_Ms;

    xTaskCreate((TaskFunction_t )start_task,
                        (const char*    )"start_task",
                        (uint16_t       )128,
                        (void*          )NULL,
                        (UBaseType_t    )1,
                        (TaskHandle_t*  )&StartTask_Handler);

    vTaskStartScheduler();

    while(1)
    {
        printf("shouldn't run at here!!\n");
    }
}

void Droplet_timer_callback(TimerHandle_t pxTimer)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE; //�ж��Ƿ��и����ȼ�����ִ��
    BaseType_t err;
    //�ص������в���ʹ���������񣬷��ʶ��л��ź����ķ�������ʱ��Ҳ���ܵ���
    //Һ��ÿ�������ֵ���ȵȸĳ�Һ��ÿ��������ֵ

//    printf("Droplet�����д�����%d\r\n",COUNT);
    err = xQueueSendToFrontFromISR(Droplet_queue_handler,&COUNT,&xHigherPriorityTaskWoken);
    if(err != pdTRUE )printf("�ж϶��з���ʧ��\n");

    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
    COUNT =0;  //�и���������һֱ����
}
