/*
 * CLCD.PROGRAM.c
 *
 *  Created on: Jun 27, 2022
 *      Author: Mustapha
 */
#include <avr/delay.h>
#include"../../MCAL/DIO/DIO_INTERFACE.h"
#include "../CLCD1602/CLCD_CONFIG.h"
#include "../CLCD1602/CLCD_INTERFACE.h"

/**************/
/* 8-BIT MODE */
/**************/
void LCD8Bit_Send_Command(u8 command){
	//RW is 0 to Write
    // DIO_SetPin_Value(LCD_Command_Port,LCD_RW_Pin,LOW);
	//RS is 0 to Send COMMAND
     DIO_SetPin_Value(LCD_Command_Port,LCD_RS_Pin,LOW);
	//Send Command
    DIO_SetPort_Value(LCD_Data_Port,command);
	//Enable
    DIO_SetPin_Value(LCD_Command_Port,LCD_ENA_Pin,HIGH);
    _delay_ms(2);
    DIO_SetPin_Value(LCD_Command_Port,LCD_ENA_Pin,LOW);
    _delay_ms(2);

}

void LCD8Bit_Send_Data(u8 data){
	//RW is 0 to Write
    // DIO_SetPin_Value(LCD_Command_Port,LCD_RW_Pin,LOW);
	//RS is 0 to Send DATA
     DIO_SetPin_Value(LCD_Command_Port,LCD_RS_Pin,HIGH);
	//Send Command
    DIO_SetPort_Value(LCD_Data_Port,data);
	//Enable
    DIO_SetPin_Value(LCD_Command_Port,LCD_ENA_Pin,HIGH);
    _delay_ms(2);
    DIO_SetPin_Value(LCD_Command_Port,LCD_ENA_Pin,LOW);
    _delay_ms(2);


}
void LCD8Bit_init(){
    //Wait more than 30 ms
	_delay_ms(40);
	//Function Set
	LCD8Bit_Send_Command(FUNC_SET);
	//ON OFF Control
	LCD8Bit_Send_Command(ON_OFF);
	//Clear
	LCD8Bit_Send_Command(LCD8Bit_CLEAR);
}

/**************/
/* 4-BIT MODE */
/**************/



/***************/
/*LCD FUNCTIONS*/
/***************/
void LCD_Send_String(const char* word){
	u8 cnt = 0;
	while(word[cnt] != '\0'){
		LCD8Bit_Send_Data(word[cnt]);
		cnt++;
	}
}

void LCD_Send_Int(u32 num){
	char arr[10];
	itoa(num,arr,10);
	LCD_Send_String(arr);

}


void LCD_GOTOXY(u8 x, u8 y){
	u8 DDRAM_ADDRESS = 0;
	if(y == 0){
		DDRAM_ADDRESS = x;
	}
	if(y == 1){
	    DDRAM_ADDRESS = x + 0x40;
	}
	LCD8Bit_Send_Command(DDRAM_ADDRESS + 128);
}

void LCD_Save_Character(u8* arr,u8 BlockNumber){
	//Calculate CGRAM ADDRESS
	u8 CGRAM = 0;
	CGRAM = BlockNumber * 8;
	//Write the Character in CGRAM
	LCD8Bit_Send_Command(CGRAM + 64);
	for(u8 i = 0 ;i<8;i++){
		LCD8Bit_Send_Data(arr[i]);
	}

}


void LCD_Display_Character(u8 BlockNumber ,u8 x ,u8 y){
	//Calculate CGRAM ADDRESS
	u8 CGRAM = 0;
	CGRAM = BlockNumber * 8;
	//Write the Character in CGRAM
	LCD8Bit_Send_Command(CGRAM + 64);
	//Goto to print position
	LCD_GOTOXY(x,y);
	//Write the character on the DDRAM (LCD)
	LCD8Bit_Send_Data(BlockNumber);
    }

