/*
 * EXTI_interface.h
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

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_

/*
 * EXTI Modes
 */
#define RISE_EDGE		1
#define FALL_EDGE		2
#define ANY_CHANGE		3
#define LOW_LEVEL		4

/*
 * Interrupt ID
 */
#define INT0			6
#define INT1			7
#define	INT2			5



u8 EXTI_u8EnableEXTI(u8 Copy_u8IntIndex, u8 Copy_u8Mode);
u8 EXTI_u8DisableEXTI(u8 Copy_u8IntIndex);

u8 EXTI_u8SetCallBack(u8 Copy_u8IntIndex, void (* Copy_pf)(void));


#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
