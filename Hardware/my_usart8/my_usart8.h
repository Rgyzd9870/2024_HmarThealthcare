#ifndef _HARDWARE_MY_USART8_H_
#define _HARDWARE_MY_USART8_H_

#include "debug.h"

void USART8_CFG(void);
void DMA8_INIT(void);
FlagStatus uartWriteHeart(char * data , uint16_t num);
uint32_t uartReadHeart(char * buffer , uint16_t num);
FlagStatus uartWriteHeartStr(char * str);
char uartReadByteHeart();
uint16_t uartAvailableHeart();
uint8_t Rx8Buffer_Printf(char *buffer);
uint8_t heart_receive_judge(char *str);


/*******************************************��ʱJFC103����***************************************************************/


uint8_t  Rx8Buffer_Str(void);
#define RXBUF_SIZE8 88 // DMA buffer size

extern uint8_t RxBuffer_u8[RXBUF_SIZE8];  //ֻ��������ʱ������


#endif /* HARDWARE_MY_USART8_H_ */
