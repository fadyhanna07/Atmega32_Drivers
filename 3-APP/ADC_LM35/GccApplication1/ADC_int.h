/*******************************************/
/*ADC Driver
Target: ATMEGA32
Author :FADY
 Date:2023-02-10*/
/*******************************************/
#ifndef _ADC_INT_H
#define _ADC_INT_H
#define NULL	(void *)0
/***************************************************************************************                                               
* Description :  Voltage reference options  
*      [1] AREF: External, 'AREF' pin.
*      [2] AVCC: 'AVCC' (with external capacitor on 'AREF' pin).
*      [3] Internal: Internal 2.56V voltage (with external capacitor on 'AREF' pin).
*****************************************************************************************/
//clear the bits before setting the ADC_VoltageReference
#define  ADC_VoltageReference_clear          0x3F
/***************************************************************************/
#define  ADC_VoltageReference_AREF           0x00
#define  ADC_VoltageReference_AVCC           0x40
#define  ADC_VoltageReference_Internal       0xC0

/***************************************************************************************                                               
* Description :  Input Channel options  
*   ---> choose a chanel from 0 to 7
*   ADC_InputChannel_x
*****************************************************************************************/
//clear the bits before setting the ADC_InputChanne
#define  ADC_InputChannel_clear              0xE0
/***************************************************************************/
#define  ADC_InputChannel_0                  0x00
#define  ADC_InputChannel_1                  0x01
#define  ADC_InputChannel_2                  0x02
#define  ADC_InputChannel_3                  0x03
#define  ADC_InputChannel_4                  0x04
#define  ADC_InputChannel_5                  0x05
#define  ADC_InputChannel_6                  0x06
#define  ADC_InputChannel_7                  0x07

/***************************************************************************************                                               
* Description :  ADC Clock Prescaler options  
*   ---> choose a Division Factor in this range [2,4,8,16,32,64,128]
*   ADC_InputChannel_x
*****************************************************************************************/
//clear the bits before setting the ADC_InputChanne
#define  ADC_ClockPrescaler_clear            0xF8
/***************************************************************************/
#define  ADC_ClockPrescaler_2                0x01
#define  ADC_ClockPrescaler_4                0x02
#define  ADC_ClockPrescaler_8                0x03
#define  ADC_ClockPrescaler_16               0x04
#define  ADC_ClockPrescaler_32               0x05
#define  ADC_ClockPrescaler_64               0x06
#define  ADC_ClockPrescaler_128              0x07
/***************************************************************************************  
  
/***************************************************************************************                                               
* Description :  ADC Auto trigger configure options  

*****************************************************************************************/
//clear the bits before setting the ADC_AutoTriggerSource
#define  ADC_AutoTriggerSource_clear                       0x1F
/***************************************************************************/
#define ADC_AutoTriggerSource_FreeRunningMode              0x00
#define ADC_AutoTriggerSource_AnalogComparator             0x20
#define ADC_AutoTriggerSource_ExternalInterrupt0           0x40
#define ADC_AutoTriggerSource_Timer0CompareMatch           0x60
#define ADC_AutoTriggerSource_Timer0Overflow               0x80
#define ADC_AutoTriggerSource_Timer1CompareMatch           0xA0
#define ADC_AutoTriggerSource_Timer1Overflow               0xC0
#define ADC_AutoTriggerSource_Timer1CaptureEvent           0xE0             

/***************************************************************************************                                               
* Description :  ADC resolutions options  
*****************************************************************************************/
#define ADC_Resolution_8bit         0
#define ADC_Resolution_10bit        1
/***************************************************************************************                                               
* Description :  ADC control
*****************************************************************************************/
#define ADC_Control_clear           0x7f
#define ADC_Enable                  0x80
#define ADC_Disable                 0x00
/***************************************************************************************                                               
* Description :  ADC Auto Trigger control
*****************************************************************************************/
#define ADC_AutoTriggerControl_clear           0xdf
#define ADC_EnableAutoTrigger                  0x20
#define ADC_DisableAutoTrigger                 0x00
/***************************************************************************************                                               
* Description :  ADC Auto Trigger control
*****************************************************************************************/
#define ADC_InterruptControl_clear           0xf7
#define ADC_EnableInterrupt                  0x08
#define ADC_DisableInterrupt                 0x00
/***************************************************************************************                                               
* Description :  Error status 
*****************************************************************************************/
typedef enum {
    ADC_enuOk = 0,
    ADC_enuNullPointer,
    ADC_enuTimeout
} ADC_tenuErrorStatus;
/***************************************************************************************                                               
* Description :  Configure Voltage reference                        #done#
* Input  : Voltage reference options  
* Return:  None 
*****************************************************************************************/
void ADC_voidConfigureVoltageReference(u8 VoltageReference);

/***************************************************************************************                                               
* Description :  Configure Input Channel                             #done#
* Input  : Input Channel options  
* Return:  None 
*****************************************************************************************/
void ADC_voidConfigureInputChannel(u8 InputChannel);

/***************************************************************************************                                               
* Description :  Configure ADC Clock Prescaler                       #done#
* Input  : Clock Prescaler options  
* Return:  None 
*****************************************************************************************/
void ADC_voidConfigureClockPrescaler(u8 ClockPrescaler);

/***************************************************************************************                                               
* Description :  control ADC                                            #done#
* Input  : [Enable , Disable]
* Return:  None 
*****************************************************************************************/
void ADC_voidControlADC(u8 AdcControl);

/***************************************************************************************                                               
* Description :  Start Conversion                                        #done#
* Input  : None 
* Return:  None 
*****************************************************************************************/
void ADC_voidStartConversion(void);

/***************************************************************************************                                               
* Description :  Start Conversion and wait to get data                      #done#
* Input  : ADC resolutions options , address to return the data
* Return:  error statues
*****************************************************************************************/
ADC_tenuErrorStatus ADC_enuStartConversionAndWait(u8 ResolutionsOptions , u16 * Add_u16data);
/***************************************************************************************                                               
* Description :  Get values from ADC                                        #done#
* Input  : ADC resolutions options , address to return the data
* Return:  error statues
*****************************************************************************************/
ADC_tenuErrorStatus ADC_enuGetValue(u8 ResolutionsOptions , u16 * Add_u16data);

/***************************************************************************************                                               
* Description :  Configure Auto trigger                                     #done#
* Input  : Auto trigger options
* Return:  None 
*****************************************************************************************/
void ADC_voidConfigureAutoTrigger(u8 AutotriggerOption);

/***************************************************************************************                                               
* Description :  Control Auto trigger                                       #done#
* Input  : Auto trigger Control [Enable , Disable]
* Return:  None 
*****************************************************************************************/
void ADC_voidControlAutoTrigger(u8 AutotriggerControl);
/***************************************************************************************                                               
* Description :  Control ADC Interrupt                                      #done#
* Input  :  ADC Interrupt Control [Enable , Disable]
* Return:  None 
*****************************************************************************************/
void ADC_voidControlInterrupt(u8 AutotriggerControl);
/***************************************************************************************                                               
* Description :   ADC callback function                                        #done#
* Input  :  pointer function of function which will be excuted after interrupt
* Return:  None 
*****************************************************************************************/
void ADC_voidSetCallback(void (*pf)(void));
/***************************************************************************************                                               
* Description :  init ADC from configraton file in build process                 #done#
* Input  :  None
* Return:  None 
*****************************************************************************************/
void ADC_voidInit(void);

#endif /*ADC_INT_H*/
