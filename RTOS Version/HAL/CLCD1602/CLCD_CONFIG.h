/*
 * CLCD.CONFIG.h
 *
 *  Created on: Jun 27, 2022
 *      Author: Mustapha
 */

#ifndef HAL_CLCD1602_CLCD_CONFIG_H_
#define HAL_CLCD1602_CLCD_CONFIG_H_

/* COMMANDS SHORTCUT */
#define LCD8Bit_CLEAR 0x01

/* CONNECTIONS */
#define LCD_Data_Port     GroupC
#define LCD_Command_Port  GroupA
#define LCD_RS_Pin        0
#define LCD_RW_Pin        2
#define LCD_ENA_Pin       1


/* Choose State of Cursor */
#define ON_OFF            ON_OFF_NoCursor
/* OPTIONS */
#define ON_OFF_Blink      0b0001111        //for cursor blink
#define ON_OFF_NoBlink    0b0001110        //for cursor without blink
#define ON_OFF_NoCursor   0b0001100        //for no cursor

/* Choose Function Set */
#define FUNC_SET FUNC_SET_2Line_5x8
/* OPTIONS */
#define FUNC_SET_1Line_5x8  0b00110000     //Display on 1 Line and 5*8 size
#define FUNC_SET_2Line_5x8  0b00111000     //Display on 2 Line and 5*8 size
#define FUNC_SET_1Line_5x11 0b00110111     //Display on 1 Line and 5*11 size
#define FUNC_SET_2Line_5x11 0b00111111     //Display on 2 Line and 5*11 size





#endif /* HAL_CLCD1602_CLCD_CONFIG_H_ */
