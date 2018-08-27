#include "H/Function_Init.H"

unsigned int xdata PWMRD[8]  _at_  0x740;
void PWM_Init(void);
/*****************************************************
*函数名称：void PWM_Test(void)
*函数功能：PWM测试
*入口参数：void
*出口参数：void
*****************************************************/
void PWM_Test(void)
{
	PWM_Init();
	while(1)
	{
	}
}
/*****************************************************
*函数名称：void PWM_Init(void)
*函数功能：PWM初始化
*入口参数：void
*出口参数：void
*****************************************************/
void PWM_Init(void)
{
	unsigned int i = 0;
	PWMCON = 0x7F;    //周期设置低8位,200us
  PWMCFG = 0x8C;    //7:开关  5-4：时钟源选择  3-0：周期设置高4位
	for(i=0;i<8;i++)
	{	
	  PWMRD[i] = 0x8640;
	}
}