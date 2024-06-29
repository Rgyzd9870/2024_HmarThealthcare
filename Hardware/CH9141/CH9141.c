/*******************************************************************************
* CH9141 BLE 蓝牙与WCHLink串口通过DMA实现数据互传的例程
* 赤菟开发板上 UART7 CH9141 串口透传模块
* 本例程演示使用 DMA 通过 UART7 与 CH9141 通信
*
* 可以用手机或电脑连接 CH9141 进行通信。
*
* 用手机端连接时，需要通过蓝牙调试软件与CH9141通信
* 注意 CH9141 透传服务的 UUID 为 0000fff0,其中 CH9141的 TX 为 0000fff1,RX 为 0000fff2
* 配置不正确可以连接但不能通信
*
* 例程中 uartWriteBLE(), uartWriteBLEstr() 是非阻塞的。
* 调用这些函数发送时，若上一次发送尚未完成，将不等待而直接返回
*
* 安卓平台调试 APP
* BLEAssist　沁恒官方的 BLE 调试 APP，配置比较详细，适合复杂调试 http://www.wch.cn/downloads/BLEAssist_ZIP.html
* 蓝牙调试器 XLazyDog 开发，适合简单调试、遥控调试 https://blog.csdn.net/XLazyDog/article/details/99584735
*******************************************************************************/
#include "CH9141.h"
#include "stdio.h"
#include "stdarg.h"
#include "string.h"
#include "lcd.h"
/* Global define */
#define CH9141_RXBUF_SIZE 1024     // DMA buffer size
#define CH9141_size(a)   (sizeof(a) / sizeof(*(a)))

/* Global Variable */
u8 CH9141_TxBuffer[] = " ";
u8 CH9141_RxBuffer[CH9141_RXBUF_SIZE]={0};


/*******************************************************************************
* Function Name  : USARTx_CFG
* Description    : Initializes the USART peripheral.
* 描述    ：   串口初始化
* Input          : None
* Return         : None
*******************************************************************************/
void CH9141_USARTx_CFG(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;
    //开启时钟
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART7, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

    /* USART7 TX-->C2  RX-->C3 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;           //RX，输入上拉
    GPIO_Init(GPIOC, &GPIO_InitStructure);

    USART_InitStructure.USART_BaudRate = 115200;                    // 波特率
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;     // 数据位 8
    USART_InitStructure.USART_StopBits = USART_StopBits_1;          // 停止位 1
    USART_InitStructure.USART_Parity = USART_Parity_No;             // 无校验
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; // 无硬件流控
    USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx; //使能 RX 和 TX

    USART_Init(UART7, &USART_InitStructure);
    DMA_Cmd(DMA2_Channel9, ENABLE);                                  //开启接收 DMA
    USART_Cmd(UART7, ENABLE);                                        //开启UART
}

/*******************************************************************************
* Function Name  : DMA_INIT
* Description    : Configures the DMA.
* 描述    ：   DMA 初始化
* Input          : None
* Return         : None
*******************************************************************************/
void CH9141_DMA_INIT(void)
{
    DMA_InitTypeDef DMA_InitStructure;
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA2, ENABLE);

    // TX DMA 初始化
    DMA_DeInit(DMA2_Channel8);
    DMA_InitStructure.DMA_PeripheralBaseAddr = (u32)(&UART7->DATAR);        // DMA 外设基址，需指向对应的外设
    DMA_InitStructure.DMA_MemoryBaseAddr = (u32)CH9141_TxBuffer;                   // DMA 内存基址，指向发送缓冲区的首地址
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;                      // 方向 : 外设 作为 终点，即 内存 ->  外设
    DMA_InitStructure.DMA_BufferSize = 0;                                   // 缓冲区大小,即要DMA发送的数据长度,目前没有数据可发
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;        // 外设地址自增，禁用
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;                 // 内存地址自增，启用 ；读取的时候地址自增，也就是存到数组自增
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte; // 外设数据位宽，8位(Byte)
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;         // 内存数据位宽，8位(Byte)
    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;                           // 普通模式，发完结束，不循环发送
    DMA_InitStructure.DMA_Priority = DMA_Priority_VeryHigh;                 // 优先级最高
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;                            // M2P,禁用M2M
    DMA_Init(DMA2_Channel8, &DMA_InitStructure);

    // RX DMA 初始化，环形缓冲区自动接收
    DMA_DeInit(DMA2_Channel9);
    DMA_InitStructure.DMA_PeripheralBaseAddr = (u32)(&UART7->DATAR);
    DMA_InitStructure.DMA_MemoryBaseAddr = (u32)CH9141_RxBuffer;                   // 接收缓冲区
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;                      // 方向 : 外设 作为 源，即 内存 <- 外设
    DMA_InitStructure.DMA_BufferSize = CH9141_RXBUF_SIZE;                          // 缓冲区长度为 CH9141_RXBUF_SIZE
    DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;                         // 循环模式，构成环形缓冲区
    DMA_Init(DMA2_Channel9, &DMA_InitStructure);

}


/*******************************************************************************
* Function Name  : GPIO_CFG
* Description    : Initializes GPIOs.
* 描述    ：   GPIO　初始化
* Input          : None
* Return         : None
*******************************************************************************/
void CH9141_GPIO_CFG(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    // CH9141 配置引脚初始化
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    /* BLE_sleep --> C13  BLE_AT-->A7 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
}
/*******************************************************************************
* Function Name  :  uartWriteBLE
* Description    :  send data to BLE via UART7          向蓝牙模组发送数据
* Input          :  char * data          data to send   要发送的数据的首地址
*                   uint16_t num         number of data 数据长度
* Return         :  RESET                UART7 busy,failed to send  发送失败
*                   SET                  send success               发送成功
*******************************************************************************/
FlagStatus CH9141_uartWriteBLE(char * data , uint16_t num)
{
    //如上次发送未完成，返回
    if(DMA_GetCurrDataCounter(DMA2_Channel8) != 0){
        return RESET;
    }

    DMA_ClearFlag(DMA2_FLAG_TC8);
    DMA_Cmd(DMA2_Channel8, DISABLE );           // 关 DMA 后操作
    DMA2_Channel8->MADDR = (uint32_t)data;      // 发送缓冲区为 data
    DMA_SetCurrDataCounter(DMA2_Channel8,num);  // 设置缓冲区长度
    DMA_Cmd(DMA2_Channel8, ENABLE);             // 开 DMA
    return SET;
}

/*******************************************************************************
* Function Name  :  uartWriteBLEstr
* Description    :  send string to BLE via UART7    向蓝牙模组发送字符串
* Input          :  char * str          string to send
* Return         :  RESET                UART7 busy,failed to send  发送失败
*                   SET                  send success               发送成功
*******************************************************************************/
FlagStatus CH9141_uartWriteBLEstr(char * str)
{
    uint16_t num = 0;
    while(str[num])num++;           // 计算字符串长度
    return CH9141_uartWriteBLE(str,num);
}


/*******************************************************************************
* Function Name  :  uartReadBLE
* Description    :  read some bytes from receive buffer 从接收缓冲区读出一组数据
* Input          :  char * buffer        buffer to storage the data 用来存放读出数据的地址
*                   uint16_t num         number of data to read     要读的字节数
* Return         :  int                  number of bytes read       返回实际读出的字节数
*******************************************************************************/
uint16_t CH9141_rxBufferReadPos = 0;       //接收缓冲区读指针
uint32_t CH9141_uartReadBLE(char * buffer , uint16_t num)
{
    uint16_t CH9141_rxBufferEnd = CH9141_RXBUF_SIZE - DMA_GetCurrDataCounter(DMA2_Channel9); //计算 DMA 数据尾的位置
    uint16_t i = 0;

    if (CH9141_rxBufferReadPos == CH9141_rxBufferEnd){
        // 无数据，返回
        return 0;
    }

    while (CH9141_rxBufferReadPos!=CH9141_rxBufferEnd && i < num){
        buffer[i] = CH9141_RxBuffer[CH9141_rxBufferReadPos];
        i++;
        CH9141_rxBufferReadPos++;
        if(CH9141_rxBufferReadPos >= CH9141_RXBUF_SIZE){
            // 超出缓冲区，回零
            CH9141_rxBufferReadPos = 0;
        }
    }
    return i;
}

/*******************************************************************************
* Function Name  :  uartReadByteBLE  这里它只运行了一次，返回值也是一个字节
* Description    :  read one byte from UART buffer  从接收缓冲区读出 1 字节数据
* Input          :  None
* Return         :  char    read data               返回读出的数据(无数据也返回0)
*******************************************************************************/
char CH9141_uartReadByteBLE()
{
    char ret;
    uint16_t CH9141_rxBufferEnd = CH9141_RXBUF_SIZE - DMA_GetCurrDataCounter(DMA2_Channel9);//计算 DMA 数据尾的位置
    if (CH9141_rxBufferReadPos == CH9141_rxBufferEnd){
        // 无数据，返回
        return 0;
    }
    ret = CH9141_RxBuffer[CH9141_rxBufferReadPos];
    CH9141_rxBufferReadPos++;
    if(CH9141_rxBufferReadPos >= CH9141_RXBUF_SIZE){
        // 超出缓冲区，回零
        CH9141_rxBufferReadPos = 0;
    }
    return ret;
}
/*******************************************************************************
* Function Name  :  uartAvailableBLE
* Description    :  get number of bytes Available to read from the UART buffer  获取缓冲区中可读数据的数量
* Input          :  None
* Return         :  uint16_t    number of bytes Available to readd              返回可读数据数量
*******************************************************************************/
uint16_t CH9141_uartAvailableBLE()
{
    uint16_t CH9141_rxBufferEnd = CH9141_RXBUF_SIZE - DMA_GetCurrDataCounter(DMA2_Channel9);//计算 DMA 数据尾的位置
    // 计算可读字节
    if (CH9141_rxBufferReadPos <= CH9141_rxBufferEnd){
        return CH9141_rxBufferEnd - CH9141_rxBufferReadPos;
    }else{
        return CH9141_rxBufferEnd +CH9141_RXBUF_SIZE -CH9141_rxBufferReadPos;
    }
}

void CH9141_Init(void)
{
    CH9141_DMA_INIT();
    CH9141_USARTx_CFG();                                                 /* USART INIT */
    USART_DMACmd(UART7,USART_DMAReq_Tx|USART_DMAReq_Rx,ENABLE);

    CH9141_GPIO_CFG();
        GPIO_WriteBit(GPIOA, GPIO_Pin_7,RESET); //进入 AT
        GPIO_WriteBit(GPIOC, GPIO_Pin_13,SET); //enable CH9141
        Delay_Ms(1000);

        //串口空闲 0.5s 后发送  "AT...\r\n" 可以直接进入 AT 模式
                //uartWriteBLEstr("AT...\r\n");
        printf("1.AT指令准备\r\n");
       if( CH9141_AT_WriteCmd(50, "AT...\r\n", "OK"))
       {
           printf("开启AT模式失败!\r\n");

       }
       else
           printf("开启AT模式成功!\r\n");
           printf("\r\n");

       printf("2.重置所有参数\r\n");
      if( CH9141_AT_WriteCmd(50, "AT+RELOAD\r\n", "OK"))
      {
          printf("重置所有参数失败!\r\n");

      }
      else
          printf("重置所有参数成功!\r\n");
          printf("\r\n");

      printf("2.设置密码关闭\r\n");
           if( CH9141_AT_WriteCmd(50, "AT+PASEN=OFF\r\n", "OK"))
           {
               printf("关闭失败!\r\n");

           }
           else
               printf("关闭成功!\r\n");
               printf("\r\n");
       printf("3.查询MAC\r\n");
      if( CH9141_AT_WriteCmd(50, "AT+MAC?\r\n", "OK"))
      {
          printf("查询MAC失败!\r\n");

      }
      else
          printf("查询MAC成功!\r\n");
          printf("\r\n");

          printf("4.重启\r\n");
          if( CH9141_AT_WriteCmd(50, "AT+RESET\r\n", "OK"))
          {
              printf("重启失败!\r\n");

          }
          else
              printf("重启成功!\r\n");
              printf("\r\n");



      GPIO_WriteBit(GPIOA, GPIO_Pin_7,SET); // 退出AT。可用手机或电脑连接CH9141,测试数据收发

}

/*******************************************************************************
* Function Name  :  LCD_TurnBufferBLE
* Description    :  将字符串转换成数组格式（用buffer）
* Input          :  None
* Return         :  uint16_t    number of bytes Available to readd              返回可读数据数量
*******************************************************************************/
char buffer[100];
void LCD_TurnBufferBLE(char* format, ...)
{
    va_list vArgList;
    va_start(vArgList, format);
    vsnprintf(buffer, 100, format, vArgList);/*把可变参数表中的数据转成字符存到buffer中，每个参数间用','隔开 */
    va_end(vArgList);
}

/*******************************************************************************
* Function Name  :  LCD_TurnBufferBLE
* Description    :  串口接收蓝牙数据并打印在串口蓝牙上
* Input          :  None
* Return         :  uint16_t    number of bytes Available to readd              返回可读数据数量
*******************************************************************************/
void CH9141_ReadPrint_LCD_BLE(void)
{
    int num = CH9141_uartAvailableBLE();             //读取蓝牙字符串
    if (num > 0 )
    {
        lcd_clear(BLACK);                   //  清屏
        char buffer[1024]={"\0"};
        CH9141_uartReadBLE(buffer , num);
        lcd_set_color(BLACK,GREEN);           //将读取的字符串显示在屏幕上
        lcd_show_string(30, 208, 16,0,"Receive    : %8s", buffer);
        printf("Revceived:%s\r\n",buffer);    //将收到的字符串发送给串口
        Delay_Ms(100);
    }
}

/*******************************************************************************
* Function Name  :  CH9141_AT_WriteCmd
* Description    :  串口写AT命令
* Input          :  time：超时时间；cmd:命令 ；response:对比接收的字符看是否成功
* Return         :  0：成功；1：失败
*******************************************************************************/
char CH9141_AT_WriteCmd(int time,char*cmd,char*response)
{
    memset(CH9141_RxBuffer,0,1024);       //将蓝牙模块接收清零

    CH9141_uartWriteBLEstr(cmd);          //蓝牙模组发送字符串
    while(time--)
    {
        delay_ms(100);
        //
        int num = CH9141_uartAvailableBLE();//读取蓝牙字符串
        char buffer[1024]={"\0"};
        if (num > 0 ){

                        CH9141_uartReadBLE(buffer , num);
                        printf("%s",buffer);   //测试
        }

        if(strstr(buffer,response))//对比接收数据
            break;
            printf("%d ",time);
    }
    if(time>0)
       return 0;
    else
       return 1;

}
void CH9141_RX_Str(void)
{
    char buffer[1024];
    uint8_t batteryPercentage, bloodOxygen;

    int num1 = CH9141_uartAvailableBLE();

    if (num1 > 0 ){
         memset(buffer,'\0',1024);
        CH9141_uartReadBLE(buffer , num1);      //读取蓝牙传输出来的数据
        printf("buffer:%d\r\n",buffer);

        char *strBattery = strstr(buffer, "battery:");
        if(strBattery){
            sscanf(strBattery,"battery:%d",&batteryPercentage);
        }
        char *strOxygen = strstr(buffer,"oxygen:");
        if(strOxygen){
            sscanf(strOxygen,"oxygen:%d",&bloodOxygen);
        }
//    mutex(onenet_mutex_handler,100,
//            MQTT_Buffer.BatteryPercentage = batteryPercentage;
//            MQTT_Buffer.BloodOxygen = bloodOxygen;
//            );
    printf("BatteryPercentage:%d  BloodOxygen:%d\r\n",batteryPercentage,bloodOxygen);

                            }
}
