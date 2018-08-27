#include "H/Function_Init.H"
/*****************************************************
*函数名称：void IO_Init(void)
*函数功能：IO初始化
*入口参数：void
*出口参数：void
*****************************************************/
void IO_Init(void)
{
	//P0CON = 0xFF;  //设置P0为强推挽IO
	//P0PH  = 0x00;
	P1CON = 0xFF;  //设置P1为强推挽IO
	P1PH  = 0x00;
	P13 = 1;
	//P2CON = 0xFF;  //设置P2为强推挽IO
	//P2PH  = 0x00;
}