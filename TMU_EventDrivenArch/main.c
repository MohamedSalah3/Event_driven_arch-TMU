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
	TMU_Init(&TMU_Configuration);
	TMU_Start_Timer(Tmu_excute,1,0,1);
	
	while(1)
    {
		TMU_Main_Function();
	}

}