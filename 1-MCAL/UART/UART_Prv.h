/*******************************************/
/*UART Driver
Target: ATMEGA32
Author :FADY
 Date:2023-04-30*/
/*******************************************/

#ifndef _UART_PRV_H
#define _UART_PRV_H

/***************************************************
*                                                  *
* Description :  MEMEROY MAPPING I/O  Peripheral   *
*                                                  *
****************************************************/
#define UDR              *((volatile u8 *)0x2C)  
#define UCSRA            *((volatile u8 *)0x2B)
#define UCSRB            *((volatile u8 *)0x2A)
#define UCSRC            *((volatile u8 *)0x40)
#define UBRRL            *((volatile u8 *)0x29)
#define UBRRH            *((volatile u8 *)0x40)
/*************************************************/

void __vector_16(void) __attribute__((signal));
#endif /*UART_PRV_H*/
