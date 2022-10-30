/*
 * TIMER_INTERFACE.h
 *
 *  Created on: Jun 30, 2022
 *      Author: Mustapha
 */

#ifndef MCAL_TIMER_TIMER_INTERFACE_H_
#define MCAL_TIMER_TIMER_INTERFACE_H_
#include"../../UTILS/STD_TYPES.h"

void Timer0_init();
void Timer1_init();
void Timer2_init();

void SET_TCNT0(u8 value);
void SET_OCR0(u8 value);
void SET_TCNT2(u8 value);
void SET_OCR2(u8 value);
void SET_TCNT1(u16 value);
void SET_OCR1A(u16 value);
void SET_OCR1B(u16 value);





#endif /* MCAL_TIMER_TIMER_INTERFACE_H_ */
