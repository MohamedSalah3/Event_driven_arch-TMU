/*
 * DIO.c
 *
 * Created: 17/02/2020 02:20:28 م
 *  Author: mo
 */
#include "Error_Report.h"
#include "DIO.h"
#include "DIO_config.h"
/*
*Input: DIO_Cfg_s -> to get PORT name, pins to be initiated and the required direction
*Output: No output
*In/Out:
*Description: This function can set the direction of a full port, a nibble
* 			  or even one pin.
*/

ERROR_STATUS DIO_init (DIO_Cfg_s *DIO_info)
{	
	uint8_t RET=0;
	if (DIO_info== NULL)
	{
		RET=NULL_PTR+DIO_MODULE;
		
	}else{
		switch(DIO_info->dir)
			{	
		case INPUT:
		     	switch(DIO_info ->GPIO)
		 		{
					case GPIOA:
					PORTA_DIR &=(~(DIO_info->pins))	;
					break;
					case GPIOB:
					PORTB_DIR &=(~(DIO_info->pins))	;
					break;
					case GPIOC:
					PORTC_DIR &=(~(DIO_info->pins))	;
					break;
					case GPIOD:
					PORTD_DIR &=(~(DIO_info->pins))	;
					break;
					RET=E_OK;
				}
				RET=E_OK;
				break;

		case OUTPUT:
			  switch(DIO_info ->GPIO)
			  {
				  case GPIOA:
				  PORTA_DIR |=(DIO_info->pins)	;
				  break;
				  case GPIOB:
				  PORTB_DIR |=(DIO_info->pins)	;
				  break;
				  case GPIOC:
				  PORTC_DIR |=(DIO_info->pins)	;
				  break;
				  case GPIOD:
				  PORTD_DIR |=(DIO_info->pins)	;
				  break;
				  RET=E_OK;
			  }
			  RET=E_OK;
			  break;

			default:
			RET=E_NOK;
	}
	
}	
return RET;
}

ERROR_STATUS DIO_Write (uint8_t GPIO, uint8_t pins, uint8_t value)
{uint8_t Ret=0;
switch(value){
case LOW:
{
switch (GPIO)
{	case GPIOA:
	PORTA_DATA &= ~(pins);   // 0b01111111
Ret=E_OK;
	break;
	case GPIOB:
	PORTB_DATA &= ~(pins);
Ret=E_OK;
	break;
	case GPIOC:
	PORTC_DATA &= ~(pins);
Ret=E_OK;
	break;
	case GPIOD:
	PORTD_DATA &= ~(pins);
	Ret=E_OK;
	break;
	default:
	Ret=E_NOK;
	break;
	}
Ret=E_OK;
break;
}
case HIGH:{
switch (GPIO)
{	case GPIOA:
	PORTA_DATA |=(pins);
Ret=E_OK;
	break;
	case GPIOB:
	PORTB_DATA |=(pins);
Ret=E_OK;
	break;
	case GPIOC:
	PORTC_DATA |=(pins);
Ret=E_OK;
	break;
	case GPIOD:
	PORTD_DATA |=(pins);
Ret=E_OK;
	break;
	default:
	Ret=E_NOK;
	break;
}
Ret=E_OK;
break;
}
default:
Ret=E_NOK;
break;
}
return Ret;
}


ERROR_STATUS DIO_Read (uint8_t GPIO,uint8_t pins, uint8_t *data)
{

switch (GPIO)
{	case GPIOA:
	*data=(PORTA_PIN & pins);
	break;
	case GPIOB:
	*data=(PORTB_PIN & pins);
	break;
	case GPIOC:
	*data=(PORTC_PIN & pins);
	break;
	case GPIOD:
	*data=(PORTD_PIN & pins);
	break;
}
if(*data > 0)
{
	*data = 1;
}


}
ERROR_STATUS DIO_Toggle (uint8_t GPIO, uint8_t pins)
{
uint8_t ret=0;
	switch (GPIO)
	{	case GPIOA:
		PORTA_DATA ^=(pins);
		ret=E_OK;
		break;
		case GPIOB:
		PORTB_DATA ^=(pins);
ret=E_OK;
		break;
		case GPIOC:
		PORTC_DATA ^=(pins);
ret=E_OK;
		break;
		case GPIOD:
		PORTD_DATA ^=(pins);
ret=E_OK;
		break;
		default:
		ret=E_NOK;
		break;
	}

return ret;
}
