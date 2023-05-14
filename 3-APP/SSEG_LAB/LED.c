#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "LED.h"
#include "LED_Cfg.h"
#include "LED_Private.h"

LED_tenuErrorStatus LED_enuOnLED( LED_tenuPORTS Cpy_u8PortNumber,LED_tenuNums Cpy_u8PinNumber){

    LED_tenuErrorStatus Loc_u8ErrorStatus = LED_enOK;
    Loc_u8ErrorStatus = DIO_enuSetPin((Cpy_u8PortNumber * LED_enuNumbers) + Cpy_u8PinNumber);
    return Loc_u8ErrorStatus;

}
LED_tenuErrorStatus LED_enuOffLED( LED_tenuPORTS Cpy_u8PortNumber,LED_tenuNums Cpy_u8PinNumber){
    
    LED_tenuErrorStatus Loc_u8ErrorStatus = LED_enOK;
    Loc_u8ErrorStatus = DIO_enuClrPin((Cpy_u8PortNumber * LED_enuNumbers) + Cpy_u8PinNumber);
    return Loc_u8ErrorStatus;
}
