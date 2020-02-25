/*
 * TMU.c
 *
 * Created: 24/02/2020 01:22:29 م
 *  Author: mo
 */ 

#include "TMU.h"
#include "Interrupts.h"
#define Buffer_Size 3


void Tmu_excute(void);
uint8_t u8_Is_Intialized=0;

uint8_t u8_FUN_index=0;
Buffer_Request Buffer_Array[Buffer_Size];
volatile uint16_t u16Excution_to_be_done=0;

ERROR_STATUS TMU_Init (const TMU_ConfigType * ConfigPtr )
{uint8_t u8_channel_ID=ConfigPtr->u8_Timer_channel;
uint8_t ret=E_OK;
/*************************************************************************/
/*			Intializ the required timer identified by the user			 */
/************************************************************************/
u8_Is_Intialized++;
switch(u8_channel_ID)
{
	case TIMER_CH0:
			G_interrupt_Enable();
			Timer_Init(&Timer_Configuration0);
				break;
	case TIMER_CH2:
		G_interrupt_Enable();
		ret=Timer_Init(&Timer_Configuration2);
			break;
	default:
			ret=E_NOK;
			break;
}	

/*************************************************************************/
/*Intializ the required timer identified by the user using required prescaler  */
/************************************************************************/

switch(ConfigPtr->u8_resolution)
{
	case TIMER_RESOLUTION_1_MS:
	{
		switch(u8_channel_ID)
		{
			case TIMER_CH0 :
				Timer_Start(TIMER_CH0,NUM_OF_TICKS_FOR_1_MS);
					break;
			case TIMER_CH2 :
				Timer_Start(TIMER_CH2,NUM_OF_TICKS_FOR_1_MS);
					break;
			default:
				ret=E_NOK;
					break;
		}					
	break;
	}	
	
	
	
	default:
	ret=E_NOK;
	break;

}


/****************************************************************************/
/*      Deal with Errors  to be returned									*/
/***************************************************************************/
return ret;
}



ERROR_STATUS TMU_DeInit( void )
{
	uint8_t ret=E_OK;
/************************************************************************************************/
/*1    	De_intialize the timer																	*/
/*2		make sure this function is not called unless timer was intialized before by  TMU_INIT	*/
/************************************************************************************************/
	
	
	
return ret;	
}

ERROR_STATUS TMU_Start_Timer(ptr_to_Fun Function_Consumer,uint8_t  u8_Preodicity,uint8_t u8_function_index,uint16_t u16_Time_delay)
{uint8_t ret=E_OK;
	/*
	this enables interrupt and start the timer with the required configurations
	and provide the request to request buffer (ptr_to_func,delay) Dispatcher with the call back function needed(consumer)
	and make sure this function must not be excuted unless Init happened and De_init not happened
	*/
	if(u8_Is_Intialized == 1)
	{
		
		(Buffer_Array[u8_function_index]).Fuction_consumer=Function_Consumer;
		(Buffer_Array[u8_function_index]).preodic=u8_Preodicity;
		(Buffer_Array[u8_function_index]).u16_time_delay=u16_Time_delay;
		(Buffer_Array[u8_function_index]).u8_flag_is_stopped=0;
		
		
	}
	else{
		ret=E_NOK;
	}

	return ret;
}

ERROR_STATUS TMU_Main_Function(void)
{	uint8_t ret=E_OK;
	uint8_t status_flag=0;
	uint8_t preodic_status_flag=0;
	uint16_t u16_Time_needed=0;
	ptr_to_Fun Excuted=((Buffer_Array[u8_FUN_index]).Fuction_consumer);
	
	u16_Time_needed =(Buffer_Array[u8_FUN_index]).u16_time_delay;
	status_flag =(Buffer_Array[u8_FUN_index]).u8_flag_is_stopped;
	preodic_status_flag=(Buffer_Array[u8_FUN_index]).preodic;
if(status_flag==1){ret=E_OK;}
else{
/*	u16Excution_to_be_done=100;  ISR*/
	if(u16_Time_needed == u16Excution_to_be_done )
	{
		Excuted();
	
		u16Excution_to_be_done=0;
	}

	if(preodic_status_flag==0){
		u8_FUN_index++;
	}
}
return ret;


}


ERROR_STATUS TMU_Stop_Timer(uint8_t u8_function_index)
{
	(Buffer_Array[u8_function_index]).u8_flag_is_stopped=1;
}

void Tmu_Fun(void){DIO_Toggle(GPIOC,BIT4);}
void Tmu_For(void){DIO_Toggle(GPIOB,BIT4);}
void Tmu_excute(void){DIO_Toggle(GPIOB,BIT4);}


void timer_interrupt(void){
	u16Excution_to_be_done+=1;
	UDR+=1;
	Timer_Start(TIMER_CH0,14);
//TCNT0=15;
}