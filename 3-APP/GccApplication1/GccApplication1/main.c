/*
 * GccApplication1.c
 *
 * Created: 3/14/2023 7:54:12 PM
 * Author : fadyh
 */ 

#include <avr/io.h>


int main(void)
{
    /* Replace with your application code */
    while (1) 
    {
		DDRA=0xff;
		PORTA=0xff;
		DDRB=0xff;
		PORTB=0x00;
    }
}

