/*
 ============================================================================
 Name        :keypad.h
 Author      : kareem mohamed
 Description : declration the  functions and interface registers that support 2 types of keypad , 4x4 and 4x3 keypad
 Date        : 21/4/2019
 ============================================================================
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_
/*include the lib used in the drivers*/
#include "datatypes.h"
#include "commonMacros.h"
#include "dioavrRegisters.h"

/******************************************************************/
/* KEYPAD  INTERFACE REGISTER */
#define   KEYPAD_DATA_DIR DDRA_REG
#define   KEYPAD_DATA_OUT PORTA_REG
#define	  KEYPAD_DATA_IN  PINA_REG
/******************************************************************/
/*function prototypes*/
uint8 KEYPAD_getPressedKey(void);
/************************************************************************/
/*keypad types*/
#define NUM_COL 4
#define NUM_ROW 4

#endif /* KEYPAD_H_ */
