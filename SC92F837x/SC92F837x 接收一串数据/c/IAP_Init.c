#include "H/Function_Init.H"

//#define IapROM  0x00	  //0x00：选择ROM区操作  0x02：选择EEPROM区操作
//#define IapEPPROM  0x02	  //0x00：选择ROM区操作  0x02：选择EEPROM区操作
unsigned char code *IapAddr=0x00;

void IAPWrite(uint Addr,uchar Data,uchar IapTotal);
uchar IAPRead(uint Addr,uchar IapTotal);
uchar IapReadData=0x00;   //存放读取的IAP数据

/*****************************************************
*函数名称：void IAP_Test(void)
*函数功能：IAP测试
*入口参数：void
*出口参数：void
*****************************************************/
void IAP_Test(int Address,uchar IapTotal)
{
	IAPWrite(Address,0xff,IapTotal);
	IapReadData=IAPRead(Address,IapTotal);
	while(1)
	{
		if(IapReadData == 0xff)
		{
			P00 = ~P00;
		}
		else
		{
			P01 = ~P01;
		}
	}
}

/*****************************************************
*函数名称：void IAP_Init(void)
*函数功能：IAP初始化
*入口参数：void
*出口参数：void
*****************************************************/
//IAP写操作
void IAPWrite(uint Addr,uchar Data,uchar IapTotal)
{	
	EA = 0;
	IAPDAT=Data;      //写入数据Data
	IAPADH=(uchar)((Addr>>8)&0X3F);   //写入地址的高5位
	IAPADL=(uchar)Addr;               //写入地址的低8位
	
	IAPADE=IapTotal;  //IapTotal=0x00：选择ROM区操作  IapTotal=0x02：选择EEPROM区操作
	IAPKEY=240;		   //IAP开启保护控制时间
	IAPCTL=0x06;     //CPU hold time为2ms，写入操作命令
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	EA = 1;
}
//IAP读操作
uchar IAPRead(uint Addr,uchar IapTotal)
{
	IAPADE=IapTotal;
	return (*(IapAddr+Addr));	
}
