

#include "Dis_Picture.h" 
										    

//////////////////////////////////////////////////////////////////////////////////	 
/******************************************************************************/	 
//图片显示 驱动代码	

//DevEBox  大越创新
//淘宝店铺：mcudev.taobao.com
//淘宝店铺：shop389957290.taobao.com	
/******************************************************************************/							  


//16位 垂直扫描  右到左  高位在前
void Show_Picture(void)
{
	u32 i,j,k=0;
	
	u16 picH,picL;
	
	LCD_Clear(WHITE);//清屏
	
	Draw_Font16B(24,16,BLUE,"3: 图片显示测试");	
	
	Delay_Ms(1000);    //延时显示
	
	LCD_Clear(WHITE);  //清屏
	
	#if USE_HORIZONTAL==1	//使用横屏	

	{
		
		LCD_Set_Window(0,0,320,240);//设置一个自动换行显示区域窗口

		LCD_WriteRAM_Prepare();     	//开始写入GRAM	
						
		for(i=0;i<240;i++)
		for(j=0;j<320;j++)
		{
			picH=gImage_LCD280[k++];
			picL=gImage_LCD280[k++];
			
			LCD_WR_DATA8(picH);  //写8位显示数据
			LCD_WR_DATA8(picL);
			
		}			
	}	

		
	#else	
	
	{
		        /**************二次元图片*************/
//		LCD_Set_Window(10,40,100,143);//设置一个自动换行显示区域窗口
//
//		LCD_WriteRAM_Prepare();     	//开始写入GRAM
//
//		for(i=0;i<143;i++)
//		for(j=0;j<100;j++)
//		{
//			picH=gImage_LCD280[k++];
//			picL=gImage_LCD280[k++];
//
//			LCD_WR_DATA8(picH);  //写8位显示数据
//			LCD_WR_DATA8(picL);
//		}

		Delay_Ms(10);
		    /**********************心率**************/
		k =0;
        LCD_Set_Window(22,100,24,24);//设置一个自动换行显示区域窗口

        LCD_WriteRAM_Prepare();         //开始写入GRAM

        for(i=0;i<24;i++)
        for(j=0;j<24;j++)
        {
            picH=gImage_hrart[k++];
            picL=gImage_hrart[k++];

            LCD_WR_DATA8(picH);  //写8位显示数据
            LCD_WR_DATA8(picL);
        }


    Delay_Ms(10);

        /**********************血氧**************/
    k =0;
    LCD_Set_Window(22,150,24,24);//设置一个自动换行显示区域窗口

    LCD_WriteRAM_Prepare();         //开始写入GRAM

    for(i=0;i<24;i++)
    for(j=0;j<24;j++)
    {
        picH=gImage_Oxygen[k++];
        picL=gImage_Oxygen[k++];

        LCD_WR_DATA8(picH);  //写8位显示数据
        LCD_WR_DATA8(picL);
    }
        /******************老人摔倒**************/
    k =0;
    LCD_Set_Window(22,200,24,24);//设置一个自动换行显示区域窗口

    LCD_WriteRAM_Prepare();         //开始写入GRAM

    for(i=0;i<24;i++)
    for(j=0;j<24;j++)
    {
        picH=gImage_elderlyFall[k++];
        picL=gImage_elderlyFall[k++];

        LCD_WR_DATA8(picH);  //写8位显示数据
        LCD_WR_DATA8(picL);
    }
}
	
	#endif
	
} 





/*******************************************************************************/

//DevEBox  大越创新

//淘宝店铺：mcudev.taobao.com
//淘宝店铺：shop389957290.taobao.com
/*******************************************************************************/

















		  






