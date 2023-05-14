/*
 * GccApplication5.c
 *
 * Created: 3/31/2023 6:43:54 PM
 * Author : fadyh
 */ 

#include <avr/io.h>


int main(void)
{
	char  ptr[] ={0b00000001,0b00000000,0b00000011,0b00000011,0b00010001,0b00010001,0b00011111,0b00011111};
    LCD_enuInit();
	//LCD_enuGoToXY(0,3);
	//LCD_enuWriteString("fady");
	LCD_enuWriteSpecialChar(ptr,0,0,0);
    while (1) 
    {
    }
}

