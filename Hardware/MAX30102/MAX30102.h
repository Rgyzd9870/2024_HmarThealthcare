#ifndef __MAX30102_H
#define __MAX30102_H

//INT
#define INT_GPIO_PORT               GPIOB
#define INT_GPIO_PIN                GPIO_Pin_6//GPIO_Pin_13
#define INT_GPIO_CLK_ENABLE()       do{RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);}while(0)   /* PB口时钟使能 */
#define MAX30102_INT_READ()                  GPIO_ReadInputDataBit(INT_GPIO_PORT, INT_GPIO_PIN)

//device addresses
#define I2C_WRITE_ADDR  0xAE
#define I2C_READ_ADDR   0xAF

//register addresses
#define REG_INTR_STATUS_1 0x00
#define REG_INTR_STATUS_2 0x01
#define REG_INTR_ENABLE_1 0x02
#define REG_INTR_ENABLE_2 0x03
#define REG_FIFO_WR_PTR   0x04
#define REG_OVF_COUNTER   0x05
#define REG_FIFO_RD_PTR   0x06
#define REG_FIFO_DATA     0x07
#define REG_FIFO_CONFIG   0x08
#define REG_MODE_CONFIG   0x09
#define REG_SPO2_CONFIG   0x0A
#define REG_LED1_PA       0x0C
#define REG_LED2_PA       0x0D
#define REG_PILOT_PA      0x10
#define REG_MULTI_LED_CTRL1 0x11
#define REG_MULTI_LED_CTRL2 0x12
#define REG_TEMP_INTR     0x1F
#define REG_TEMP_FRAC     0x20
#define REG_TEMP_CONFIG   0x21
#define REG_PROX_INT_THRESH 0x30
#define REG_REV_ID        0xFE
#define REG_PART_ID       0xFF

uint8_t MAX30102_Write_Byte(uint8_t Address,uint8_t data);
uint8_t MAX30102_Read_Byte(uint8_t Address);

void MAX30102_Init(void);
void MAX30102_INT_Init(void);
void MAX30102_Reset(void);
void MAX30102_Read_IntStatus(uint8_t *INTR_STATUS_1,uint8_t *INTR_STATUS_2);
void MAX30102_Read_FIFO(uint32_t *red_led, uint32_t *ir_led);

#endif
