/*
 * GccApplication2.c
 *
 * Created: 3/31/2023 2:33:35 AM
 * Author : fadyh
 */ 

#include <avr/io.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "LCD_int.h"

int main(void)
{
	
    LCD_enuInit();
	LCD_enuWriteString("fady");
    while (1) 
    {
		
    }
}

