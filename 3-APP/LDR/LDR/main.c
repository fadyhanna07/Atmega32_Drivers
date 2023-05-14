/*
 * GccApplication1.c
 *
 * Created: 2/12/2023 2:22:43 PM
 * Author : fadyh
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Prv.h"
#include "DIO_int.h"
#include "ADC_Cfg.h"
#include "ADC_int.h"
#include "ADC_Prv.h"


int main(void)
{
    /* Replace with your application code */
	ADC_voidInit();
	DIO_enuInit();
	ADC_voidConfigureInputChannel(ADC_InputChannel_1);
	u16 ADC_value=0,Analog,degree;
    while (1) 
    {
		//DIO_enuInit();
		
		ADC_enuStartConversionAndWait(ADC_Resolution_8bit,&ADC_value);	
		//Analog = (u16)((u32)ADC_value * 5000  /1024);
		//degree = Analog/10;
		
			DIO_enuSetPort(2,ADC_value);
		
		
    }
}

