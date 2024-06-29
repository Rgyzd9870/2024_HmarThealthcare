#include "timer.h"

void Delay_test(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

       /* PA1 -->TIM2_CH2  */
       GPIO_InitTypeDef GPIO_InitStructure;
       GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
       GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
       GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
       GPIO_Init(GPIOB, &GPIO_InitStructure);

       GPIO_WriteBit(GPIOB, GPIO_Pin_15, SET);
}

void TIM3_Init(void)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);  ///ʹ��TIM3ʱ��
    TIM_TimeBaseInitStructure.TIM_Period    = 50000-1;  //�Զ���װ��ֵ
    TIM_TimeBaseInitStructure.TIM_Prescaler = 144-1;     //��ʱ����Ƶ
    TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; //���ϼ���ģʽ
    TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
    TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructure);//��ʼ��TIM3
}

//΢�뼶��ʱ
void TIM3_Delayus(u16 xus)
{
    TIM_Cmd(TIM3,ENABLE); //������ʱ��
    while(TIM3->CNT < xus);
    TIM3->CNT = 0;
    TIM_Cmd(TIM3,DISABLE); //�رն�ʱ��
}

//���뼶��ʱ
void TIM3_Delayms(u16 xms)
{
    int i;
    for(i=0;i<xms;i++)
    {
        TIM3_Delayus(1000);
    }
}
