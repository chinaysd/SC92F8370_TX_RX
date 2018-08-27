#ifndef _Function_Init_H_
#define _Function_Init_H_

#include "SC92F837x_C.H"
#include "intrins.H"
#define uchar unsigned char
#define uint unsigned int
#define BUF_SIZE     7
#define STOP_DATA    0X0D0A
#define get_hight(x)   (((x)>>8)&0xff)
#define get_low(x)       ((x)&0xff)

#define IapROM  0x00	  //0x00：选择ROM区操作  0x02：选择EEPROM区操作
#define IapEPPROM  0x02	  //0x00：选择ROM区操作  0x02：选择EEPROM区操作

typedef struct
{
	 unsigned char MessageID;
	 unsigned char Add;
	 unsigned char Data1;
	 unsigned char Data2;
	 unsigned char Checksum;
	 unsigned char Stop1;
	 unsigned char Stop2;
}
DATA_FORMAT_t;

typedef union
{
	 DATA_FORMAT_t Data_Format;
	 unsigned char Buf[BUF_SIZE];
}
PROTOCOL_BUF_t;

typedef enum
{
	add1 = 1,
	add2 
}
ADDR_DATA;

typedef enum
{
	id1 = 1,
	id2
}
ID_DATA;



void IO_Init(void);
void Uart1_Init(int Freq,long int baud);
#endif