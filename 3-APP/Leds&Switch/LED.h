#ifndef _LED_H_
#define _LED_H_

typedef enum{
    LED_enOK = 0,
    LED_enNotOK,
}LED_tenuErrorStatus;

typedef enum{
    LED_enuNum0,
    LED_enuNum1,
    LED_enuNum2,
    LED_enuNum3,
    LED_enuNum4,
    LED_enuNum5,
    LED_enuNum6,
    LED_enuNum7,
    LED_enuNumbers
}LED_tenuNums;

typedef enum{
    LED_enuPORT0,
    LED_enuPORT1,
    LED_enuPORT2,
    LED_enuPORT3
}LED_tenuPORTS;

LED_tenuErrorStatus LED_enuOnLED( LED_tenuPORTS Cpy_u8PortNumber,LED_tenuNums Cpy_u8PinNumber);
LED_tenuErrorStatus LED_enuOffLED( LED_tenuPORTS Cpy_u8PortNumber,LED_tenuNums Cpy_u8PinNumber);

#endif
