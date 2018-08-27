#include "H/Function_Init.H"
#include "string.h"

bit flag1 = 0;   //�жϱ�־λ
unsigned int i;

void Send_Byte(unsigned char ssdat)
{
	 SSDAT = ssdat;
	 while(!flag1);
	 flag1 = 0;
}

unsigned int Protocol_Send(PROTOCOL_BUF_t *p)
{
	char cnt;
	for(cnt = 0;cnt < BUF_SIZE;cnt++)
	{
		 Send_Byte(p->Buf[cnt]);
	}
	return 1;
}

unsigned int Send_Data(ADDR_DATA addr,ID_DATA id,unsigned int tx_data)
{
	PROTOCOL_BUF_t buf;
	memset(&buf,0,sizeof(buf));
	buf.Data_Format.Add = addr;
	buf.Data_Format.MessageID = id;
	buf.Data_Format.Data1 = get_hight(tx_data);
	buf.Data_Format.Data2 = get_low(tx_data);
	buf.Data_Format.Checksum = (unsigned char)((buf.Data_Format.Add)+(buf.Data_Format.MessageID)+(buf.Data_Format.Data1)+(buf.Data_Format.Data2));
	buf.Data_Format.Stop1 = get_hight(STOP_DATA);
	buf.Data_Format.Stop2 = get_low(STOP_DATA);
	return Protocol_Send(&buf); 
}

void main(void)
{
	   IO_Init();
	   Uart1_Init(12,9600);
     while(1)
		 {
			 for(i = 0;i < 60000;i++);
			 Send_Data(0x01,0x02,0x01);
		 }
}


/*****************************************************
*�������ƣ�void TWI_Int() interrupt 7
*�������ܣ�SSI�жϺ���
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void Uart1_Int() interrupt 7   //Uart1�жϺ���
{
	if(SSCON0&0x02)    //���ձ�־λ�ж�
	{
		SSCON0&=0xFD;
	}
	if((SSCON0&0x01))  //���ͱ�־λ�ж�
	{
		SSCON0&=0xFE;
	}
	flag1 = 1;
}

