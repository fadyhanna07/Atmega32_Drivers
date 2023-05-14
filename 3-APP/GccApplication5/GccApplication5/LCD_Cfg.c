/*******************************************/
/*LCD Driver
Target: ATMEGA32
Author :FADY
 Date:2023-03-29 */ 
/*******************************************/
#include "STD_TYPES.h"
#include "DIO_int.h"
#include "LCD_Cfg.h"

const LCD_Operation_cfg_t LCD_Operation_cfg = {
    .backlight = Backlight_on,
    .blink = Blink_off,
    .font = Font_7,
    .mode = Mode_8bit,
    .numOfLines = Num_2_lines,
    .curser = Curser_off
};

const LCD_Pins_cfg_t LCD_Pins_cfg = {
    .RS = { .Port=DIO_PORTB,.Pin = 0},
    .ReadWrite = { .Port = DIO_PORTB,.Pin = 1},
    .Enable ={.Port = DIO_PORTB,.Pin = 2},
    .Data = {
        [0] = { .Port=DIO_PORTA,.Pin = 0},  //D0
        [1] = { .Port=DIO_PORTA,.Pin = 1},  //D1
        [2] = { .Port=DIO_PORTA,.Pin = 2},  //D2
        [3] = { .Port=DIO_PORTA,.Pin = 3},  //D3
        [4] = { .Port=DIO_PORTA,.Pin = 4},  //D4
        [5] = { .Port=DIO_PORTA,.Pin = 5},  //D5
        [6] = { .Port=DIO_PORTA,.Pin = 6},  //D6
        [7] = { .Port=DIO_PORTA,.Pin = 7}   //D7
        }
};
