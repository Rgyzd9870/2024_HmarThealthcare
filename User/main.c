
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

/* Global define */
#define ONENET_SEND_PRIO     10
#define ONENET_SEND_STK_SIZE      128
TaskHandle_t OnenetSend_Handler;

#define START_TASK_PRIO 1                   /* 任务优先级 */
#define START_STK_SIZE  128                 /* 任务堆栈大小 */
TaskHandle_t            StartTask_Handler;  /* 任务句柄 */

void start_task(void *pvParameters);
void OnenetSend_task(void *pvParameters);

MQTT_Heart_struct MQTT_Buffer ;

/*********************************************************************
 * @fn      OnenetSend_task
 * @brief   OnenetSend_task program.
 * @param  有互斥锁，负责发送数据给云平台(每十秒)
 * @return  none
 */
void OnenetSend_task(void *pvParameters)
{
    ESP8266_Init();

    while(1)
    {
        printf("test1\r\n");
        vTaskDelay(pdMS_TO_TICKS(5000));
        printf("test2\r\n");
        ESP8266_MQTTPUB(NULL);
        printf("test3\r\n");
    }
}

void start_task(void *pvParameters)      /* 任务函数 */
{
    taskENTER_CRITICAL();           /* 进入临界区 */

    /*创建任务*/
    xTaskCreate(OnenetSend_task,"OnenetSend_task",ONENET_SEND_STK_SIZE,NULL,ONENET_SEND_PRIO,&OnenetSend_Handler);

    vTaskDelete(StartTask_Handler); /* 删除开始任务 */
    taskEXIT_CRITICAL();            /* 退出临界区 */
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

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    SystemCoreClockUpdate();
    Delay_Init();
    USART_Printf_Init(115200);

    printf("SystemClk:%d\r\n",SystemCoreClock);
    printf( "ChipID:%08x\r\n", DBGMCU_GetCHIPID() );
    printf("FreeRTOS Kernel Version:%s\r\n",tskKERNEL_VERSION_NUMBER);

    cJSON_Hooks hooks;
    hooks.malloc_fn = pvPortMalloc;
    hooks.free_fn = vPortFree;
    cJSON_InitHooks(&hooks);

    xTaskCreate((TaskFunction_t )start_task,
                        (const char*    )"start_task",
                        (uint16_t       )START_STK_SIZE,
                        (void*          )NULL,
                        (UBaseType_t    )START_TASK_PRIO,
                        (TaskHandle_t*  )&StartTask_Handler);

    vTaskStartScheduler();

    while(1)
    {
        printf("shouldn't run at here!!\n");
    }
}
