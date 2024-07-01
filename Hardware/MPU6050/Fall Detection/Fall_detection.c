#include "debug.h"
#include "Fall_detection.h"
#include "mpu6050.h"
#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h"
#include "math.h"

extern float pitch,roll,yaw;       //ŷ����
extern short aacx,aacy,aacz;       //���ٶȴ�����ԭʼ����

/*********************************************************************
 * @fn      Fall_detection
 *
 * @brief   �о��������������ʱ��Ϊ 0.3~0.4 s����30Hz����ʮ����
 *          http://qkxb.hut.edu.cn:6688/zk/hngydxzrb/article/pdf/20180314
 *
 * @param   ���ٶȷ���ֵ SVM;����ָ��CV
 *
 * @return  none
 */
uint8_t Fall_detection(void)
{
    static uint8_t cnt;

   float temp=0;
   uint8_t res=0;

    float SVM;

    float W=0;
    static uint8_t W_res;
    static float last_roll,last_yaw;

    float q_aacx,q_aacy,q_aacz;

//    Delay_Ms(20);
    MPU_Get_Accelerometer(&aacx,&aacy,&aacz);
    mpu_dmp_get_data(&pitch,&roll,&yaw);

    //�Ƕȱ仯
    temp=last_roll-roll;
    W+=temp*temp;
    temp=last_yaw-yaw;
    W+=temp*temp;
    W=sqrtf(W);
    last_roll=roll;
    last_yaw=yaw;

    //���ٶȷ���
    q_aacx=aacx / 16384;
    q_aacy=aacy / 16384;
    q_aacz=aacz / 16384;
    SVM=sqrtf((q_aacx*q_aacx)+(q_aacy*q_aacy)+(q_aacz*q_aacz));

    cnt++;

    if(cnt==30)
    {
        cnt=0;
        W_res=0;
    }

    if(W>50)
    {
        W_res=1;
    }

    if(SVM>1.5 && W_res)
    {
//        printf("SVM:%f\r\n",SVM[i]);
        res=1;
    }

    return res;
}











