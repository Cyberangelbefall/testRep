#ifndef LCD_H
#define LCD_H

/**********************************
						����ͷ�ļ�
**********************************/
#include <reg51.h>
#include "dht11.h"

/**********************************
						PIN�ڶ���
**********************************/
#define LCD1602_DB  P0      //data bus ��������
sbit LCD1602_RS = P2^5;
sbit LCD1602_RW = P2^6;
sbit LCD1602_EN = P2^7;	 

/**********************************
						��������
**********************************/
void LCD_Delay10ms(uint c);
void Lcd1602_Write_Cmd(uchar cmd);     //д����
void Lcd1602_Write_Data(uchar dat);   //д����
void LcdSetCursor(uchar x,uchar y);  //������ʾ
void LcdShowStr(uchar x,uchar y,uchar *str);     //��ʾ�ַ���
void InitLcd1602();              //1602��ʼ������
					  
#endif