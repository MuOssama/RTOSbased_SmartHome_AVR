/*
 * Buzzer_program.c
 *
 *  Created on: Aug 1, 2022
 *      Author: Mustapha
 */
#include"../../MCAL/DIO/DIO_INTERFACE.h"
#include"../../MCAL/DIO/DIO_REG.h"
#include <avr/delay.h>

#include "../../Config.h"


void BuzzerON(){
  DIO_SetPin_Value(BuzzerPort,BuzzerPin,HIGH);
}
void BuzzerOFF(){
	  DIO_SetPin_Value(BuzzerPort,BuzzerPin,LOW);

}
void BuzzerTOGGLE(u32 ontime){
	BuzzerON();
    _delay_ms(ontime);
	BuzzerOFF();
}
