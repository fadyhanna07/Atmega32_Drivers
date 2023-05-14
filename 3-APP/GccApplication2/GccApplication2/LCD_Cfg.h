/*******************************************/
/*LCD Driver
Target: ATMEGA32
Author :FADY
 Date:2023-03-29*/
/*******************************************/
#ifndef _LCD_CFG_H
#define _LCD_CFG_H
/*********************************  types  *******************************************************************************/
typedef enum {
    Backlight_off = 0,
    Backlight_on
}Backlight_control;
typedef enum {
    Curser_off = 0,
    Curser_on
}Curser_control;
typedef enum {
    Blink_off = 0,
    Blink_on
}Blink_control;
typedef enum {
    Font_7 = 0,
    Font_10
}Font_cfg;
typedef enum {
    Mode_8bit = 0,
    Mode_4bit
}Mode_cfg;
typedef enum {
    Num_1_line = 0,
    Num_2_lines
}NumOfLines_cfg;
typedef struct 
{
    u8 numOfLines;
    u8 backlight;
    u8 curser;
    u8 blink;
    u8 font;
    u8 mode;
}LCD_Operation_cfg_t;
typedef struct 
{
    u8 Port;
    u8 Pin;
}LCD_DIO_cfg_t;
typedef struct 
{
    LCD_DIO_cfg_t Enable;
    LCD_DIO_cfg_t RS;
    LCD_DIO_cfg_t ReadWrite;
    LCD_DIO_cfg_t Data[8];
}LCD_Pins_cfg_t;

extern const LCD_Operation_cfg_t LCD_Operation_cfg; 
extern const LCD_Pins_cfg_t LCD_Pins_cfg;
#endif /*LCD_CFG_H*/
