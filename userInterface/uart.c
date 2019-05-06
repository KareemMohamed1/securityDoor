/*
 * uart.c
 *
 *  Created on: May 5, 2019
 *      Author: karee
 */


#include"uart.h"

void UART_init(void){
	UCSRA |=(1<<U2X);
	UCSRB =(1<<RXEN)|(1<<TXEN);
	UCSRC =(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
	UBRRL = 103;
}

void UART_sendByte(uint8 data){
	UDR = data;
	while(BIT_IS_CLEAR(UCSRA,TXC)){}
	SET_BIT(UCSRA,TXC);

}

uint8 UART_recieveByte(void){
	while(BIT_IS_CLEAR(UCSRA,RXC)){}
	return UDR;
}



void UART_sendArray(uint8 *data,uint8 size){
	uint8 i=0;
	while (i<size){
		UART_sendByte(data[i]);
		i++;
	}
}
 void UART_recieveArray(uint8 *data, uint8 size){
	 uint8 i =0;
	 while(i<size){
		 data[i] = UART_recieveByte();
		 i++;
	 }
}
