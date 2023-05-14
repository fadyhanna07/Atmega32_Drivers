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
	u8 Switch_1_Statues;
	u8 Switch_2_Statues;
	static u8 Counter_1_OfPush=0;
	SWITCH_enuGetSwitchValue(1,0,&Switch_1_Statues);
	SWITCH_enuGetSwitchValue(1,1,& Switch_2_Statues);
	///////////////////////////////////////////////////
	if(Switch_1_Statues==0)
		{
			LED_enuOnLED(0,Counter_1_OfPush++);
			//_delay_ms(1000);
		}

	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	if(Switch_2_Statues==0)
	{
		LED_enuOffLED(0,--Counter_1_OfPush);
		//_delay_ms(1000);
	}




	//else{LED_enuOffLED(0,0);}
}
}
