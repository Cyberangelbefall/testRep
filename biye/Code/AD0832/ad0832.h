#ifndef AD0832_H
#define AD0832_H

/**********************************
					包含头文件
**********************************/
#include <reg51.h>
#include "delay.h"
#include "dht11.h"
/*********接口定义****************/ 
sbit ADC_CS =P2^0; 
sbit ADC_CLK=P2^1; 
sbit ADC_DO =P2^2; 
sbit ADC_DI =P2^3; 
extern data_c; //重复定义 data_c，在ad0832.c中使用
/**********************************
					函数声明
**********************************/
uchar ADC0832(void);
void delay_us(uchar i);				  
#endif