/*
 ============================================================================
 Name        : lcd.c
 Author      : kareem mohamed
 Description : define the used driver for lcd support 2line lcd for 4 bit mode and 8 bit mode
 Date        : 21/4/2019
 ============================================================================
 */

#include "lcd.h"
#include "stdlib.h"

void LCD_init(void){
	LCD_CTRL_REG_DIR.data |=(1<<PIN_RS)|(1<<PIN_RW)|(1<<PIN_E);
#if(DATA_BIT_MODE ==8)
	LCD_DATA_REG_DIR.data=0xff;
	LCD_sendCommand(TWO_LINE_LCD_Eight_BIT_MODE);
#elif(DATA_BIT_MODE ==4)
	LCD_DATA_REG_DIR.data|= 0xf0;
	LCD_sendCommand(FOUR_BITS_DATA_MODE);
	LCD_sendCommand(TWO_LINE_LCD_FOUR_BIT_MODE);
#endif
	LCD_sendCommand(CURSOR_OFF);
	LCD_sendCommand(CLEAR_COMMAND);
}

void LCD_sendCommand(uint8 a_command){
	LCD_CTRL_REG_PORT.BITS.RS=LOW;
	LCD_CTRL_REG_PORT.BITS.RW=LOW;
#if(DATA_BIT_MODE == 8)
	_delay_ms(1);
	LCD_CTRL_REG_PORT.BITS.E=HIGH; //or we use command  SET_BIT(LCD_CTRL_REG_PORT.data,PIN_E);
	_delay_ms(1);
	LCD_DATA_REG_PORT.data=a_command;
	_delay_ms(1);
	LCD_CTRL_REG_PORT.BITS.E=LOW;
	_delay_ms(1);
#elif(DATA_BIT_MODE ==4)
	_delay_ms(1);
	LCD_CTRL_REG_PORT.BITS.E=HIGH; //or we use command  SET_BIT(LCD_CTRL_REG_PORT.data,PIN_E);
	_delay_ms(1);
	LCD_DATA_REG_PORT.data=(LCD_DATA_REG_PORT.data & 0X0F)|(a_command & 0XF0) ;
	_delay_ms(1);
	LCD_CTRL_REG_PORT.BITS.E=LOW;
	_delay_ms(1);
	LCD_CTRL_REG_PORT.BITS.E=HIGH; //or we use command  SET_BIT(LCD_CTRL_REG_PORT.data,PIN_E);
	_delay_ms(1);
	LCD_DATA_REG_PORT.data=(LCD_DATA_REG_PORT.data & 0X0F)|((a_command& 0X0f)<<4) ;
	_delay_ms(1);
	LCD_CTRL_REG_PORT.BITS.E=LOW;
	_delay_ms(1);
#endif

}

void LCD_sendCharacter(uint8 a_data){
	LCD_CTRL_REG_PORT.BITS.RS=HIGH;
	LCD_CTRL_REG_PORT.BITS.RW=LOW;
#if(DATA_BIT_MODE == 8)
	_delay_ms(1);
	LCD_CTRL_REG_PORT.BITS.E=HIGH; //or we use command  SET_BIT(LCD_CTRL_REG_PORT.data,PIN_E);
	_delay_ms(1);
	LCD_DATA_REG_PORT.data=a_data;
	_delay_ms(1);
	LCD_CTRL_REG_PORT.BITS.E=LOW;
	_delay_ms(1);
#elif(DATA_BIT_MODE ==4)
	_delay_ms(1);
	LCD_CTRL_REG_PORT.BITS.E=HIGH;
	_delay_ms(1);
	LCD_DATA_REG_PORT.data=(LCD_DATA_REG_PORT.data & 0X0F)|(a_data& 0XF0) ;
	_delay_ms(1);
	LCD_CTRL_REG_PORT.BITS.E=LOW;
	_delay_ms(1);
	LCD_CTRL_REG_PORT.BITS.E=HIGH;
	_delay_ms(1);
	LCD_DATA_REG_PORT.data=(LCD_DATA_REG_PORT.data & 0X0F)|((a_data& 0X0f)<<4) ;
	_delay_ms(1);
	LCD_CTRL_REG_PORT.BITS.E=LOW;
	_delay_ms(1);
#endif
}

void LCD_displayString(char *str){
	uint8 i =0;
	while(str[i]!='/0'){
		LCD_sendCharacter(str[i]);
		i++;
	}
}

void LCD_goToRowColumn(uint8 row,uint8 col)
{
	uint8 Address;

	/* first of all calculate the required address */
	switch(row)
	{
		case 0:
				Address=col;
				break;
		case 1:
				Address=col+0x40;
				break;
		case 2:
				Address=col+0x10;
				break;
		case 3:
				Address=col+0x50;
				break;
	}
	/* to write to a specific address in the LCD
	 * we need to apply the corresponding command 0b10000000+Address */
	LCD_sendCommand(Address | SET_CURSOR_LOCATION);
}

void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str)
{
	LCD_goToRowColumn(row,col); /* go to to the required LCD position */
	LCD_displayString(Str); /* display the string */
}

void LCD_intgerToString(int data)
{
   char buff[16]; /* String to hold the ascii result */
   itoa(data,buff,10); /* 10 for decimal */
   LCD_displayString(buff);
}
