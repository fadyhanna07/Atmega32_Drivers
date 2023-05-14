/*******************************************/
/*UART Driver
Target: ATMEGA32
Author :FADY
 Date:2023-04-30*/
/*******************************************/
#ifndef _UART_CFG_H
#define _UART_CFG_H
/***********************/
#define Enable      1
#define Disable     0
/***********************/
// define the data size from 5 to 9 bit 
#define UART_datasize       8

//define the Parity
#define No_Parity       0
#define Even_Parity     2
#define Odd_Parity      3

#define UART_Parity     Even_Parity

//define uart mode 
#define Asynchronous       0
#define Synchronous        1

#define UART_Mode       Asynchronous

// control rx and tx interrupt
#define UART_RxInterrupt    Enable
#define UART_TxInterrupt    Enable

// control Rx and Tx 
#define UART_RX   Enable
#define UART_TX   Enable


#endif /*UART_CFG_H*/
