
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

#include "lvgl.h"
#include "lv_port_indev_template.h"
#include "lv_port_disp_template.h"
#include "ui.h"

/* Global define */
#define Deafult_TASK_PRIO     1
#define Deafult_STK_SIZE      128

TaskHandle_t StartTask_Handler;
TaskHandle_t OnenetSend_Handler;
TaskHandle_t OnenetRestr_Handler;
TaskHandle_t LVGL_Handler;
QueueHandle_t Droplet_queue_handler;
TimerHandle_t Droplet_timer_handle = 0;
void (*Delay_ms_set)(uint32_t);
MQTT_Heart_struct MQTT_Buffer ;
lv_group_t *group;
extern int COUNT;

void start_task(void *pvParameters);
void OnenetSend_task(void *pvParameters);
void LVGL_task(void *pvParameters);
void Droplet_timer_callback(TimerHandle_t pxTimer);
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
        Delay_Ms(5000);

        ESP8266_MQTTPUB_Send(55 , 77);

        printf("����1�ɹ�\r\n");
    }
}

void LVGL_task(void *pvParameters)
{
    ui_init();

    while(1)
    {
        lv_timer_handler(); /* LVGL ��ʱ�� */
        Delay_Ms(5);
    }
}

void start_task(void *pvParameters)
{
    taskENTER_CRITICAL();
//    Droplet_queue_handler= xQueueCreate(1,sizeof(uint16_t));         //���г���һ����Сu16
//    if (Droplet_queue_handler == NULL) printf("���д���ʧ��\n");
    xTaskCreate(OnenetSend_task,"OnenetSend_task",1024,NULL,5,&OnenetSend_Handler);
//    xTaskCreate(LVGL_task,"LVGL_task",2*1024,NULL,11,&LVGL_Handler);
    Droplet_timer_handle = xTimerCreate( "Droplet_timer", 1000, pdTRUE, (void *)1,Droplet_timer_callback );     //���ؾ��

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

//    EXTI1_INT_INIT();
    lv_init();
    group = lv_group_create();
    lv_group_set_default(group);
    lv_port_disp_init();
    lv_port_indev_init();

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

    printf("Droplet�����д�����%d\r\n",COUNT);
    err = xQueueSendToFrontFromISR(Droplet_queue_handler,&COUNT,&xHigherPriorityTaskWoken);
    if(err != pdTRUE )printf("�ж϶��з���ʧ��\n");

    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
    COUNT =0;  //�и���������һֱ����
}
