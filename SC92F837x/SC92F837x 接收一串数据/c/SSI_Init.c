#include "H/Function_Init.H"




/*****************************************************
*�������ƣ�void Uart1_Init(void)
*�������ܣ�Uart1�жϳ�ʼ��
*��ڲ�����Freq-��Ƶ��baud-������
*���ڲ�����void
*****************************************************/
void Uart1_Init(int Freq,long int baud)
{
	OTCON = 0xC0;    //���нӿ�SSIѡ��Uart1ͨ��
	SSCON0 = 0x5F;   //����ͨ�ŷ�ʽΪģʽһ���������
	SSCON1 = Freq*1000000/baud;   //�����ʵ�λ����
	SSCON2 = (Freq*1000000/baud)>>8;   //�����ʸ�λ����
	IE1 = 0x01;      //����SSI�ж�
  EA = 1;	
}

