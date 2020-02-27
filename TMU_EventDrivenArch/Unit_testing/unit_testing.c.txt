#include <stdio.h>
#include <stdlib.h>
#define Buffer_Size 2
#define E_OK        0
#define E_NOK        1

typedef unsigned char uint8_t;
typedef uint8_t ERROR_STATUS;
typedef unsigned short int uint16_t;
typedef void (*ptr_to_Fun) (void);
typedef struct Buffer_Request
{	/*function that the main function should excute*/
	ptr_to_Fun Fuction_consumer;
	/*	when TMU_STop called this falg == 1 */
	uint8_t u8_flag_is_stopped;
	/*Time needed that the dispatcher should make a delay upon it*/
	uint16_t u16_time_delay;  
	/*if one shot ==0 if preodic ==1 */
	uint8_t preodic;
	
}Buffer_Request;
void Tmu_excute(void);
ERROR_STATUS TMU_Stop_Timer(uint8_t u8_function_index);
ERROR_STATUS TMU_Start_Timer(ptr_to_Fun Function_Consumer,uint8_t  u8_Preodicity,uint8_t u8_function_index,uint16_t u16_Time_delay);
uint8_t u8_Is_Intialized=0;
ERROR_STATUS TMU_Main_Function(void);
void Tmu_Fun(void);
void Tmu_For(void);
uint8_t u8_FUN_index=0;
Buffer_Request Buffer_Array[Buffer_Size];
volatile uint16_t u16Excution_to_be_done=0;
int main()
{
	
		u8_Is_Intialized=1;
		
		TMU_Start_Timer(Tmu_excute,0,0,100);
			printf("%d ",(Buffer_Array[u8_FUN_index]).preodic);

		TMU_Start_Timer(Tmu_Fun,0,1,100);
	printf("%d ",(Buffer_Array[u8_FUN_index]).preodic);

		TMU_Start_Timer(Tmu_For,1,2,100);
	printf("%d ",(Buffer_Array[u8_FUN_index]).preodic);

		TMU_Stop_Timer(2);	
		TMU_Main_Function();
			printf("%d ",(Buffer_Array[u8_FUN_index]).preodic);
		TMU_Main_Function();
	
		TMU_Main_Function();
 
	return 0;
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
					
	
	}
else{
		ret=E_NOK;
	}

	return ret;
}

ERROR_STATUS TMU_Main_Function(void)
{
	uint8_t ret=E_OK;
	uint8_t status_flag=0;
	uint8_t preodic_status_flag=0;
	uint16_t u16_Time_needed=0;
	ptr_to_Fun Excuted;
	/***********************************************************************/
	/*					LOOP upon Buffer Request						*/
	/*********************************************************************/
for (u8_FUN_index=0;u8_FUN_index<Buffer_Size;u8_FUN_index++)
{
	Excuted=((Buffer_Array[u8_FUN_index]).Fuction_consumer);
	u16_Time_needed =(Buffer_Array[u8_FUN_index]).u16_time_delay;
	status_flag =(Buffer_Array[u8_FUN_index]).u8_flag_is_stopped;
	preodic_status_flag=(Buffer_Array[u8_FUN_index]).preodic;

/****************************************************************/
/* check if the event is stopped ... do nothing*/
		if(status_flag==1){ret=E_OK;}
		
	else{
	/***************************************************************/
	/*if the timer started .. and condition met excute the consumer*/
	/***************************************************************/
		if (u8Excution_to_be_done==1)
			{
	/********************************************/
	/*Count up when flag is set**/
	((Buffer_Array[u8_FUN_index]).u16_Counter)++;
	/*make the flag down*/
	u8Excution_to_be_done=0;
			}

/*	u16Excution_to_be_done=100;  ISR*/
	if(((Buffer_Array[u8_FUN_index]).u16_time_delay) == ((Buffer_Array[u8_FUN_index]).u16_Counter) )
	{
		Excuted();
	/******************************************/
	/*Make it zero so that it will work the next time at the required time (to stop it of ovf)*/
		(Buffer_Array[u8_FUN_index]).u16_Counter=0;
		
	}		
		
	/*********************************************************/
	/* if not preodic increment the index after excuteing	*/
	/*********************************************************/

	if(preodic_status_flag==0){
		/*to make it see the next event in the next time
		Also Status_flag =1 so that this function will be stopped
		*/
		status_flag=1;	
		u8_FUN_index++;
			}

		}		
	}
	
return ret;

}


ERROR_STATUS TMU_Stop_Timer(uint8_t u8_function_index)
{
	(Buffer_Array[u8_function_index]).u8_flag_is_stopped=1;
}
void Tmu_Fun(void){printf("funny\n");}
void Tmu_For(void){printf("WOW\n");}
void Tmu_excute(void){printf("hello\n");}
