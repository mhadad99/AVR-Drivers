/*
 * LCD_program.c
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

/* LIB Layer */
#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBIT_MATH.h"
#include <avr/delay.h>

/* MCAL Layer */
#include "../../MCAL/DIO/DIO_interface.h"

/* HAL Layer */
#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_configure.h"

void LCD_voidInit() {
	/* Wait > 30ms */
	_delay_ms(35);
	/* Function Set Command */
	LCD_voidSendCommand(0b00111000);
	/* Wait > 39ms */
	_delay_ms(40);
	/* Display ON/OFF Control */
	LCD_voidSendCommand(0b00001111);
	/* Wait > 39ms */
	_delay_ms(40);
	/* Display Clear */
	LCD_voidSendCommand(0b00000001);
	/* Wait > 1.53ms */
	_delay_ms(2);
	/* Entry Mode */
	LCD_voidSendCommand(0b00000110);

}

void LCD_voidSendCommand(u8 Copy_u8Command) {
	/* Make RS = 0 */
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_RS_PIN, LOW);
	/* RW = 0 */
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_RW_PIN, LOW);
	/* Send Command */
	DIO_u8SetPortValue(LCD_u8_DATA_PORT, Copy_u8Command);
	/* E = 1 */
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_E_PIN, HIGH);
	_delay_us(1);
	/* E = 0 */
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_E_PIN, LOW);

}

void LCD_voidSendChar(u8 Copy_u8Char) {
	/* Make RS = 1 */
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_RS_PIN, HIGH);
	/* RW = 0 */
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_RW_PIN, LOW);
	/* Send Char */
	DIO_u8SetPortValue(LCD_u8_DATA_PORT, Copy_u8Char);
	/* E = 1 */
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_E_PIN, HIGH);
	_delay_us(1);
	/* E = 0 */
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT, LCD_u8_E_PIN, LOW);
}

void LCD_voidSendString(u8 * Copy_pu8String) {
	u8 i = 0;
	while (Copy_pu8String[i] != '\0') {
		LCD_voidSendChar(Copy_pu8String[i]);
		i++;
	}
}

void LCD_voidSendNumber(u16 Copy_u16Number) {
	u16 temp = Copy_u16Number;
	u8 arr[10];
	u8 i = 0;
	while (temp != 0) {
		arr[i] = temp % 10;
		temp /= 10;
		i++;
	}

	for (s8 j = i - 1; j >= 0; j--) {
		LCD_voidSendChar(arr[j] + 48);
	}
}

u8 LCD_u8SetPosition(u8 Copy_u8Row, u8 Copy_u8Column) {
	u8 Local_u8ErrorState = TRUE;
	if (Copy_u8Column < 40) {
		switch (Copy_u8Row) {
		case LCD_ROW_1:
			LCD_voidSendCommand(0x80 + Copy_u8Column);
			break;
		case LCD_ROW_2:
			LCD_voidSendCommand(0xc0 + Copy_u8Column);
			break;
		default:
			Local_u8ErrorState = FALSE;
		}
	} else {
		Local_u8ErrorState = FALSE;
	}
	return Local_u8ErrorState;
}

void LCD_voidClearDisplay() {
	LCD_voidSendCommand(0x01);
}
