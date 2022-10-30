/*
 * DIO.H
 *
 *  Created on: Jun 24, 2022
 *      Author: Mustapha
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_
#include"../../UTILS/STD_TYPES.h"
#include"../../UTILS/BIT_MATH.h"
#include"DIO_REG.h"


void DIO_SetPin_Value(u8 u8_port, u8 u8_pin, u8 value);
void DIO_SetPin_Direction(u8 u8_port, u8 u8_pin, u8 direction);
void DIO_SetPort_Value(u8 u8_port,u8 value);
void DIO_SetPort_Direction(u8 u8_port,u8 value);
u8 DIO_GetPinValue(u8 u8_port, u8 u8_pin);



#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
