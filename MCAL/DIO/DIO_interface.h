/*
 * DIO_interface.h
 *
 *  Created on: Feb 8, 2024
 *      Author: mhadd
 */
/*********************************************************************************/
/*************************** Name    : Muhammad Haddad ***************************/
/*************************** Date    : 08/02/2024      ***************************/
/*************************** Version : 1.0             ***************************/
/*************************** SWC     : DIO             ***************************/
/*********************************************************************************/

#ifndef DIO_DIO_INTERFACE_H_
#define DIO_DIO_INTERFACE_H_

typedef enum {
	PORTA_ID = 0, PORTB_ID, PORTC_ID, PORTD_ID
} port_type;

typedef enum {
	PIN0 = 0, PIN1, PIN2, PIN3, PIN4, PIN5, PIN6, PIN7
} pin_type;

typedef enum {
	LOW = 0, HIGH
} value_type;
typedef enum {
	INPUT = 0, OUTPUT
} direction_type;

void DIO_voidInit(void);
u8 DIO_u8SetPinDirection(u8 Copy_u8PortId, u8 Copy_u8PinId,
		u8 Copy_u8PinDirection);
u8 DIO_u8SetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinValue);
u8 DIO_u8GetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId,
		u8 * Copy_u8ReturnedPinValue);

u8 DIO_u8SetPortDirection(u8 Copy_u8PortId, u8 Copy_u8PortDirection);
u8 DIO_u8SetPortValue(u8 Copy_u8PortId, u8 Copy_u8PortValue);
u8 DIO_u8GetPortValue(u8 Copy_u8PortId, u8 * Copy_u8ReturnedPortValue);

#endif /* DIO_DIO_INTERFACE_H_ */
