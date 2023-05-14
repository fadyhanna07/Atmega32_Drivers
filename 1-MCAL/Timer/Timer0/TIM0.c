/*******************************************/
/*TIM0 Driver
Target: ATMEGA32
Author :FADY
 Date:2023-03-22 */ 
/*******************************************/
#include "../../../4-LIB/STD_TYPES.h"
#include "../../../4-LIB/BIT_MATH.h"
#include "TIM0_Prv.h"
#include "TIM0_Cfg.h"
#include "TIM0_int.h"
/******************************************  Types and Masks  ************************************************************/

/******************************************  Global Variables  ************************************************************/
static u8 global_clkPrescaler;
static u8 global_Tim0Mode;
static u8 global_Tim0CTCMode;
static u16 OverFlows_no =0;
static void(*OVcallback)void = NULL;
static void(*Comparecallback)void = NULL; 
/******************************************  Functions Implementation  ************************************************************/
TIM0_tenuErrorStatus TIM0_enuinitPreCompile(void)
{
    TIM0_tenuErrorStatus Loc_enuErrorStatus = TIM0_enuOK;
    u8 Loc_u8Temp = TCCR0;
    Loc_u8Temp &= TMR0_MODE_CLRMask & TMR0_CTCMode_CLRMask;
    #if(TIM0_Mode != TMR0_MODE_NORMAL && TIM0_Mode != TMR0_MODE_CTC && TIM0_Mode != TMR0_MODE_FAST_PWM && TIM0_Mode != TMR0_MODE_PhaseCorrect_PWM)
    {
        Loc_enuErrorStatus = TIM0_enuInvalidMode;
    }
    #elif(TIM0_CTCMode != TMR0_CTCMode_Disconnec_OC0 && TIM0_CTCMode != TMR0_CTCMode_Toggle_OC0 && TIM0_CTCMode != TMR0_CTCMode_Clear_OC0 && TIM0_CTCMode != TMR0_CTCMode_Set_OC0)
    {
        Loc_enuErrorStatus = TIM0_enuInvalidCTCMode;
    }
    #else 
    {
        global_Tim0Mode = TIM0_Mode;
        Loc_u8Temp |= TIM0_Mode | TIM0_CTCMode;
        TCCR0 = Loc_u8Temp;
    }
    #endif
    global_clkPrescaler = TIM0_Clk;
    global_Tim0CTCMode = TIM0_CTCMode;
    return Loc_enuErrorStatus;
    
}
/*********************************************************************************************************/
TIM0_tenuErrorStatus TMR0_enuinitPostCompile(TMR0_Config_t * AddTMR0_Config)
{
    TIM0_tenuErrorStatus Loc_enuErrorStatus = TIM0_enuOK;
    u8 Loc_u8Temp = TCCR0;
    Loc_u8Temp &= TMR0_MODE_CLRMask & TMR0_CTCMode_CLRMask;
    if(AddTMR0_Config->Timer0_Mode != TMR0_MODE_NORMAL && AddTMR0_Config->Timer0_Mode != TMR0_MODE_CTC && AddTMR0_Config->Timer0_Mode != TMR0_MODE_FAST_PWM && AddTMR0_Config->Timer0_Mode!= TMR0_MODE_PhaseCorrect_PWM)
    {
        Loc_enuErrorStatus = TIM0_enuInvalidMode;
    }
    else if(AddTMR0_Config->Timer0_CTCMode != TMR0_CTCMode_Disconnect_OC0 && AddTMR0_Config->Timer0_CTCMode != TMR0_CTCMode_Toggle_OC0 && AddTMR0_Config->Timer0_CTCMode != TMR0_CTCMode_Clear_OC0 && AddTMR0_Config->Timer0_CTCMode != TMR0_CTCMode_Set_OC0)
    {
        Loc_enuErrorStatus = TIM0_enuInvalidCTCMode;
    }
    else
    {
        global_Tim0Mode = AddTMR0_Config->Timer0_Mode ;
        global_Tim0CTCMode = AddTMR0_Config->Timer0_CTCMode;
        Loc_u8Temp |= AddTMR0_Config->Timer0_Mode | AddTMR0_Config->Timer0_CTCMode;
        TCCR0 = Loc_u8Temp;
    }
     global_clkPrescaler = AddTMR0_Config->Timer0_Clk;
     return Loc_enuErrorStatus;

}
/*********************************************************************************************************/
TIM0_tenuErrorStatus TIM0_enuStart(void)
{
    TIM0_tenuErrorStatus Loc_enuErrorStatus = TIM0_enuOK;
    u8 Loc_u8Temp = TCCR0;
    #if(global_clkPrescaler != 0 && global_clkPrescaler != 1 && global_clkPrescaler != 2 && global_clkPrescaler != 3 && global_clkPrescaler != 4 && global_clkPrescaler != 5 && global_clkPrescaler != 6 && global_clkPrescaler != 7)
    {
        Loc_enuErrorStatus = TIM0_enuInvalidClk;
    }
     #else 
    {
       Loc_u8Temp &= TMR0_Clk_CLRMask;
       Loc_u8Temp |= TIM0_Clk;
       TCCR0 = Loc_u8Temp;
    }
    #endif
     return Loc_enuErrorStatus;
}
/*********************************************************************************************************/
TIM0_tenuErrorStatus TIM0_SetPeriod_ms(u8 Cpy_Period_ms)
{												
	
    TIM0_tenuErrorStatus Loc_enuErrorStatus = TIM0_enuOK;
    f32 Loc_Ticktime ;
    f32 Loc_OVtime ;
    u16 loc_prescaler = 1;
    u16 preload;
    switch (global_clkPrescaler)
    {
    case TMR0_Clk_NO_Prescaler:
        loc_prescaler = 1;
        break;
    case TMR0_Clk_Prescaler_8:
        loc_prescaler = 8;
        break;
    case TMR0_Clk_Prescaler_64:
        loc_prescaler = 64;
        break;   
    case TMR0_Clk_Prescaler_256:
        loc_prescaler = 256;
        break;
    case TMR0_Clk_Prescaler_1024:
        loc_prescaler = 1024;
        break;    
    }
    Loc_Ticktime = (loc_prescaler * 1000) / System_Clk ; 
    if(global_Tim0Mode == TMR0_MODE_NORMAL )
    {
        Loc_OVtime = 256 * Loc_Ticktime;
        f32 overflow = Cpy_Period_ms / Loc_OVtime;
        OverFlows_no = overflow;
        preload = 256 * (1- (overflow - Loc_OVnum));
        TCNT0 = preload;
        if(preload != 256)
        {
            OverFlows_no++;
        }
        else {}
    }
    else if(global_Tim0Mode == TMR0_MODE_CTC)
    {
        OCR0 = Compare_val;
        Loc_OVtime = Compare_val * Loc_Ticktime;
        OverFlows_no = Cpy_Period_ms / Loc_OVtime;
    }
    return Loc_enuErrorStatus;
}
/*************************************************************************/
TIM0_tenuErrorStatus TIM0_SetDutyCycle(u8 Cpy_DutyCycle)
{
    TIM0_tenuErrorStatus Loc_enuErrorStatus = TIM0_enuOK;
    u8 compare ;
    if(global_Tim0Mode == TMR0_MODE_FAST_PWM || global_Tim0Mode == TMR0_MODE_PhaseCorrect_PWM )
    {
        if(global_Tim0CTCMode == TMR0_CTCMode_Clear_OC0)
        compare = (250 * Cpy_DutyCycle)/100;
        else if (global_Tim0CTCMode == TMR0_CTCMode_Set_OC0)
        {
        compare = 255 - ( (250 * Cpy_DutyCycle)/100 );
        }
        OCR0 =compare;
    }
    else 
    {
        Loc_enuErrorStatus = TIM0_enuInvalidMode;
    }
    return Loc_enuErrorStatus;
}
/*************************************************************************/
void TIM0_voidEnableOverflowInterrupt(void)
{
    SET_BIT(TIMSK,0);
}
/*************************************************************************/
void TIM0_voidDisableOverflowInterrupt(void)
{
    CLR_BIT(TIMSK,0);
}
/*************************************************************************/
void TIM0_voidEnableOutputCompareMatchInterrupt(void)
{
    SET_BIT(TIMSK,1);
}
/*************************************************************************/
void TIM0_voidDisableOutputCompareMatchInterrupt(void)
{
    CLR_BIT(TIMSK,1);
}
/*************************************************************************/

void TIM0_voidSetOverflowCallback(void (*Cpy_fCallback)(void))
{
    OVcallback = Cpy_fCallback;
}
/*************************************************************************/
void TIM0_voidSetOutputCompareMatchCallback(void (*Cpy_fCallback)(void))
{
    Comparecallback = Cpy_fCallback;
}
/*************************************************************************/
void __vector_11(void)
{
    static u8 Counter1 = 0;
    if(OVcallback != NULL)
      Counter1++;
    {
        if(Counter1 == OverFlows_no)
        {
            Counter1 = 0;
            OVcallback();
        }
    }
    
}
/*************************************************************************/
void __vector_10(void)
{
     static u8 Counter2 = 0;
    if(Comparecallback != NULL)
      Counter2++;
    {
        if(Counter2 == OverFlows_no)
        {
            Counter1 = 0;
             Comparecallback();
        }
    }
   
}