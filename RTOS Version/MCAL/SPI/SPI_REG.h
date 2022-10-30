/*
 * SPI_REG.h
 *
 *  Created on: Jul 7, 2022
 *      Author: Mustapha
 */

#ifndef MCAL_SPI_SPI_REG_H_
#define MCAL_SPI_SPI_REG_H_

#define SPCR_REG    *((volatile u8*)0x2D) //SPI control register
#define SPCR_SPR0   0  //Clock frequency select
#define SPCR_SPR1   1  //Clock frequency select
#define SPCR_CPOL   2  //Clock Polarity
#define SPCR_CPHA   3  //Clock Phase
#define SPCR_MSTR   4   //Master select
#define SPCR_DORD   5   //Data order (transmit first or shift first)
#define SPCR_SPE    6   //SPI enable
#define SPCR_SPIE   7   //SPI Interrupt enable


#define SPSR_REG    *((volatile u8*)0x2E) //SPI status register
#define SPSR_SPR2x  0  //Clock frequency select
#define SPSR_WCOL   6  //Write collision flag
#define SPSR_SPIF   7  //SPI interrupt flag

#define SPDR_REG    *((volatile u8*)0x2F) //SPI data register



#endif /* MCAL_SPI_SPI_REG_H_ */
