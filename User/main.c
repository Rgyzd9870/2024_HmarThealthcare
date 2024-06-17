
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
TaskHandle_t LVGL_Handler;

void (*Delay_ms_set)(uint32_t);
MQTT_Heart_struct MQTT_Buffer ;
lv_group_t *group;

void start_task(void *pvParameters);
void OnenetSend_task(void *pvParameters);
void LVGL_task(void *pvParameters);

/*********************************************************************
 * @fn      OnenetSend_task
 * @brief   OnenetSend_task program.
 * @param  有互斥锁，负责发送数据给云平台(每十秒)
 * @return  none
 */
void OnenetSend_task(void *pvParameters)
{
    while(1)
    {
        Delay_Ms(5000);
        ESP8266_MQTTPUB(NULL);
    }
}

void LVGL_task(void *pvParameters)
{
    ui_init();

    while(1)
    {
        lv_timer_handler(); /* LVGL 计时器 */
        Delay_Ms(5);
    }
}

void start_task(void *pvParameters)
{
    taskENTER_CRITICAL();
    xTaskCreate(OnenetSend_task,"OnenetSend_task",128,NULL,5,&OnenetSend_Handler);
    xTaskCreate(LVGL_task,"LVGL_task",2*1024,NULL,4,&LVGL_Handler);
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
