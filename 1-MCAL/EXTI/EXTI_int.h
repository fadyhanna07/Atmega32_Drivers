/*******************************************/
/*EXTI Driver
Target: ATMEGA32
Author :FADY
 Date:2023-01-27*/
/*******************************************/
#ifndef _EXTI_INT_H
#define _EXTI_INT_H

typedef enum{
    DIO_enOK = 0,
    DIO_enNotOK,
    DIO_enNull,
 
}EXTI_tenuErrorStatus;
void EXTI_voidInit(void);
EXTI_tenuErrorStatus EXTI_enuEnable(u8 Cpy_u8EXTINum);
EXTI_tenuErrorStatus EXTI_enuDisable(u8 Cpy_u8EXTINum);
void EXTI0_SetCallBack(void (*pf)(void));
void EXTI1_SetCallBack(void (*pf)(void));
void EXTI2_SetCallBack(void (*pf)(void));
#endif /*EXTI_INT_H*/
