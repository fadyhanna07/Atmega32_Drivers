/*******************************************/
/*KeyPad.h
Author :FADY
 Date:2023-03-29 */ 
/*******************************************/
#ifndef _KeyPad_INT_H
#define _KeyPad_INT_H
define NUMBER_OF_COLMUNS		4
#define NUMBER_OF_ROWS			4
//An enum data type to have the error that may occur in the Keypad functions 
typedef enum{
	KeyPad_enuOk = 0,
	KeyPad_enuNotOk,
	KeyPad_enuNullPtr,
	KeyPad_enuInvalidPINNumber,
	KeyPad_enuInvalidNumber
}KeyPad_enuErrorStatus;
/*
Keypad init  Function :
A function that sets the DIO pin based on the given mode
Input	: Void 
return	: KeyPad_enuErrorStatus to report error
*/
KeyPad_enuErrorStatus KeyPad_enuInit (void) ; 

/*
Keypad init  Function :
A function that sets the DIO pin based on the given mode
Input	: Void 
return	: KeyPad_enuErrorStatus to report error
*/

KeyPad_enuErrorStatus KeyPad_enuGetKey(u8 * Add_u8KeyPressed);

#endif /*KeyPad_INT_H*/

