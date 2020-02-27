/*
 * DIO_config.h
 *
 * Created: 17/02/2020 03:55:53 م
 *  Author: mo
 */ 


#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_



#include "std_types.h"
#include "registers.h"
/************************************************************************/
/*						PINS/BITS defines                               */
/************************************************************************/

#define PIN0	0x01
#define PIN1	0x02
#define PIN2	0x04
#define PIN3	0x08
#define PIN4	0x10
#define PIN5	0x20
#define PIN6	0x40
#define PIN7	0x80

#define BIT0	0x01
#define BIT1	0x02
#define BIT2	0x04
#define BIT3	0x08
#define BIT4	0x10
#define BIT5	0x20
#define BIT6	0x40
#define BIT7	0x80

#define UPPER_NIBBLE	0xF0
#define LOWER_NIBBLE	0x0F
#define FULL_PORT		0xFF

#define GPIOA			0
#define GPIOB			1
#define GPIOC			2
#define GPIOD			3

#define OUTPUT			0xFF
#define INPUT			0x00
/************************************************************************/
/*						Typedefs defines                               	*/
/************************************************************************/
typedef struct DIO_Cfg_s
{
	uint8_t GPIO;
	uint8_t pins;
	uint8_t dir;
}DIO_Cfg_s;

extern DIO_Cfg_s Dio_configurationA;
extern DIO_Cfg_s Dio_configurationD;
extern DIO_Cfg_s Dio_configurationB;
extern DIO_Cfg_s Dio_configurationC;
#define E_OK 0
#define E_NOK 1
typedef uint8_t ERROR_STATUS;

#endif /* DIO_CONFIG_H_ */