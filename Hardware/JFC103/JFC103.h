/*
 * JFC103.h
 *
 *  Created on: 2024��5��13��
 *      Author: rgyzd9870
 */

#ifndef HARDWARE_JFC103_H_
#define HARDWARE_JFC103_H_


typedef struct _Heart_mqtt
{
    double BloodOxygen;       //Ѫ��
    double BatteryPercentage;
    int Droplet_speed;        //Һ���ٶ�
    double PulseFrequency;
    double elderlyFallDetection;
}MQTT_Heart_struct;




#endif /* HARDWARE_JFC103_H_ */
