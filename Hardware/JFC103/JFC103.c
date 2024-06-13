/*
 * JFC103.c
 *�����ָ��ģ��ĳ���
 *���ڶ�ȡ�ֽڰ��������ʣ�38400
 *�ɼ�����0x8A;�ɼ��أ�0x88
 *���߿���0x98�����߹أ�0x00
 *1.28�봫��һ������
 *  Created on: 2024��5��13��
 *      Author: rgyzd9870
 */

#include "debug.h"
#include "string.h"
#include "my_usart8.h"
#include "JFC103.h"


uint8_t Rebuffer[88];//�������ݴ����
MQTT_Heart_struct MQTT_Heart;

/*
 * ����ֵ��0����ȷ����1������
 * ��������������ݣ�
 * ���ڿ���Ҫ��Ҫ��Flag,��ֹ���ݴ۸�
 */
uint8_t Finger_in (void)
{

    uint8_t i ; //��������
//    uint8_t Rebuffer[88];//�������ݴ����
    uint8_t error = 0; //���ݱ���

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
                printf("�����ƴ�������%d\r\n",error);
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
 * �ж��Ƿ����������ݲ�����MQTT�ṹ����
 * ����������ݲ���������Χ�ڣ�30��150֮�䣩�����������Ϣ��
 */
void Heartcase(void)
{
    if(Finger_in() == 0)
    {
        if((Rebuffer[65]>0x96)||(Rebuffer[65]<0x1E))//����յ�����������150����С��30
        {
            printf("������������\r\n");
        }
        else
        {
            MQTT_Heart.BloodOxygen = (double)Rebuffer[65];
        }
    }
}


