/*******************************************/
/*DIO Driver
Target: ATMEGA32
Author :FADY
 Date:2023-01-18*/
/*******************************************/

#ifndef _DIO_INT_H
#define _DIO_INT_H
#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

typedef enum{
    DIO_enOK = 0,
    DIO_enNotOK,
    DIO_enNull,
 
}DIO_tenuErrorStatus;

typedef enum{
    DIO_enuLow = 0,
    DIO_enuHigh,
}DIO_tenuPinValue;

/*enum to define all pins*/

/*enum to define all pins*/
typedef enum{
    DIO_enuPin0,
    DIO_enuPin1,
    DIO_enuPin2,
    DIO_enuPin3,
    DIO_enuPin4,
    DIO_enuPin5,
    DIO_enuPin6,
    DIO_enuPin7,
    DIO_enuPin8,
    DIO_enuPin9,
    DIO_enuPin10,
    DIO_enuPin11,
    DIO_enuPin12,
    DIO_enuPin13,
    DIO_enuPin14,
    DIO_enuPin15,
    DIO_enuPin16,
    DIO_enuPin17,
    DIO_enuPin18,
    DIO_enuPin19,
    DIO_enuPin20,
    DIO_enuPin21,
    DIO_enuPin22,
    DIO_enuPin23,
    DIO_enuPin24,
    DIO_enuPin25,
    DIO_enuPin26,
    DIO_enuPin27,
    DIO_enuPin28,
    DIO_enuPin29,
    DIO_enuPin30,
    DIO_enuPin31,
    DIO_u8NumberOfPins
}DIO_tenuPins;

/*   DIO init Function                            */

DIO_tenuErrorStatus DIO_enuInit(void);


/*   DIO set pin Function                            */

DIO_tenuErrorStatus DIO_enuSetPin(DIO_tenuPins Cpy_u8PinNumber);


/*   DIO clear pin Function                            */

DIO_tenuErrorStatus DIO_enuClrPin(DIO_tenuPins Cpy_u8PinNumber);


/*   DIO get pin Function                          */

DIO_tenuErrorStatus DIO_enuGetPinValue(DIO_tenuPins Cpy_u8PinNumber, u8* Add_pu8PinValue);

DIO_tenuErrorStatus DIO_enuWritePinVAlue(u8 Cpy_u8Port,u8 Cpy_u8Pin,DIO_tenuPinValue Cpy_u8Value);
DIO_tenuErrorStatus DIO_enuSetPort(u8 Cpy_u8PortNumber,u8 Cpy_u8PortValue);
#endif /*DIO_INT_H*/
