#ifndef LCD_H
#define LCD_H

#include "DIO.h"


#define LCD_4bitMode       0
#define LCD_8bitMode       1

typedef enum
{
		LCD_enuOk=0,
		LCD_enuNotOk,
		LCD_enuNullPtr
}LCD_enuErrorStatus;


void LCD_vidInit(void);
LCD_enuErrorStatus LCD_enuSendData(u8 Copy_u8Data);
LCD_enuErrorStatus LCD_enuSendCommand(u8 Copy_u8Command);
LCD_enuErrorStatus LCD_enuGotoXY(u8 Copy_u8XPos, u8 Copy_u8YPos);
LCD_enuErrorStatus LCD_enuWriteSpecialPattern(u8* Add_pu8Pattern, u8 Copy_u8BlockNum, u8 Copy_u8XPos, u8 Copy_u8YPos);
LCD_enuErrorStatus LCD_enuWriteString(char* Add_pchString);
LCD_enuErrorStatus LCD_enuWriteNumber(u16 Copy_u16Number);
void LCD_Clear(void);
static void LCD_TriggerEnable(void);
static void LCD_Custom_Char (u8 loc, u8 *msg);
#endif