/*
 * motor.c
 *
 *  Created on: 2024年6月28日
 *      Author: Ooo
 */


#include "debug.h"
#include "motor.h"


//按键初始化函数  需要三个引脚 使能，方向，脉冲

void MOTOR_Init(void) //IO初始化pin9=en,pin10=cp pin11=dir
{

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);

       GPIO_InitTypeDef GPIO_InitStructure;
       GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
       GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11;//pin9使能，pin11方向，pin10速度
       GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
       GPIO_Init(GPIOD, &GPIO_InitStructure);
       GPIO_ResetBits(GPIOD, GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11);//共阳极接法

}
    void Motor_Run(uint32_t dir,uint32_t num,uint32_t speed)//方向，圈数，速度，
    {
      if (dir==1)//方向反
      {

          GPIO_ResetBits(GPIOD, GPIO_Pin_11);////正转方向
           GPIO_SetBits(GPIOD, GPIO_Pin_9);//使能
     }
      if (dir==0)//方向正
       {
          GPIO_SetBits(GPIOD, GPIO_Pin_11);////正转方向
           GPIO_SetBits(GPIOD, GPIO_Pin_9);//使能
       }
      else if(dir==2){//失能

           GPIO_ResetBits(GPIOD, GPIO_Pin_9);

                }
      for(uint32_t i=0;i<=num*200;i++)//电平翻转2次产生一次脉冲，一周
      {

         Delay_Ms(speed);// 两次翻转一次脉冲，200个就转一周了
          Toggle_GPIO_Pin(GPIOD, GPIO_Pin_10);

      }
    }
//
//    uint32_t timer_update_arc_value(void) {
//
//        static int value = 0;  // 静态变量，保持状态
//       while(1)
//       {
//            value=10+value;
//        Delay_Ms(2000);
//             if (value > 100) {
//                 value = 0; // 如果值超   过100，重置为0
//       }
//
//        }
//
//
//        return value;
//    }

    void Toggle_GPIO_Pin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) {
        // 读取当前引脚状态
        uint8_t pin_state = GPIO_ReadOutputDataBit(GPIOx, GPIO_Pin);

        // 切换引脚状态
        if (pin_state == Bit_SET) {
            GPIO_ResetBits(GPIOx, GPIO_Pin);  // 将引脚设置为低电平
        } else {
            GPIO_SetBits(GPIOx, GPIO_Pin);    // 将引脚设置为高电平
        }
    }


    //需要初始化
