#include "DIO.h"
#include "DIO_Cfg.h"
#define NULL  (void *)0
DIO_tenuErrorStatus DIO_enuInit(void)
{
	DIO_tenuErrorStatus Status = DIO_enuOk;
	u8 local_Port=0;
	u8 local_Pin=0;
	u8 local_iterator=0;
	
	for(local_iterator=0 ; local_iterator<DIO_PinNumber ; local_iterator++)
	{
		local_Port = local_iterator/8;
		local_Pin  = local_iterator%8;
		
		switch(local_Port)
		{
			case DIO_PortA:
			switch(DIO_srtConfigArray[local_iterator].PinDir)
			{
				case DIO_Input:
				switch(DIO_srtConfigArray[local_iterator].PinMode)
				{
					case DIO_PullDown:
					CLR_BIT(DDRA  ,local_Pin);
					CLR_BIT(PORTA ,local_Pin);
					break;
					
					case DIO_PullUp:
					CLR_BIT(DDRA  ,local_Pin);
					SET_BIT(PORTA ,local_Pin);
					break;
					
					default:
					Status = DIO_enuNotOk;
					break;
				}
				break;
				
				case DIO_Output:
				switch(DIO_srtConfigArray[local_iterator].PinMode)
				{
					case DIO_OutputLow:
					SET_BIT(DDRA  ,local_Pin);
					CLR_BIT(PORTA ,local_Pin);
					break;
					
					case DIO_OutputHigh:
					SET_BIT(DDRA  ,local_Pin);
					SET_BIT(PORTA ,local_Pin);
					break;
					
					default:
					Status = DIO_enuNotOk;
					break;
				}
				break;
				
				default:
				Status = DIO_enuNotOk;
				break;
			}
			break;
			
			case DIO_PortB:
			switch(DIO_srtConfigArray[local_iterator].PinDir)
			{
				case DIO_Input:
				switch(DIO_srtConfigArray[local_iterator].PinMode)
				{
					case DIO_PullDown:
					CLR_BIT(DDRB  ,local_Pin);
					CLR_BIT(PORTB ,local_Pin);
					break;
					
					case DIO_PullUp:
					CLR_BIT(DDRB  ,local_Pin);
					SET_BIT(PORTB ,local_Pin);
					break;
					
					default:
					Status = DIO_enuNotOk;
					break;
				}
				break;
				
				case DIO_Output:
				switch(DIO_srtConfigArray[local_iterator].PinMode)
				{
					case DIO_OutputLow:
					SET_BIT(DDRB  ,local_Pin);
					CLR_BIT(PORTB ,local_Pin);
					break;
					
					case DIO_OutputHigh:
					SET_BIT(DDRB  ,local_Pin);
					SET_BIT(PORTB ,local_Pin);
					break;
					
					default:
					Status = DIO_enuNotOk;
					break;
				}
				break;
				
				default:
				Status = DIO_enuNotOk;
				break;
			}
			break;
			
			case DIO_PortC:
			switch(DIO_srtConfigArray[local_iterator].PinDir)
			{
				case DIO_Input:
				switch(DIO_srtConfigArray[local_iterator].PinMode)
				{
					case DIO_PullDown:
					CLR_BIT(DDRC  ,local_Pin);
					CLR_BIT(PORTC ,local_Pin);
					break;
					
					case DIO_PullUp:
					CLR_BIT(DDRC  ,local_Pin);
					SET_BIT(PORTC ,local_Pin);
					break;
					
					default:
					Status = DIO_enuNotOk;
					break;
				}
				break;
				
				case DIO_Output:
				switch(DIO_srtConfigArray[local_iterator].PinMode)
				{
					case DIO_OutputLow:
					SET_BIT(DDRC  ,local_Pin);
					CLR_BIT(PORTC ,local_Pin);
					break;
					
					case DIO_OutputHigh:
					SET_BIT(DDRC  ,local_Pin);
					SET_BIT(PORTC ,local_Pin);
					break;
					
					default:
					Status = DIO_enuNotOk;
					break;
				}
				break;
				
				default:
				Status = DIO_enuNotOk;
				break;
			}
			break;
			
			case DIO_PortD:
			switch(DIO_srtConfigArray[local_iterator].PinDir)
			{
				case DIO_Input:
				switch(DIO_srtConfigArray[local_iterator].PinMode)
				{
					case DIO_PullDown:
					CLR_BIT(DDRD  ,local_Pin);
					CLR_BIT(PORTD ,local_Pin);
					break;
					
					case DIO_PullUp:
					CLR_BIT(DDRD  ,local_Pin);
					SET_BIT(PORTD ,local_Pin);
					break;
					
					default:
					Status = DIO_enuNotOk;
					break;
				}
				break;
				
				case DIO_Output:
				switch(DIO_srtConfigArray[local_iterator].PinMode)
				{
					case DIO_OutputLow:
					SET_BIT(DDRD  ,local_Pin);
					CLR_BIT(PORTD ,local_Pin);
					break;
					
					case DIO_OutputHigh:
					SET_BIT(DDRD  ,local_Pin);
					SET_BIT(PORTD ,local_Pin);
					break;
					
					default:
					Status = DIO_enuNotOk;
					break;
				}
				break;
				
				default:
				Status = DIO_enuNotOk;
				break;
			}
			break;
			
			default:
			Status = DIO_enuNotOk;
			break;
		}
	}
	return Status;
}



DIO_tenuErrorStatus DIO_enuChangeDir(DIO_tenuPinNumber Cpy_u8PinNumber)
{
	DIO_tenuErrorStatus Status = DIO_enuOk;
	u8 local_Port = Cpy_u8PinNumber/8;
	u8 local_Pin  = Cpy_u8PinNumber%8;
	
	switch(local_Port)
	{
		case DIO_PortA:
		TGL_BIT(DDRA,local_Pin);
		break;
		
		case DIO_PortB:
		TGL_BIT(DDRB,local_Pin);
		break;
		
		case DIO_PortC:
		TGL_BIT(DDRC,local_Pin);
		break;
		
		case DIO_PortD:
		TGL_BIT(DDRD,local_Pin);
		break;
		
		default:
		Status = DIO_enuNotOk;
		break;
	}
	return Status;
}



DIO_tenuErrorStatus DIO_enuSetPin(DIO_tenuPinNumber Cpy_u8PinNumber)
{
	DIO_tenuErrorStatus Status = DIO_enuOk;
	u8 local_Port = Cpy_u8PinNumber/8;
	u8 local_Pin  = Cpy_u8PinNumber%8;
	
	switch(local_Port)
	{
		case DIO_PortA:
		SET_BIT(PORTA,local_Pin);
		break;
		
		case DIO_PortB:
		SET_BIT(PORTB,local_Pin);
		break;
		
		case DIO_PortC:
		SET_BIT(PORTC,local_Pin);
		break;
		
		case DIO_PortD:
		SET_BIT(PORTD,local_Pin);
		break;
		
		default:
		Status = DIO_enuNotOk;
		break;
	}
	return Status;
}


DIO_tenuErrorStatus DIO_enuClearPin(DIO_tenuPinNumber Cpy_u8PinNumber)
{
	DIO_tenuErrorStatus Status = DIO_enuOk;
	u8 local_Port = Cpy_u8PinNumber/8;
	u8 local_Pin  = Cpy_u8PinNumber%8;
	
	switch(local_Port)
	{
		case DIO_PortA:
		CLR_BIT(PORTA,local_Pin);
		break;
		
		case DIO_PortB:
		CLR_BIT(PORTB,local_Pin);
		break;
		
		case DIO_PortC:
		CLR_BIT(PORTC,local_Pin);
		break;
		
		case DIO_PortD:
		CLR_BIT(PORTD,local_Pin);
		break;
		
		default:
		Status = DIO_enuNotOk;
		break;
	}
	return Status;
}



DIO_tenuErrorStatus DIO_enuToggelPin(DIO_tenuPinNumber Cpy_u8PinNumber)
{
	DIO_tenuErrorStatus Status = DIO_enuOk;
	u8 local_Port = Cpy_u8PinNumber/8;
	u8 local_Pin  = Cpy_u8PinNumber%8;
	
	switch(local_Port)
	{
		case DIO_PortA:
		TGL_BIT(PORTA,local_Pin);
		break;
		
		case DIO_PortB:
		TGL_BIT(PORTB,local_Pin);
		break;
		
		case DIO_PortC:
		TGL_BIT(PORTC,local_Pin);
		break;
		
		case DIO_PortD:
		TGL_BIT(PORTD,local_Pin);
		break;
		
		default:
		Status = DIO_enuNotOk;
		break;
	}
	return Status;
}



DIO_tenuErrorStatus DIO_enuGetPinVal(DIO_tenuPinNumber Cpy_u8PinNumber , u8* Add_pu8PinValue)
{
	DIO_tenuErrorStatus Status = DIO_enuOk;
	u8 local_Port = Cpy_u8PinNumber/8;
	u8 local_Pin  = Cpy_u8PinNumber%8;
	
	if(Add_pu8PinValue == NULL) //null pointer argument
	return DIO_enuNullPtr;
	
	switch(local_Port)
	{
		case DIO_PortA:
		*Add_pu8PinValue = GET_BIT(PINA,local_Pin);
		break;
		
		case DIO_PortB:
		*Add_pu8PinValue = GET_BIT(PINB,local_Pin);
		break;
		
		case DIO_PortC:
		*Add_pu8PinValue = GET_BIT(PINC,local_Pin);
		break;
		
		case DIO_PortD:
		*Add_pu8PinValue = GET_BIT(PIND,local_Pin);
		break;
		
		default:
		Status = DIO_enuNotOk;
		break;
	}
	return Status;
}