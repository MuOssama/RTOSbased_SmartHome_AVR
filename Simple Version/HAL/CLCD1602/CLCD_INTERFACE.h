/*
 * CLCD.INTERFACE.h
 *
 *  Created on: Jun 27, 2022
 *      Author: Mustapha
 */

#ifndef HAL_CLCD1602_CLCD_INTERFACE_H_
#define HAL_CLCD1602_CLCD_INTERFACE_H_
#include"../../UTILS/STD_TYPES.h"

void LCD8Bit_init();
void LCD8Bit_Send_Command(u8 command);
void LCD8Bit_Send_Data(u8 data);
/*
void LCD4Bit_init();
void LCD4Bit_Send_Command(u8 command);
void LCD4Bit_Send_Data(u8 data);
*/

void LCD_Send_String(const char* word);
void LCD_GOTOXY(u8 x, u8 y);
void LCD_Save_Character(u8 *arr,u8 block);
void LCD_Display_Character(u8 BlockNumber ,u8 x ,u8 y);
void LCD_Send_Int(u32 num);

#endif /* HAL_CLCD1602_CLCD_INTERFACE_H_ */
