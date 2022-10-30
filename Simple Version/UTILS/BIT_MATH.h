/*
 * BIT_MATH.h
 *
 *  Created on: Jun 24, 2022
 *      Author: Mustapha
 */

#ifndef UTILS_BIT_MATH_H_
#define UTILS_BIT_MATH_H_

#define SET_BIT(byte,bit) byte|=(0x01<<bit)
#define CLR_BIT(byte,bit) byte&= ~(0x01<<bit)
#define TOG_BIT(byte,bit) byte^=(0x01<<bit)
#define GET_BIT(byte,bit) (byte>>bit)&0x01

#endif /* UTILS_BIT_MATH_H_ */
