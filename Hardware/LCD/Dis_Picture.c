

#include "Dis_Picture.h" 
										    

//////////////////////////////////////////////////////////////////////////////////	 
/******************************************************************************/	 
//ͼƬ��ʾ ��������	

//DevEBox  ��Խ����
//�Ա����̣�mcudev.taobao.com
//�Ա����̣�shop389957290.taobao.com	
/******************************************************************************/							  


//16λ ��ֱɨ��  �ҵ���  ��λ��ǰ
void Show_Picture(void)
{
	u32 i,j,k=0;
	
	u16 picH,picL;
	
	LCD_Clear(WHITE);//����
	
	Draw_Font16B(24,16,BLUE,"3: ͼƬ��ʾ����");	
	
	Delay_Ms(1000);    //��ʱ��ʾ
	
	LCD_Clear(WHITE);  //����
	
	#if USE_HORIZONTAL==1	//ʹ�ú���	

	{
		
		LCD_Set_Window(0,0,320,240);//����һ���Զ�������ʾ���򴰿�

		LCD_WriteRAM_Prepare();     	//��ʼд��GRAM	
						
		for(i=0;i<240;i++)
		for(j=0;j<320;j++)
		{
			picH=gImage_LCD280[k++];
			picL=gImage_LCD280[k++];
			
			LCD_WR_DATA8(picH);  //д8λ��ʾ����
			LCD_WR_DATA8(picL);
			
		}			
	}	

		
	#else	
	
	{
		        /**************����ԪͼƬ*************/
//		LCD_Set_Window(10,40,100,143);//����һ���Զ�������ʾ���򴰿�
//
//		LCD_WriteRAM_Prepare();     	//��ʼд��GRAM
//
//		for(i=0;i<143;i++)
//		for(j=0;j<100;j++)
//		{
//			picH=gImage_LCD280[k++];
//			picL=gImage_LCD280[k++];
//
//			LCD_WR_DATA8(picH);  //д8λ��ʾ����
//			LCD_WR_DATA8(picL);
//		}

		Delay_Ms(10);
		    /**********************����**************/
		k =0;
        LCD_Set_Window(22,100,24,24);//����һ���Զ�������ʾ���򴰿�

        LCD_WriteRAM_Prepare();         //��ʼд��GRAM

        for(i=0;i<24;i++)
        for(j=0;j<24;j++)
        {
            picH=gImage_hrart[k++];
            picL=gImage_hrart[k++];

            LCD_WR_DATA8(picH);  //д8λ��ʾ����
            LCD_WR_DATA8(picL);
        }


    Delay_Ms(10);

        /**********************Ѫ��**************/
    k =0;
    LCD_Set_Window(22,150,24,24);//����һ���Զ�������ʾ���򴰿�

    LCD_WriteRAM_Prepare();         //��ʼд��GRAM

    for(i=0;i<24;i++)
    for(j=0;j<24;j++)
    {
        picH=gImage_Oxygen[k++];
        picL=gImage_Oxygen[k++];

        LCD_WR_DATA8(picH);  //д8λ��ʾ����
        LCD_WR_DATA8(picL);
    }
        /******************����ˤ��**************/
    k =0;
    LCD_Set_Window(22,200,24,24);//����һ���Զ�������ʾ���򴰿�

    LCD_WriteRAM_Prepare();         //��ʼд��GRAM

    for(i=0;i<24;i++)
    for(j=0;j<24;j++)
    {
        picH=gImage_elderlyFall[k++];
        picL=gImage_elderlyFall[k++];

        LCD_WR_DATA8(picH);  //д8λ��ʾ����
        LCD_WR_DATA8(picL);
    }
}
	
	#endif
	
} 





/*******************************************************************************/

//DevEBox  ��Խ����

//�Ա����̣�mcudev.taobao.com
//�Ա����̣�shop389957290.taobao.com
/*******************************************************************************/

















		  






