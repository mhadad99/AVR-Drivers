/*
 * KPD_configure.h
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

#ifndef HAL_KPD_KPD_CONFIGURE_H_
#define HAL_KPD_KPD_CONFIGURE_H_

#define KPD_u8_ROWS_PORT		PORTD_ID

#define KPD_u8_R1_PIN			PIN0
#define KPD_u8_R2_PIN			PIN1
#define KPD_u8_R3_PIN			PIN2
#define KPD_u8_R4_PIN			PIN3

/*******************************************/

#define KPD_u8_COLUMNS_PORT		PORTD_ID

#define KPD_u8_C1_PIN			PIN4
#define KPD_u8_C2_PIN			PIN5
#define KPD_u8_C3_PIN			PIN6
#define KPD_u8_C4_PIN			PIN7

#define KPD_KEYS				{{'7', '8', '9', '/'},\
								 {'4', '5', '6', '*'},\
								 {'1', '2', '3', '-'},\
								 {'C', '0', '=', '+'}}

#endif /* HAL_KPD_KPD_CONFIGURE_H_ */
