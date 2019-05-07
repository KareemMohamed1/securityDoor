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
#include"avr/wdt.h"
#define PASSWORD_CHANGED 5
#define OPEN_DOOR 3
#define PASS_SIZE 4
uint8 matchFlag;
uint8 pass[PASS_SIZE];
uint8 passMatch[PASS_SIZE];
uint8 PassmatchFlag;
uint8 errorCounter =0;

int main (void){
	UART_init();
	uint8 key;
	start();
	while(TRUE){
		key = KEYPAD_getPressedKey();
		if(key == '*'){
			UART_sendByte('*');
			getCurrentUserPassword(pass,PASS_SIZE);
			UART_sendByte(PASS_SIZE);
			UART_sendArray(pass,PASS_SIZE);
			_delay_ms(50);
			PassmatchFlag = UART_recieveByte();
			if(PassmatchFlag==1){
				LCD_sendCommand(CLEAR_COMMAND);
				LCD_displayString("welcome");
				_delay_ms(500);
				getUserNewPassword( pass,passMatch,PASS_SIZE);
				checkNewPasswordMatching(pass, passMatch, PASS_SIZE);
				UART_sendByte(PASSWORD_CHANGED);
				UART_sendByte(PASS_SIZE);
				UART_sendArray(passMatch,PASS_SIZE);
				if(UART_recieveByte()){
					wdt_enable(1);
					while(1){}
				}
			}
			else{
				LCD_sendCommand(CLEAR_COMMAND);
				LCD_displayString("access denied");
				if(errorCounter<3){
					errorCounter++;
				}
			}
		}
		else if (key == '#'){
			UART_sendByte('#');
			getUserPasswordToOpenDoor(pass,PASS_SIZE);
			UART_sendByte(PASS_SIZE);
			UART_sendArray(pass,PASS_SIZE);
			_delay_ms(50);
			PassmatchFlag = UART_recieveByte();
			if(PassmatchFlag==1){
				LCD_sendCommand(OPEN_DOOR);
				LCD_sendCommand(CLEAR_COMMAND);
				LCD_displayString("welcome");
				_delay_ms(500);
			}
			else{
				LCD_sendCommand(CLEAR_COMMAND);
				LCD_displayString("access denied");
				if(errorCounter<3){
					errorCounter++;
				}
			}

		}
	}
}
