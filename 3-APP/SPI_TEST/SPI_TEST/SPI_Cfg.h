/*******************************************/
/*SPI Driver
Target: ATMEGA32
Author :FADY
 Date:2023-05-01*/
/*******************************************/
#ifndef _SPI_CFG_H
#define _SPI_CFG_H

/* Macros for Config */
/**********************************************************************************/
/* Master or slave Mode options */

#define SPI_Mode_MASTER               0
#define SPI_Mode_SLAVE                1

/* Config For SPI MODE  */
#define SPI_Mode            SPI_Mode_MASTER
/**********************************************************************************/
/* Macros For Interrupt control */

#define SPI_INT_ENABLE           0
#define SPI_INT_DISABLE          1

/* Control SPI Interrupt  */
#define SPI_Interrupt       SPI_INT_ENABLE
/**********************************************************************************/
/* Config Macros For The data order options*/
#define SPI_DataOrder_MSB                  0
#define SPI_DataOrder_LSB                  1

/* Config For SPI Data order  */
#define SPI_DataOrder       SPI_DataOrder_MSB
/**********************************************************************************/
/* Config Macros for CLK Polarity options */
#define SPI_RAISING_EDGE         0
#define SPI_FALLING_EDGE         1

/* Config For SPI CLK Polarity */
#define SPI_CLKPolarity     SPI_RAISING_EDGE
/**********************************************************************************/
/* Config Macros for CLK PHASE options*/
#define SPI_SAMPLE               0
#define SPI_SETUP                1

/* Config For SPI CLK PHASE */
#define SPI_CLKPHASE        SPI_SAMPLE
/**********************************************************************************/
/* Config Macros for CLK in Master Mode */
#define SPI_CLK_OVER_4              0
#define SPI_CLK_OVER_16             1
#define SPI_CLK_OVER_64             2
#define SPI_CLK_OVER_128            3
#define SPI_HCLK_OVER_2             4
#define SPI_HCLK_OVER_8             5
#define SPI_HCLK_OVER_32            6
#define SPI_HCLK_OVER_64            7

/* Config For SPI Master CLK  */
#define SPI_MasterCLK        SPI_CLK_OVER_16
#endif /*SPI_CFG_H*/
