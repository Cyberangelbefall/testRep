#ifndef DHT11_H_
#define DHT11_H_

#include <reg51.h>
//---重定义关键词---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif
/**********************************
						PIN口定义
**********************************/
sbit Temp_data=P1^1;  //使用P1^1作为DHT11的数据总线传输端口
extern uint rec_dat[4]; //重复定义rec_dat[4]数组，在dht11.c文件中使用
/**********************************
						函数声明
**********************************/
void DHT11_start();
uchar DHT11_rec_byte();
void DHT11_receive();
#endif