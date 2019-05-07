/*
 ============================================================================
 Name        : userinterfaceFunction.h
 Author      : kareem mohamed
 Description : the main source file application for user interface
 	 	 	   with the security door system.
 Date        : 5/5/2019
 ============================================================================
 */

#ifndef USERINTERFACEFUNCTIONS_H_
#define USERINTERFACEFUNCTIONS_H_
#include"lcd.h"
#include"keypad.h"
void start(void);
void getUserNewPassword(uint8 * pass, uint8 * passMatch, uint8 PASS_SIZE);
void checkNewPasswordMatching(uint8 * pass, uint8 * passMatch,uint8 PASS_SIZE);

void getCurrentUserPassword(uint8 * pass,uint8 PASS_SIZE);

void getUserPasswordToOpenDoor(uint8 * pass,uint8 PASS_SIZE);
#endif /* USERINTERFACEFUNCTIONS_H_ */
