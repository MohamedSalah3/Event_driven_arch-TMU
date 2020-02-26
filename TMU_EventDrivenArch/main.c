﻿/*
 * TMU_EventDrivenArch.c
 *
 * Created: 24/02/2020 01:20:36 م
 *  Author: mo
 */ 


#include "Timer.h"
#include "TMU.h"
int main(void)
{	
	DIO_init(&Dio_configurationB);
	DIO_init(&Dio_configurationC);
	DIO_init(&Dio_configurationA);
	TMU_Init(&TMU_Configuration);
	PORTC_DATA=0xff;
	PORTB_DATA=0xff;
	TMU_Start_Timer(Tmu_excute,1,0,1);
	TMU_Start_Timer(Tmu_Fun,1,1,1);
	//TMU_Start_Timer(Tmu_For,1,2,10);
	
	while(1)
    {
		TMU_Main_Function();
	}

}