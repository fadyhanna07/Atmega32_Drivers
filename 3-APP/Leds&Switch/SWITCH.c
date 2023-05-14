
#include "STD_TYPES.h"
#include "SWITCH.h"
#include "DIO_int.h"
#include <avr/delay.h>

SWITCH_tenuErrorStatus SWITCH_enuGetSwitchValue(SWITCH_tenuPORTS Cpy_u8PortNumber,SWITCH_tenuNums Cpy_u8PinNumber, u8* Add_u8SwitchState){
	SWITCH_tenuErrorStatus Loc_u8ErrorStatus = SWITCH_enOK;
	u8 ButtonStatues=1;
	* Add_u8SwitchState=1;
	u8 Debounce_Counter=0;

	for(u8 i=0;i<5;i++){
		Loc_u8ErrorStatus = DIO_enuGetPinValue((Cpy_u8PortNumber * SWITCH_enuNumbers) + Cpy_u8PinNumber,& ButtonStatues);
		if(ButtonStatues==0){Debounce_Counter++;}
		_delay_ms(5);
	}
	if(Debounce_Counter>3){* Add_u8SwitchState=0;}

     _delay_ms(50);
    return Loc_u8ErrorStatus;
}
