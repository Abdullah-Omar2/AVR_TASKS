/*
 * main.c
 *
 *  Created on: Aug 26, 2024
 *      Author: abdullahalazhary
 */
#include <util/delay.h>
#include "../include/LIB/STDtypes.h"
#include "../include/LIB/Error_State.h"
#include "../include/MCAL/DIO/DIO_int.h"
#include "../include/HAL/LCD/LCD_int.h"


int main (void)
{
	LCD_enumInit();

	LCD_enumSendString("abdullah");

	u8 char1[] = {
	  0x00,
	  0x00,
	  0x00,
	  0x03,
	  0x02,
	  0x1F,
	  0x00,
	  0x00
	};

	u8 char2[] = {
	  0x00,
	  0x00,
	  0x00,
	  0x01,
	  0x01,
	  0x1F,
	  0x04,
	  0x00
	};

	u8 char3[] = {
	  0x00,
	  0x00,
	  0x00,
	  0x01,
	  0x01,
	  0x07,
	  0x00,
	  0x00
	};

	u8 char4[] = {
	  0x01,
	  0x01,
	  0x01,
	  0x01,
	  0x01,
	  0x01,
	  0x01,
	  0x00
	};

	u8 char5[] = {
	  0x01,
	  0x01,
	  0x01,
	  0x01,
	  0x01,
	  0x01,
	  0x1F,
	  0x00
	};

	u8 char6[] = {
	  0x07,
	  0x05,
	  0x07,
	  0x01,
	  0x01,
	  0x01,
	  0x01,
	  0x00
	};

	LCD_enumSendCustomChar(0,char1);
	LCD_enumSendCustomChar(1,char2);
	LCD_enumSendCustomChar(2,char3);
	LCD_enumSendCustomChar(3,char4);
	LCD_enumSendCustomChar(4,char5);
	LCD_enumSendCustomChar(5,char6);

	LCD_enumGoTOPosition(2,16);
	LCD_enumSendCommand(0x04);
	LCD_enumSendChar(0);
	LCD_enumSendChar(1);
	LCD_enumSendChar(2);
	LCD_enumSendChar(3);
	LCD_enumSendChar(4);
	LCD_enumSendChar(4);
	LCD_enumSendChar(5);

	_delay_ms(1000);
	LCD_enumClear();

	while(1);
	return 0;
}

