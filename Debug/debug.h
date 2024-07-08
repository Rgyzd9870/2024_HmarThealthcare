/********************************** (C) COPYRIGHT  *******************************
* File Name          : debug.h
* Author             : WCH
* Version            : V1.0.0
* Date               : 2021/06/06
* Description        : This file contains all the functions prototypes for UART
*                      Printf , Delay functions.
*********************************************************************************
* Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
* Attention: This software (modified or not) and binary are used for 
* microcontroller manufactured by Nanjing Qinheng Microelectronics.
*******************************************************************************/
#ifndef __DEBUG_H
#define __DEBUG_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "stdio.h"
#include "ch32v30x.h"

/* UART Printf Definition */
#define DEBUG_UART1    1
#define DEBUG_UART2    2
#define DEBUG_UART3    3

/* DEBUG UATR Definition */
#ifndef DEBUG
#define DEBUG   DEBUG_UART2
#endif

/* SDI Printf Definition */
#define SDI_PR_CLOSE   0
#define SDI_PR_OPEN    1

#ifndef SDI_PRINT
#define SDI_PRINT   SDI_PR_CLOSE
#endif

/************************************”Ô“Ù¥´ ‰**********************************************/
#define TTS_Droplet         0x01
#define TTS_elderlyFall     0x02
#define TTS_Pulse           0x04
#define TTS_Temp            0x08
#define TTS_WR_Temp         0x10
#define TTS_emptyDroplet    0x20
#define TTS_ask10s          0x40
#define TTS_ask5s           0x80
#define TTS_NONE            0xFF
 /***********************************”Ô“Ù”Ô“Ù**********************************************/

void Delay_Init(void);
//void Delay_Us (uint32_t n);
void Delay_Ms (uint32_t n);
void USART_Printf_Init(uint32_t baudrate);
void SDI_Printf_Enable(void);
void Delay_Us(uint32_t n);

void RTOS_Delay_Ms(uint32_t n);
void NoRTOS_Delay_Ms(uint32_t n);

#ifdef __cplusplus
}
#endif

#endif 



