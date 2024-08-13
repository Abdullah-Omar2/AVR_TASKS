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

    char var=0;
	while(1)
	{
		for(var=0;var<=5;var++)
		{
			SET_BIT(PORTA,var);
			_delay_ms(100);
		}
		for(var=0;var<=5;var++)
		{
			CLEAR_BIT(PORTA,var);
			_delay_ms(100);
		}
	}
	return 0;
}

