#ifndef _Function_Init_H_
#define _Function_Init_H_

#include "SC92F837x_C.H"
#include "intrins.H"
#define uchar unsigned char
#define uint unsigned int
#define BUF_SIZE   7
#define Get_32bit(x,y)		((x << 8) | y) & 0XFFFF

#define IapROM  0x00	  //0x00：选择ROM区操作  0x02：选择EEPROM区操作
#define IapEPPROM  0x02	  //0x00：选择ROM区操作  0x02：选择EEPROM区操作

typedef struct
{
	unsigned char ADDR;
	unsigned char ID;
	unsigned char DATA1;
	unsigned char DATA2;
	unsigned char CHECKSUM;
	unsigned char STOP1;
	unsigned char STOP2;
}
DATA_FORMAT_R;

typedef union
{
	DATA_FORMAT_R Data_Format;
	unsigned char Buf[BUF_SIZE];
}
PROTOCOL_BUF_R;




void IO_Init(void);
void Uart1_Init(int Freq,long int baud);

#endif