/*
 * motor.h
 *
 *  Created on: 2024Äê6ÔÂ28ÈÕ
 *      Author: Ooo
 */

#ifndef HARDWARE_MOTOR_MOTOR_H_
#define HARDWARE_MOTOR_MOTOR_H_
    #include "debug.h"
 uint32_t timer_update_arc_value(void);
    void Motor_Run(uint32_t dir,uint32_t num,uint32_t speed);
    void Toggle_GPIO_Pin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
    void MOTOR_Init(void);
#endif /* HARDWARE_MOTOR_MOTOR_H_ */
