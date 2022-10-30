/*
 * UART_INTERFACE.H
 *
 *  Created on: Jul 4, 2022
 *      Author: Mustapha
 */

#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_

void UART_init();
void UART_disable();
void UART_enable();


void UART_Send(u8 data);

u8 UART_Receive();
void UART_Receive_String(char* arr);
void UART_SEND_String(const char* arr);




#endif /* MCAL_UART_UART_INTERFACE_H_ */
