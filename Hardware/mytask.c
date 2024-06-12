#include "mytask.h"
#include "debug.h"
#include "MAX30102.h"
#include "algorithm.h"
#include "myiic.h"
#include "wchble.H"
#include "central.h"

extern uint8_t centralTaskId;

//MAX30102
uint32_t n_ir_buffer_length=500;     //data length
uint32_t aun_ir_buffer[500];    //IR LED sensor data
uint32_t aun_red_buffer[500];   //Red LED sensor data
int32_t n_sp02;                 //SPO2 value
int8_t ch_spo2_valid;           //indicator to show if the SP02 calculation is valid
int32_t n_heart_rate;           //heart rate value
int8_t  ch_hr_valid;            //indicator to show if the heart rate calculation is valid

static uint8_t MyTaskId;


uint16_t MyTask_ProcessEvent(uint8_t task_id, uint16_t events);

//初始化传感器硬件及任务
void MyTask_Init(void)
{
    iic_init();
    MAX30102_Init();
    MAX30102_INT_Init();

    MyTaskId=TMOS_ProcessEventRegister(MyTask_ProcessEvent);

    tmos_start_task( MyTaskId, MAX30102_INT_ENT, MS1_TO_SYSTEM_TIME( 50 ));
}

uint16_t MyTask_ProcessEvent(uint8_t task_id, uint16_t events)
{
    static uint16_t MAX30102_ReadNum=0;

    //消息事件
    if(events & SYS_EVENT_MSG)
    {
        return (events ^ SYS_EVENT_MSG);
    }

    //MAX30102 中断读取和判断
    if(events & MAX30102_INT_ENT)
    {
        uint8_t INTR_STATUS_1,INTR_STATUS_2;

        if(MAX30102_INT_READ())
        {
            MAX30102_Read_IntStatus(&INTR_STATUS_1,&INTR_STATUS_2);

            if(INTR_STATUS_1 & 0x40)
            {
                tmos_set_event( MyTaskId, MAX30102_READ_ENT);
            }
        }

        tmos_start_task( MyTaskId, MAX30102_INT_ENT, MS1_TO_SYSTEM_TIME( 50 ));

        return (events ^ MAX30102_INT_ENT);
    }

    //MAX30102 读取值
    if(events & MAX30102_READ_ENT)
    {
        MAX30102_Read_FIFO(aun_red_buffer+MAX30102_ReadNum,aun_ir_buffer+MAX30102_ReadNum);
        MAX30102_ReadNum++;
        if(MAX30102_ReadNum==500)
        {
            tmos_start_task( MyTaskId, MAX30102_SENDMSG_ENT, MS1_TO_SYSTEM_TIME( 200 ));
        }
        return (events ^ MAX30102_READ_ENT);
    }

    //MAX30102 发送
    if(events & MAX30102_SENDMSG_ENT)
    {
        maxim_heart_rate_and_oxygen_saturation(aun_ir_buffer, n_ir_buffer_length, aun_red_buffer, &n_sp02, &ch_spo2_valid, &n_heart_rate, &ch_hr_valid);

        if(ch_spo2_valid&&ch_hr_valid)
        {
            printf("n_sp02:%d,n_heart_rate:%d\r\n",n_sp02,n_heart_rate);
//            tmos_start_task(centralTaskId, START_READ_OR_WRITE_EVT, MS1_TO_SYSTEM_TIME( 600 ));
        }

        return (events ^ MAX30102_SENDMSG_ENT);
    }

    // Discard unknown events
    return 0;
}








