#include "uart.h"
#include "dht11.h"

void InitUART(void)
{
    TH1 = 0xF3;	 //12   F3  11.0592 FD
    TL1 = TH1;
    TMOD |= 0x20;	 
    SCON = 0x50;	 
    ES = 1;			
    TR1 = 1;		
    TI = 1;			
}