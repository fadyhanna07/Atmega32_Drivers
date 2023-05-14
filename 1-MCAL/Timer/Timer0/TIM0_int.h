/*******************************************/
/*TIM0 Driver
Target: ATMEGA32
Author :FADY
 Date:2023-03-22*/
/*******************************************/
#ifndef _TIM0_INT_H
#define _TIM0_INT_H

/*********************************  types  *******************************************************************************/
/***************************************************************************************                                               
* Description :   An Enum Datatype used to return Error status 
*****************************************************************************************/
typedef enum {
    TIM0_enuOK = 0,
    TIM0_enuNOTOK ,
    TIM0_enuInvalidMode,
    TIM0_enuInvalidCTCMode,
    TIM0_enuInvalidClk,
    TIM0_enuNULLPOINTER 
}TIM0_tenuErrorStatus;

typedef struct 
{
    u8 Timer0_Mode;
    u8 Timer0_CTCMode;
    u8 Timer0_Clk;  
}TMR0_Config_t;

/*********************************  Functions prototype  *******************************************************************************/
/***************************************************************************************                                               
* Description :  init Precompile Timer0    configure TIM0 mode and ctc mode                
* Input  : none
* Return:  error statues
*****************************************************************************************/
TIM0_tenuErrorStatus TIM0_enuinitPreCompile(void);
/***************************************************************************************                                               
* Description :  init Postcompile Timer0    configure TIM0 mode and ctc mode                
* Input  : object of TMR0_Config_t
* Return:  error statues
*****************************************************************************************/
TIM0_tenuErrorStatus TMR0_enuinitPostCompile(TMR0_Config_t * AddTMR0_Config);

/***************************************************************************************                                               
* Description :  Start Timer0                    
* Input  : none
* Return:  error statues
*****************************************************************************************/
TIM0_tenuErrorStatus TIM0_enuStart(void);

/***************************************************************************************                                               
* Description :  set period time in ms                     
* Input  : period time
* Return:  error statues
*****************************************************************************************/
TIM0_tenuErrorStatus TIM0_SetPeriod_ms(u8 Cpy_Period_ms);

/***************************************************************************************                                               
* Description :  Set duty cycle for Timer0   (for PWM mode)                
* Input  : Duty cycle 
* Return:  error statues
*****************************************************************************************/
TIM0_tenuErrorStatus TIM0_SetDutyCycle(u8 Cpy_DutyCycle);

/***************************************************************************************                                               
* Description :  Enable/Disable overflow interrupt.                  
* Input  : none
* Return:  none
*****************************************************************************************/
void TIM0_voidEnableOverflowInterrupt(void);
void TIM0_voidDisableOverflowInterrupt(void);

/***************************************************************************************                                               
* Description :  Enable/Disable compare match interrupt.                 
* Input  : none
* Return:  none
*****************************************************************************************/
void TIM0_voidEnableOutputCompareMatchInterrupt(void);
void TIM0_voidDisableOutputCompareMatchInterrupt(void);

/***************************************************************************************                                               
* Description :  Set overflow/compare-match callback function.                 
* Input  : none
* Return:  none
*****************************************************************************************/
void TIM0_voidSetOverflowCallback(void (*Cpy_fCallback)(void));
void TIM0_voidSetOutputCompareMatchCallback(void (*Cpy_fCallback)(void));

#endif /*TIM0_INT_H*/
