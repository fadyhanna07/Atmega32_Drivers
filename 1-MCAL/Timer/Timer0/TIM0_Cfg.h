/*******************************************/
/*TIM0 Driver
Target: ATMEGA32
Author :FADY
 Date:2023-03-22*/
/*******************************************/
#ifndef _TIM0_CFG_H
#define _TIM0_CFG_H
/******************************************************************************************/
                /*    Configure TIMER0 mode operation  */
/* TIMER0 mode of operation options : */ 

#define TMR0_MODE_NORMAL                 0x0 
#define TMR0_MODE_CTC                    0x8 
#define TMR0_MODE_FAST_PWM               0x48 
#define TMR0_MODE_PhaseCorrect_PWM       0x40      

#define TIM0_Mode   TMR0_MODE_CTC

/******************************************************************************************/
                /*    Configure TIMER0 CTC mode   */
/* TIMER0 CTC mode  options */

#define TMR0_CTCMode_Disconnect_OC0       0x0
#define TMR0_CTCMode_Toggle_OC0          0x10
#define TMR0_CTCMode_Clear_OC0           0x20
#define TMR0_CTCMode_Set_OC0             0x30

#define TIM0_CTCMode     TMR0_CTCMode_Clear_OC0

/***************************************************************************************/

                /*    Configure TIMER0 Clock  */
/* TIMER0 Clock options */
#define TMR0_Clk_NO_Clk					 0x0     
#define TMR0_Clk_NO_Prescaler			 0x1		 
#define TMR0_Clk_Prescaler_8			 0x2			
#define TMR0_Clk_Prescaler_64			 0x3	   
#define TMR0_Clk_Prescaler_256			 0x4		
#define TMR0_Clk_Prescaler_1024			 0x5		
#define TMR0_ExternalClk_FallingEdge     0x6
#define TMR0_ExternalClk_RisingEdge	     0x7

#define TIM0_Clk        TMR0_Clk_Prescaler_8
/****************************************/
#define System_Clk 8000000
/*****************************/
// in ctc mode set compare value from 1 to 255
#define Compare_val     255
#endif /*TIM0_CFG_H*/
