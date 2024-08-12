/*
 * main.c
 *
 *  Created on: Aug 12, 2024
 *      Author: abdullahalazhary
 */
#include <util/delay.h>
typedef unsigned char u8;

#define DDRA *((volatile u8*)0x3A)
#define PORTA *((volatile u8*)0x3B)
#define PINA *((volatile u8*)0x39)

int main (void)
{
	DDRA|=(1<<0);
	DDRA|=(1<<1);
	DDRA|=(1<<2);
	DDRA|=(1<<3);
	DDRA|=(1<<4);
	DDRA|=(1<<5);

	while(1)
	{
		PORTA|=(1<<0);
		_delay_ms(100);
		PORTA|=(1<<1);
		_delay_ms(100);
		PORTA|=(1<<2);
		_delay_ms(100);
		PORTA|=(1<<3);
		_delay_ms(100);
		PORTA|=(1<<4);
		_delay_ms(100);
		PORTA|=(1<<5);
		_delay_ms(100);
		PORTA&=~(1<<0);
		_delay_ms(100);
		PORTA&=~(1<<1);
		_delay_ms(100);
		PORTA&=~(1<<2);
		_delay_ms(100);
		PORTA&=~(1<<3);
		_delay_ms(100);
		PORTA&=~(1<<4);
		_delay_ms(100);
		PORTA&=~(1<<5);
		_delay_ms(100);
	}
	return 0;
}

