/*
 * EXTI_program.c
 *
 *  Created on: Feb 28, 2024
 *      Author: mhadd
 */
/*********************************************************************************/
/*************************** Name    : Muhammad Haddad ***************************/
/*************************** Date    : 28/02/2024      ***************************/
/*************************** Version : 1.0             ***************************/
/*************************** SWC     : EXTI            ***************************/
/*********************************************************************************/

/*
 * LIB Layer
 */
#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBIT_MATH.h"

/*
 * MCAL Layer
 */
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_configure.h"


/*
 * Global Pointer to Function
 */

static void (* EXTI_AptEXTI[3])(void) = {NULL, NULL, NULL};


u8 EXTI_u8EnableEXTI(u8 Copy_u8IntIndex, u8 Copy_u8Mode){
	u8 Local_u8ErrorState = TRUE;

	switch(Copy_u8IntIndex){
	case INT0 :
		switch (Copy_u8Mode){
		case RISE_EDGE :
			SET_BIT(EXTI_u8_MCUCR, ISC00);
			SET_BIT(EXTI_u8_MCUCR, ISC01);
			/*
			 * Enable EXTI 0
			 */
			SET_BIT(EXTI_u8_GICR, INT0);
			break;
		case FALL_EDGE :
			CLR_BIT(EXTI_u8_MCUCR, ISC00);
			SET_BIT(EXTI_u8_MCUCR, ISC01);
			/*
			 * Enable EXTI 0
			 */
			SET_BIT(EXTI_u8_GICR, INT0);
			break;
		case ANY_CHANGE :
			SET_BIT(EXTI_u8_MCUCR, ISC00);
			CLR_BIT(EXTI_u8_MCUCR, ISC01);
			/*
			 * Enable EXTI 0
			 */
			SET_BIT(EXTI_u8_GICR, INT0);
			break;
		case LOW_LEVEL :
			CLR_BIT(EXTI_u8_MCUCR, ISC00);
			CLR_BIT(EXTI_u8_MCUCR, ISC01);
			/*
			 * Enable EXTI 0
			 */
			SET_BIT(EXTI_u8_GICR, INT0);
			break;
		default : Local_u8ErrorState = FALSE;
		}
		break;
	case INT1 :
		switch (Copy_u8Mode){
		case RISE_EDGE :
			SET_BIT(EXTI_u8_MCUCR, ISC10);
			SET_BIT(EXTI_u8_MCUCR, ISC11);
			/*
			 * Enable EXTI 1
			 */
			SET_BIT(EXTI_u8_GICR, INT1);
			break;
		case FALL_EDGE :
			CLR_BIT(EXTI_u8_MCUCR, ISC10);
			SET_BIT(EXTI_u8_MCUCR, ISC11);
			/*
			 * Enable EXTI 1
			 */
			SET_BIT(EXTI_u8_GICR, INT1);
			break;
		case ANY_CHANGE :
			SET_BIT(EXTI_u8_MCUCR, ISC10);
			CLR_BIT(EXTI_u8_MCUCR, ISC11);
			/*
			 * Enable EXTI 1
			 */
			SET_BIT(EXTI_u8_GICR, INT1);
			break;
		case LOW_LEVEL :
			CLR_BIT(EXTI_u8_MCUCR, ISC10);
			CLR_BIT(EXTI_u8_MCUCR, ISC11);
			/*
			 * Enable EXTI 1
			 */
			SET_BIT(EXTI_u8_GICR, INT1);
			break;
		default : Local_u8ErrorState = FALSE;
		}
		break;
	case INT2 :
		switch (Copy_u8Mode) {
			case FALL_EDGE:
				CLR_BIT(EXTI_u8_MCUCSR, ISC2);
				/*
				 * Enable EXTI 2
				 */
				SET_BIT(EXTI_u8_GICR, INT2);
				break;
			case RISE_EDGE:
				SET_BIT(EXTI_u8_MCUCSR, ISC2);
				/*
				 * Enable EXTI 2
				 */
				SET_BIT(EXTI_u8_GICR, INT2);
				break;
			default: Local_u8ErrorState = FALSE;
				break;
		}
		break;
	default : Local_u8ErrorState = FALSE;

	}

	return Local_u8ErrorState;
}
u8 EXTI_u8DisableEXTI(u8 Copy_u8IntIndex){
	u8 Local_u8ErrorState = TRUE;

	switch ( Copy_u8IntIndex){
	case INT0 :
		CLR_BIT(EXTI_u8_GICR, INT0);
		break;
	case INT1 :
		CLR_BIT(EXTI_u8_GICR, INT1);
		break;
	case INT2 :
		CLR_BIT(EXTI_u8_GICR, INT2);
		break;
	default : Local_u8ErrorState = FALSE;
	}

	return Local_u8ErrorState;
}
/*
 * Set Call Back Function
 */
u8 EXTI_u8SetCallBack(u8 Copy_u8IntIndex, void (* Copy_pf)(void)){
	u8 Local_u8ErrorState = TRUE;
	if(Copy_u8IntIndex <= 2 && Copy_pf != NULL){
		EXTI_AptEXTI[Copy_u8IntIndex] = Copy_pf;
	}else {
		Local_u8ErrorState = FALSE;
	}
	return Local_u8ErrorState;
}

/*
 * Prototype for ISR of EXTI0
 */
void __vector_1(void) __attribute__((signal));
void __vector_1(void){

	if(EXTI_AptEXTI[0] != NULL){
		EXTI_AptEXTI[0]();
	}


}

/*
 * Prototype for ISR of EXTI1
 */
void __vector_2(void) __attribute__((signal));
void __vector_2(void){

	if(EXTI_AptEXTI[1] != NULL){
		EXTI_AptEXTI[1]();
	}

}

/*
 * Prototype for ISR of EXTI2
 */
void __vector_3(void) __attribute__((signal));
void __vector_3(void) {
	if(EXTI_AptEXTI[2] != NULL){
		EXTI_AptEXTI[2]();
	}
}


