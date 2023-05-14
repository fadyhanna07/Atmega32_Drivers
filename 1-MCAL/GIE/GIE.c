/*******************************************/
/*GIE Driver
Target: ATMEGA32
Author :FADY
 Date:2023-01-31 */ 
/*******************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE_Cfg.h"
#include "GIE_Prv.h"
#include "GIE_int.h"

void GIE_voidEnable(void)
{
	SET_BIT(SREG , 7);
}
void GIE_voidDisable(void)
{
	CLR_BIT(SREG , 7);
}