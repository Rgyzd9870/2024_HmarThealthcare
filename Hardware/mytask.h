#ifndef __MYTASK_H
#define __MYTASK_H

#define MAX30102_INT_ENT              0x0001
#define MAX30102_SEND_ENT             0x0002
#define MPU6050_SEND_ENT              0x1000
#define FALL_SHOW_ENT                 0x2000
void MyTask_Init(void);
void MAX30102_ReadData(void);

#endif
