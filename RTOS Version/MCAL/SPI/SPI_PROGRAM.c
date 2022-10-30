/*
 * SPI_PROGRAM.c
 *
 *  Created on: Jul 7, 2022
 *      Author: Mustapha
 */
#include"../../UTILS/STD_TYPES.h"
#include"../../UTILS/BIT_MATh.h"
#include "../SPI/SPI_INTERFACE.h"
#include "../SPI/SPI_REG.h"
void SPI_Master_init(){

	//Clock frequency select
	SET_BIT(SPCR_REG,SPCR_SPR0);
	CLR_BIT(SPCR_REG,SPCR_SPR1);
	SET_BIT(SPSR_REG,SPSR_SPR2x);
    //Master Select
	SET_BIT(SPCR_REG,SPCR_MSTR);
	//SPI Enable
	SET_BIT(SPCR_REG,SPCR_SPE);
}
void SPI_Slave_init(){


    //Master Select
	CLR_BIT(SPCR_REG,SPCR_MSTR);
	//SPI Enable
	SET_BIT(SPCR_REG,SPCR_SPE);
}
u8 SPI_Transive(u8 data){
	SPDR_REG = data;
	while(GET_BIT(SPSR_REG,SPSR_SPIF)==0);
	return SPDR_REG;

}
