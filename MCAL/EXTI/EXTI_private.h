/*
 * EXTI_private.h
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

#ifndef MCAL_EXTI_EXTI_PRIVATE_H_
#define MCAL_EXTI_EXTI_PRIVATE_H_


/* Definitions for Registers of EXTI */

#define EXTI_u8_MCUCR			(*(( volatile u8*)0x55 ))
#define ISC00					0
#define ISC01					1
#define ISC10					2
#define ISC11					3

#define EXTI_u8_MCUCSR			(*(( volatile u8*)0x54 ))
#define ISC2					6

#define EXTI_u8_GICR			(*(( volatile u8*)0x5B ))
//#define INT2					5
//#define INT0					6
//#define INT1					7

#define EXTI_u8_GIFR			(*(( volatile u8*)0x5A ))
#define INTF2					5
#define INTF0					6
#define INTF1					7


#endif /* MCAL_EXTI_EXTI_PRIVATE_H_ */
