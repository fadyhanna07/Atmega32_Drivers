/*
 * SPI_TEST.c
 *
 * Created: 5/5/2023 12:59:30 AM
 * Author : fadyh
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_int.h"
#include "SPI_int.h"
//#include "SPI_int.h"

int main(void)
{
    /* Replace with your application code */
	
    
		DIO_enuInit();
		SPI_voidInit();
		while(1){
		 SPI_u8SendRecieveByte(5);
		
		//_delay_ms(2);
		}
		return 0;
}

