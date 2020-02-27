/*
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
	DIO_init(&Dio_configurationD);
	TMU_Init(&TMU_Configuration);

	TMU_Start_Timer(Tmu_excute,1,0,3);
	TMU_Start_Timer(Tmu_Fun,1,1,3);
	TMU_Start_Timer(Tmu_For,1,2,3);
	
	while(1)
    {
		TMU_Main_Function();
	}

}