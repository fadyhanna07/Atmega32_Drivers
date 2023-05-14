#include "DIO_Prv.h"
#include "BIT_MATH.h"
#include "Std_Types.h"
/****************************************/
/*           DIO Interface File         */
/****************************************/
#ifndef DIO_H
#define DIO_H

typedef enum
{
	DIO_Low=0,
	DIO_High
}DIO_tenuPinStatus;

typedef enum
{
	DIO_Input=0,
	DIO_Output
}DIO_tenuPinDir;


typedef enum
{
	DIO_PullDown=0, //this option for input direction only
	DIO_PullUp,			//this option for input direction only
	DIO_OutputLow,  //this option for output direction only
	DIO_OutputHigh	//this option for output direction only
}DIO_tenuPinMode;

typedef enum
{
	DIO_PortA=0,
	DIO_PortB,
	DIO_PortC,
	DIO_PortD
}DIO_tenuPortNumber;

typedef enum
{
	DIO_PIN0=0,/*PORTA*/ /*PIN0*/
	DIO_PIN1,  /*PORTA*/ /*PIN1*/
	DIO_PIN2,  /*PORTA*/ /*PIN2*/
	DIO_PIN3,  /*PORTA*/ /*PIN3*/
	DIO_PIN4,  /*PORTA*/ /*PIN4*/
	DIO_PIN5,  /*PORTA*/ /*PIN5*/
	DIO_PIN6,  /*PORTA*/ /*PIN6*/
	DIO_PIN7,  /*PORTA*/ /*PIN7*/
	DIO_PIN8,  /*PORTB*/ /*PIN0*/
	DIO_PIN9,  /*PORTB*/ /*PIN1*/
	DIO_PIN10, /*PORTB*/ /*PIN2*/
	DIO_PIN11, /*PORTB*/ /*PIN3*/
	DIO_PIN12, /*PORTB*/ /*PIN4*/
	DIO_PIN13, /*PORTB*/ /*PIN5*/
	DIO_PIN14, /*PORTB*/ /*PIN6*/
	DIO_PIN15, /*PORTB*/ /*PIN7*/
	DIO_PIN16, /*PORTC*/ /*PIN0*/
	DIO_PIN17, /*PORTC*/ /*PIN1*/
	DIO_PIN18, /*PORTC*/ /*PIN2*/
	DIO_PIN19, /*PORTC*/ /*PIN3*/
	DIO_PIN20, /*PORTC*/ /*PIN4*/
	DIO_PIN21, /*PORTC*/ /*PIN5*/
	DIO_PIN22, /*PORTC*/ /*PIN6*/
	DIO_PIN23, /*PORTC*/ /*PIN7*/
	DIO_PIN24, /*PORTD*/ /*PIN0*/
	DIO_PIN25, /*PORTD*/ /*PIN1*/
	DIO_PIN26, /*PORTD*/ /*PIN2*/
	DIO_PIN27, /*PORTD*/ /*PIN3*/
	DIO_PIN28, /*PORTD*/ /*PIN4*/
	DIO_PIN29, /*PORTD*/ /*PIN5*/
	DIO_PIN30, /*PORTD*/ /*PIN6*/
	DIO_PIN31  /*PORTD*/ /*PIN7*/
}DIO_tenuPinNumber;

typedef struct
{
	DIO_tenuPinDir   PinDir;
	DIO_tenuPinMode  PinMode;
}DIO_tstrPinConfig;

typedef enum
{
		DIO_enuOk=0,
		DIO_enuNotOk,
		DIO_enuNullPtr
}DIO_tenuErrorStatus;



/****************************************/
/*Function: DIO_enuInit                 */
/*Input: void                           */
/*Output: status for the initialization */
/****************************************/
DIO_tenuErrorStatus DIO_enuInit(void);


/*****************************************/
/*Function: DIO_enuChangeDir             */
/*Input: Pin Number                      */
/*Output: change the direction of the pin*/
/*****************************************/
DIO_tenuErrorStatus DIO_enuChangeDir(DIO_tenuPinNumber Cpy_u8PinNumber);


/*****************************************/
/*Function: DIO_enuSetPin                */
/*Input: Pin Number                      */
/*Output: Set the Pin value              */
/*****************************************/
DIO_tenuErrorStatus DIO_enuSetPin(DIO_tenuPinNumber Cpy_u8PinNumber);


/*****************************************/
/*Function: DIO_enuClearPin              */
/*Input: Pin Number                      */
/*Output: Clear the Pin value            */
/*****************************************/
DIO_tenuErrorStatus DIO_enuClearPin(DIO_tenuPinNumber Cpy_u8PinNumber);


/*****************************************/
/*Function: DIO_enuToggelPin             */
/*Input: Pin Number                      */
/*Output: Toggel the Pin value           */
/*****************************************/
DIO_tenuErrorStatus DIO_enuToggelPin(DIO_tenuPinNumber Cpy_u8PinNumber);


/*****************************************/
/*Function: DIO_Get_Pin_Val              */
/*Input: Pin Number                      */
/*Output: Get the Pin value              */
/*****************************************/
DIO_tenuErrorStatus DIO_enuGetPinVal(DIO_tenuPinNumber Cpy_u8PinNumber , u8* Add_pu8PinValue);


#endif