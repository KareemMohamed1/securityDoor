/*
 * uart.h
 *
 *  Created on: May 5, 2019
 *      Author: karee
 */

#ifndef UART_H_
#define UART_H_

#include "datatypes.h"
#include "dioavrRegisters.h"
#include "util/delay.h"
#include "commonMacros.h"
#include "stdlib.h"
#include "avr/io.h"
#include "avr/interrupt.h"

void UART_init(void);
void UART_sendByte(uint8 data);
uint8 UART_recieveByte(void);
void UART_sendArray(uint8 *data,uint8 size);
void UART_recieveArray(uint8 *data,uint8 size);
#endif /* UART_H_ */
