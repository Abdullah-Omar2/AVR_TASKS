/*
 * main.c
 *
 *  Created on: Aug 14, 2024
 *      Author: abdullahalazhary
 */
#include <util/delay.h>
#include "STDtypes.h"
#include "EMBEDDED_functions.h"

#define PINA *((volatile u8*)0x39)
#define DDRA *((volatile u8*)0x3A)
#define PORTA *((volatile u8*)0x3B)

#define PINB *((volatile u8*)0x36)
#define DDRB *((volatile u8*)0x37)
#define PORTB *((volatile u8*)0x38)

#define PINC *((volatile u8*)0x33)
#define DDRC *((volatile u8*)0x34)
#define PORTC *((volatile u8*)0x35)

#define PIND *((volatile u8*)0x30)
#define DDRD *((volatile u8*)0x31)
#define PORTD *((volatile u8*)0x32)

int main (void)
{
	SET_BIT(DDRA,0);
	SET_BIT(DDRA,1);

	CLEAR_BIT(DDRB,0);
	CLEAR_BIT(DDRB,1);
	CLEAR_BIT(DDRB,2);

	SET_BIT(PORTB,0);
	SET_BIT(PORTB,1);
	SET_BIT(PORTB,2);

	while(1)
	{
		if(READ_BIT(PINB,0)==0)SET_BIT(PORTA,0);
		if(READ_BIT(PINB,0)==1)CLEAR_BIT(PORTA,0);
		if(READ_BIT(PINB,1)==0)SET_BIT(PORTA,1);
		if(READ_BIT(PINB,1)==1)CLEAR_BIT(PORTA,1);
		if(READ_BIT(PINB,2)==0){SET_BIT(PORTA,0);SET_BIT(PORTA,1);}
		if(READ_BIT(PINB,2)==1){CLEAR_BIT(PORTA,0);CLEAR_BIT(PORTA,1);}
	}
	return 0;
}

