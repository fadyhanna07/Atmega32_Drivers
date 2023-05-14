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
/*********************************************************  Types  ******************************************************************/
typedef enum {
    ADC_READY = 0,
    ADC_BUSY  
} ADC_tenuStatus;
/****************************************************  Global variables ****************************************************************/
// pointer function used to excuted in adc Isr
static u8 ADC_u8State = ADC_READY;
static volatile u8 Glo_ResolutionsOptions = 0;
static void (*ADC_CallBack)(void)=NULL;
static volatile u16 *ADC_Conversion_Data = NULL; // ptr to return the data after ADC finish the conversion
static void (*EndOfJob)(void)= NULL; // pointer function used in chain conversion
static volatile u16 *ADC_u16ChainValues = NULL; //Pointer to access the array of chain values 
static volatile u8 *Chain_Channels_Id = NULL;   // Pointer to carry chanells array
static volatile u8 Chain_Size = 0;              /*Global variable carry the chain size*/
static volatile u8 Chain_Id = 0;                /*Global variable carry the chain id*/
static volatile u8 ADC_Chain_Flag = 0;          /*Global variable to check if the chain or single async function is use ISR*/   
static volatile u8 ADC_Chain_Index = 0; 
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
    SET_BIT(ADCSRA,3);      //enable interrupt
    SET_BIT(ADCSRA,6);
}

ADC_tenuErrorStatus ADC_enuStartConversion_Async(u8 ResolutionsOptions, u16 * Add_u16data, void(*ADC_Callback_pf)void )
{
    ADC_tenuErrorStatus Loc_enuErrorStatus = ADC_enuOk;
    ADC_Chain_Flag = 0;
    if(ADC_u8State == ADC_BUSY)
    { Loc_enuErrorStatus = ADC_enuBusy;}
    else if (Add_u16data == NULL || ADC_Callback_pf == NULL)
    {
        Loc_enuErrorStatus = ADC_enuNullPointer;
    }
    
    else{
        ADC_u8State = ADC_BUSY;
        ADC_CallBack = ADC_Callback_pf;
        ADC_Conversion_Data = Add_u16data;
        Glo_ResolutionsOptions = ResolutionsOptions;
        SET_BIT(ADCSRA,3);//enable interrupt
        SET_BIT(ADCSRA,6);// start conversion

    }
    return Loc_enuErrorStatus ;
}
ADC_tenuErrorStatus ADC_enuStartConversionAndWait(u8 ResolutionsOptions , u16 * Add_u16data)
{
    ADC_tenuErrorStatus Loc_enuErrorStatus = ADC_enuOk;
    u8 Loc_u8Timeout = ADC_CONVERSION_TIME;
    if(Add_u16data == NULL)
    {Loc_enuErrorStatus = ADC_enuNullPointer;}
    else if (ADC_u8State == ADC_BUSY)
    {
        Loc_enuErrorStatus == ADC_enuBusy;
    }
    
    else
    {
        ADC_u8State = ADC_BUSY;
        SET_BIT(ADCSRA,3);                //enable interrupt
        SET_BIT(ADCSRA,4);                // to clear ADC interrupt flag 
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
        ADC_u8State = ADC_READY;
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

void ADC_voidInit(void)
{
    /* Select the Voltage reference from config file */
    ADC_voidConfigureVoltageReference(ADC_VoltageReference_CFG);
   /*Select The Prescaler value  from config file*/ 
    ADC_voidConfigureClockPrescaler(ADC_ClockPrescaler_CFG);
    /* enable the ADC */
    ADC_voidControlADC(ADC_Enable);
}

ADC_tenuErrorStatus ADC_enuStartChainConversion(ADC_Chain *Add_Chain)
{
    ADC_tenuErrorStatus Loc_enuErrorStatus = ADC_enuOk;
    if(ADC_u8State == ADC_BUSY)
    { Loc_enuErrorStatus = ADC_enuBusy;}
    else if (Add_Chain == NULL)
    {
        Loc_enuErrorStatus = ADC_enuNullPointer;
    }
    
    else{
    ADC_Chain_Flag = 1;
    ADC_u8State = ADC_BUSY;
    Chain_Id = Add_Chain->Chain_id;
    Chain_Size = Add_Chain->Chain_Size;
    ADC_u16ChainValues = Add_Chain->Res_Arr;
    EndOfJob = Add_Chain->EOJ;
    Glo_ResolutionsOptions = Add_Chain->chain_resolution;
    ADC_Chain_Index = 0;
    Chain_Channels_Id = Add_Chain->Channels_id;
    ADC_voidControlInterrupt(ADC_EnableInterrupt);
    ADC_voidConfigureInputChannel(Chain_Channels_Id[ADC_Chain_Index]);
    ADC_voidStartConversion();
    }
    return Loc_enuErrorStatus;
}
void __vector_16(void)
{
    if(ADC_Chain_Flag)
    {
        if( ADC_Chain_Index == Chain_Size)
        {
            EndOfJob();
            ADC_Chain_Flag = 0;
            ADC_u8State = ADC_READY;
            CLR_BIT(ADCSRA,3);      //disable interrupt
        }
        else{
             if(Glo_ResolutionsOptions == ADC_Resolution_8bit)
            {
                SET_BIT(ADMUX,5);  // left adjusted and no more than 8-bit precision is required
                ADC_u16ChainValues[ADC_Chain_Index] = (u16) ADCH; 
            }
            else
            {
                CLR_BIT(ADMUX,5);   // to read 10 bit
                ADC_u16ChainValues[ADC_Chain_Index] = (u16) ADCL; 
                ADC_u16ChainValues[ADC_Chain_Index] |= ( (u16) ADCH ) << 8;
            }
            ADC_Chain_Index++;
            ADC_voidConfigureInputChannel(Chain_Channels_Id[ADC_Chain_Index]);
            ADC_voidStartConversion();
        }
      
    }
    else
    {
           if(Glo_ResolutionsOptions == ADC_Resolution_8bit)
            {
                SET_BIT(ADMUX,5);  // left adjusted and no more than 8-bit precision is required
                *ADC_Conversion_Data = (u16) ADCH; 
            }
            else
            {
                CLR_BIT(ADMUX,5);   // to read 10 bit
                *ADC_Conversion_Data = (u16) ADCL; 
                *ADC_Conversion_Data |= ( (u16) ADCH ) << 8;
            }
            CLR_BIT(ADCSRA,3);      //disable interrupt
            ADC_u8State = ADC_READY;
            ADC_CallBack();

    }
}