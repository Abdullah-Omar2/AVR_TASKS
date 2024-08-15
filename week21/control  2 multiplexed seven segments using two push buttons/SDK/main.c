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
	PORTC=0;

	SET_BIT(DDRD,0);
	SET_BIT(DDRD,1);

	u8 counter1=0,counter2=5;
	while(1)
	{
		if (READ_BIT(PINA,0)==0)
		{
			counter1++;
			if(counter1==10){counter2++;counter1=0;}
			while(READ_BIT(PINA,0)==0);
		}
		if (READ_BIT(PINA,1)==0)
		{
			counter1--;
			if(counter1==255){counter2--;counter1=9;}
			while(READ_BIT(PINA,1)==0);
		}
		if(counter2==10){counter1=9;counter2=9;}
		if(counter2==255){counter1=0;counter2=0;}
		SET_BIT(PORTD,0);
		PORTC=segment[counter1];
		CLEAR_BIT(PORTD,1);
		_delay_ms(.001);
		SET_BIT(PORTD,1);
		PORTC=segment[counter2];
		CLEAR_BIT(PORTD,0);
		_delay_ms(.001);
	}
	return 0;
}


