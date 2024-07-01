/*
 * motor.c
 *
 *  Created on: 2024��6��28��
 *      Author: Ooo
 */


#include "debug.h"
#include "motor.h"


//������ʼ������  ��Ҫ�������� ʹ�ܣ���������

void MOTOR_Init(void) //IO��ʼ��pin9=en,pin10=cp pin11=dir
{

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);

       GPIO_InitTypeDef GPIO_InitStructure;
       GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
       GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11;//pin9ʹ�ܣ�pin11����pin10�ٶ�
       GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
       GPIO_Init(GPIOD, &GPIO_InitStructure);
       GPIO_ResetBits(GPIOD, GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11);//�������ӷ�

}
    void Motor_Run(uint32_t dir,uint32_t num,uint32_t speed)//����Ȧ�����ٶȣ�
    {
      if (dir==1)//����
      {

          GPIO_ResetBits(GPIOD, GPIO_Pin_11);////��ת����
           GPIO_SetBits(GPIOD, GPIO_Pin_9);//ʹ��
     }
      if (dir==0)//������
       {
          GPIO_SetBits(GPIOD, GPIO_Pin_11);////��ת����
           GPIO_SetBits(GPIOD, GPIO_Pin_9);//ʹ��
       }
      else if(dir==2){//ʧ��

           GPIO_ResetBits(GPIOD, GPIO_Pin_9);

                }
      for(uint32_t i=0;i<=num*200;i++)//��ƽ��ת2�β���һ�����壬һ��
      {

         Delay_Ms(speed);// ���η�תһ�����壬200����תһ����
          Toggle_GPIO_Pin(GPIOD, GPIO_Pin_10);

      }
    }
//
//    uint32_t timer_update_arc_value(void) {
//
//        static int value = 0;  // ��̬����������״̬
//       while(1)
//       {
//            value=10+value;
//        Delay_Ms(2000);
//             if (value > 100) {
//                 value = 0; // ���ֵ��   ��100������Ϊ0
//       }
//
//        }
//
//
//        return value;
//    }

    void Toggle_GPIO_Pin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) {
        // ��ȡ��ǰ����״̬
        uint8_t pin_state = GPIO_ReadOutputDataBit(GPIOx, GPIO_Pin);

        // �л�����״̬
        if (pin_state == Bit_SET) {
            GPIO_ResetBits(GPIOx, GPIO_Pin);  // ����������Ϊ�͵�ƽ
        } else {
            GPIO_SetBits(GPIOx, GPIO_Pin);    // ����������Ϊ�ߵ�ƽ
        }
    }


    //��Ҫ��ʼ��
