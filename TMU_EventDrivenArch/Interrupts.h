/*
 * Interrupts.h
 *
 * Created: 21/01/2020 01:18:31 م
 *  Author: mo
 */


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_
//#include "pushButton.h"
#include "registers.h"
//#include "timers.h"
//#include "gpio.h"
//#include "uart.h"
//

extern volatile uint8_t u8Excution_to_be_done;
extern void timer_interrupt(void);
typedef void (*ptr_to_Fun)(void);
extern ptr_to_Fun INT0_external_interrupt;
extern ptr_to_Fun INT1_external_interrupt;
extern ptr_to_Fun INT2_external_interrupt;
extern ptr_to_Fun TIMER2COMP;
extern ptr_to_Fun TIMER2OVF;
extern ptr_to_Fun TIMER1CAPT;
extern ptr_to_Fun TIMER1COMPA;
extern ptr_to_Fun TIMER1COMPB;
extern ptr_to_Fun TIMER1OVF;
extern ptr_to_Fun TIMER0COMP;
extern ptr_to_Fun TIMER0OVF_INT;
extern ptr_to_Fun SPI_STC;
extern ptr_to_Fun USART_RXC;
extern ptr_to_Fun USART_UDRE;
extern ptr_to_Fun USART_TXC;
extern ptr_to_Fun ADC_INT;
extern ptr_to_Fun EE_RDY;
extern ptr_to_Fun ANA_COMP;
extern ptr_to_Fun TWI_I2C;
extern ptr_to_Fun SPM_RDY;
extern void G_interrupt_Enable(void);
extern void G_interrupt_Disable(void);
extern void EX_interrupt_enable2(void);
extern volatile uint8_t u8_ovf_counter;
#define INT2 5
#define INT0    6
#define INT1    7

#endif /* INTERRUPTS_H_ */