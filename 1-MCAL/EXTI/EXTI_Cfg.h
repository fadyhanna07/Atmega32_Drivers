/*******************************************/
/*EXTI Driver
Target: ATMEGA32
Author :FADY
 Date:2023-01-27*/
/*******************************************/
#ifndef _EXTI_CFG_H
#define _EXTI_CFG_H

/*options : RISING_EDGE
			FALLING_EDGE
			ANY_CHANGE
			LOW_LEVEL
			DISABLE		*/
#define EXTI0_MODE	FALLING_EDGE

/*options : RISING_EDGE
			FALLING_EDGE
			ANY_CHANGE
			LOW_LEVEL
			DISABLE		*/
#define EXTI1_MODE	DISABLE

/*options : RISING_EDGE
			FALLING_EDGE
			DISABLE
*/
#define EXTI2_MODE	DISABLE

#endif /*EXTI_CFG_H*/
