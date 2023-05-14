/*******************************************/
/*EXTI Driver
Target: ATMEGA32
Author :FADY
 Date:2023-01-27 */ 
/*******************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_Prv.h"
#include "EXTI_Cfg.h"
#include "EXTI_int.h"

void (*EXTI0_CallBack)(void)=NULL;
void (*EXTI1_CallBack)(void)=NULL;
void (*EXTI2_CallBack)(void)=NULL;
void EXTI_voidInit(void){
///////////////// EXTI0 Initilization/////////////////////////////////////
	#if		EXTI0_MODE == RISING_EDGE
			SET_BIT(MCUCR,0);
			SET_BIT(MCUCR,1);
	#elif   EXTI0_MODE == FALLING_EDGE
			CLR_BIT(MCUCR,0);
			SET_BIT(MCUCR,1);
	#elif   EXTI0_MODE == ANY_CHANGE
			SET_BIT(MCUCR,0);
			CLR_BIT(MCUCR,1);
	#elif   EXTI0_MODE == LOW_LEVEL
			CLR_BIT(MCUCR,0);
			CLR_BIT(MCUCR,1);
	#elif   EXTI0_MODE == DISABLE
			CLR_BIT(GICR,6);
	#else
			#error("Wrong choice of Sense mode!")
	#endif
	
	///////////////// EXTI1 Initilization/////////////////////////////////////
	#if		EXTI1_MODE == RISING_EDGE
			SET_BIT(MCUCR,2);
			SET_BIT(MCUCR,3);
	#elif   EXTI1_MODE == FALLING_EDGE
			CLR_BIT(MCUCR,2);
			SET_BIT(MCUCR,3);
	#elif   EXTI1_MODE == ANY_CHANGE
			SET_BIT(MCUCR,2);
			CLR_BIT(MCUCR,3);
	#elif   EXTI1_MODE == LOW_LEVEL
			CLR_BIT(MCUCR,2);
			CLR_BIT(MCUCR,3);
	#elif   EXTI1_MODE == DISABLE
			CLR_BIT(GICR,7);
	#else
			#error("Wrong choice of Sense mode!")
	#endif
	
	///////////////// EXTI2 Initilization/////////////////////////////////////
	#if		EXTI1_MODE == RISING_EDGE
			SET_BIT(MCUCSR,6);
	#elif   EXTI1_MODE == FALLING_EDGE
			CLR_BIT(MCUCSR,6);
	#elif   EXTI1_MODE == DISABLE
			CLR_BIT(GICR,5);
	#else
			#error("Wrong choice of Sense mode!")
	#endif
	
	////////// disable all external interrupts///////////////////////////////////
	CLR_BIT(GICR,6);
	CLR_BIT(GICR,7);
	CLR_BIT(GICR,5);
}

EXTI_tenuErrorStatus EXTI_enuEnable(u8 Cpy_u8EXTINum)
{
	EXTI_tenuErrorStatus Loc_enuErrorStatus = EXTI_enOK;
	if(Cpy_u8EXTNum == 0){SET_BIT(GICR,6);}
	else if(Cpy_u8EXTINum == 1){SET_BIT(GICR,7);}
	else if(Cpy_u8EXTINum == 2){SET_BIT(GICR,5);}
	else  Loc_enuErrorStatus = DIO_enNotOK;
	return Loc_enuErrorStatus;
}

EXTI_tenuErrorStatus EXTI_enuDisable(u8 Cpy_u8EXTINum)
{
	EXTI_tenuErrorStatus Loc_enuErrorStatus = EXTI_enOK;
	if(Cpy_u8EXTNum == 0){CLR_BIT(GICR,6);}
	else if(Cpy_u8EXTINum == 1){CLR_BIT(GICR,7);}
	else if(Cpy_u8EXTINum == 2){CLR_BIT(GICR,5);}
	else  Loc_enuErrorStatus = DIO_enNotOK;
	return Loc_enuErrorStatus;
}
void EXTI0_SetCallBack(void (*pf)(void)){
	EXTI0_CallBack = (void (*)(void))pf;
	
}
void EXTI1_SetCallBack(void (*pf)(void)){
	EXTI1_CallBack = (void (*)(void))pf;
	
}
void EXTI2_SetCallBack(void (*pf)(void)){
	EXTI2_CallBack = (void (*)(void))pf;
	
}
void __vector_1(void){
	EXTI0_CallBack();
}
void __vector_2(void){
	EXTI1_CallBack();
}
void __vector_3(void){
	EXTI2_CallBack();
}
