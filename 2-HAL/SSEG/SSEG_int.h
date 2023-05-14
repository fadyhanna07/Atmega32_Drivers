/*******************************************/
/*SSEG Driver
Target: ATMEGA32
Author :FADY
 Date:2023-01-25*/
/*******************************************/
#ifndef _SSEG_INT_H
#define _SSEG_INT_H

typedef enum
{
	SSEG_enuOK=0,
	SSEG_enuNotOK,
}SSEG_tenuErrorStatus_t;

SSEG_tenuErrorStatus_t SSEG_enuDisplayNum(u8 Cpy_enuPortNumber, u8 Cpy_number);

#endif /*SSEG_INT_H*/
