/*******************************************/
/*EXTI Driver
Target: ATMEGA32
Author :FADY
 Date:2023-01-27*/
/*******************************************/

#ifndef _EXTI_PRV_H
#define _EXTI_PRV_H

#define RISING_EDGE		0
#define FALLING_EDGE	1
#define ANY_CHANGE		2
#define LOW_LEVEL		3
#define DISABLE			4
#define MCUCR			*((volatile u8*) 0x55)
#define MCUCSR			*((volatile u8*) 0x54)
#define GICR			*((volatile * u8 ) 0x5B)
#define GIFR			*((volatile * u8 ) 0x5A)



void __vector_1(void) __attribute__((signal));
void __vector_2(void) __attribute__((signal));
void __vector_3(void) __attribute__((signal));


#endif /*EXTI_PRV_H*/
