/*
 * DIO.c
 *
 *  Created on: Jun 24, 2022
 *      Author: Mustapha
 */
#include "DIO_INTERFACE.H"



void DIO_SetPin_Value(u8 u8_port, u8 u8_pin, u8 value) {
	if (value == HIGH) {
		switch (u8_port) {
		case GroupA:
			SET_BIT(PORTA_REG, u8_pin);
			break;
		case GroupB:
			SET_BIT(PORTB_REG, u8_pin);
			break;
		case GroupC:
			SET_BIT(PORTC_REG, u8_pin);
			break;
		case GroupD:
			SET_BIT(PORTD_REG, u8_pin);
			break;

		}

	}
	else if (value == LOW) {
		switch (u8_port) {
		case GroupA:
			CLR_BIT(PORTA_REG, u8_pin);
			break;
		case GroupB:
			CLR_BIT(PORTB_REG, u8_pin);
			break;
		case GroupC:
			CLR_BIT(PORTC_REG, u8_pin);
			break;
		case GroupD:
			CLR_BIT(PORTD_REG, u8_pin);
			break;
		}
	}
}





void DIO_SetPin_Direction(u8 u8_port, u8 u8_pin, u8 direction) {
	if (direction == OUTPUT) {
		switch (u8_port) {
		case GroupA:
			SET_BIT(DDRA_REG, u8_pin);
			break;
		case GroupB:
			SET_BIT(DDRB_REG, u8_pin);
			break;
		case GroupC:
			SET_BIT(DDRC_REG, u8_pin);
			break;
		case GroupD:
			SET_BIT(DDRD_REG, u8_pin);
			break;

		}

	}
	else if (direction == INPUT) {
		switch (u8_port) {
		case GroupA:
			CLR_BIT(DDRA_REG, u8_pin);
			break;
		case GroupB:
			CLR_BIT(DDRB_REG, u8_pin);
			break;
		case GroupC:
			CLR_BIT(DDRC_REG, u8_pin);
			break;
		case GroupD:
			CLR_BIT(DDRD_REG, u8_pin);
			break;
		}
	}
}







void DIO_SetPort_Value(u8 u8_port,u8 value){
	switch(u8_port){
	case GroupA: PORTA_REG = value;break;
	case GroupB: PORTB_REG = value;break;
	case GroupC: PORTC_REG = value;break;
	case GroupD: PORTD_REG = value;break;

	}

}





void DIO_SetPort_Direction(u8 u8_port,u8 direction){
	switch(u8_port){
	case GroupA: DDRA_REG = direction;break;
	case GroupB: DDRB_REG = direction;break;
	case GroupC: DDRC_REG = direction;break;
	case GroupD: DDRD_REG = direction;break;

	}

}





u8 DIO_GetPinValue(u8 u8_port, u8 u8_pin){
	u8 value = 0;
	switch(u8_port){
	case GroupA:value = GET_BIT(PINA_REG,u8_pin);break;
	case GroupB:value = GET_BIT(PINB_REG,u8_pin);break;
	case GroupC:value = GET_BIT(PINC_REG,u8_pin);break;
	case GroupD:value = GET_BIT(PIND_REG,u8_pin);break;

	}
	return value;
}

