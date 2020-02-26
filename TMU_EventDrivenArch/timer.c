/*

 * Timers.c
 *
 * Created: 14/02/2020 04:57:53 ص
 *  Author: mo
 */
 /*INCLUDES*/
#include "Timer.h"
#include "Timer_Config.h"
#include "Error_Report.h"
/************************************************************************/
/*		         TIMER FUNCTIONS' IMPLEMENTATION		        */
/************************************************************************/
 /**
 * Input: Pointer to a structure contains the information needed to initialize the timer.
 * Output:
 * In/Out:
 * Return: The error status of the function.
 * Description: Initiates the module.
 *
 */
 static uint8_t prescaler_value=0;
 
ERROR_STATUS Timer_Init(Timer_cfg_s* Timer_cfg)
{uint8_t Ret=E_OK;
prescaler_value=Timer_cfg->Timer_Prescaler;
if (Timer_cfg==NULL)
{
	Ret=TIMER_MODULE+NULL_PTR;
}
switch (Timer_cfg->Timer_CH_NO) {
/*************************************************************************/
/*                             TIMER 0                                   */
/*************************************************************************/
    case TIMER_CH0:
        {
  TCCR0 |=T0_NORMAL_MODE;
  
          switch (Timer_cfg->Timer_Mode) {
          case TIMER_MODE:
              {
                switch (Timer_cfg->Timer_Polling_Or_Interrupt)
				{
                    case TIMER_POLLING_MODE:
                        {/*Disable interrupts for T0 without effecting any other timer*/
                         /*without Disabling Global interrupt*/
                        TIMSK &=T0_INTERRUPT_DISABLE;
                            break;
                         }
                                  case TIMER_INTERRUPT_MODE:
                                  { /*Enable Global INTERRUPT
                                    Enable Timer0 interrupt
                                    */
                                    G_interrupt_Enable();
                                    TIMSK |= T0_INTERRUPT_NORMAL;
                                    break;
                                  }
                                  default :
                                  Ret+=E_NOK;
								  break;
                          }

                          break;
                          }
/*************************************************************************/
/*                             TIMER 0 As a COUNTER_RISING_MODE          */
/*************************************************************************/

                          case COUNTER_RISING_MODE:
                            {
                                  TCCR0 |=T0_COUNTER_RISING_MODE_CONFIG;
                                    switch (Timer_cfg->Timer_Polling_Or_Interrupt) {
                                        case TIMER_POLLING_MODE:
                                          {
            /*Disable interrupts for T0 without effecting any other timer*/
              /*without Disabling Global interrupt*/
                                            TIMSK &=T0_INTERRUPT_DISABLE;
                                            break;

                                          case TIMER_INTERRUPT_MODE:
                                           /*Enable Global INTERRUPT
                                              Enable Timer0 interrupt
                                              */
                                              G_interrupt_Enable();
                                              TIMSK |= T0_INTERRUPT_NORMAL;
                                              break;

                                          default :
                                          Ret+=E_NOK;
										  break;
										}
                                    break;
                                    }
/*************************************************************************/
/*                             TIMER 0 As a COUNTER_FALLING_MODE         */
/*************************************************************************/

                                    case COUNTER_FALLING_MODE:
                                    {
                                        TCCR0 |=T0_COUNTER_FALLING_MODE_CONFIG;
                                          switch (Timer_cfg->Timer_Polling_Or_Interrupt) {
                                              case TIMER_POLLING_MODE:
                                                {

            /*Disable interrupts for T0 without effecting any other timer*/
                /*without Disabling Global interrupt*/
                                                  TIMSK &=T0_INTERRUPT_DISABLE;

                                                  break;
                                                }
                                                case TIMER_INTERRUPT_MODE:
                                                  {
                                                    /*Enable Global INTERRUPT
                                                    Enable Timer0 interrupt
                                                    */
                                                    G_interrupt_Enable();
                                                    TIMSK |= T0_INTERRUPT_NORMAL;

                                                    break;
                                                  }
                                                  default:
                                                  Ret+=E_NOK;
												  break;
                                                }
                                      break;
                                      }
                                      default:
                                      Ret+=E_NOK;
									  break;
                                    }
                                    Ret+=E_OK;
									break;
                                  }
                                }
/*************************************************************************/
/*                             TIMER 1                                   */
/*************************************************************************/

    case TIMER_CH1:
        {

    switch (Timer_cfg->Timer_Mode)
    {
      case TIMER_MODE:
      {
        TCCR1 = T1_NORMAL_MODE_CONFIG;
              switch (Timer_cfg->Timer_Polling_Or_Interrupt) {
              case TIMER_POLLING_MODE:
                {
                  /*Disable interrupts for T1 without effecting any other timer*/
                   /*without Disabling Global interrupt*/
                  TIMSK &=T1_INTERRUPT_DISABLE;

                break;
              }
              case TIMER_INTERRUPT_MODE:
              {
                G_interrupt_Enable();
                TIMSK |=T1_INTERRUPT_NORMAL;
                /*Enable Global INTERRUPT
                Enable Timer0 interrupt
                */
                break;
              }
              default :
              Ret+=E_NOK;
			  break;
            }
        break;
      }
      case COUNTER_RISING_MODE:
      {
            TCCR1|=T1_COUNTER_RISING_MODE_CONFIG;

            switch (Timer_cfg->Timer_Polling_Or_Interrupt) {
              case TIMER_POLLING_MODE:
              {
                /*Disable interrupts for T1 without effecting any other timer*/
                 /*without Disabling Global interrupt*/
                TIMSK &=T1_INTERRUPT_DISABLE;

                break;
              }
              case TIMER_INTERRUPT_MODE:
              {
                G_interrupt_Enable();
                TIMSK |=T1_INTERRUPT_NORMAL;
                /*Enable Global INTERRUPT
                Enable Timer0 interrupt
                */
                break;
              }
              default:
              Ret+=E_NOK;
			  break;
            }
        break;
      }
      case COUNTER_FALLING_MODE:
      {
            TCCR1|=T1_COUNTER_FALLING_MODE_CONFIG;
            switch (Timer_cfg->Timer_Polling_Or_Interrupt) {
              case TIMER_POLLING_MODE:
              {
                /*Disable interrupts for T1 without effecting any other timer*/
                 /*without Disabling Global interrupt*/
                TIMSK &=T1_INTERRUPT_DISABLE;
                break;
              }
              case TIMER_INTERRUPT_MODE:
              {
                G_interrupt_Enable();
                TIMSK |=T1_INTERRUPT_NORMAL;
                /*Enable Global INTERRUPT
                Enable Timer0 interrupt
                */

                break;
              }
              default :
              Ret+=E_NOK;
			  break;
            }
      break;
      }
      default :
      Ret+=E_NOK;
    break;
	}

  Ret+=E_OK;
  break;
  }
  /*************************************************************************/
  /*                             TIMER 2                                   */
  /*************************************************************************/

  case TIMER_CH2:
  {
TCCR2 |=T2_NORMAL_MODE_CONFIG;
    switch (Timer_cfg->Timer_Mode) {
      case TIMER_MODE:
      {
            switch (Timer_cfg->Timer_Polling_Or_Interrupt) {
              case TIMER_POLLING_MODE:
              {
                  TIMSK &= T2_INTERRUPT_DISABLE;
                break;
              }
              case TIMER_INTERRUPT_MODE:
              {
                G_interrupt_Enable();
                  TIMSK|=T2_INTERRUPT_NORMAL;

                break;
              }
              default :
              Ret+=E_NOK;
			  break;
            }
        break;
      }
      case COUNTER_RISING_MODE:
      {
          ASSR |=0x08;
            switch (Timer_cfg->Timer_Polling_Or_Interrupt)
            {
              case TIMER_POLLING_MODE:
              {
                TIMSK &= T2_INTERRUPT_DISABLE;

                break;
              }
              case TIMER_INTERRUPT_MODE:
              {
                G_interrupt_Enable();
                  TIMSK|=T2_INTERRUPT_NORMAL;
                break;
              }
              case COUNTER_FALLING_MODE:
              {
                  ASSR |=0x08;
                    switch (Timer_cfg->Timer_Polling_Or_Interrupt)
                    {
                      case TIMER_POLLING_MODE:
                      {
                        TIMSK &= T2_INTERRUPT_DISABLE;

                        break;
                      }
                      case TIMER_INTERRUPT_MODE:
                      {
                        G_interrupt_Enable();
                          TIMSK|=T2_INTERRUPT_NORMAL;
                        break;
                      }

              default :
              Ret+=E_NOK;
			  break;
            }
        break;
            }
            }
  default:
  Ret+=E_NOK;
  break;
}



}
 }

}
return Ret;
}
/*
 * Input:
 * Timer_CH_NO: The channel number of the timer needed to be started.
 * Timer_Count: The start value of the timer.
 * Output:
 * In/Out:
 * Return: The error status of the function.
 * Description: This function strats the needed timer.
 *
 */
ERROR_STATUS Timer_Start(uint8_t Timer_CH_NO, uint16_t Timer_Count){
uint8_t Ret;
switch (Timer_CH_NO) {
case TIMER_CH0:{
/***********************************************************************************************************************/
switch(prescaler_value){
case TIMER_PRESCALER_NO :{
if(Timer_Count < MAX0){
TCCR0 |=TIMER_PRESCALER_NO;
TCNT0 =	MAX0 - Timer_Count;
}else
{
Ret=E_NOK;
}
break;
}
case TIMER_PRESCALER_8 :{
if(Timer_Count < MAX0){
TCCR0 |=TIMER0_PRESCALER_8_CONFIG;
TCNT0 =MAX0 - Timer_Count;
}else
{
Ret=E_NOK;
}
break;
}
case TIMER_PRESCALER_64 :{
if(Timer_Count < MAX0){
TCCR0 |=TIMER0_PRESCALER_64_CONFIG;
TCNT0 = MAX0 - Timer_Count;
}else
{
Ret=E_NOK;
}
break;
}
case TIMER_PRESCALER_256 :{
if(Timer_Count < MAX0){
TCCR0 |=TIMER0_PRESCALER_256_CONFIG;
TCNT0 =MAX0 - Timer_Count;
}else
{
Ret=E_NOK;
}
break;
}
case TIMER_PRESCALER_1024 :{
if(Timer_Count < MAX0){
TCCR0 |=TIMER0_PRESCALER_1024_CONFIG;
TCNT0 =MAX0 - Timer_Count;
}else
{
Ret=E_NOK;
}
break;

}
default :
Ret=E_NOK;
break;
}

Ret=E_OK;
break;
}
case TIMER_CH1:{

  switch(prescaler_value){
  case TIMER_PRESCALER_NO :{
  if(Timer_Count < MAX1){
  TCCR1 |=TIMER_PRESCALER_NO;
  TCNT1 =MAX1 - Timer_Count;
  }else
  {
  Ret=E_NOK;
  }
  break;
  }
  case TIMER_PRESCALER_8 :{
  if(Timer_Count < MAX1){
  TCCR1 |=TIMER1_PRESCALER_8_CONFIG;
  TCNT1 =MAX1 - Timer_Count;
  }else
  {
  Ret= E_NOK;
  }
  break;
  }
  case TIMER_PRESCALER_64 :{
  if(Timer_Count < MAX1){
  TCCR1 |=TIMER1_PRESCALER_64_CONFIG;
  TCNT1 =MAX1 - Timer_Count;
  }else
  {
  Ret= E_NOK;
  }
  break;
  }
  case TIMER_PRESCALER_256 :{
  if(Timer_Count < MAX1){
  TCCR1 |=TIMER1_PRESCALER_256_CONFIG;
  TCNT1 =MAX1 - Timer_Count;
  }else
  {
  Ret= E_NOK;

  }
  break;
  }
  case TIMER_PRESCALER_1024 :{
  if(Timer_Count < MAX1){
  TCCR1 |=TIMER1_PRESCALER_1024_CONFIG;
  TCNT1 =MAX1 - Timer_Count;
  }else
  {
  Ret= E_NOK;

  }
  break;

  }
  default :
  Ret= E_NOK;
  break;
  }


  Ret= E_OK;
	break;
}
case TIMER_CH2:
	{
  
		switch(prescaler_value){
   
		  case TIMER_PRESCALER_NO :
			{
    
				if(Timer_Count < MAX0){
     
			      TCCR2 |= TIMER_PRESCALER_NO;
		      
				  TCNT2 = MAX2 - Timer_Count;
                            }
                            else
                             {
                               Ret=E_NOK;
							 }
			break;
			}

case TIMER_PRESCALER_8 :
  {
          if(Timer_Count < MAX0)
            {
           TCCR2 |=TIMER_PRESCALER_8;
           TCNT2 =MAX2 - Timer_Count;
            }
            else
            {
             Ret=E_NOK;
		    }
       break;
  }
  case TIMER_PRESCALER_32:
  {
    if(Timer_Count < MAX1)
         {
         TCCR2 |=TIMER_PRESCALER_32;
         TCNT2 =MAX2 - Timer_Count;
        }
        else
        {
    Ret=E_NOK;
  }

    break;
  }
  case TIMER_PRESCALER_64 :
  {
       if(Timer_Count < MAX2)
       {
       TCCR2 |=TIMER_PRESCALER_64;
       TCNT2 =MAX2 - Timer_Count;
      }
      else
      {
  Ret=E_NOK;
  }
  break;
  }
  case TIMER_PRESCALER_128 :{
  if(Timer_Count < MAX2){
  TCCR2 |= TIMER_PRESCALER_128;
  TCNT2 =MAX2 - Timer_Count;
  }else
  {
  Ret= E_NOK;
    }
  break;
  }
  case TIMER_PRESCALER_256 :{
  if(Timer_Count < MAX2){
  TCCR2 |= TIMER_PRESCALER_256;
  TCNT2 =MAX2 - Timer_Count;
  }else
  {
  Ret= E_NOK;

  }
  break;
  }
  case TIMER_PRESCALER_1024 :{
  if(Timer_Count < MAX2){
  TCCR2 |=TIMER_PRESCALER_1024;
  TCNT2 =MAX2 - Timer_Count;
  }else
  {
 Ret= E_NOK;

  }
  break;
  }
  default :
  Ret= E_NOK;

  }
Ret=E_OK;
break;
}
default:
Ret= E_NOK;
break;
}
return Ret;

}
/**
 * Input:
 *Timer_CH_NO: The channel number of the timer needed to be stopped.
 * Output:
 * In/Out:
 * Return: The error status of the function.
 * Description: This function stops the needed timer.
 *
 */
ERROR_STATUS Timer_Stop(uint8_t Timer_CH_NO)
{uint8_t Ret;
switch (Timer_CH_NO) {
  case TIMER_CH0:
  {
		TCCR0 &=0xF8;
		Ret=E_OK;
		break;
  }
  case TIMER_CH1:
  {
	     TCCR1 &=0xFFF8;
		 Ret=E_OK;
		 break;
  }
  case TIMER_CH2:
    {
		 TCCR2 &= 0xF8;
		 Ret=E_OK;
		 break;
    }
  default :
  Ret=E_NOK;
  break;
}

return Ret;

}
/**
 * Input:
 * 	Timer_CH_NO: The channel number of the timer needed to get its status.
 * Output:
 * 	Data: A variable of type bool returns if the flag of the timer is raised or not.
 * In/Out:
 * Return: The error status of the function.
 * Description: This function is used to return if the flag of the timer is raised or not.
 *
 */
ERROR_STATUS Timer_GetStatus(uint8_t Timer_CH_NO,uint8_t* Data)
{
  switch (Timer_CH_NO) {
    case TIMER_CH0:
    {
  *Data =((TIFR>>TOV0)&1);
    return E_OK;
    }
    case TIMER_CH1:
    {
    *Data =((TIFR>>TOV1)&1);
    return E_OK;
    }
     case TIMER_CH2:
      {
  *Data =((TIFR>>TOV2)&1);
    return E_OK;
      }
    default :
    return E_NOK;
  }
}
/**
 * Input:
 * 	Timer_CH_NO: The channel number of the timer needed to get its value.
 * Output:
 * 	Data: This is the output variable of the function which holds the status of the timer if ovf reached data = 1 else data = 0.
 * In/Out:
 * Return: The error status of the function.
 * Description: This function is used to return the value of the timer.
 *
 */
ERROR_STATUS Timer_GetValue(uint8_t Timer_CH_NO, uint16_t* Data)
{
	uint8_t Ret=0;
	switch (Timer_CH_NO) {
		case TIMER_CH0:
		{
			*Data =TCNT0;
			Ret= E_OK;
			break;
		}
		case TIMER_CH1:
		{
			*Data =TCNT1;
			Ret= E_OK;
			break;
		}
		case TIMER_CH2:
		{
			*Data =TCNT2;
			Ret = E_OK;
			break;
		}
		default :
		Ret= E_NOK;
		break;
	}
return Ret;

}
