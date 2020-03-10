#include <stdint.h>
#include "TIVA_LCD.h"
#include "TM4C123GH6PM.h"
#include "TIVA_TIMER.h"

int main(){
	SYSCTL->RCGCGPIO=0x20;
	while((SYSCTL->PRGPIO & 0x20)==0);
	GPIOF->LOCK = 0x4C4F434B;
	GPIOF->CR =0x0E;
	GPIOF->AMSEL=0;
	GPIOF->AFSEL=0;
	GPIOF->PCTL=0;
	GPIOF->DIR=0x0E;
	GPIOF->DEN=0x0E;
	
	Start_Timer();
	
	Setup();
	Clear();
	Send_String_Pos("Hello World",1,1);
	
	int x=0;
	
	//Setup();
	
	while(1){
		Send_String_Pos("Hello World",1,1);
		x++;
		if(x==8)x=1;
		GPIOF->DATA=(x<<1);
		Delay_ms(1000);
	}
}

