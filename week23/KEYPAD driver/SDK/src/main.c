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
#include "../include/HAL/LCD/LCD_config.h"
#include "../include/HAL/LCD/LCD_int.h"
#include "../include/HAL/KEYPAD/KEYPAD_config.h"
#include "../include/HAL/KEYPAD/KEYPAD_int.h"


int main (void)
{
	DIO_enumPortInit();
	LCD_enumInit();
	KEYPAD_enumInit();

	u8 Local_u8KeyPressed=KEYPAD_NO_KET_PRESSED;

	while(1)
	{
		KEYPAD_enumGetPressedKey(&Local_u8KeyPressed);
		switch(Local_u8KeyPressed)
		{
			case 'c':
				LCD_enumClear();
			break;

			case KEYPAD_NO_KET_PRESSED:
			break;

			default:
				LCD_enumSendChar(Local_u8KeyPressed);
		};
	}
	return 0;
}

