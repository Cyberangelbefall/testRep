
#include <stdio.h>
#include <reg52.h>
//#include"lcd.h"
#include <intrins.h>

sbit Temp_data=P3^6;

unsigned int rec_dat[4];
//unsigned char data_byte;
//unsigned char rec_dat_lcd=[4];
//unsigned char rec_dat_lcd0[6];
//unsigned char rec_dat_lcd1[6];
//unsigned char rec_dat_lcd2[6];
//unsigned char rec_dat_lcd3[6];


void DHT11_delay_us(unsigned char n);
void DHT11_delay_ms(unsigned int z);
void DHT11_start();
unsigned char DHT11_rec_byte();
void DHT11_receive();
void InitUART(void);

void InitUART(void)
{
    TH1 = 0xFD;	 
    TL1 = TH1;
    TMOD |= 0x20;	 
    SCON = 0x50;	 
    ES = 1;			
    TR1 = 1;		
    TI = 1;			
}

void main()
{
    InitUART();	//?????
    EA = 1;	  	//????
    while(1)
    {
			DHT11_delay_ms(150);
			DHT11_receive();

		
//			sprintf(rec_dat_lcd0,"%d",rec_dat[0]);
//			sprintf(rec_dat_lcd1,"%d",rec_dat[1]);
//			sprintf(rec_dat_lcd2,"%d",rec_dat[2]);
//			sprintf(rec_dat_lcd3,"%d",rec_dat[3]);
			DHT11_delay_ms(100);
//        delay_ms(500);
//        printf("Hello World!\n");//??????
			printf("Humi:%d.%d \n",rec_dat[0],rec_dat[1]);
			printf("Temp:%d.%d C\n",rec_dat[2],rec_dat[3]);
			DHT11_delay_ms(2000);
    }
}


void DHT11_start()	
{
	Temp_data=1;
	
	DHT11_delay_us(2);
	
	Temp_data=0;
	
	DHT11_delay_ms(20);
	
	Temp_data=1;
	
	DHT11_delay_us(13);
	

}

unsigned char DHT11_rec_byte()
{
	
	unsigned char i,dat;
	for(i=0;i<8;i++)
	{
			while(!Temp_data);
		  DHT11_delay_us(8);
			dat<<=1;
			if(Temp_data==1)
			{
				dat+=1;
			}
			while(Temp_data);
	}
	return dat;
}

void DHT11_receive()
{
	unsigned int R_H,R_L,T_H,T_L;
	unsigned char RH,RL,TH,TL,revise;
	DHT11_start();
	Temp_data=1;
	if(Temp_data==0)
	{
		while(Temp_data==0);   
        DHT11_delay_us(40);  
        R_H=DHT11_rec_byte();    
        R_L=DHT11_rec_byte();   
        T_H=DHT11_rec_byte();   
        T_L=DHT11_rec_byte();    
        revise=DHT11_rec_byte(); 
        DHT11_delay_us(25);    
        if((R_H+R_L+T_H+T_L)==revise)     
        {
            RH=R_H;
            RL=R_L;
            TH=T_H;
            TL=T_L;
        } 
        rec_dat[0]=RH;
        rec_dat[1]=RL;
        rec_dat[2]=TH;
        rec_dat[3]=TL;
	}
}