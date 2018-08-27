#include "H/Function_Init.H"

//#define IapROM  0x00	  //0x00��ѡ��ROM������  0x02��ѡ��EEPROM������
//#define IapEPPROM  0x02	  //0x00��ѡ��ROM������  0x02��ѡ��EEPROM������
unsigned char code *IapAddr=0x00;

void IAPWrite(uint Addr,uchar Data,uchar IapTotal);
uchar IAPRead(uint Addr,uchar IapTotal);
uchar IapReadData=0x00;   //��Ŷ�ȡ��IAP����

/*****************************************************
*�������ƣ�void IAP_Test(void)
*�������ܣ�IAP����
*��ڲ�����void
*���ڲ�����void
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
*�������ƣ�void IAP_Init(void)
*�������ܣ�IAP��ʼ��
*��ڲ�����void
*���ڲ�����void
*****************************************************/
//IAPд����
void IAPWrite(uint Addr,uchar Data,uchar IapTotal)
{	
	EA = 0;
	IAPDAT=Data;      //д������Data
	IAPADH=(uchar)((Addr>>8)&0X3F);   //д���ַ�ĸ�5λ
	IAPADL=(uchar)Addr;               //д���ַ�ĵ�8λ
	
	IAPADE=IapTotal;  //IapTotal=0x00��ѡ��ROM������  IapTotal=0x02��ѡ��EEPROM������
	IAPKEY=240;		   //IAP������������ʱ��
	IAPCTL=0x06;     //CPU hold timeΪ2ms��д���������
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
//IAP������
uchar IAPRead(uint Addr,uchar IapTotal)
{
	IAPADE=IapTotal;
	return (*(IapAddr+Addr));	
}
