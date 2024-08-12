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
		//D1
		PORTA&=~(1<<3);
		PORTA|=(1<<0);
		PORTA|=(1<<4);
		PORTA|=(1<<5);
		_delay_ms(500);
		//D2
		PORTA&=~(1<<0);
		PORTA|=(1<<1);
		_delay_ms(500);
		//D3
		PORTA&=~(1<<1);
		PORTA|=(1<<2);
		_delay_ms(500);
		//D6
		PORTA&=~(1<<4);
		PORTA|=(1<<3);
		_delay_ms(500);
		//D9
	    PORTA&=~(1<<5);
		PORTA|=(1<<4);
		_delay_ms(500);
		//D8
		PORTA&=~(1<<2);
		PORTA|=(1<<1);
		_delay_ms(500);
		//D7
		PORTA&=~(1<<1);
		PORTA|=(1<<0);
		_delay_ms(500);
		//D4
		PORTA|=(1<<5);
		PORTA&=~(1<<4);
		_delay_ms(500);
	}
	return 0;
}
