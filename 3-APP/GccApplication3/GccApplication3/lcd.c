#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"
#include "lcd_cfg.h"


void LCD_vidInit(void)
{
	DIO_enuInit();
	_delay_ms(100); //delay 100 ms
	#if 	LCD_MODE == LCD_8bitMode
		_delay_ms(20); //delay 20 ms
		LCD_enuSendCommand(0x38);		/* Initialization of 16X2 LCD in 8bit mode */
		LCD_enuSendCommand(0x0C);		/* Display ON Cursor OFF */
		LCD_enuSendCommand(0x06);		/* Auto Increment cursor */
		LCD_enuSendCommand(0x01);		/* clear display */
		_delay_ms(2); //delay 2 ms
	#elif LCD_MODE == LCD_4bitMode
		LCD_enuSendCommand(0x33);
		LCD_enuSendCommand(0x32);
		LCD_enuSendCommand(0x28);
		LCD_enuSendCommand(0x0C);
    LCD_enuSendCommand(0x01);
		LCD_enuSendCommand(0x06);
		LCD_enuSendCommand(0x02);
		_delay_ms(2); //delay 2 ms
	#endif
}

LCD_enuErrorStatus LCD_enuSendData(u8 Copy_u8Data)
{
	LCD_enuErrorStatus status = LCD_enuOk;
	DIO_enuSetPin(LCD_RSPin);
	DIO_enuClearPin(LCD_RWPin);
	#if 	LCD_MODE == LCD_8bitMode
		switch(GET_BIT(Copy_u8Data,7))
			{
				case DIO_Low:
					DIO_enuClearPin(LCD_DB7Pin);
				break;
				case DIO_High:
					DIO_enuSetPin(LCD_DB7Pin);
				break;
			}
			
			switch(GET_BIT(Copy_u8Data,6))
			{
				case DIO_Low:
					DIO_enuClearPin(LCD_DB6Pin);
				break;
				case DIO_High:
					DIO_enuSetPin(LCD_DB6Pin);
				break;
			}
			
			switch(GET_BIT(Copy_u8Data,5))
			{
				case DIO_Low:
					DIO_enuClearPin(LCD_DB5Pin);
				break;
				case DIO_High:
					DIO_enuSetPin(LCD_DB5Pin);
				break;
			}
			
			switch(GET_BIT(Copy_u8Data,4))
			{
				case DIO_Low:
					DIO_enuClearPin(LCD_DB4Pin);
				break;
				case DIO_High:
					DIO_enuSetPin(LCD_DB4Pin);
				break;
			}
	
			switch(GET_BIT(Copy_u8Data,3))
			{
				case DIO_Low:
					DIO_enuClearPin(LCD_DB3Pin);
				break;
				case DIO_High:
					DIO_enuSetPin(LCD_DB3Pin);
				break;
			}
			
			switch(GET_BIT(Copy_u8Data,2))
			{
				case DIO_Low:
					DIO_enuClearPin(LCD_DB2Pin);
				break;
				case DIO_High:
					DIO_enuSetPin(LCD_DB2Pin);
				break;
			}
			
			switch(GET_BIT(Copy_u8Data,1))
			{
				case DIO_Low:
					DIO_enuClearPin(LCD_DB1Pin);
				break;
				case DIO_High:
					DIO_enuSetPin(LCD_DB1Pin);
				break;
			}
			
			switch(GET_BIT(Copy_u8Data,0))
			{
				case DIO_Low:
					DIO_enuClearPin(LCD_DB0Pin);
				break;
				case DIO_High:
					DIO_enuSetPin(LCD_DB0Pin);
				break;
			}
	
	
	#elif LCD_MODE == LCD_4bitMode
		switch(GET_BIT(Copy_u8Data,7))
			{
				case DIO_Low:
					DIO_enuClearPin(LCD_DB7Pin);
				break;
				case DIO_High:
					DIO_enuSetPin(LCD_DB7Pin);
				break;
			}
			
			switch(GET_BIT(Copy_u8Data,6))
			{
				case DIO_Low:
					DIO_enuClearPin(LCD_DB6Pin);
				break;
				case DIO_High:
					DIO_enuSetPin(LCD_DB6Pin);
				break;
			}
			
			switch(GET_BIT(Copy_u8Data,5))
			{
				case DIO_Low:
					DIO_enuClearPin(LCD_DB5Pin);
				break;
				case DIO_High:
					DIO_enuSetPin(LCD_DB5Pin);
				break;
			}
			
			switch(GET_BIT(Copy_u8Data,4))
			{
				case DIO_Low:
					DIO_enuClearPin(LCD_DB4Pin);
				break;
				case DIO_High:
					DIO_enuSetPin(LCD_DB4Pin);
				break;
			}
			
			LCD_TriggerEnable();
			_delay_ms(2); //delay 2 ms
			
		switch(GET_BIT(Copy_u8Data,3))
			{
				case DIO_Low:
					DIO_enuClearPin(LCD_DB7Pin);
				break;
				case DIO_High:
					DIO_enuSetPin(LCD_DB7Pin);
				break;
			}
			
			switch(GET_BIT(Copy_u8Data,2))
			{
				case DIO_Low:
					DIO_enuClearPin(LCD_DB6Pin);
				break;
				case DIO_High:
					DIO_enuSetPin(LCD_DB6Pin);
				break;
			}
			
			switch(GET_BIT(Copy_u8Data,1))
			{
				case DIO_Low:
					DIO_enuClearPin(LCD_DB5Pin);
				break;
				case DIO_High:
					DIO_enuSetPin(LCD_DB5Pin);
				break;
			}
			
			switch(GET_BIT(Copy_u8Data,0))
			{
				case DIO_Low:
					DIO_enuClearPin(LCD_DB4Pin);
				break;
				case DIO_High:
					DIO_enuSetPin(LCD_DB4Pin);
				break;
			}
	#endif
	LCD_TriggerEnable();
	_delay_ms(2); //delay 2 ms
}

static void LCD_TriggerEnable(void)
{
	DIO_enuSetPin(LCD_EPin);
	_delay_ms(1); //delay 1 ms
	DIO_enuClearPin(LCD_EPin);
}

LCD_enuErrorStatus LCD_enuSendCommand(u8 Copy_u8Command)
{
	LCD_enuErrorStatus status =LCD_enuOk;
	DIO_enuClearPin(LCD_RSPin);
	DIO_enuClearPin(LCD_RWPin);
	#if 	LCD_MODE == LCD_8bitMode
			switch(GET_BIT(Copy_u8Command,7))
			{
				case DIO_Low:
					DIO_enuClearPin(LCD_DB7Pin);
				break;
				case DIO_High:
					DIO_enuSetPin(LCD_DB7Pin);
				break;
			}
			
			switch(GET_BIT(Copy_u8Command,6))
			{
				case DIO_Low:
					DIO_enuClearPin(LCD_DB6Pin);
				break;
				case DIO_High:
					DIO_enuSetPin(LCD_DB6Pin);
				break;
			}
			
			switch(GET_BIT(Copy_u8Command,5))
			{
				case DIO_Low:
					DIO_enuClearPin(LCD_DB5Pin);
				break;
				case DIO_High:
					DIO_enuSetPin(LCD_DB5Pin);
				break;
			}
			
			switch(GET_BIT(Copy_u8Command,4))
			{
				case DIO_Low:
					DIO_enuClearPin(LCD_DB4Pin);
				break;
				case DIO_High:
					DIO_enuSetPin(LCD_DB4Pin);
				break;
			}
	
			switch(GET_BIT(Copy_u8Command,3))
			{
				case DIO_Low:
					DIO_enuClearPin(LCD_DB3Pin);
				break;
				case DIO_High:
					DIO_enuSetPin(LCD_DB3Pin);
				break;
			}
			
			switch(GET_BIT(Copy_u8Command,2))
			{
				case DIO_Low:
					DIO_enuClearPin(LCD_DB2Pin);
				break;
				case DIO_High:
					DIO_enuSetPin(LCD_DB2Pin);
				break;
			}
			
			switch(GET_BIT(Copy_u8Command,1))
			{
				case DIO_Low:
					DIO_enuClearPin(LCD_DB1Pin);
				break;
				case DIO_High:
					DIO_enuSetPin(LCD_DB1Pin);
				break;
			}
			
			switch(GET_BIT(Copy_u8Command,0))
			{
				case DIO_Low:
					DIO_enuClearPin(LCD_DB0Pin);
				break;
				case DIO_High:
					DIO_enuSetPin(LCD_DB0Pin);
				break;
			}
			
	#elif LCD_MODE == LCD_4bitMode
		switch(GET_BIT(Copy_u8Command,7))
			{
				case DIO_Low:
					DIO_enuClearPin(LCD_DB7Pin);
				break;
				case DIO_High:
					DIO_enuSetPin(LCD_DB7Pin);
				break;
			}
			
			switch(GET_BIT(Copy_u8Command,6))
			{
				case DIO_Low:
					DIO_enuClearPin(LCD_DB6Pin);
				break;
				case DIO_High:
					DIO_enuSetPin(LCD_DB6Pin);
				break;
			}
			
			switch(GET_BIT(Copy_u8Command,5))
			{
				case DIO_Low:
					DIO_enuClearPin(LCD_DB5Pin);
				break;
				case DIO_High:
					DIO_enuSetPin(LCD_DB5Pin);
				break;
			}
			
			switch(GET_BIT(Copy_u8Command,4))
			{
				case DIO_Low:
					DIO_enuClearPin(LCD_DB4Pin);
				break;
				case DIO_High:
					DIO_enuSetPin(LCD_DB4Pin);
				break;
			}
			
			LCD_TriggerEnable();
			_delay_ms(2); //delay 2 ms
			
		switch(GET_BIT(Copy_u8Command,3))
			{
				case DIO_Low:
					DIO_enuClearPin(LCD_DB7Pin);
				break;
				case DIO_High:
					DIO_enuSetPin(LCD_DB7Pin);
				break;
			}
			
			switch(GET_BIT(Copy_u8Command,2))
			{
				case DIO_Low:
					DIO_enuClearPin(LCD_DB6Pin);
				break;
				case DIO_High:
					DIO_enuSetPin(LCD_DB6Pin);
				break;
			}
			
			switch(GET_BIT(Copy_u8Command,1))
			{
				case DIO_Low:
					DIO_enuClearPin(LCD_DB5Pin);
				break;
				case DIO_High:
					DIO_enuSetPin(LCD_DB5Pin);
				break;
			}
			
			switch(GET_BIT(Copy_u8Command,0))
			{
				case DIO_Low:
					DIO_enuClearPin(LCD_DB4Pin);
				break;
				case DIO_High:
					DIO_enuSetPin(LCD_DB4Pin);
				break;
			}
	
	#endif
	LCD_TriggerEnable();
	_delay_ms(2); //delay 2 ms
	return status;
}

LCD_enuErrorStatus LCD_enuGotoXY(u8 Copy_u8XPos, u8 Copy_u8YPos)
{
	LCD_enuErrorStatus status =LCD_enuOk;
	if(Copy_u8YPos>1 || Copy_u8XPos>15)
	{
		status =LCD_enuNotOk;
	}
	else
	{
		u8 pos[2] = {0x80 , 0xC0};
		LCD_enuSendCommand(pos[Copy_u8YPos]+Copy_u8XPos);
	}
	return status;
}


LCD_enuErrorStatus LCD_enuWriteSpecialPattern(u8* Add_pu8Pattern, u8 Copy_u8BlockNum, u8 Copy_u8XPos, u8 Copy_u8YPos)
{
	LCD_enuErrorStatus status =LCD_enuOk;
	if(Copy_u8YPos>1 || Copy_u8XPos>15 || Copy_u8BlockNum >8)
	{
		status =LCD_enuNotOk;
	}
	else
	{
		LCD_Custom_Char(Copy_u8BlockNum,Add_pu8Pattern);
		LCD_enuSendCommand(0x80);
		LCD_enuGotoXY(Copy_u8XPos,Copy_u8YPos);
		LCD_enuSendData(Copy_u8BlockNum);
	}
	return status;
}


LCD_enuErrorStatus LCD_enuWriteString(char* Add_pchString)
{
	LCD_enuErrorStatus status =LCD_enuOk;
	u8 i = 0;
	while(Add_pchString[i] != '\0')
	{
		LCD_enuSendData(Add_pchString[i]);
		i++;
	}
	return status;
}

LCD_enuErrorStatus LCD_enuWriteNumber(u16 Copy_u16Number)
{
	LCD_enuErrorStatus status =LCD_enuOk;
	u32 temp =1;
	while (Copy_u16Number)
	{
		temp=(temp*10)+(Copy_u16Number %10);
		Copy_u16Number/=10;
	}
	while(temp>1)
	{
		LCD_enuSendData((temp%10)+48);
		temp/=10;
	}
	return status;
}

void LCD_Clear(void)
{
	LCD_enuSendCommand(0x01);
}

static void LCD_Custom_Char (u8 loc, u8 *msg)
{
	unsigned char i;
	if(loc<8)
	{
		LCD_enuSendCommand (0x40 + (loc*8));	/* Command 0x40 and onwards forces the device to point CGRAM address */
		for(i=0;i<8;i++)	/* Write 8 byte for generation of 1 character */
		LCD_enuSendData(msg[i]);
	}
}