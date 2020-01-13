#ifndef LCD_H
#define LCD_H

/**********************************
						包含头文件
**********************************/
#include <reg51.h>
#include "dht11.h"

/**********************************
						PIN口定义
**********************************/
#define LCD1602_DB  P0      //data bus 数据总线
sbit LCD1602_RS = P2^5;
sbit LCD1602_RW = P2^6;
sbit LCD1602_EN = P2^7;	 

/**********************************
						函数声明
**********************************/
void LCD_Delay10ms(uint c);
void Lcd1602_Write_Cmd(uchar cmd);     //写命令
void Lcd1602_Write_Data(uchar dat);   //写数据
void LcdSetCursor(uchar x,uchar y);  //坐标显示
void LcdShowStr(uchar x,uchar y,uchar *str);     //显示字符串
void InitLcd1602();              //1602初始化函数
					  
#endif