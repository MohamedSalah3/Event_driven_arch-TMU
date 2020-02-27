/*
 * Timers_Config.c
 *
 * Created: 14/02/2020 04:58:23 ص
 *  Author: mo
 */
 /*INCLUDES**/
#include "TMU.h"

Timer_cfg_s Timer_Configuration2 =
{
TIMER_CH2,
TIMER_MODE,
TIMER_INTERRUPT_MODE,
TIMER_PRESCALER_1024,/*it will not start untill we call timer start function*/
};
Timer_cfg_s Timer_Configuration0  =
{ 
	TIMER_CH0,
	TIMER_MODE,
	TIMER_INTERRUPT_MODE,
	TIMER_PRESCALER_64,/*it will not start untill we call timer start function*/
};
Timer_cfg_s Timer_Deinit_Configuration0  =
{
	TIMER_CH0,
	TIMER_MODE,
	TIMER_INTERRUPT_MODE,
	TIMER_NO_CLOCK,/*it will not start untill we call timer start function*/
};