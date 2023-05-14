/*******************************************/
/*SPI Driver
Target: ATMEGA32
Author :FADY
 Date:2023-05-01 */ 
/*******************************************/
#include "../../4-LIB/STD_TYPES.h"
#include "../../4-LIB/BIT_MATH.h"
#include "SPI_Prv.h"
#include "SPI_Cfg.h"
#include "SPI_int.h"


void SPI_voidInit(void)
{
    //configure SPI mode 
    #if(SPI_Mode == SPI_Mode_MASTER)
        SET_BIT(SPCR,SPCR_MSTR)
    #elif(SPI_Mode == SPI_Mode_SLAVE)
        CLR_BIT(SPCR,SPCR_MSTR)
    #endif
    //configure interrupt 
    #if(SPI_Interrupt == SPI_INT_ENABLE)
        SET_BIT(SPCR,SPCR_SPIE);
    #elif (SPI_Interrupt == SPI_INT_DISABLE)
        CLR_BIT(SPCR,SPCR_SPIE);
    #endif
    // Config For SPI Data order  
    #if(SPI_DataOrder == SPI_DataOrder_LSB)
        SET_BIT(SPCR,SPCR_DORD);
    #elif (SPI_DataOrder == SPI_DataOrder_MSB)
        CLR_BIT(SPCR,SPCR_DORD);
    #endif
    /* Config For SPI CLK Polarity */
    #if(SPI_CLKPolarity == SPI_RAISING_EDGE)
        SET_BIT(SPCR,SPCR_CPOL);
    #elif (SPI_CLKPolarity == SPI_FALLING_EDGE)
        CLR_BIT(SPCR,SPCR_CPOL);
    #endif
    /* Config For SPI CLK PHASE */
    #if(SPI_CLKPHASE == SPI_SETUP)
        SET_BIT(SPCR,SPCR_CPHA);
    #elif(SPI_CLKPHASE == SPI_SAMPLE)
        CLR_BIT(SPCR,SPCR_CPHA);
    #endif
    /* Config For SPI Master CLK  */
    #if(SPI_MasterCLK == SPI_CLK_OVER_4)
        CLR_BIT(SPCR,SPCR_SPR0);
        CLR_BIT(SPCR,SPCR_SPR1);
        CLR_BIT(SPSR,SPSR_SPI2X);
    #elif(SPI_MasterCLK == SPI_CLK_OVER_16)
        SET_BIT(SPCR,SPCR_SPR0);
        CLR_BIT(SPCR,SPCR_SPR1);
        CLR_BIT(SPSR,SPSR_SPI2X);
    #elif(SPI_MasterCLK == SPI_CLK_OVER_64)
        CLR_BIT(SPCR,SPCR_SPR0);
        SET_BIT(SPCR,SPCR_SPR1);
        CLR_BIT(SPSR,SPSR_SPI2X);
    #elif(SPI_MasterCLK == SPI_CLK_OVER_128)
        SET_BIT(SPCR,SPCR_SPR0);
        SET_BIT(SPCR,SPCR_SPR1);
        CLR_BIT(SPSR,SPSR_SPI2X);
    #elif(SPI_MasterCLK == SPI_HCLK_OVER_2)
        CLR_BIT(SPCR,SPCR_SPR0);
        CLR_BIT(SPCR,SPCR_SPR1);
        SET_BIT(SPSR,SPSR_SPI2X);
    #elif(SPI_MasterCLK == SPI_HCLK_OVER_8)
        SET_BIT(SPCR,SPCR_SPR0);
        CLR_BIT(SPCR,SPCR_SPR1);
        SET_BIT(SPSR,SPSR_SPI2X);
    #elif(SPI_MasterCLK == SPI_HCLK_OVER_32)
        CLR_BIT(SPCR,SPCR_SPR0);
        SET_BIT(SPCR,SPCR_SPR1);
        SET_BIT(SPSR,SPSR_SPI2X);  
     #elif(SPI_MasterCLK == SPI_HCLK_OVER_64)
        SET_BIT(SPCR,SPCR_SPR0);
        SET_BIT(SPCR,SPCR_SPR1);
        SET_BIT(SPSR,SPSR_SPI2X); 
    #endif
    // ENABLE SPI 
    SET_BIT(SPCR,SPCR_SPE);
}
u8 SPI_u8SendRecieveByte(u8 Copy_u8Data)
{
    SPDR = Copy_u8Data;
    // wait until trasfer complete (busy wait)
    while(GET_BIT(SPSR,SPSR_SPIF) == 0);
    return SPDR;
}

