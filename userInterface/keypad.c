/*
 ============================================================================
 Name        :keypad.c
 Author      : kareem mohamed
 Description : define the  driver that support 2 types of keypad , 4x4 and 4x3 keypad
 Date        : 21/4/2019
 ============================================================================
 */

#include"keypad.h"
/*****************************************************************/
/*private functions prototypes*/
#if(NUM_COL==4)
static uint8 KEYPAD_4x4_keyNumber(uint8 a_buttonNumber);
#elif(NUM_COL==3)
static uint8 KEYPAD_4x3_keyNumber(uint8 a_buttonNumber);
#endif
/*****************************************************************/


/*	uint8 KEYPAD_getPressedKey(void)  is used to return the pressed key on the keypad*/
uint8 KEYPAD_getPressedKey(void){
	while(1){
		uint8 col,row;
		for(col=0;col<NUM_COL;col++){
			/*we cleared first 4 pins to be input and set last 4 bits to be output*/
			KEYPAD_DATA_DIR.data =0b00010000 <<(col);
			/*enable the internal pull up resistors to the input pins
			 * and loop for the 4 output pins to set high value in each pin*/
			KEYPAD_DATA_OUT.data =~(0b00010000 <<(col));
			/*loop in rows to check which key is pressed*/
			for(row=0;row<NUM_ROW;row++){
				if(BIT_IS_CLEAR(KEYPAD_DATA_IN.data,row)){
#if(NUM_COL ==4)
					return KEYPAD_4x4_keyNumber((row*NUM_COL)+col+1);
#elif(NUM_COL ==3)
					return KEYPAD_4x3_keyNumber((row*NUM_COL)+col+1);
#endif
				}
			}

		}
	}
}

#if(NUM_COL ==4)
static uint8 KEYPAD_4x4_keyNumber(uint8 a_buttonNumber){
	switch(a_buttonNumber){
	case 1: return 7;
	break;
	case 2: return 8;
	break;
	case 3: return 9;
	break;
	case 4: return '/';
	break;
	case 5: return 4;
	break;
	case 6: return 5;
	break;
	case 7: return 6;
	break;
	case 8: return '*';
	break;
	case 9: return 1;
	break;
	case 10: return 2;
	break;
	case 11: return 3;
	break;
	case 12: return '-';
	break;
	case 13: return '0';
	break;
	case 14: return 0;
	break;
	case 15: return '=';
	break;
	case 16: return'+';
	break;
	default: return 0;
	break;
	}
}
#elif(NUM_COL ==3)
static uint8 KEYPAD_4x3_keyNumber(uint8 a_buttonNumber){
	switch(a_buttonNumber){
	case 10: return '*';
	break;
	case 11: return 0;
	break;
	case 12: return '#';
	break;
	default : return a_buttonNumber ;
	}
}
#endif

