#include "H/Function_Init.H"

unsigned int xdata PWMRD[8]  _at_  0x740;
void PWM_Init(void);
/*****************************************************
*�������ƣ�void PWM_Test(void)
*�������ܣ�PWM����
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void PWM_Test(void)
{
	PWM_Init();
	while(1)
	{
	}
}
/*****************************************************
*�������ƣ�void PWM_Init(void)
*�������ܣ�PWM��ʼ��
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void PWM_Init(void)
{
	unsigned int i = 0;
	PWMCON = 0x7F;    //�������õ�8λ,200us
  PWMCFG = 0x8C;    //7:����  5-4��ʱ��Դѡ��  3-0���������ø�4λ
	for(i=0;i<8;i++)
	{	
	  PWMRD[i] = 0x8640;
	}
}