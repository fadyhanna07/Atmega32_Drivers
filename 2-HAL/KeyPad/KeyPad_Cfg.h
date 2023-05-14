/*******************************************/
/*KeyPad_cfg.h
Author :FADY
 Date:2023-03-29 */ 
/*******************************************/
#ifndef _KeyPad_CFG_H
#define _KeyPad_CFG_H
//extern the numbers that has been configured in the keypad
extern u8 KeyPad_LookUpTable [NUMBER_OF_ROWS] [NUMBER_OF_COLMUNS] ;
//extern the columns pins 
extern const u8 KeyPad_ArrColsCfg [ NUMBER_OF_COLMUNS];
//extern the Rows pins 
extern const u8 KeyPad_ArrRowsCfg [ NUMBER_OF_ROWS] ;
#endif /*KeyPad_CFG_H*/
