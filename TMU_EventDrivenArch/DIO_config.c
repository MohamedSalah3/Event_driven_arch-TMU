/*
 * DIO_config.c
 *
 * Created: 17/02/2020 03:53:11 م
 *  Author: mo
 */ 
#include "registers.h"
#include "DIO.h" 
DIO_Cfg_s Dio_configurationA= {
	GPIOA,
	UPPER_NIBBLE,
	OUTPUT
};

DIO_Cfg_s Dio_configurationB= {
	GPIOB,
	UPPER_NIBBLE,
	OUTPUT
};

DIO_Cfg_s Dio_configurationC= {
	GPIOC,
	UPPER_NIBBLE,
	OUTPUT
};

DIO_Cfg_s Dio_configurationD= {
	GPIOD,
	BIT4|BIT3|BIT2,
	OUTPUT
};
