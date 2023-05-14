/*******************************************/
/*UART Driver
Target: ATMEGA32
Author :FADY
 Date:2023-04-30*/
/*******************************************/
#ifndef _UART_INT_H
#define _UART_INT_H
/******************************************* Prototypes *********************************************************/
void UART_voidInit(void);
void UART_voidEnableTXInterrupt(void);
void UART_voidEnableRXInterrupt(void);
void UART_voidDisableTXInterrupt(void);
void UART_voidDisableRXInterrupt(void);
void UART_voidEnableTX(void);
void UART_voidDisableTX(void);
void UART_voidEnableRX(void);
void UART_voidDisableRX(void);
void UART_voidSendData(u8 Cpy_u8data);
u8 UART_voidGetdata(void);

#endif /*UART_INT_H*/
