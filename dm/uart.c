#include "uart.h"
void Uart_Init() //���ڳ�ʼ��
{
	SCON=0x50; //8λ�첽ģʽ
	TMOD|=0x20;	//��ʱ��1������ʽ2
	TH1=253;//9600bit/s
	TR1=1;
}

void Send_Byte(u8 dat)	  //���ڷ���һ���ֽ�
{
	SBUF=dat; //�������ͣ�ֻ��Ҫ�ѷ������ݸ�SBUF����Ĵ���
	while(TI==0); //�ȴ�������ɣ���ΪTIΪ1ʱ��ʾ�ڷ���ֹͣλ
	TI=0;
}
 
 void Send_String(u8 *str)	 //����һ���ַ���	*strΪ�ַ�����һ���ַ��ĵ�ַ
 {
    abc:      //���
 	if(*str != 0)
	{
		Send_Byte(*str);
		str++;
		goto abc;	
	}
 }