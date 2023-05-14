/*
 * GccApplication3.c
 *
 * Created: 3/31/2023 3:59:15 AM
 * Author : fadyh
 */ 

#include <avr/io.h>


int main(void)
{
    LCD_vidInit();
	LCD_enuWriteString("fady");
    while (1) 
    {
    }
}

