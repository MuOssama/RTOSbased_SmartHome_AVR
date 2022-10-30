#include"../../UTILS/STD_TYPES.h"
#include"../../UTILS/BIT_MATH.h"
#include"UART_INTERFACE.h"
#include"UART_REG.h"
#include"../../HAL/CLCD1602/CLCD_INTERFACE.h"

void UART_init() {

	/*Character Select*/
	CLR_BIT(UCSRB_REG, UCSRB_UCSZ2);
	u8 UCRSC = 0;
	SET_BIT(UCRSC, UCSRC_UCSZ0);
	SET_BIT(UCRSC, UCSRC_UCSZ1);
	SET_BIT(UCRSC, UCSRC_URSEL);
	UCSRC_REG = UCRSC;
	/*Baud rate 9600*/
	UBRRL_REG = 51;
	/*Rx and Tx enable*/
	SET_BIT(UCSRB_REG, UCSRB_TXEN);
	SET_BIT(UCSRB_REG, UCSRB_RXEN);
	/*interrupt enable*/
	//SET_BIT(UCSRB_REG, UCSRB_RXCIE);
	//SET_BIT(UCSRB_REG, UCSRB_TXCIE);
}

u8 UART_Receive() {
	while (GET_BIT(UCSRA_REG,UCSRA_RXC) == 0)
		;
	return UDR_REG;

}
void UART_Send(u8 data) {
	while (GET_BIT(UCSRA_REG,UCSRA_UDRE) == 0)
		;
	UDR_REG = data;
}
void UART_RXFlAG_down() {
	SET_BIT(UCSRA_REG, UCSRA_RXC);
}

void UART_Receive_String(char* arr) {
	char ca;
	for (u8 j = 0; j < 5; j++) {
		ca = UART_Receive();
		if (ca >= '1' && ca <= 'z') {
			LCD8Bit_Send_Data(ca);
			arr[j] = ca;
		}
	}
	if (ca == '*') {
		for (u8 k = 0;k < 4; k++)
			LCD8Bit_Send_Data(arr[k]);

	}

}
void UART_SEND_String(const char* arr){
	u8 i = 0;
   while(arr[i]!='\0'){
	   UART_Send(arr[i]);
	   i++;
   }
}
void UART_disable() {
	CLR_BIT(UCSRB_REG, UCSRB_RXEN);
}
void UART_enable() {
	SET_BIT(UCSRB_REG, UCSRB_RXEN);

}
