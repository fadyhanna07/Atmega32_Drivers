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
#include "SSEG_int.h"
#include "LED_Cfg.h"
#include <util/delay.h>
#include<avr/io.h>

int main(void){
//DIO_enuInit();
for(u8 i=1;i<10;i++){
	for(u8 j=1;j<10;j++){
	SSEG_enuDisplayNum(0,j);
	_delay_ms(500);
	}
	SSEG_enuDisplayNum(0,0);
	SSEG_enuDisplayNum(3,i);
	_delay_ms(500);
}



	return 0;
}
