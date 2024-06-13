/*
 * JFC103.c
 *这个是指纹模块的程序
 *串口读取字节包，波特率：38400
 *采集开：0x8A;采集关：0x88
 *休眠开：0x98；休眠关：0x00
 *1.28秒传输一次心率
 *  Created on: 2024年5月13日
 *      Author: rgyzd9870
 */

#include "debug.h"
#include "string.h"
#include "my_usart8.h"
#include "JFC103.h"


uint8_t Rebuffer[88];//接收数据存放区
MQTT_Heart_struct MQTT_Heart;

/*
 * 返回值：0（正确）；1（错误）
 * 检测有无心跳数据，
 * 后期考虑要不要加Flag,防止数据篡改
 */
uint8_t Finger_in (void)
{

    uint8_t i ; //遍历数组
//    uint8_t Rebuffer[88];//接收数据存放区
    uint8_t error = 0; //数据报错

    if(DMA_GetFlagStatus(DMA2_FLAG_TC11))
    {
        DMA_ClearFlag(DMA2_FLAG_TC11);


            while(USART_GetFlagStatus(USART2, USART_FLAG_TC)==RESET);
            printf("%d\r\n",RxBuffer_u8[65]);

                memcpy(Rebuffer,RxBuffer_u8,88);

                for(i=0;i<88;i++)
                {
                    if(Rebuffer[i]==0xc4)
                    {
                        error++;
                    }
                }

            if(error >= 25)
            {
                printf("无手势触碰数：%d\r\n",error);
                return 1;
            }
            else
            {
                printf("%d\r\n",Rebuffer[65]);
                return 0;
            }
            return 0;
    }
}

/*
 * 判断是否有心跳数据并存入MQTT结构体中
 * 如果心率数据不在正常范围内（30到150之间），输出错误信息。
 */
void Heartcase(void)
{
    if(Finger_in() == 0)
    {
        if((Rebuffer[65]>0x96)||(Rebuffer[65]<0x1E))//如果收到的心跳大于150或者小于30
        {
            printf("心跳计量错误\r\n");
        }
        else
        {
            MQTT_Heart.BloodOxygen = (double)Rebuffer[65];
        }
    }
}


