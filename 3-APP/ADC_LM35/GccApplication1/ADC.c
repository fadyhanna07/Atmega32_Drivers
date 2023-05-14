/*******************************************/
/*ADC Driver
Target: ATMEGA32
Author :FADY
 Date:2023-02-10 */ 
/*******************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_int.h"
#include "ADC_Cfg.h"
#include "ADC_Prv.h"
// pointer function used to excuted in adc Isr
void (*ADC_CallBack)(void)= NULL;

void ADC_voidConfigureVoltageReference(u8 VoltageReference)
{
    ADMUX = (ADMUX & ADC_VoltageReference_clear) | VoltageReference;
}

void ADC_voidConfigureInputChannel(u8 InputChannel)
{
    ADMUX = (ADMUX & ADC_InputChannel_clear) | InputChannel;
}

void ADC_voidConfigureClockPrescaler(u8 ClockPrescaler)
{
    ADCSRA = (ADCSRA & ADC_ClockPrescaler_clear) | ClockPrescaler;
}

void ADC_voidControlADC(u8 AdcControl)
{
    ADCSRA = (ADCSRA & ADC_Control_clear) | AdcControl;
}

void ADC_voidStartConversion(void)
{
    SET_BIT(ADCSRA,6);
}
ADC_tenuErrorStatus ADC_enuStartConversionAndWait(u8 ResolutionsOptions , u16 * Add_u16data)
{
    ADC_tenuErrorStatus Loc_enuErrorStatus = ADC_enuOk;
    u8 Loc_u8Timeout = ADC_CONVERSION_TIME;
    if(Add_u16data == NULL)
    {Loc_enuErrorStatus = ADC_enuNullPointer;}
    else
    {
       // SET_BIT(ADCSRA,4);                // to clear ADC interrupt flag 
        SET_BIT(ADCSRA,6);                // to start conversion
        while (GET_BIT(ADCSRA,4) == 0 && --Loc_u8Timeout > 0);
        if (Loc_u8Timeout == 0)
        {
            Loc_enuErrorStatus = ADC_enuTimeout;
        }
        else{
            if(ResolutionsOptions == ADC_Resolution_8bit)
            {
                SET_BIT(ADMUX,5);  // left adjusted and no more than 8-bit precision is required
                *Add_u16data = (u16) ADCH; 
            }
            else
            {
                CLR_BIT(ADMUX,5);   // to read 10 bit
                *Add_u16data = (u16) ADCL; 
                *Add_u16data |= ( (u16) ADCH ) << 8;

            }
            SET_BIT(ADCSRA,4);                // to clear ADC interrupt flag 
        }

    }
    return Loc_enuErrorStatus;
}

ADC_tenuErrorStatus ADC_enuGetValue(u8 ResolutionsOptions , u16 * Add_u16data)
{
    ADC_tenuErrorStatus Loc_enuErrorStatus = ADC_enuOk;
    if(Add_u16data == NULL)
    {Loc_enuErrorStatus = ADC_enuNullPointer;}
    else
    {
        if(ResolutionsOptions == ADC_Resolution_8bit)
            {
                SET_BIT(ADMUX,5);  // left adjusted and no more than 8-bit precision is required
                *Add_u16data = (u16) ADCH; 
            }
            else
            {
                CLR_BIT(ADMUX,5);   // to read 10 bit
                *Add_u16data = (u16) ADCL; 
                *Add_u16data |= ( (u16) ADCH ) << 8;

            }
    }
   return Loc_enuErrorStatus; 
}

void ADC_voidConfigureAutoTrigger(u8 AutotriggerOption)
{
    SFIOR = (SFIOR & ADC_AutoTriggerSource_clear) | AutotriggerOption;
}

void ADC_voidControlAutoTrigger(u8 AutotriggerControl)
{
    ADCSRA = (ADCSRA & ADC_AutoTriggerControl_clear) | AutotriggerControl;
}
void ADC_voidControlInterrupt(u8 InterruptControl)
{
    ADCSRA = (ADCSRA & ADC_InterruptControl_clear) | InterruptControl;
}
void ADC_voidSetCallback(void (*pf)(void))
{
    ADC_CallBack = (void (*)(void))pf;
}
void __vector_16(void)
{
    ADC_CallBack();
}
void ADC_voidInit(void)
{
    /* Select the Voltage reference from config file */
    ADC_voidConfigureVoltageReference(ADC_VoltageReference_CFG);
   /*Select The Prescaler value  from config file*/ 
    ADC_voidConfigureClockPrescaler(ADC_ClockPrescaler_CFG);
    /* enable the ADC */
    ADC_voidControlADC(ADC_Enable);
}
