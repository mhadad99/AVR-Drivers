/*
 * LCD_configure.h
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
#ifndef LCD_LCD_CONFIGURE_H_
#define LCD_LCD_CONFIGURE_H_

/* Options : 1- PORTA_ID
 * 			 2- PORTB_ID
 * 			 3- PORTC_ID
 * 			 4- PORTD_ID
 */

#define LCD_u8_CONTROL_PORT			PORTA_ID
#define LCD_u8_RS_PIN				PIN0
#define LCD_u8_RW_PIN				PIN1
#define LCD_u8_E_PIN				PIN2

#define LCD_u8_DATA_PORT			PORTB_ID

#endif /* LCD_LCD_CONFIGURE_H_ */
