/*******************************************/
/*SSEG Driver
Target: ATMEGA32
Author :FADY
 Date:2023-01-25 */ 
/*******************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "SSEG_int.h"
u8 SSEG_LookUpTable[10]={
	0b00111111,
	0b00000110,
	0b01011011,
	0b01001111,
	0b01100110,
	0b01101101,
	0b01111101,
	0b00000111,
	0b01111111,
	0b01101111,
};
SSEG_tenuErrorStatus_t SSEG_enuDisplayNum(u8 Cpy_enuPortNumber, u8 Cpy_number)
{
		SSEG_tenuErrorStatus_t Loc_u8ErrorStatus = SSEG_enuOK;
		DIO_enuSetPort(Cpy_enuPortNumber,SSEG_LookUpTable[Cpy_number]);
		return Loc_u8ErrorStatus;

}
