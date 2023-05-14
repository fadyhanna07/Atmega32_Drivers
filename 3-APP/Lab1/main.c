/*
 * main.c
 *
 *  Created on: Jan 20, 2023
 *      Author: fadyh
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "LED.h"
#include "LED_Cfg.h"
#include "SWITCH.h"
#include <util/delay.h>
//#include<avr/io.h>

int main(void){
DIO_enuInit();
while(1){
	LED_enuOnLED(0,0);
			for(u8 i=0;i<7;i++)
			{
				_delay_ms(500);
				LED_enuOffLED(0,i);
				LED_enuOnLED(0,i+1);
			}
		for(u8 i=7;i>0;i--)
				{
				_delay_ms(500);
				LED_enuOffLED(0,i);
				LED_enuOnLED(0,i-1);
				}

}

	return 0;
}

