/*
 * GI_program.c
 *
 *  Created on: Mar 2, 2024
 *      Author: mhadd
 */
/*********************************************************************************/
/*************************** Name    : Muhammad Haddad ***************************/
/*************************** Date    : 01/03/2024      ***************************/
/*************************** Version : 1.0             ***************************/
/*************************** SWC     : GI              ***************************/
/*********************************************************************************/

/*
 * LIB Layer
 */
#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBIT_MATH.h"

/* MCAL Layer */
#include "GI_interface.h"
#include "GI_private.h"


void GI_voidEnable(){

	SET_BIT(GI_u8_SREG, I_BIT);
}

void GI_voidDisable(){

	CLR_BIT(GI_u8_SREG, I_BIT);
}
