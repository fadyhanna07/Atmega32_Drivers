/*******************************************/
/*SSEG Driver
Target: ATMEGA32
Author :FADY
 Date:2023-01-25 */ 
/*******************************************/
u8 SSEG_LookUpTable[10]={
	0b10000001,   
	0b11110011,	
	0b01001001,  
	0b01100001,  
	0b00110011,  
	0b00100101,  
	0b00000101,   
	0b11110001,   
	0b00000001,   
	0b00100001,  
};
SSEG_tenuErrorStatus_t SSEG_enuDisplayNum(u8 Cpy_enuPortNumber, u8 Cpy_number)
{
		SSEG_tenuErrorStatus_t Loc_u8ErrorStatus = SSEG_enuOK;
		DIO_enuSetPort(Cpy_enuPortNumber,SSEG_LookUpTable[Cpy_number]);
		return Loc_u8ErrorStatus;

}