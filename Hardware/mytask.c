#include "mytask.h"
#include "debug.h"
#include "MAX30102.h"
#include "algorithm.h"
#include "myiic.h"
#include "wchble.H"
#include "central.h"
#include "mpu6050.h"
#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h"
#include "Fall_detection.h"
#include "lcd.h"
#include "Dis_Picture.h"
#include "Text.h"
#include "GBK_LibDrive.h"

static uint8_t MyTaskId;

extern uint8_t centralTaskId;

uint8_t flag;
//MAX30102
uint32_t n_ir_buffer_length=500;     //data length
uint32_t aun_ir_buffer[500];    //IR LED sensor data
uint32_t aun_red_buffer[500];   //Red LED sensor data
int32_t n_sp02;                 //SPO2 value
int8_t ch_spo2_valid;           //indicator to show if the SP02 calculation is valid
int32_t n_heart_rate;           //heart rate value
int8_t  ch_hr_valid;            //indicator to show if the heart rate calculation is valid

//MPU6050
int32_t mpu6050_res;
int32_t mpu6050_buff;
uint8_t MAX30102_ReadEnable=0;

//LCD
char LCD_heart[128];
char LCD_n_sp02[128];
char LCD_mpu6050[128];
uint16_t MyTask_ProcessEvent(uint8_t task_id, uint16_t events);

//初始化传感器硬件及任务
void MyTask_Init(void)
{
    uint8_t res;


    LCD_Init();           //初始化LCD SPI 接口
    GBK_Lib_Init();       //硬件GBK字库初始化--(如果使用不带字库的液晶屏版本，此处可以屏蔽，不做字库初始化）
    POINT_COLOR=RED;      //画笔颜色：红色
    LCD_Clear(GRAY0); //清屏

    Show_Picture();                                //显示图片
    LCD_Set_Window(0,0,lcddev.width,lcddev.height);//设置全屏窗口
    Demo_Menu();                                   //演示程序


    MyTaskId=TMOS_ProcessEventRegister(MyTask_ProcessEvent);

    iic_init();
    MAX30102_Init();
    MAX30102_INT_Init();

    MPU_Init();
    res=mpu_dmp_init();
    if(!res)
    {
        printf("MPU6050 SUCCESS\r\n");
        Delay_Ms(3000);

    }
    else
    {
        printf("MPU6050 Error:%d\r\n",res);
        while(1);
    }

    tmos_start_task(MyTaskId, MPU6050_SEND_ENT, MS1_TO_SYSTEM_TIME( 30 ));
}

uint16_t MyTask_ProcessEvent(uint8_t task_id, uint16_t events)
{
    //消息事件
    if(events & SYS_EVENT_MSG)
    {
        return (events ^ SYS_EVENT_MSG);
    }

    //MAX30102 发送
    if(events & MAX30102_SEND_ENT)
    {
        maxim_heart_rate_and_oxygen_saturation(aun_ir_buffer, n_ir_buffer_length, aun_red_buffer, &n_sp02, &ch_spo2_valid, &n_heart_rate, &ch_hr_valid);   //获取心率血氧

        if(ch_spo2_valid&&ch_hr_valid)
        {
            printf("n_sp02:%d,n_heart_rate:%d\r\n",n_sp02,n_heart_rate);

                 sprintf(LCD_heart,"%d",n_heart_rate);     //显示心率变量
                 Draw_Font24B(120,100,BLUE,LCD_heart);
                 sprintf(LCD_n_sp02,"%d",n_sp02);          //显示血氧变量
                 Draw_Font24B(120,150,BLUE,LCD_n_sp02);

            tmos_start_task(centralTaskId, START_READ_OR_WRITE_EVT, MS1_TO_SYSTEM_TIME( 200 ));
        }

        return (events ^ MAX30102_SEND_ENT);
    }

    //MPU6050 发送
    if(events & MPU6050_SEND_ENT)
    {
        mpu6050_buff=Fall_detection();              //获取有人摔倒
        if((mpu6050_buff != 0) &&(flag ==0))        //有人摔倒立即发送
        {
            mpu6050_res = mpu6050_buff;
            flag++;
            printf("mpu6050_res:%d , flag:%d\r\n",mpu6050_res,flag);

            sprintf(LCD_mpu6050,"%d",mpu6050_res);          //显示摔倒变量
            Draw_Font24B(120,150,BLUE,LCD_mpu6050);

            tmos_start_task(centralTaskId, START_READ_OR_WRITE_EVT, MS1_TO_SYSTEM_TIME( 200 ));
        }
        tmos_start_task(MyTaskId, MPU6050_SEND_ENT, MS1_TO_SYSTEM_TIME(50));
        return (events ^ MPU6050_SEND_ENT);
    }

    // Discard unknown events
    return 0;
}


void MAX30102_ReadData(void)
{
    static uint16_t MAX30102_ReadNum=0;
    uint8_t INTR_STATUS_1,INTR_STATUS_2;

    if(MAX30102_ReadEnable)
    {
        if(!MAX30102_INT_READ())
        {
            MAX30102_Read_IntStatus(&INTR_STATUS_1,&INTR_STATUS_2);

            if(INTR_STATUS_1 & 0x40)
            {
                MAX30102_Read_FIFO(aun_red_buffer+MAX30102_ReadNum,aun_ir_buffer+MAX30102_ReadNum);
                MAX30102_ReadNum++;

                if(MAX30102_ReadNum==n_ir_buffer_length)
                {
                    MAX30102_ReadNum=0;
                    tmos_set_event( MyTaskId, MAX30102_SEND_ENT);
                }
            }
        }
    }
}
