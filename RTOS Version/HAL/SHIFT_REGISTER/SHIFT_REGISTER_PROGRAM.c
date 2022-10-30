/*
 * SHIFT_REGISTER.c
 *
 *  Created on: Jul 14, 2022
 *      Author: Mustapha
 */
#include <avr/delay.h>
#include"../../UTILS/STD_TYPES.h"
#include"../../UTILS/BIT_MATh.h"
#include "SHIFT_REGISTER_INTERFACE.h"
#include "../../MCAL/DIO/DIO_INTERFACE.h"

void Shift(u8 port,u8 latch_pin,u8 data_pin,u8 clk_pin,u16 binary){

	//latch low
	DIO_SetPin_Value(port,latch_pin,0);
	//clock trigger
	DIO_SetPin_Value(port,clk_pin,0);
	DIO_SetPin_Value(port,clk_pin,1);
	for(u8 i =0;i<16;i++){
		if(GET_BIT(binary,i)==1)
		  DIO_SetPin_Value(port,data_pin,1);
		else
			DIO_SetPin_Value(port,data_pin,0);
		//clock trigger
		DIO_SetPin_Value(port,clk_pin,0);
		DIO_SetPin_Value(port,clk_pin,1);

	}

   //latch high
	DIO_SetPin_Value(port,latch_pin,1);

}


