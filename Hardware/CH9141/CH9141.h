#ifndef __CH9141_H
#define __CH9141_H

#include "debug.h"

void CH9141_Init(void);
uint16_t CH9141_uartAvailableBLE();
uint32_t CH9141_uartReadBLE(char * buffer , uint16_t num);


void CH9141_USARTx_CFG(void);
void CH9141_DMA_INIT(void);
void LCD_TurnBufferBLE(char* format, ...);
void CH9141_ReadPrint_LCD_BLE(void);
char CH9141_AT_WriteCmd(int time,char*cmd,char*response);
#endif

