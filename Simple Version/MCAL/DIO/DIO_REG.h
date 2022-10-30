/*
 * DIO_REG.h
 *
 *  Created on: Jun 24, 2022
 *      Author: Mustapha
 */

#ifndef MCAL_DIO_DIO_REG_H_
#define MCAL_DIO_DIO_REG_H_

//PORTA
#define PORTA_REG *((volatile u8*)0x3B)
#define DDRA_REG  *((volatile u8*)0x3A)
#define PINA_REG  *((volatile u8*)0x39)

//PORTB
#define PORTB_REG *((volatile u8*)0x38)
#define DDRB_REG  *((volatile u8*)0x37)
#define PINB_REG  *((volatile u8*)0x36)

//PORTC
#define PORTC_REG *((volatile u8*)0x35)
#define DDRC_REG  *((volatile u8*)0x34)
#define PINC_REG  *((volatile u8*)0x33)

//PORTD
#define PORTD_REG *((volatile u8*)0x32)
#define DDRD_REG  *((volatile u8*)0x31)
#define PIND_REG  *((volatile u8*)0x30)

//PORTS
#define GroupA 0
#define GroupB 1
#define GroupC 2
#define GroupD 3

//PINS
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7



#define HIGH 1
#define LOW 0
#define OUTPUT 1
#define INPUT 0


#endif /* MCAL_DIO_DIO_REG_H_ */
