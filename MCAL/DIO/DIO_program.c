/*
 * DIO_program.c
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

/* LIB Layer */
#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBIT_MATH.h"

/* MCAL Layer */
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

void DIO_voidInit(void) {
	DIO_u8_DDRA_REG = Conc(DIO_u8_PA7_INTIAL_DIRECTION,
			DIO_u8_PA6_INTIAL_DIRECTION, DIO_u8_PA5_INTIAL_DIRECTION,
			DIO_u8_PA4_INTIAL_DIRECTION, DIO_u8_PA3_INTIAL_DIRECTION,
			DIO_u8_PA2_INTIAL_DIRECTION, DIO_u8_PA1_INTIAL_DIRECTION,
			DIO_u8_PA0_INTIAL_DIRECTION);

	DIO_u8_DDRB_REG = Conc(DIO_u8_PB7_INTIAL_DIRECTION,
			DIO_u8_PB6_INTIAL_DIRECTION, DIO_u8_PB5_INTIAL_DIRECTION,
			DIO_u8_PB4_INTIAL_DIRECTION, DIO_u8_PB3_INTIAL_DIRECTION,
			DIO_u8_PB2_INTIAL_DIRECTION, DIO_u8_PB1_INTIAL_DIRECTION,
			DIO_u8_PB0_INTIAL_DIRECTION);

	DIO_u8_DDRC_REG = Conc(DIO_u8_PC7_INTIAL_DIRECTION,
			DIO_u8_PC6_INTIAL_DIRECTION, DIO_u8_PC5_INTIAL_DIRECTION,
			DIO_u8_PC4_INTIAL_DIRECTION, DIO_u8_PC3_INTIAL_DIRECTION,
			DIO_u8_PC2_INTIAL_DIRECTION, DIO_u8_PC1_INTIAL_DIRECTION,
			DIO_u8_PC0_INTIAL_DIRECTION);

	DIO_u8_DDRD_REG = Conc(DIO_u8_PD7_INTIAL_DIRECTION,
			DIO_u8_PD6_INTIAL_DIRECTION, DIO_u8_PD5_INTIAL_DIRECTION,
			DIO_u8_PD4_INTIAL_DIRECTION, DIO_u8_PD3_INTIAL_DIRECTION,
			DIO_u8_PD2_INTIAL_DIRECTION, DIO_u8_PD1_INTIAL_DIRECTION,
			DIO_u8_PD0_INTIAL_DIRECTION);

	DIO_u8_PORTA_REG = Conc(DIO_u8_PA7_INTIAL_VALUE, DIO_u8_PA6_INTIAL_VALUE,
			DIO_u8_PA5_INTIAL_VALUE, DIO_u8_PA4_INTIAL_VALUE,
			DIO_u8_PA3_INTIAL_VALUE, DIO_u8_PA2_INTIAL_VALUE,
			DIO_u8_PA1_INTIAL_VALUE, DIO_u8_PA0_INTIAL_VALUE);

	DIO_u8_PORTB_REG = Conc(DIO_u8_PB7_INTIAL_VALUE, DIO_u8_PB6_INTIAL_VALUE,
			DIO_u8_PB5_INTIAL_VALUE, DIO_u8_PB4_INTIAL_VALUE,
			DIO_u8_PB3_INTIAL_VALUE, DIO_u8_PB2_INTIAL_VALUE,
			DIO_u8_PB1_INTIAL_VALUE, DIO_u8_PB0_INTIAL_VALUE);

	DIO_u8_PORTC_REG = Conc(DIO_u8_PC7_INTIAL_VALUE, DIO_u8_PC6_INTIAL_VALUE,
			DIO_u8_PC5_INTIAL_VALUE, DIO_u8_PC4_INTIAL_VALUE,
			DIO_u8_PC3_INTIAL_VALUE, DIO_u8_PC2_INTIAL_VALUE,
			DIO_u8_PC1_INTIAL_VALUE, DIO_u8_PC0_INTIAL_VALUE);

	DIO_u8_PORTD_REG = Conc(DIO_u8_PD7_INTIAL_VALUE, DIO_u8_PD6_INTIAL_VALUE,
			DIO_u8_PD5_INTIAL_VALUE, DIO_u8_PD4_INTIAL_VALUE,
			DIO_u8_PD3_INTIAL_VALUE, DIO_u8_PD2_INTIAL_VALUE,
			DIO_u8_PD1_INTIAL_VALUE, DIO_u8_PD0_INTIAL_VALUE);
}

u8 DIO_u8SetPinDirection(u8 Copy_u8PortId, u8 Copy_u8PinId,
		u8 Copy_u8PinDirection) {
	u8 Local_u8ErrorState = TRUE;
	if ((Copy_u8PortId <= PORTD_ID) && (Copy_u8PinId <= PIN7)
			&& ((Copy_u8PinDirection == OUTPUT)
					|| (Copy_u8PinDirection == INPUT))) {
		switch (Copy_u8PinDirection) {
		case OUTPUT:
			switch (Copy_u8PortId) {
			case PORTA_ID:
				SET_BIT(DIO_u8_DDRA_REG, Copy_u8PinId);
				break;
			case PORTB_ID:
				SET_BIT(DIO_u8_DDRB_REG, Copy_u8PinId);
				break;
			case PORTC_ID:
				SET_BIT(DIO_u8_DDRC_REG, Copy_u8PinId);
				break;
			case PORTD_ID:
				SET_BIT(DIO_u8_DDRD_REG, Copy_u8PinId);
				break;
			}
			break;
		case INPUT:
			switch (Copy_u8PortId) {
			case PORTA_ID:
				CLR_BIT(DIO_u8_DDRA_REG, Copy_u8PinId);
				break;
			case PORTB_ID:
				CLR_BIT(DIO_u8_DDRB_REG, Copy_u8PinId);
				break;
			case PORTC_ID:
				CLR_BIT(DIO_u8_DDRC_REG, Copy_u8PinId);
				break;
			case PORTD_ID:
				CLR_BIT(DIO_u8_DDRD_REG, Copy_u8PinId);
				break;
			}
			break;
		}
	} else {
		Local_u8ErrorState = FALSE;
	}
	return Local_u8ErrorState;
}
u8 DIO_u8SetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinValue) {
	u8 Local_u8ErrorState = TRUE;
	if (Copy_u8PinId <= PIN7) {
		switch (Copy_u8PinValue) {
		case HIGH:
			switch (Copy_u8PortId) {
			case PORTA_ID:
				SET_BIT(DIO_u8_PORTA_REG, Copy_u8PinId);
				break;
			case PORTB_ID:
				SET_BIT(DIO_u8_PORTB_REG, Copy_u8PinId);
				break;
			case PORTC_ID:
				SET_BIT(DIO_u8_PORTC_REG, Copy_u8PinId);
				break;
			case PORTD_ID:
				SET_BIT(DIO_u8_PORTD_REG, Copy_u8PinId);
				break;
			default:
				Local_u8ErrorState = FALSE;
			}
			break;

		case LOW:
			switch (Copy_u8PortId) {
			case PORTA_ID:
				CLR_BIT(DIO_u8_PORTA_REG, Copy_u8PinId);
				break;
			case PORTB_ID:
				CLR_BIT(DIO_u8_PORTB_REG, Copy_u8PinId);
				break;
			case PORTC_ID:
				CLR_BIT(DIO_u8_PORTC_REG, Copy_u8PinId);
				break;
			case PORTD_ID:
				CLR_BIT(DIO_u8_PORTD_REG, Copy_u8PinId);
				break;
			default:
				Local_u8ErrorState = FALSE;
			}
			break;
		default:
			Local_u8ErrorState = FALSE;
		}
	} else {
		Local_u8ErrorState = FALSE;
	}
	return Local_u8ErrorState;
}
u8 DIO_u8GetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId,
		u8 * Copy_pu8ReturnedPinValue) {
	u8 Local_u8ErrorState = TRUE;
	if ((Copy_u8PortId <= PORTD_ID) && (Copy_u8PinId <= PIN7)
			&& (Copy_pu8ReturnedPinValue != NULL)) {
		switch (Copy_u8PortId) {
		/***check port id********Get bit value******************if pin = 1  the value =1 not value =0******************  */
		case PORTA_ID:
			GET_BIT(DIO_u8_PINA_REG, Copy_u8PinId) ?
					(*Copy_pu8ReturnedPinValue = HIGH) :
					(*Copy_pu8ReturnedPinValue = LOW);
			break;
		case PORTB_ID:
			GET_BIT(DIO_u8_PINB_REG, Copy_u8PinId) ?
					(*Copy_pu8ReturnedPinValue = HIGH) :
					(*Copy_pu8ReturnedPinValue = LOW);
			break;
		case PORTC_ID:
			GET_BIT(DIO_u8_PINC_REG, Copy_u8PinId) ?
					(*Copy_pu8ReturnedPinValue = HIGH) :
					(*Copy_pu8ReturnedPinValue = LOW);
			break;
		case PORTD_ID:
			GET_BIT(DIO_u8_PIND_REG, Copy_u8PinId) ?
					(*Copy_pu8ReturnedPinValue = HIGH) :
					(*Copy_pu8ReturnedPinValue = LOW);
			break;
		}
	} else {
		Local_u8ErrorState = FALSE;
	}
	return Local_u8ErrorState;
}
u8 DIO_u8SetPortDirection(u8 Copy_u8PortId, u8 Copy_u8PortDirection) {
	u8 Local_u8ErrorState = TRUE;
	switch (Copy_u8PortDirection) {
	case OUTPUT:
		switch (Copy_u8PortId) {
		case PORTA_ID:
			DIO_u8_DDRA_REG = 0xff;
			break;
		case PORTB_ID:
			DIO_u8_DDRB_REG = 0xff;
			break;
		case PORTC_ID:
			DIO_u8_DDRC_REG = 0xff;
			break;
		case PORTD_ID:
			DIO_u8_DDRD_REG = 0xff;
			break;
		default:
			Local_u8ErrorState = FALSE;
		}
		break;
	case INPUT:
		switch (Copy_u8PortId) {
		case PORTA_ID:
			DIO_u8_DDRA_REG = 0x00;
			break;
		case PORTB_ID:
			DIO_u8_DDRB_REG = 0x00;
			break;
		case PORTC_ID:
			DIO_u8_DDRC_REG = 0x00;
			break;
		case PORTD_ID:
			DIO_u8_DDRD_REG = 0x00;
			break;
		default:
			Local_u8ErrorState = FALSE;
		}
		break;
	default:
		Local_u8ErrorState = FALSE;
	}
	return Local_u8ErrorState;
}
u8 DIO_u8SetPortValue(u8 Copy_u8PortId, u8 Copy_u8PortValue) {
	u8 Local_u8ErrorState = TRUE;
	switch (Copy_u8PortId) {
	case PORTA_ID:
		DIO_u8_PORTA_REG = Copy_u8PortValue;
		break;
	case PORTB_ID:
		DIO_u8_PORTB_REG = Copy_u8PortValue;
		break;
	case PORTC_ID:
		DIO_u8_PORTC_REG = Copy_u8PortValue;
		break;
	case PORTD_ID:
		DIO_u8_PORTD_REG = Copy_u8PortValue;
		break;
	default:
		Local_u8ErrorState = FALSE;
	}
	return Local_u8ErrorState;
}
u8 DIO_u8GetPortValue(u8 Copy_u8PortId, u8 * Copy_pu8ReturnedPortValue) {
	u8 Local_u8ErrorState = TRUE;
	if (Copy_pu8ReturnedPortValue != NULL) {
		switch (Copy_u8PortId) {
		case PORTA_ID:
			*Copy_pu8ReturnedPortValue = DIO_u8_PINA_REG;
			break;
		case PORTB_ID:
			*Copy_pu8ReturnedPortValue = DIO_u8_PINB_REG;
			break;
		case PORTC_ID:
			*Copy_pu8ReturnedPortValue = DIO_u8_PINC_REG;
			break;
		case PORTD_ID:
			*Copy_pu8ReturnedPortValue = DIO_u8_PIND_REG;
			break;
		default:
			Local_u8ErrorState = FALSE;
		}
	} else {
		Local_u8ErrorState = FALSE;
	}
	return Local_u8ErrorState;
}

