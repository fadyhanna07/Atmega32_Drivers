/*******************************************/
/*UART Driver
Target: ATMEGA32
Author :FADY
 Date:2023-04-30 */ 
/*******************************************/
#include "../../4-LIB/STD_TYPES.h"
#include "../../4-LIB/BIT_MATH.h"
#include "UART_Prv.h"
#include "UART_Cfg.h"
#include "UART_int.h"
/******************************* types *****************************************************/
#define Idle    0
#define Busy    1
/*************************************  static variables ********************************************/
static u8  UART_TxStatus = Idle ;

/******************************************************************************************************/
void UART_voidInit(void)
{
u8 TempReg = UCSRC ;
//configure data size 
    #if(UART_datasize == 5)
        CLR_BIT(TempReg,1);
        CLR_BIT(TempReg,2);
        CLR_BIT(UCSRB,2); 
    #elif(UART_datasize == 6)
        SET_BIT(TempReg,1);
        CLR_BIT(TempReg,2);
        CLR_BIT(UCSRB,2); 
    #elif(UART_datasize == 7)
        CLR_BIT(TempReg,1);
        SET_BIT(TempReg,2);
        CLR_BIT(UCSRB,2); 
    #elif(UART_datasize == 8)
        SET_BIT(TempReg,1);
        SET_BIT(TempReg,2);
        CLR_BIT(UCSRB,2); 
    #elif(UART_datasize == 9)
        SET_BIT(TempReg,1);
        SET_BIT(TempReg,2); 
        SET_BIT(UCSRB,2);   
    #endif
// configure parity
    #if(UART_Parity == No_Parity)
        CLR_BIT(TempReg,4);
        CLR_BIT(TempReg,5);
    #elif(UART_Parity == Even_Parity)
        CLR_BIT(TempReg,4);
        SET_BIT(TempReg,5);
    #elif(UART_Parity == Odd_Parity)
        SET_BIT(TempReg,4);
        SET_BIT(TempReg,5);
    #endif
// configure uart mode 
    #if(UART_Mode == Asynchronous)
        CLR_BIT(TempReg,6);
    #elif(UART_Mode == Synchronous)
        SET_BIT(TempReg,6);
    #endif
    SET_BIT(TempReg,7);
    UCSRC = TempReg;
 // control rx and tx interrupt
    #if(UART_RxInterrupt == Enable)
        SET_BIT(UCSRB,7);
        #endif
    #if(UART_TxInterrupt == Enable)
        SET_BIT(UCSRB,5);
        SET_BIT(UCSRB,6); 
        #endif
 // control rx and tx
    #if(UART_RX == Enable)
    SET_BIT(UCSRB,4);
    #endif
    #if(UART_TX == Enable)
    SET_BIT(UCSRB,3);
    #endif
    
}
void UART_voidEnableTXInterrupt(void)
{
    SET_BIT(UCSRB,5);
    SET_BIT(UCSRB,6); 
}
void UART_voidEnableRXInterrupt(void)
{
    SET_BIT(UCSRB,7);
}
void UART_voidDisableTXInterrupt(void)
{
    CLR_BIT(UCSRB,5);
    CLR_BIT(UCSRB,6); 
}
void UART_voidDisableRXInterrupt(void)
{
    CLR_BIT(UCSRB,7);
}
void UART_voidEnableTX(void)
{
    SET_BIT(UCSRB,3);
}
void UART_voidDisableTX(void)
{
    CLR_BIT(UCSRB,3);
}
void UART_voidEnableRX(void)
{
    SET_BIT(UCSRB,4);
}
void UART_voidDisableRX(void)
{
    CLR_BIT(UCSRB,4);
}
void UART_voidSendData(u8 Cpy_u8data)
{
    if(UART_TxStatus == Idle)
    {
        UART_TxStatus = Busy;
        UDR = Cpy_u8data;
    }
    else{}
}
u8 UART_voidGetdata(void)
{
    u8 Result;
  // Wait until Reception Complete
  while((UCSRA&0x80) == 0x00);
  Result = UDR;
  
  /* Clear Flag */
  SET_BIT(UCSRA,7);
  return Result;
}
//USART Data Register Empty handler
void __vector_14(void)
{
    UART_TxStatus = Idle;
}
//USART, Rx Complete handler
void __vector_13(void)
{
   
}
//USART, Tx Complete handler
void __vector_15(void)
{
   
}

