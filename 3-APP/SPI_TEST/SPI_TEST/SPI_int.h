/*******************************************/
/*SPI Driver
Target: ATMEGA32
Author :FADY
 Date:2023-05-01*/
/*******************************************/
#ifndef _SPI_INT_H
#define _SPI_INT_H

/******************************************* Prototypes *********************************************************/
void SPI_voidInit(void);

u8 SPI_u8SendRecieveByte(u8 Copy_u8Data);

#endif /*SPI_INT_H*/
