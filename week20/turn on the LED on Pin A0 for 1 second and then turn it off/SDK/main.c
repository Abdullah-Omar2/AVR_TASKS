/*
 * main.c
 *
 *  Created on: Aug 11, 2024
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

	PORTA|=(1<<0);
	_delay_ms(1000);
	PORTA&=~(1<<0);

	while(1);
	return 0;
}
