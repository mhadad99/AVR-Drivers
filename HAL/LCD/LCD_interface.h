/*
 * LCD_interface.h
 *
 *  Created on: Feb 14, 2024
 *      Author: mhadd
 */
/*********************************************************************************/
/*************************** Name    : Muhammad Haddad ***************************/
/*************************** Date    : 14/02/2024      ***************************/
/*************************** Version : 1.0             ***************************/
/*************************** SWC     : LCD             ***************************/
/*********************************************************************************/
#ifndef LCD_LCD_INTERFACE_H_
#define LCD_LCD_INTERFACE_H_

#define LCD_ROW_1		0
#define LCD_ROW_2		1

void LCD_voidInit();
void LCD_voidSendCommand(u8 Copy_u8Command);
void LCD_voidSendChar(u8 Copy_u8Char);
void LCD_voidSendString(u8 * Copy_pu8String);
void LCD_voidSendNumber(u16 Copy_u16Number);
u8 LCD_u8SetPosition(u8 Copy_u8Row, u8 Copy_u8Column);
void LCD_voidClearDisplay();

#endif /* LCD_LCD_INTERFACE_H_ */
