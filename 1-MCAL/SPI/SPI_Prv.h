/*******************************************/
/*SPI Driver
Target: ATMEGA32
Author :FADY
 Date:2023-05-01*/
/*******************************************/

#ifndef _SPI_PRV_H
#define _SPI_PRV_H
/**************************************************/
/* SPCR Bits */
#define SPCR_SPIE                   7
#define SPCR_SPE                    6
#define SPCR_DORD                   5
#define SPCR_MSTR                   4
#define SPCR_CPOL                   3
#define SPCR_CPHA                   2
#define SPCR_SPR1                   1
#define SPCR_SPR0                   0

/* SPSR BITS */
#define SPSR_SPIF                   7
#define SPSR_WCOL                   6
#define SPSR_SPI2X                  0

/***************************************************
*                                                  *
* Description :  MEMEROY MAPPING I/O  Peripheral   *
*                                                  *
****************************************************/
#define SPCR   *((volatile u8*)0x2D)
#define SPSR   *((volatile u8*)0x2E)
#define SPDR   *((volatile u8*)0x2F)

#endif /*SPI_PRV_H*/
