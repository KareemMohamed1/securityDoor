/*
 * system.c
 *
 *  Created on: May 5, 2019
 *      Author: karee
 */

#include"uart.h"
#include"external_eeprom.h"
#define PASS_SIZE 4
uint8 savedPass[PASS_SIZE]={0,0,0,0};
uint8 recievedPass[PASS_SIZE];
uint8 size;
uint8 i;
int main (void){
	EEPROM_init();
	UART_init();
	EEPROM_writeArray(0x0311, recievedPass,size);
	while(1){
		size=UART_recieveByte();
		_delay_ms(50);
		UART_recieveArray(recievedPass,size);
		EEPROM_writeArray(0x0311, recievedPass,size);

	}
}
