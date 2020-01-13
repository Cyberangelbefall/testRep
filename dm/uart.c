#include "uart.h"
void Uart_Init() //串口初始化
{
	SCON=0x50; //8位异步模式
	TMOD|=0x20;	//定时器1工作方式2
	TH1=253;//9600bit/s
	TR1=1;
}

void Send_Byte(u8 dat)	  //串口发送一个字节
{
	SBUF=dat; //启动发送，只需要把发送内容给SBUF这个寄存器
	while(TI==0); //等待发送完成，因为TI为1时表示在发送停止位
	TI=0;
}
 
 void Send_String(u8 *str)	 //发送一个字符串	*str为字符串第一个字符的地址
 {
    abc:      //标号
 	if(*str != 0)
	{
		Send_Byte(*str);
		str++;
		goto abc;	
	}
 }