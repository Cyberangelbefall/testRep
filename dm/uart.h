#ifndef UART_H

#define UART_H

#include <reg51.h> 
#define u16 unsigned int
#define u8 unsigned char
	
void Uart_Init(void);
void Send_Byte(u8 dat);
void Send_String(u8 *str);

#endif