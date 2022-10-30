/*
 * DCMOTOR_PROGRAM.c
 *
 *  Created on: Aug 2, 2022
 *      Author: Mustapha
 */
#include "../../MCAL/Timer/TIMER_INTERFACE.h"
#include"../../UTILS/STD_TYPES.h"

void Motor_PWM_8BIT(u8 value){
    SET_OCR0(value);

}
void Motor_MAXSPEED_8BIT(){
    SET_OCR0(255);
}
void Motor_PWM_16BIT(u16 value){
	SET_OCR1A(value);
}
void Motor_MAXSPEED_16BIT(){
	SET_OCR1A(65535);
}
