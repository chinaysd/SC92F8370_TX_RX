#include "H/Function_Init.H"
#include "string.h"
bit flag1 = 0;   //中断标志位

/*************************************************************
说明：
1、Options for Target‘Target1’：BL51 Locate->Code Range:0x100，烧录选项请选择DISRST，复位脚作为普通IO使用；
2、改变TEST的定义，可以分别测试对应的功能；
***************************************************************/
unsigned int i;
unsigned char res;
static unsigned char rev_num;
unsigned int temp;
PROTOCOL_BUF_R rev_para;
#if 1
unsigned char Rev_Data(void)
{
	return SSDAT;
}
unsigned char Serial_Get_Status(void)
{
	if(rev_num & 0x80)
	{
		rev_num = 0;
		return 1;
	}
	else
	{
		return 0;
	}
}

void Serial_Rev_IQH(void)
{
	res = Rev_Data();
	
	if((rev_num & 0x80) == 0)
	{
		if(rev_num & 0x40)
		{
			if(res == 0x0a)
			{
				rev_num = 0x80;
			}
			else
			{
				rev_num = 0;
			}
		}
		else
		{
			if(res == 0x0d)
			{
				rev_num |= 0x40;
				
			}
			else
			{
				rev_para.Buf[rev_num] = res;
				rev_num++;
				if(rev_para.Buf[0] != 0x01)
				{
					rev_num = 0;
				}
				if(rev_num > BUF_SIZE)
				{
					rev_num = 0;
					
				}
			}
		}
	}
	
}
#endif

void main(void)
{
	 IO_Init();
	 Uart1_Init(12,9600);
   while(1)
	 {
		 //for(i = 0;i < 30000;i++);
		 if(Serial_Get_Status())
		 {
			  temp = (unsigned int)Get_32bit(rev_para.Data_Format.DATA1,rev_para.Data_Format.DATA2);
				memset(&rev_para,0,sizeof(rev_para));
				switch(temp)
				{
					case 0x0001:
										P14 = 1;
										break;
					case 0x0002:
						        P14 = 0;
										break;
					default:
										break;
				}

		 }
		
    
	 }
}


/*****************************************************
*函数名称：void TWI_Int() interrupt 7
*函数功能：SSI中断函数
*入口参数：void
*出口参数：void
*****************************************************/
void Uart1_Int() interrupt 7   //Uart1中断函数
{
	
	Serial_Rev_IQH();
	if(SSCON0&0x02)    //接收标志位判断
	{
		SSCON0&=0xFD;
		
	}
	if((SSCON0&0x01))  //发送标志位判断
	{
		SSCON0&=0xFE;
		
	}
	//flag1 = 1;
}
