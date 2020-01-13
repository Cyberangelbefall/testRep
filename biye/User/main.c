#include <reg51.h> 
#include <intrins.h> 
#include <math.h> 
#include <stdio.h>
#include "ad0832.h"
#include "delay.h"
#include "dht11.h"
#include "uart.h"
#include "lcd.h"

uint data_temp = 0; 
uint rec_dat[4];
uchar rec_dat_lcd0[6];
uchar rec_dat_lcd1[6];
uchar rec_dat_lcd2[6];
uchar rec_dat_lcd3[6];
uchar vol_dat0[6];
uchar vol_dat1[6];
uint vol[1];
void main()
{
    InitUART();	
    EA = 1;	
	  InitLcd1602();
	  LcdShowStr(0,0,"H:");
	  LcdShowStr(8,0,"T:");	
    LcdShowStr(0,1,"Vol:");	
	while(1)
    {
			DHT11_delay_ms(150);
			DHT11_receive();
			DHT11_delay_ms(100);
			data_temp = ADC0832();
			if(data_temp < 10)
				data_temp = 13;
//			vol[0] = (int)data_temp;
//			printf("Vol 0:%d V\n",vol[0]);
//			printf("Vol 1:%d V\n",vol[1]);
//			vol[1] = data_temp%vol[0];
			sprintf(rec_dat_lcd0,"%d",rec_dat[0]);
		  sprintf(rec_dat_lcd1,"%d",rec_dat[1]);
		  sprintf(rec_dat_lcd2,"%d",rec_dat[2]);
		  sprintf(rec_dat_lcd3,"%d",rec_dat[3]);
//			sprintf(vol_dat0,"%d",vol[0]);
//		  sprintf(vol_dat1,"%d",vol[1]);
	  	//湿度
		  LcdShowStr(2,0,rec_dat_lcd0);
		  LcdShowStr(4,0,".");
		  LcdShowStr(5,0,rec_dat_lcd1);
		  LcdShowStr(6,0,"%");
		
  		//温度
	  	LcdShowStr(10,0,rec_dat_lcd2);
		  LcdShowStr(12,0,".");
		  LcdShowStr(13,0,rec_dat_lcd3);
//		LcdShowStr(14,0,0xdf);
  		LcdShowStr(15,0,"C");
			
			//气体浓度
//			LcdShowStr(4,1,vol_dat0);
//			LcdShowStr(6,1,".");
//			LcdShowStr(7,1,vol_dat1);
//		  LcdShowStr(8,1,"V");
			printf("Humi:%d.%d %\n",rec_dat[0],rec_dat[1]);
			printf("Temp:%d.%d ℃\n",rec_dat[2],rec_dat[3]);
			printf("Voltage:%d.%d V\n",data_temp);
			DHT11_delay_ms(1000);
    }
}