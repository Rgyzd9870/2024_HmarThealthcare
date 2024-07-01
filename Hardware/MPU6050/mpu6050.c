#include "mpu6050.h"

static void MPU_IIC_Delay(void)
{
    Delay_Us(2);
}

//��ʼ��IIC
void MPU_IIC_Init(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure;

    MPUIIC_SCL_GPIO_CLK_ENABLE();    //��ʹ������IO PORTBʱ��
    MPUIIC_SDA_GPIO_CLK_ENABLE();

    GPIO_InitStructure.GPIO_Pin = MPUIIC_SCL_GPIO_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(MPUIIC_SCL_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = MPUIIC_SDA_GPIO_PIN;
    GPIO_Init(MPUIIC_SDA_GPIO_PORT, &GPIO_InitStructure);

    GPIO_SetBits(MPUIIC_SCL_GPIO_PORT,MPUIIC_SCL_GPIO_PIN);
    GPIO_SetBits(MPUIIC_SDA_GPIO_PORT,MPUIIC_SDA_GPIO_PIN);
}

//����IIC��ʼ�ź�
static void MPU_IIC_Start(void)
{
    MPU_IIC_SDA(1);
    MPU_IIC_SCL(1);
    MPU_IIC_Delay();
    MPU_IIC_SDA(0);//START:when CLK is high,DATA change form high to low
    MPU_IIC_Delay();
    MPU_IIC_SCL(0);//ǯסI2C���ߣ�׼�����ͻ��������
    MPU_IIC_Delay();
}
//����IICֹͣ�ź�
static void MPU_IIC_Stop(void)
{
    MPU_IIC_SCL(0);
    MPU_IIC_SDA(0);//STOP:when CLK is high DATA change form low to high
    MPU_IIC_Delay();
    MPU_IIC_SCL(1);
    MPU_IIC_Delay();
    MPU_IIC_SDA(1);//����I2C���߽����ź�
    MPU_IIC_Delay();
}


//�ȴ�Ӧ���źŵ���
//����ֵ��1������Ӧ��ʧ��
//        0������Ӧ��ɹ�
static u8 MPU_IIC_Wait_Ack(void)
{
    u8 ucErrTime=0;
    MPU_IIC_SDA(1);MPU_IIC_Delay();
    MPU_IIC_SCL(1);MPU_IIC_Delay();
    while(MPU_READ_SDA)
    {
        ucErrTime++;
        if(ucErrTime>250)
        {
            MPU_IIC_Stop();
            return 1;
        }
    }
    MPU_IIC_SCL(0);//ʱ�����0
    MPU_IIC_Delay();
    return 0;
}

//����ACKӦ��
static void MPU_IIC_Ack(void)
{
    MPU_IIC_SCL(0);
    MPU_IIC_SDA(0);
    MPU_IIC_Delay();
    MPU_IIC_SCL(1);
    MPU_IIC_Delay();
    MPU_IIC_SCL(0);
    MPU_IIC_Delay();
    MPU_IIC_SDA(1);
    MPU_IIC_Delay();
}
//������ACKӦ��
static void MPU_IIC_NAck(void)
{
    MPU_IIC_SCL(0);
    MPU_IIC_SDA(1);
    MPU_IIC_Delay();
    MPU_IIC_SCL(1);
    MPU_IIC_Delay();
    MPU_IIC_SCL(0);
}

//IIC����һ���ֽ�
//���شӻ�����Ӧ��
//1����Ӧ��
//0����Ӧ��
static void MPU_IIC_Send_Byte(u8 txd)
{
    u8 t;
    MPU_IIC_SCL(0);//����ʱ�ӿ�ʼ���ݴ���
    for(t=0;t<8;t++)
    {
        MPU_IIC_SDA((txd&0x80)>>7);
        MPU_IIC_Delay();
        MPU_IIC_SCL(1);
        MPU_IIC_Delay();
        MPU_IIC_SCL(0);
        MPU_IIC_Delay();
        txd<<=1;
    }
    MPU_IIC_SDA(1);
}
//��1���ֽڣ�ack=1ʱ������ACK��ack=0������nACK
static u8 MPU_IIC_Read_Byte(unsigned char ack)
{
    unsigned char i,receive=0;
    for(i=0;i<8;i++ )
    {
        receive<<=1;
        MPU_IIC_SCL(1);
        MPU_IIC_Delay();
        if(MPU_READ_SDA)receive++;
        MPU_IIC_SCL(0);
        MPU_IIC_Delay();
    }
    if (!ack)
        MPU_IIC_NAck();//����nACK
    else
        MPU_IIC_Ack(); //����ACK
    return receive;
}

//��ʼ��MPU6050
//����ֵ:0,�ɹ�
//    ����,�������
u8 MPU_Init(void)
{
    uint8_t res;

    MPU_IIC_Init();//��ʼ��IIC����
    MPU_Write_Byte(MPU_PWR_MGMT1_REG,0X80); //��λMPU6050
    Delay_Ms(100);
    MPU_Write_Byte(MPU_PWR_MGMT1_REG,0X00); //����MPU6050
    MPU_Set_Gyro_Fsr(3);                    //�����Ǵ�����,��2000dps
    MPU_Set_Accel_Fsr(0);                   //���ٶȴ�����,��2g
    MPU_Set_Rate(50);                       //���ò�����50Hz
    MPU_Write_Byte(MPU_INT_EN_REG,0X00);    //�ر������ж�
    MPU_Write_Byte(MPU_USER_CTRL_REG,0X00); //I2C��ģʽ�ر�
    MPU_Write_Byte(MPU_FIFO_EN_REG,0X01);   //�ر�FIFO
    MPU_Write_Byte(MPU_INTBP_CFG_REG,0X80); //INT���ŵ͵�ƽ��Ч
    res=MPU_Read_Byte(MPU_DEVICE_ID_REG);
    if(res==MPU_ADDR)//����ID��ȷ
    {
        MPU_Write_Byte(MPU_PWR_MGMT1_REG,0X01); //����CLKSEL,PLL X��Ϊ�ο�
        MPU_Write_Byte(MPU_PWR_MGMT2_REG,0X00); //���ٶ��������Ƕ�����
        MPU_Set_Rate(50);                       //���ò�����Ϊ50Hz
    }else return 1;
    return 0;
}
//����MPU6050�����Ǵ����������̷�Χ
//fsr:0,��250dps;1,��500dps;2,��1000dps;3,��2000dps
//����ֵ:0,���óɹ�
//    ����,����ʧ��
u8 MPU_Set_Gyro_Fsr(u8 fsr)
{
    return MPU_Write_Byte(MPU_GYRO_CFG_REG,fsr<<3);//���������������̷�Χ
}
//����MPU6050���ٶȴ����������̷�Χ
//fsr:0,��2g;1,��4g;2,��8g;3,��16g
//����ֵ:0,���óɹ�
//    ����,����ʧ��
u8 MPU_Set_Accel_Fsr(u8 fsr)
{
    return MPU_Write_Byte(MPU_ACCEL_CFG_REG,fsr<<3);//���ü��ٶȴ����������̷�Χ
}
//����MPU6050�����ֵ�ͨ�˲���
//lpf:���ֵ�ͨ�˲�Ƶ��(Hz)
//����ֵ:0,���óɹ�
//    ����,����ʧ��
u8 MPU_Set_LPF(u16 lpf)
{
    u8 data=0;
    if(lpf>=188)data=1;
    else if(lpf>=98)data=2;
    else if(lpf>=42)data=3;
    else if(lpf>=20)data=4;
    else if(lpf>=10)data=5;
    else data=6;
    return MPU_Write_Byte(MPU_CFG_REG,data);//�������ֵ�ͨ�˲���
}
//����MPU6050�Ĳ�����(�ٶ�Fs=1KHz)
//rate:4~1000(Hz)
//����ֵ:0,���óɹ�
//    ����,����ʧ��
u8 MPU_Set_Rate(u16 rate)
{
    u8 data;
    if(rate>1000)rate=1000;
    if(rate<4)rate=4;
    data=1000/rate-1;
    data=MPU_Write_Byte(MPU_SAMPLE_RATE_REG,data);  //�������ֵ�ͨ�˲���
    return MPU_Set_LPF(rate/2); //�Զ�����LPFΪ�����ʵ�һ��
}

//�õ��¶�ֵ
//����ֵ:�¶�ֵ(������100��)
short MPU_Get_Temperature(void)
{
    u8 buf[2];
    short raw;
    float temp;
    MPU_Read_Len(MPU_ADDR,MPU_TEMP_OUTH_REG,2,buf);
    raw=((u16)buf[0]<<8)|buf[1];
    temp=36.53+((double)raw)/340;
    return temp*100;;
}
//�õ�������ֵ(ԭʼֵ)
//gx,gy,gz:������x,y,z���ԭʼ����(������)
//����ֵ:0,�ɹ�
//    ����,�������
u8 MPU_Get_Gyroscope(short *gx,short *gy,short *gz)
{
    u8 buf[6],res;
    res=MPU_Read_Len(MPU_ADDR,MPU_GYRO_XOUTH_REG,6,buf);
    if(res==0)
    {
        *gx=((u16)buf[0]<<8)|buf[1];
        *gy=((u16)buf[2]<<8)|buf[3];
        *gz=((u16)buf[4]<<8)|buf[5];
    }
    return res;;
}
//�õ����ٶ�ֵ(ԭʼֵ)
//gx,gy,gz:������x,y,z���ԭʼ����(������)
//����ֵ:0,�ɹ�
//    ����,�������
u8 MPU_Get_Accelerometer(short *ax,short *ay,short *az)
{
    u8 buf[6],res;
    res=MPU_Read_Len(MPU_ADDR,MPU_ACCEL_XOUTH_REG,6,buf);
    if(res==0)
    {
        *ax=((u16)buf[0]<<8)|buf[1];
        *ay=((u16)buf[2]<<8)|buf[3];
        *az=((u16)buf[4]<<8)|buf[5];
    }
    return res;;
}
//IIC����д
//addr:������ַ
//reg:�Ĵ�����ַ
//len:д�볤��
//buf:������
//����ֵ:0,����
//    ����,�������
u8 MPU_Write_Len(u8 addr,u8 reg,u8 len,u8 *buf)
{
    u8 i;
    MPU_IIC_Start();
    MPU_IIC_Send_Byte((addr<<1)|0);//����������ַ+д����
    if(MPU_IIC_Wait_Ack())  //�ȴ�Ӧ��
    {
        MPU_IIC_Stop();
        return 1;
    }
    MPU_IIC_Send_Byte(reg); //д�Ĵ�����ַ
    MPU_IIC_Wait_Ack();     //�ȴ�Ӧ��
    for(i=0;i<len;i++)
    {
        MPU_IIC_Send_Byte(buf[i]);  //��������
        if(MPU_IIC_Wait_Ack())      //�ȴ�ACK
        {
            MPU_IIC_Stop();
            return 1;
        }
    }
    MPU_IIC_Stop();
    return 0;
}
//IIC������
//addr:������ַ
//reg:Ҫ��ȡ�ļĴ�����ַ
//len:Ҫ��ȡ�ĳ���
//buf:��ȡ�������ݴ洢��
//����ֵ:0,����
//    ����,�������
u8 MPU_Read_Len(u8 addr,u8 reg,u8 len,u8 *buf)
{
    u8 i;

    MPU_IIC_Start();
    MPU_IIC_Send_Byte((addr<<1)|0);//����������ַ+д����
    if(MPU_IIC_Wait_Ack())  //�ȴ�Ӧ��
    {
        MPU_IIC_Stop();
        return 1;
    }
    MPU_IIC_Send_Byte(reg); //д�Ĵ�����ַ
    MPU_IIC_Wait_Ack();     //�ȴ�Ӧ��
    MPU_IIC_Start();
    MPU_IIC_Send_Byte((addr<<1)|1);//����������ַ+������
    MPU_IIC_Wait_Ack();     //�ȴ�Ӧ��
    for(i=0;i<len-1;i++)
    {
        buf[i] = MPU_IIC_Read_Byte(1);
    }
    buf[len-1] = MPU_IIC_Read_Byte(0);
    MPU_IIC_Stop(); //����һ��ֹͣ����
    return 0;
}
//IICдһ���ֽ�
//reg:�Ĵ�����ַ
//data:����
//����ֵ:0,����
//    ����,�������
u8 MPU_Write_Byte(u8 reg,u8 data)
{
    MPU_IIC_Start();
    MPU_IIC_Send_Byte((MPU_ADDR<<1)|0);//����������ַ+д����
    if(MPU_IIC_Wait_Ack())  //�ȴ�Ӧ��
    {
        MPU_IIC_Stop();
        return 1;
    }
    MPU_IIC_Send_Byte(reg); //д�Ĵ�����ַ
    MPU_IIC_Wait_Ack();     //�ȴ�Ӧ��
    MPU_IIC_Send_Byte(data);//��������
    if(MPU_IIC_Wait_Ack())  //�ȴ�ACK
    {
        MPU_IIC_Stop();
        return 1;
    }
    MPU_IIC_Stop();
    return 0;
}
//IIC��һ���ֽ�
//reg:�Ĵ�����ַ
//����ֵ:����������
u8 MPU_Read_Byte(u8 reg)
{
    u8 res;
    MPU_IIC_Start();
    MPU_IIC_Send_Byte((MPU_ADDR<<1)|0);//����������ַ+д����
    MPU_IIC_Wait_Ack();     //�ȴ�Ӧ��
    MPU_IIC_Send_Byte(reg); //д�Ĵ�����ַ
    MPU_IIC_Wait_Ack();     //�ȴ�Ӧ��
    MPU_IIC_Start();
    MPU_IIC_Send_Byte((MPU_ADDR<<1)|1);//����������ַ+������
    MPU_IIC_Wait_Ack();     //�ȴ�Ӧ��
    res=MPU_IIC_Read_Byte(0);//��ȡ����,����nACK
    MPU_IIC_Stop();         //����һ��ֹͣ����
    return res;
}




