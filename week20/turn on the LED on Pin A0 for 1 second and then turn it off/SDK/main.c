/*
 * main.c
 *
 *  Created on: Aug 11, 2024
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

	SET_BIT(PORTA,0);
	_delay_ms(1000);
	CLEAR_BIT(PORTA,0);

	while(1);
	return 0;
}
