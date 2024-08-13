/*
 * main.c
 *
 *  Created on: Aug 12, 2024
 *      Author: abdullahalazhary
 */
#include <util/delay.h>
#include "STDtypes.h"
#include "EMBEDDED_functions.h"

#define DDRA *((volatile u8*)0x3A)
#define PORTA *((volatile u8*)0x3B)
#define PINA *((volatile u8*)0x39)

int main (void)
{
	SET_BIT(DDRA,0);
	SET_BIT(DDRA,1);
	SET_BIT(DDRA,2);
	SET_BIT(DDRA,3);
	SET_BIT(DDRA,4);
	SET_BIT(DDRA,5);

	while(1)
	{
		//D1
		CLEAR_BIT(PORTA,3);
		SET_BIT(PORTA,0);
		SET_BIT(PORTA,4);
		SET_BIT(PORTA,5);
		_delay_ms(500);
		//D2
		CLEAR_BIT(PORTA,0);
		SET_BIT(PORTA,1);
		_delay_ms(500);
		//D3
		CLEAR_BIT(PORTA,1);
		SET_BIT(PORTA,2);
		_delay_ms(500);
		//D6
		CLEAR_BIT(PORTA,4);
		SET_BIT(PORTA,3);
		_delay_ms(500);
		//D9
		CLEAR_BIT(PORTA,5);
		SET_BIT(PORTA,4);
		_delay_ms(500);
		//D8
		CLEAR_BIT(PORTA,2);
		SET_BIT(PORTA,1);
		_delay_ms(500);
		//D7
		CLEAR_BIT(PORTA,1);
		SET_BIT(PORTA,0);
		_delay_ms(500);
		//D4
		SET_BIT(PORTA,5);
		CLEAR_BIT(PORTA,4);
		_delay_ms(500);
	}
	return 0;
}
