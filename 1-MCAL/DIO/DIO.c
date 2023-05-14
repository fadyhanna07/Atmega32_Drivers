/*******************************************/
/*DIO Driver
Target: ATMEGA32
Author :FADY
 Date:2023-01-18 */ 
/*******************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Cfg.h"
#include "DIO_Prv.h"
#include "DIO_int.h"


DIO_tenuErrorStatus DIO_enuInit(void){
    DIO_tenuErrorStatus Loc_enuErrorStatus = DIO_enOK;
    u8 Loc_u8Counter = 0;
    u8 Loc_u8PinNumber = 0;
    u8 Loc_u8PortNumber = 0;

    for(Loc_u8Counter = 0; Loc_u8Counter < DIO_u8NumberOfPins; Loc_u8Counter++){
        Loc_u8PinNumber = Loc_u8Counter  % 8;
        Loc_u8PortNumber = Loc_u8Counter / 8;

        switch (Loc_u8PortNumber)
        {
        case (DIO_PORTA):

            if(DIO_strPinCfg[Loc_u8Counter].DIO_PinDirection == DIO_DIR_OUTPUT){
            	SET_BIT(DDRA, Loc_u8PinNumber);
            }

            else if(DIO_strPinCfg[Loc_u8Counter].DIO_PinDirection == DIO_DIR_INPUT){
                CLR_BIT(DDRA, Loc_u8PinNumber);
                  if(DIO_strPinCfg[Loc_u8Counter].DIO_InputStatus == DIO_INPUT_PULL_UP){
                    SET_BIT(PORTA, Loc_u8PinNumber);
                  }
            }
            break;

        case (DIO_PORTB):
        if(DIO_strPinCfg[Loc_u8Counter].DIO_PinDirection == DIO_DIR_OUTPUT){
                SET_BIT(DDRB, Loc_u8PinNumber);
            }

            else if(DIO_strPinCfg[Loc_u8Counter].DIO_PinDirection == DIO_DIR_INPUT){
                CLR_BIT(DDRB, Loc_u8PinNumber);
                  if(DIO_strPinCfg[Loc_u8Counter].DIO_InputStatus == DIO_INPUT_PULL_UP){
                    SET_BIT(PORTB, Loc_u8PinNumber);
                  }
            }
            break;

        case (DIO_PORTC):
            if(DIO_strPinCfg[Loc_u8Counter].DIO_PinDirection == DIO_DIR_OUTPUT){
                SET_BIT(DDRC, Loc_u8PinNumber);
            }

            else if(DIO_strPinCfg[Loc_u8Counter].DIO_PinDirection == DIO_DIR_INPUT){
                CLR_BIT(DDRC, Loc_u8PinNumber);
                  if(DIO_strPinCfg[Loc_u8Counter].DIO_InputStatus == DIO_INPUT_PULL_UP){
                    SET_BIT(PORTC, Loc_u8PinNumber);
                  }
            }
            break;
        case (DIO_PORTD):
        if(DIO_strPinCfg[Loc_u8Counter].DIO_PinDirection == DIO_DIR_OUTPUT){
                SET_BIT(DDRD, Loc_u8PinNumber);
            }

            else if(DIO_strPinCfg[Loc_u8Counter].DIO_PinDirection == DIO_DIR_INPUT){
                CLR_BIT(DDRD, Loc_u8PinNumber);
                  if(DIO_strPinCfg[Loc_u8Counter].DIO_InputStatus == DIO_INPUT_PULL_UP){
                    SET_BIT(PORTD, Loc_u8PinNumber);
                  }
            }
            break;

        default:
            break;
        }
    }




    return Loc_enuErrorStatus;
}

DIO_tenuErrorStatus DIO_enuSetPin(DIO_tenuPins Cpy_u8PinNumber){
	DIO_tenuErrorStatus Loc_enuErrorStatus = DIO_enOK;

	u8 Loc_u8PortNumber = Cpy_u8PinNumber / 8;
	u8 Loc_u8PinNumber = Cpy_u8PinNumber % 8;

	switch(Loc_u8PortNumber){

	case (DIO_PORTA):

		SET_BIT(PORTA, Loc_u8PinNumber);
	break;

	case (DIO_PORTB):

		SET_BIT(PORTB, Loc_u8PinNumber);
	break;

	case (DIO_PORTC):

		SET_BIT(PORTC, Loc_u8PinNumber);
	break;

	case (DIO_PORTD):

		SET_BIT(PORTD, Loc_u8PinNumber);
	break;

	default:
		Loc_enuErrorStatus = DIO_enNotOK;
		break;
	}



	return Loc_enuErrorStatus;
}

DIO_tenuErrorStatus DIO_enuClrPin(DIO_tenuPins Cpy_u8PinNumber){

	DIO_tenuErrorStatus Loc_enuErrorStatus = DIO_enOK;

	u8 Loc_u8PortNumber = Cpy_u8PinNumber / 8;
	u8 Loc_u8PinNumber = Cpy_u8PinNumber % 8;

	switch(Loc_u8PortNumber){

	case (DIO_PORTA):

		CLR_BIT(PORTA, Loc_u8PinNumber);
	break;

	case (DIO_PORTB):

		CLR_BIT(PORTB, Loc_u8PinNumber);
	break;

	case (DIO_PORTC):

		CLR_BIT(PORTC, Loc_u8PinNumber);
	break;

	case (DIO_PORTD):

		CLR_BIT(PORTD, Loc_u8PinNumber);
	break;

	default:
		Loc_enuErrorStatus = DIO_enNotOK;
		break;
	}



	return Loc_enuErrorStatus;
}


DIO_tenuErrorStatus DIO_enuGetPinValue(DIO_tenuPins Cpy_u8PinNumber, u8* Add_pu8PinValue){

	DIO_tenuErrorStatus Loc_enuErrorStatus = DIO_enOK;
	u8 Loc_u8PortNumber = Cpy_u8PinNumber / 8;
	u8 Loc_u8PinNumber = Cpy_u8PinNumber % 8;

	switch(Loc_u8PortNumber){

		case (DIO_PORTA):

		*Add_pu8PinValue = GET_BIT(PINA, Loc_u8PinNumber);
		break;

		case (DIO_PORTB):

		*Add_pu8PinValue = GET_BIT(PINB, Loc_u8PinNumber);
		break;

		case (DIO_PORTC):

		*Add_pu8PinValue = GET_BIT(PINC, Loc_u8PinNumber);
		break;

		case (DIO_PORTD):

		*Add_pu8PinValue = GET_BIT(PIND, Loc_u8PinNumber);
		break;

		default:
			Loc_enuErrorStatus = DIO_enNotOK;
			break;
		}
	return Loc_enuErrorStatus;

}
DIO_tenuErrorStatus DIO_enuSetPort(u8 Cpy_u8PortNumber,u8 Cpy_u8PortValue)
{
	DIO_tenuErrorStatus Loc_enuErrorStatus = DIO_enOK;
	switch(Cpy_enuPortNumber)
	case(DIO_PORTA):
		ASSIGN_REG(PORTA,Cpy_u8PortValue);
		break;
	case(DIO_PORTB):
		ASSIGN_REG(PORTB,Cpy_u8PortValue);
		break;
	case(DIO_PORTC):
		ASSIGN_REG(PORTC,Cpy_u8PortValue);
		break;
	case(DIO_PORTD):
		ASSIGN_REG(PORTD,Cpy_u8PortValue);
		break;
	return Loc_enuErrorStatus;
}
DIO_tenuErrorStatus DIO_enuWritePinVAlue(u8 Cpy_u8Port,u8 Cpy_u8Pin,DIO_tenuPinValue Cpy_u8Value)
{
	DIO_tenuErrorStatus Loc_enuErrorStatus = DIO_enOK;
	switch(Cpy_u8Port)
	case(DIO_PORTA):
		if (Cpy_u8Value == DIO_enuHigh)
	{
		SET_BIT(PORTA,Cpy_u8Pin);
	}
	else if (Cpy_u8Value == DIO_enuLow)
	{
		CLR_BIT(PORTA,Cpy_u8Pin);
	}
		break;
	case(DIO_PORTB):
		if (Cpy_u8Value == DIO_enuHigh)
	{
		SET_BIT(PORTB,Cpy_u8Pin);
	}
	else if (Cpy_u8Value == DIO_enuLow)
	{
		CLR_BIT(PORTB,Cpy_u8Pin);
	}
		break;
	case(DIO_PORTC):
		if (Cpy_u8Value == DIO_enuHigh)
	{
		SET_BIT(PORTC,Cpy_u8Pin);
	}
	else if (Cpy_u8Value == DIO_enuLow)
	{
		CLR_BIT(PORTC,Cpy_u8Pin);
	}
		break;
	case(DIO_PORTD):
		if (Cpy_u8Value == DIO_enuHigh)
	{
		SET_BIT(PORTD,Cpy_u8Pin);
	}
	else if (Cpy_u8Value == DIO_enuLow)
	{
		CLR_BIT(PORTD,Cpy_u8Pin);
	}
		break;
	
	
	return Loc_enuErrorStatus;
	
}