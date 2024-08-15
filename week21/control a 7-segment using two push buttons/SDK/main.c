/*
 * main.c
 *
 *  Created on: Aug 16, 2024
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
	u8 segment[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

	CLEAR_BIT(DDRA,0);
	CLEAR_BIT(DDRA,1);

	SET_BIT(PORTA,0);
	SET_BIT(PORTA,1);

	DDRC=255;

	PORTC=segment[0];

	u8 counter=0;
	while(1)
	{
		if(READ_BIT(PINA,0)==0)
		{
			if(counter<9)counter++;
			while(READ_BIT(PINA,0)==0);
			PORTC=segment[counter];
		}

		if(READ_BIT(PINA,1)==0)
		{
			if(counter!=0)counter--;
			while(READ_BIT(PINA,1)==0);
			PORTC=segment[counter];
		}
	}
	return 0;
}

