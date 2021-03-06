 /******************************************************************************
 *
 * Module: External EEPROM
 *
 * File Name: external_eeprom.h
 *
 * Description: Header file for the External EEPROM Memory
 *
 * Author: Kareem Mohamed
 *
 *******************************************************************************/


#ifndef EXTERNAL_EEPROM_H_
#define EXTERNAL_EEPROM_H_

#include "datatypes.h"
#include "dioavrRegisters.h"
#include "util/delay.h"
#include "commonMacros.h"
#include "stdlib.h"
#include "avr/io.h"
#include "avr/interrupt.h"
/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
#define ERROR 0
#define SUCCESS 1

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void EEPROM_init(void);
uint8 EEPROM_writeByte(uint16 u16addr,uint8 u8data);
uint8 EEPROM_writeArray(uint16 u16addr, uint8 * u8data,uint8 size);
uint8 EEPROM_readByte(uint16 u16addr,uint8 *u8data);
uint8 EEPROM_readArray(uint16 u16addr, uint8 *u8data,uint8 size);
 
#endif /* EXTERNAL_EEPROM_H_ */
