#include "debug.h"
#include "myiic.h"
#include "MAX30102.h"

uint8_t MAX30102_Write_Byte(uint8_t Address,uint8_t data)
{
    iic_start();

    iic_send_byte(I2C_WRITE_ADDR);
    if(iic_wait_ack())
        return 0;

    iic_send_byte(Address);
    if(iic_wait_ack())
        return 0;

    iic_send_byte(data);
    if(iic_wait_ack())
        return 0;

    iic_stop();
    return 1;
}


uint8_t MAX30102_Read_Byte(uint8_t Address)
{
    uint8_t data;

    iic_start();

    iic_send_byte(I2C_WRITE_ADDR);
    iic_wait_ack();

    iic_send_byte(Address);
    iic_wait_ack();

    iic_start();

    iic_send_byte(I2C_READ_ADDR);
    iic_wait_ack();

    data=iic_read_byte(0);

    iic_stop();
    return data;
}

void MAX30102_Read_Bytes(uint8_t Address,u8* data,u8 dataLength)
{
    u8 i;

    iic_start();

    iic_send_byte(I2C_WRITE_ADDR);
    iic_wait_ack();

    iic_send_byte(Address);
    iic_wait_ack();

    iic_start();

    iic_send_byte(I2C_READ_ADDR);
    iic_wait_ack();

    for(i=0;i<dataLength-1;i++)
    {
        data[i] = iic_read_byte(1);
    }
    data[dataLength-1] = iic_read_byte(0);

    iic_stop();

}

void MAX30102_Reset(void)
{
    MAX30102_Write_Byte(REG_MODE_CONFIG, 0X40);
}

void MAX30102_Read_IntStatus(uint8_t *INTR_STATUS_1,uint8_t *INTR_STATUS_2)
{
    *INTR_STATUS_1=MAX30102_Read_Byte(REG_INTR_STATUS_1);
    *INTR_STATUS_2=MAX30102_Read_Byte(REG_INTR_STATUS_2);
}


void MAX30102_Read_FIFO(uint32_t *pun_red_led, uint32_t *pun_ir_led)
{
    uint32_t un_temp;
    char ach_i2c_data[6];
    *pun_red_led=0;
    *pun_ir_led=0;

    //read and clear status register
    MAX30102_Read_Byte(REG_INTR_STATUS_1);
    MAX30102_Read_Byte(REG_INTR_STATUS_2);

    MAX30102_Read_Bytes(REG_FIFO_DATA,(u8 *)ach_i2c_data,6);

    un_temp=(unsigned char) ach_i2c_data[0];
    un_temp<<=16;
    *pun_red_led+=un_temp;
    un_temp=(unsigned char) ach_i2c_data[1];
    un_temp<<=8;
    *pun_red_led+=un_temp;
    un_temp=(unsigned char) ach_i2c_data[2];
    *pun_red_led+=un_temp;

    un_temp=(unsigned char) ach_i2c_data[3];
    un_temp<<=16;
    *pun_ir_led+=un_temp;
    un_temp=(unsigned char) ach_i2c_data[4];
    un_temp<<=8;
    *pun_ir_led+=un_temp;
    un_temp=(unsigned char) ach_i2c_data[5];
    *pun_ir_led+=un_temp;
    *pun_red_led&=0x03FFFF;  //Mask MSB [23:18]
    *pun_ir_led&=0x03FFFF;  //Mask MSB [23:18]
}

void MAX30102_Init(void)
{
    MAX30102_Reset();
    Delay_Ms(20);

    MAX30102_Read_Byte(REG_INTR_STATUS_1);
    MAX30102_Read_Byte(REG_INTR_STATUS_2);

    MAX30102_Write_Byte(REG_INTR_ENABLE_1,0xc0); // INTR setting
    MAX30102_Write_Byte(REG_INTR_ENABLE_2,0x00);
    MAX30102_Write_Byte(REG_FIFO_WR_PTR,0x00);   //FIFO_WR_PTR[4:0]
    MAX30102_Write_Byte(REG_OVF_COUNTER,0x00);   //OVF_COUNTER[4:0]
    MAX30102_Write_Byte(REG_FIFO_RD_PTR,0x00);   //FIFO_RD_PTR[4:0]
    MAX30102_Write_Byte(REG_FIFO_CONFIG,0x0f);   //sample avg = 1, fifo rollover=false, fifo almost full = 17
    MAX30102_Write_Byte(REG_MODE_CONFIG,0x03);   //0x02 for Red only, 0x03 for SpO2 mode 0x07 multimode LED
    MAX30102_Write_Byte(REG_SPO2_CONFIG,0x27);   // SPO2_ADC range = 4096nA, SPO2 sample rate (100 Hz), LED pulseWidth (400uS)
    MAX30102_Write_Byte(REG_LED1_PA,0x24);       //Choose value for ~ 7mA for LED1
    MAX30102_Write_Byte(REG_LED2_PA,0x24);       // Choose value for ~ 7mA for LED2
    MAX30102_Write_Byte(REG_PILOT_PA,0x7f);      // Choose value for ~ 25mA for Pilot LED
}

void MAX30102_INT_Init(void)
{
    GPIO_InitTypeDef gpio_init_struct;

    INT_GPIO_CLK_ENABLE();

    gpio_init_struct.GPIO_Pin = INT_GPIO_PIN;
    gpio_init_struct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    gpio_init_struct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(INT_GPIO_PORT, &gpio_init_struct);
}



