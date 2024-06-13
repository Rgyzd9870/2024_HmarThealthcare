/*
 * JFC103.h
 *
 *  Created on: 2024年5月13日
 *      Author: rgyzd9870
 */

#ifndef HARDWARE_JFC103_H_
#define HARDWARE_JFC103_H_


typedef struct _Heart_mqtt
{
    double BloodOxygen;
    double BatteryPercentage; //血氧
    int Droplet_speed;        //液滴速度
}MQTT_Heart_struct;




#endif /* HARDWARE_JFC103_H_ */
