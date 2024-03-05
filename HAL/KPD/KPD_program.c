/*
 * KPD_program.c
 *
 *  Created on: Feb 19, 2024
 *      Author: mhadd
 */
/*********************************************************************************/
/*************************** Name    : Muhammad Haddad ***************************/
/*************************** Date    : 19/02/2024      ***************************/
/*************************** Version : 1.0             ***************************/
/*************************** SWC     : KPD             ***************************/
/*********************************************************************************/

/* LIB Layer */
#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBIT_MATH.h"
#include <avr/delay.h>

/* MCAL Layer */
#include "../../MCAL/DIO/DIO_interface.h"

/* HAL Layer */
#include "KPD_interface.h"
#include "KPD_private.h"
#include "KPD_configure.h"

const u8 KPD_Au8Keys[4][4] = KPD_KEYS;

const u8 KPD_Au8RowsPins[4] = { KPD_u8_R1_PIN, KPD_u8_R2_PIN, KPD_u8_R3_PIN,
		KPD_u8_R4_PIN };
const u8 KPD_Au8ColumnsPins[4] = { KPD_u8_C1_PIN, KPD_u8_C2_PIN, KPD_u8_C3_PIN,
		KPD_u8_C4_PIN };

u8 KPD_u8GetKeyState(u8 * Copy_u8ReturnedKey) {
	u8 Local_u8ErrorState = TRUE;
	u8 Local_u8RowsCounter, Local_u8ColumnsCounter, Local_u8PinValue,
			Local_u8Flag = 0;
	if (Copy_u8ReturnedKey != NULL) {
		*Copy_u8ReturnedKey = 0xff;
		/* Activation Each Row => For loop on the pins of the rows*/
		for (Local_u8RowsCounter = 0; Local_u8RowsCounter <= 3;
				Local_u8RowsCounter++) {
			DIO_u8SetPinValue(KPD_u8_ROWS_PORT,
					KPD_Au8RowsPins[Local_u8RowsCounter], LOW);
			/* Check which Input Pin Has Zero */
			for (Local_u8ColumnsCounter = 0; Local_u8ColumnsCounter <= 3;
					Local_u8ColumnsCounter++) {
				DIO_u8GetPinValue(KPD_u8_COLUMNS_PORT,
						KPD_Au8ColumnsPins[Local_u8ColumnsCounter],
						&Local_u8PinValue);
				if (Local_u8PinValue == LOW) {
					_delay_ms(20);
					while (Local_u8PinValue == LOW) {
						DIO_u8GetPinValue(KPD_u8_COLUMNS_PORT,
								KPD_Au8ColumnsPins[Local_u8ColumnsCounter],
								&Local_u8PinValue);
					}
					*Copy_u8ReturnedKey =
							KPD_Au8Keys[Local_u8RowsCounter][Local_u8ColumnsCounter];
					Local_u8Flag = 1;
					break;
				}
			}
			DIO_u8SetPinValue(KPD_u8_ROWS_PORT,
					KPD_Au8RowsPins[Local_u8RowsCounter], HIGH);
			if (Local_u8Flag == 1) {
				break;
			}
		}
	} else {
		Local_u8ErrorState = FALSE;
	}
	return Local_u8ErrorState;
}
