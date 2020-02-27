/*
 * TMU.h
 *
 * Created: 24/02/2020 01:22:47 م
 *  Author: mo
 */ 


#ifndef TMU_H_
#define TMU_H_
#include "TMU_Config.h"
#include "Timer.h"
#include "DIO.h"
#include "Error_Report.h"
typedef void (*ptr_to_Fun) (void);


ERROR_STATUS TMU_Init (const TMU_ConfigType * ConfigPtr );
/*************************************************************************/
/*			Intializ the required timer identified by the user			 */
/************************************************************************/
/*************************************************************************/
/*Intializ the required timer identified by the user using required prescaler  */
/************************************************************************/

/****************************************************************************/
/*      Deal with Errors  to be returned									*/
/***************************************************************************/


ERROR_STATUS TMU_DeInit( void );

/************************************************************************************************/
/*1    	De_intialize the timer																	*/
/*2		make sure this function is not called unless timer was intialized before by  TMU_INIT	*/
/************************************************************************************************/

void TMU_Stop_Timer(uint8_t u8_function_index);
/***************************************************/
/*     Set the stop flag							*/
/***************************************************/
	
ERROR_STATUS TMU_Start_Timer(ptr_to_Fun Function_Consumer,uint8_t  u8_Preodicity,uint8_t u8_function_index,uint16_t u16_Time_delay);
/*
	this enables interrupt and start the timer with the required configurations
	and provide the request to request buffer (ptr_to_func,delay) Dispatcher with the call back function needed(consumer)
	and make sure this function must not be excuted unless Init happened and De_init not happened
	*/

/*********************************************************************/
/* The manger*********************************************************/
/* Access the Request buffer and take all values created by start fun*/
/*Take a decision upon the interrupt flag*****************************/
/*********************************************************************/
ERROR_STATUS TMU_Main_Function(void);
/***************************************************************/
/*CONSUMERS(Toggle leds)*/
/***************************************************************/
void Tmu_Fun(void);
void Tmu_For(void);
void Tmu_excute(void);

typedef struct start_status
{	uint8_t u8Started;
	uint8_t function_Index;
}start_status;

typedef struct Buffer_Request
{	/*function that the main function should excute*/
	ptr_to_Fun Fuction_consumer;
	/*	when TMU_STop called this falg == 0 */
	uint8_t u8_flag_is_stopped;
	/*Time needed that the dispatcher should make a delay upon it*/
	uint16_t u16_time_delay;
	/*if one shot ==0 if preodic ==1 */
	uint8_t preodic;
	/*Counter to make the prober condition for every delay*/
	uint16_t u16_Counter;
}Buffer_Request;


#endif /* TMU_H_ */