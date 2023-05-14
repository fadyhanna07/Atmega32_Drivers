/*******************************************/
/*ADC Driver
Target: ATMEGA32
Author :FADY
 Date:2023-02-10*/
/*******************************************/

#ifndef _ADC_PRV_H
#define _ADC_PRV_H

/***************************************************
*                                                  *
* Description :  MEMEROY MAPPING I/O  Peripheral   *
*                                                  *
****************************************************/
#define     ADMUX       *( (volatile u8 *) 0x27)   
#define     ADCSRA      *( (volatile u8 *) 0x26)
#define     ADCH        *( (volatile u8 *) 0x25)
#define     ADCL        *( (volatile u8 *) 0x24)
#define     SFIOR       *( (volatile u8 *) 0x50)

void __vector_16(void) __attribute__((signal));

#define    ADC_CONVERSION_TIME         100
#endif /*ADC_PRV_H*/
