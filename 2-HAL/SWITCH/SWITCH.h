#ifndef _SWITCH_H_
#define _SWITCH_H_

typedef enum{
    SWITCH_enOK = 0,
    SWITCH_enNotOK,
    SWITCH_enNull,
 
}SWITCH_tenuErrorStatus;

typedef enum{
   SWITCH_enuNum0,
    SWITCH_enuNum1,
    SWITCH_enuNum2,
    SWITCH_enuNum3,
    SWITCH_enuNum4,
    SWITCH_enuNum5,
    SWITCH_enuNum6,
   SWITCH_enuNum7,
    SWITCH_enuNumbers
}SWITCH_tenuNums;

typedef enum{
    SWITCH_enuPORT0,
    SWITCH_enuPORT1,
    SWITCH_enuPORT2,
    SWITCH_enuPORT3
}   SWITCH_tenuPORTS;

typedef enum{
    SWITCH_PUSHED,
	SWITCH_NOT_PUSHED,
}   SWITCH_tenuStatus;

SWITCH_tenuErrorStatus SWITCH_enuGetSwitchValue(SWITCH_tenuPORTS Cpy_u8PortNumber,SWITCH_tenuNums Cpy_u8PinNumber, u8* Add_u8SwitchState);

#endif
