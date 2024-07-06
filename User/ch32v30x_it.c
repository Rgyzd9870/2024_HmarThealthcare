/********************************** (C) COPYRIGHT *******************************
* File Name          : ch32v30x_it.c
* Author             : WCH
* Version            : V1.0.0
* Date               : 2024/03/05
* Description        : Main Interrupt Service Routines.
*********************************************************************************
* Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
* Attention: This software (modified or not) and binary are used for 
* microcontroller manufactured by Nanjing Qinheng Microelectronics.
*******************************************************************************/
#include "ch32v30x_it.h"

void NMI_Handler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void HardFault_Handler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void EXTI15_10_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
/*********************************************************************
 * @fn      NMI_Handler
 *
 * @brief   This function handles NMI exception.
 *
 * @return  none
 */
void NMI_Handler(void)
{
  while (1)
  {
  }
}

/*********************************************************************
 * @fn      HardFault_Handler
 *
 * @brief   This function handles Hard Fault exception.
 *
 * @return  none
 */
void HardFault_Handler(void)
{
  while (1)
  {
  }
}

/*********************************************************************
 * @fn      EXTI15_10_IRQHandler
 *
 * @brief   这个是液滴（红外对管）的外部中断计数
 *
 * @return  none
 */
int COUNT;
void EXTI15_10_IRQHandler(void)
{

  if(EXTI_GetITStatus(EXTI_Line13)!=RESET)
  {


    if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_13))
    {

        COUNT++;
//               printf("进来了%d",COUNT);
    }

    EXTI_ClearITPendingBit(EXTI_Line13);     /* Clear Flag */
  }
}
