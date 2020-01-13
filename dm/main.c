#include <reg51.h> 
#include <intrins.h> 
#include <math.h> 
#include <stdio.h>
#include "uart.h"
#include "AD0832.h"
char data str[]="                "; 

void delay_1ms(unsigned char i)   //最小延时1ms 
{ 
unsigned char j; 
while(i--) 
for(j=0;j<125; j++); 
} 

void Delay(unsigned char j) 
{ 
unsigned char i; 
for(i=0;i<j;i++); //延时，脉冲一位持续的时间 
}
void main(void) 
{ 
unsigned int data_temp=0; 
	Uart_Init();
	
while(1) 
{ 
//void Delay(unsigned char j) 
//{ 
//unsigned char i; 
//for(i=0;i<j;i++); //延时，脉冲一位持续的时间 
//}

unsigned char ADC0832(void);
Send_String("串口可以使用......\r\n");
data_temp=ADC0832(); 

sprintf(str,"The voltage is:"); //the first line    
Send_String(str);
	sprintf(str,"%d",data_temp);	
	Send_String(str);

//xs_int(196*data_temp,1);   //10000*5V/256=196(V)，把采样值放大10000倍后再处理，移动小数点4位。4位有效数字，其实用不到，因为8位采样精度为：0.019V 
delay_1ms(1500);   
} 
}