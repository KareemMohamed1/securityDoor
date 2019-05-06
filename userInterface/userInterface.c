/*
 ============================================================================
 Name        : userInterface.c
 Author      : kareem mohamed
 Description : the main source file application for user interface
 	 	 	   with the security door system.
 Date        : 5/5/2019
 ============================================================================
 */

#include"userinterfaceFunctions.h"
#include"uart.h"
#define PASS_SIZE 4
uint8 matchFlag;
uint8 pass[PASS_SIZE];
uint8 passMatch[PASS_SIZE];
uint8 currentPass[PASS_SIZE]={1,2,4,8};


int main (void){
	UART_init();
	uint8 key;
	start();
	while(TRUE){
		key = KEYPAD_getPressedKey();
		if(key == '*'){
			getCurrentUserPassword(pass,PASS_SIZE);
			UART_sendByte(PASS_SIZE);
			_delay_ms(50);
			UART_sendArray(pass,PASS_SIZE);
			_delay_ms(500);
			matchFlag = UART_recieveByte();
			if(matchFlag==TRUE){
				getUserNewPassword( pass,passMatch,PASS_SIZE);
				checkNewPasswordMatching(pass, passMatch,currentPass,PASS_SIZE);
				UART_sendArray(currentPass,PASS_SIZE);
			}

		}
		else if (key == '#'){
			getUserPasswordToOpenDoor(pass,PASS_SIZE);

		}
	}
}
