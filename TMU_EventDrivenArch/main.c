/*
 * TMU_EventDrivenArch.c
 *
 * Created: 24/02/2020 01:20:36 م
 *  Author: mo
 */ 


#include "Timer.h"
#include "TMU.h"
int main(void)
{	PORTB_DIR=0xff;
	PORTA_DIR=0xff;
	PORTC_DIR=0xff;
	PORTD_DIR=0xff;
	PORTB_DATA=0xff;
	PORTA_DATA=0xff;
	PORTC_DATA=0xff;
	PORTD_DATA=0xff;
	
	TMU_Init(&TMU_Configuration);
	TMU_Start_Timer(Tmu_excute,1,0,1);
	//TMU_Start_Timer(Tmu_Fun,1,1,100);
	//TMU_Start_Timer(Tmu_For,1,2,100);
	
	while(1)
    {
		TMU_Main_Function();
	}

}
