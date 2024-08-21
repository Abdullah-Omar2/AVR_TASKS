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

	u8 Local_pu8Value;
	while (1)
	{
		DIO_enumSetPinValue (DIO_PORTC,DIO_PIN0,LOW);
		DIO_enumGetPinValue (DIO_PORTA,DIO_PIN0,&Local_pu8Value);
		if (Local_pu8Value==0)
		{
			DIO_enumSetPinValue (DIO_PORTC,DIO_PIN0,HIGH);
		}
	}

	return 0;
}

