/*******************************************/
/*LCD Driver
Target: ATMEGA32
Author :FADY
 Date:2023-03-29 */ 
/*******************************************/
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "LCD_Cfg.h"
#include "LCD_int.h"

/*********************************  types  *******************************************************************************/

/********************************* Global Variables  *******************************************************************************/
LCD_status_t LCD_status = LCD_Idle ;
//char * Data_Buffer = NULL;
u8 Init_done = 0;
u8 char_idx = 0 ;
User_Req_t User_Req ;


/********************************* Static Functions   *******************************************************************************/
 LCD_tenuErrorStatus LCD_enuWriteData( char data){
    LCD_tenuErrorStatus Loc_enuErrorStatus = LCD_enuOK;

    /*Set RS pin to high for data*/
   DIO_enuWritePinVAlue(DIO_PORTB,0,1);
    /*Set RW pin to low for write*/
     DIO_enuWritePinVAlue(DIO_PORTB,1,0);
    /*Set Data to data pins*/
    DIO_enuSetPort(DIO_PORTA,data);
     /*Send enable pulse*/
      DIO_enuWritePinVAlue(DIO_PORTB,2,1);
     _delay_ms(2);
    DIO_enuWritePinVAlue(DIO_PORTB,2,0);
    return Loc_enuErrorStatus;
}

/**********************************************************************************************/

static LCD_tenuErrorStatus LCD_enuSendCommand( u8 command )
{
    LCD_tenuErrorStatus Loc_enuErrorStatus = LCD_enuOK;
    /*Set RS pin to low for command*/
    //DIO_enuClrPin(DIO_enuPin16);
	DIO_enuWritePinVAlue(DIO_PORTB,0,0);
    /*Set RW pin to low for write*/
    //DIO_enuClrPin(DIO_enuPin17);
	DIO_enuWritePinVAlue(DIO_PORTB,1,0);
    /*Set Command to data pins*/
  // DIO_enuSetPort(DIO_PORTA,command);
   for(u8 idx=0;idx<8;idx++)
   {
	   DIO_enuWritePinVAlue(DIO_PORTA,idx,GET_BIT(command,idx));
   }
    /*Send enable pulse*/
     DIO_enuWritePinVAlue(DIO_PORTB,2,1);
    _delay_ms(2); 
      DIO_enuWritePinVAlue(DIO_PORTB,2,0);

    return Loc_enuErrorStatus;
}
/**********************************************************************************************/
/*static LCD_tenuErrorStatus LCD_enuClaerDisplay(u8 command){
    LCD_tenuErrorStatus Loc_enuErrorStatus = LCD_enuOK;
    LCD_enuSendCommand(command);
    LCD_status = LCD_Idle;
    return Loc_enuErrorStatus;
}*/
/*********************************  Functions Implementation  *******************************************************************************/
LCD_tenuErrorStatus LCD_enuInit()
{
	DIO_enuInit();
	_delay_ms(40);
    LCD_tenuErrorStatus Loc_enuErrorStatus = LCD_enuOK;
    
  LCD_enuSendCommand(0b00111000);
///*Display on off control: (display) enable (bit 2), (disable) cursor (bit 1), (no) blink cursor (bit 0)*/
LCD_enuSendCommand(0b00001100);
//clear display
LCD_enuSendCommand(1);
    
    return Loc_enuErrorStatus;
}

/**************************************************************************************/
LCD_tenuErrorStatus LCD_enuGoToXY(u8 pos_x ,u8 pos_y )
{
    LCD_tenuErrorStatus Loc_enuErrorStatus = LCD_enuOK;
    u8 temp_command = 0;
    if(pos_x == 0)
    {
        temp_command = pos_y;
    }
    else if (pos_x == 1)
    {
        temp_command = pos_y + 0x40;
    }
    else{ Loc_enuErrorStatus = LCD_enuNOTOK;}
    LCD_enuSendCommand(temp_command + 128);
     return Loc_enuErrorStatus;
}
/****************************************************************************************/
/*LCD_tenuErrorStatus LCD_enuWriteStringAsync(char * str )
{
    LCD_tenuErrorStatus Loc_enuErrorStatus = LCD_enuOK;
    if(str == NULL)
    {
        Loc_enuErrorStatus = LCD_enuNULLPOINTER;
    }
   else if(LCD_status == LCD_Busy)
    {
        Loc_enuErrorStatus = LCD_enuBusy;
    }
    else if (LCD_status == LCD_Idle)
    {
        LCD_status = LCD_Busy;
        Data_Buffer = str;
        User_Req = Req_Write;
    }
    else{}
    return Loc_enuErrorStatus;
}*/
/*************************************************************************************************/
/*LCD_tenuErrorStatus LCD_enuClearDisplayAsync()
{
    LCD_tenuErrorStatus Loc_enuErrorStatus = LCD_enuOK;
    if(LCD_status == LCD_Busy)
    {
        Loc_enuErrorStatus = LCD_enuBusy;
    }
     else if (LCD_status == LCD_Idle)
    {
        LCD_status = LCD_Busy;
        User_Req = Req_Clear;
    }
    else{}
    return Loc_enuErrorStatus;

}*/
/********************************************************************************************/
/*void LCD_Task(void){
    if(Init_done != 1)
    {
        LCD_enuInit();
    }
    else if (User_Req == Req_Write)
    {
        LCD_enuWriteData();
    }
    else if (User_Req == Req_Clear)
    {
        LCD_enuClaerDisplay(1);
    }
    else{}
}*/
/*****************************************************************************/
LCD_tenuErrorStatus LCD_enuWriteString(char * str )
{
	 LCD_tenuErrorStatus Loc_enuErrorStatus = LCD_enuOK;
    if(str != NULL)
    {
        u8 idx=0;
        while (str[idx] != '\0')
        {
            LCD_enuWriteData(str[idx]);
            idx++;
        }
        
    }
	return Loc_enuErrorStatus;
}