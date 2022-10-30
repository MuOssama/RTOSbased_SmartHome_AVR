/*
 * UART_REG.h
 *
 *  Created on: Jul 4, 2022
 *      Author: Mustapha
 */

#ifndef MCAL_UART_UART_REG_H_
#define MCAL_UART_UART_REG_H_

#define UDR_REG     *((volatile u8*)0x2C) //Receive/Transmit Register


#define UCSRA_REG   *((volatile u8*)0x2B)
#define UCSRA_UDRE   5       //UDR empty
#define UCSRA_TXC    6       //Transfer Complete
#define UCSRA_RXC    7       //Receive Complete


#define UCSRB_REG   *((volatile u8*)0x2A)
#define UCSRB_UCSZ2  2       //Character size
#define UCSRB_TXEN   3       //transfer enable
#define UCSRB_RXEN   4       //receive enable
#define UCSRB_TXCIE  6       //TX Complete Interrupt Enable
#define UCSRB_RXCIE  7       //RX Complete Interrupt Enable


#define UCSRC_REG   *((volatile u8*)0x40)
#define UCSRC_UCSZ0  1       //Character size
#define UCSRC_UCSZ1  2       //Character size
#define UCSRC_URSEL  7       //UBRRH or UCSRC select

#define UBRRL_REG *((volatile u8*)0x29) //Baud rate Register





#endif /* MCAL_UART_UART_REG_H_ */
