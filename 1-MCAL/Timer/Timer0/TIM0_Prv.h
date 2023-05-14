/*******************************************/
/*TIM0 Driver
Target: ATMEGA32
Author :FADY
 Date:2023-03-22*/
/*******************************************/

#ifndef _TIM0_PRV_H
#define _TIM0_PRV_H

/* TIMER0 mode of operation clear mask */

#define TMR0_MODE_CLRMask                0xB7

/* TIMER0  CTC mode  clear mask */

#define TMR0_CTCMode_CLRMask             0xCF

/* TIMER0  Clock clear mask */

#define TMR0_Clk_CLRMask                 0xF8

/*****************************************  TIM0 Registers ***************************************************/
#define TCCR0         *((volatile u8 *) 0x53)
#define TCNT0         *((volatile u8 *) 0x52)
#define OCR0          *((volatile u8 *) 0x5C)
#define TIMSK         *((volatile u8 *) 0x59)
#define TIFR          *((volatile u8 *) 0x58)
#endif /*TIM0_PRV_H*/
/*********************************************************************************/
void __vector_11(void) __attribute__((signal));// overflow
void __vector_10(void) __attribute__((signal)); //compare