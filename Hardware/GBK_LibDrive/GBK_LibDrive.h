#ifndef __GBK_LibDrive_H__
#define __GBK_LibDrive_H__	 


#include "lcd.h"  //加入关联头文件
#include "debug.h"
#include "string.h"												    


//////////////////////////////////////////////////////////////////////////////////	 
 
//汉字显示 驱动代码	   

//DevEBox  大越创新
//淘宝店铺：mcudev.taobao.com
//淘宝店铺：shop389957290.taobao.com								  
////////////////////////////////////////////////////////////////////////////////// 

#define   FontRead_CMD  0x03//接口读取字库--命令字

#define   Used_FontIO   0 //如果是独立驱动的字库接口IO，则使用独立的接口驱动

#if    Used_FontIO


#define	FCS_SET  	GPIO_SetBits(GPIOC,GPIO_Pin_13)     //片选对应
#define	FCS_CLR  	GPIO_ResetBits(GPIOC,GPIO_Pin_13)   //片选对应

#define	FDI_SET   GPIO_SetBits(GPIOF,GPIO_Pin_11)      //数据输出
#define	FDI_CLR   GPIO_ResetBits(GPIOF,GPIO_Pin_11)    //数据输出

#define	FDO_IN   GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_2)   //数据输入


#define	FCLK_SET   GPIO_SetBits(GPIOB,GPIO_Pin_0)   //数据时钟线

#define	FCLK_CLR   GPIO_ResetBits(GPIOB,GPIO_Pin_0) //数据时钟线

#define	FCS_SET 		  GPIO_SetBits(GPIOB,GPIO_Pin_12)       //片选信号 PB12
#define	FCS_CLR 		  GPIO_ResetBits(GPIOB,GPIO_Pin_12)     //片选信号 PB12


#define	Font_CS_EN 		FCS_SET; GBK_delay(5);         //片选信号  --使能
#define	Font_CS_SN 		FCS_CLR; GBK_delay(5);  		    //片选信号  --失能

#else

#define	FCS_SET 		  GPIO_SetBits(GPIOB,GPIO_Pin_12)       //片选信号 PB12
#define	FCS_CLR 		  GPIO_ResetBits(GPIOB,GPIO_Pin_12)     //片选信号 PB12

#define	Font_CS_EN 		FCS_SET; GBK_delay(5);               //片选信号  --使能
#define	Font_CS_SN 		FCS_CLR; GBK_delay(5);  		          //片选信号  --失能

#define	Font_SPI_WR    SPI2_ReadWriteByte

#endif


////索引                        文件名                    大小              偏移量            强制插入
//// 1      GBK-TS4产生-合并-宋体\ASCII-ST8x16.bin        0x00000800        0x00000000       第一个填充为预留空间，可以写其他数据

//// 2      GBK-TS4产生-合并-宋体\ASCII-ST8x16.bin        0x00000800        0x00002000             是
//// 3      GBK-TS4产生-合并-宋体\ASCII-ST12x24.bin       0x00001200        0x00003000             是
//// 4      GBK-TS4产生-合并-宋体\ASCII-ST16x32.bin       0x00002000        0x00004400             是

//// 5      GBK-TS4产生-合并-宋体\ASCII-ST24x48.bin       0x00004800        0x00006600             是
//// 6      GBK-TS4产生-合并-宋体\ASCII-ST32x64.bin       0x00008000        0x0000B000             是
//// 7      GBK-TS4产生-合并-宋体\ASCII-ST48x96.bin       0x00012000        0x00013200             是

//// 8      GBK-TS4产生-合并-宋体\ASCII-ST64x128.bin      0x00020000        0x00025400             是

//// 9      GBK-TS4产生-合并-宋体\GBK-ST16x16.bin         0x000BB080        0x00045600             是
//// 10     GBK-TS4产生-合并-宋体\GBK-ST24x24.bin         0x001A4D20        0x00100900             是
//// 11     GBK-TS4产生-合并-宋体\GBK-ST32x32.bin         0x002EC200        0x002A5A00             是


//汉字字库存储偏移位置

#define	ASCII6x12_ST   0x00080000
#define	ASCII8x16_ST   0x00080800
#define	ASCII12x24_ST  0x00081200
#define	ASCII16x32_ST  0x00082600

#define	ASCII24x48_ST  0x00084800
#define	ASCII32x64_ST  0x00089200



#define	GBK12x12_ST    0x00091400
#define	GBK16x16_ST    0x0011DD00
#define	GBK24x24_ST    0x001DA000
#define	GBK32x32_ST    0x00380000 



void GBK_Lib_Init(void);//初始化引脚接口

void FontLib_Read(u8* pBuffer,u32 ReadAddr,u16 Num_Read);//字库读写接口函数

void GBK_ReadID(void);//读字库ID

void GBK_delay(unsigned char Time);//延时函数

void GBK_GetASC_Point(uint8_t *code, uint8_t *Pdot, uint8_t Font, uint16_t Num);   // 获取点阵ASCII点阵字符 		
void GBK_ShowASCII(uint16_t x, uint16_t y, uint8_t *N_Word, uint8_t size, uint16_t D_Color, uint16_t B_Color, uint8_t mode); // 在指定位置显示ASCII码 字符--点阵字符
	
void GBK_Lib_GetHz(uint8_t *code, uint8_t *Pdot, uint8_t Font, uint16_t Num);			   //得到汉字的点阵码
void GBK_Show_Font(uint16_t x, uint16_t y, uint8_t *font, uint8_t size, uint16_t D_Color, uint16_t B_Color, uint8_t mode);			 //在指定位置显示一个汉字

void GBK_Show_Str(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint8_t *str, uint8_t size, uint16_t D_Color, uint16_t B_Color, uint8_t mode);	//在指定位置显示一个字符串 
void GBK_Show_StrMid(uint16_t x,uint16_t y, uint8_t size, uint8_t len, uint16_t D_Color, uint16_t B_Color,uint8_t*str); //在指定宽度的中间显示字符串

void DrawFont_GBK12B(u16 x,u16 y, u16 color, u8*str);//在指定位置开始显示一个12x12点阵的--字符串，支持自动换行(至屏幕一行的终点后，自动换到下一个x起点位置)	
void DrawFont_GBK16B(u16 x,u16 y, u16 color, u8*str);//在指定位置开始显示一个16x16点阵的--字符串，支持自动换行(至屏幕一行的终点后，自动换到下一个x起点位置)	
void DrawFont_GBK24B(u16 x,u16 y, u16 color, u8*str);//在指定位置开始显示一个24x24点阵的--字符串，支持自动换行(至屏幕一行的终点后，自动换到下一个x起点位置)	
void DrawFont_GBK32B(u16 x,u16 y, u16 color, u8*str);//在指定位置开始显示一个32x32点阵的--字符串，支持自动换行(至屏幕一行的终点后，自动换到下一个x起点位置)	

void DrawFontASC_GBK48B(u16 x,u16 y, u16 color, u8*str);//在指定位置开始显示一个24x48点阵的--ACSII码 

void DrawFontASC_GBK64B(u16 x,u16 y, u16 color, u8*str);//在指定位置开始显示一个32x64点阵的--ACSII码 

void GBK_LibFont_Test(void);//GBK字库测试函数

#endif
