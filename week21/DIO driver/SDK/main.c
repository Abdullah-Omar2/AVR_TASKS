/*
 * main.c
 *
 *  Created on: Aug 21, 2024
 *      Author: abdullahalazhary
 */
#include "DIO_init.h"
#include "LIB/STDtypes.h"


int main (void)
{
	DIO_enumPortInit ();
	DIO_enumSetPinDirection (DIO_PORTA,DIO_PIN0,INPUT);
	DIO_enumSetPinDirection (DIO_PORTC,DIO_PIN0,OUTPUT);
	DIO_enumSetPinValue (DIO_PORTA,DIO_PIN0,PULL_UP);
	DIO_enumSetPinValue (DIO_PORTC,DIO_PIN0,HIGH);
	u8 button=0;

	while (1)
	{
		DIO_enumGetPinValue (DIO_PORTA,DIO_PIN0,&button);
		if (button==0)
		{

			DIO_enumSetPinValue (DIO_PORTC,DIO_PIN0,HIGH);
		}
		else
		{
			DIO_enumSetPinValue (DIO_PORTC,DIO_PIN0,LOW);

		}
	}
	return 0;
}
