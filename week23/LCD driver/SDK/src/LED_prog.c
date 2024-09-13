/*
 * LED_prog.c
 *
 *  Created on: Aug 28, 2024
 *      Author: abdullahalazhary
 */
#include "../include/LIB/STDtypes.h"
#include "../include/LIB/Error_State.h"
#include "../include/MCAL/DIO/DIO_int.h"
#include "../include/HAL/LED/LED_priv.h"
#include "../include/HAL/LED/LED_config.h"

ES_T LED_enumInit(LED_T* Copy_pstrLeds)
{
	ES_T Local_enumErrorState=ES_NOK;

	if (Copy_pstrLeds!=NULL)
	{
		u8 Local_u8Counter=0;
		for (Local_u8Counter=0;Local_u8Counter<LED_NUM;Local_u8Counter++)
		{
			Local_enumErrorState=DIO_enumSetPinDirection (Copy_pstrLeds[Local_u8Counter].LED_u8PortID,Copy_pstrLeds[Local_u8Counter].LED_u8PinID,OUTPUT);

			if(Copy_pstrLeds[Local_u8Counter].LED_u8Connection==LED_SINK)
			{
				if (Copy_pstrLeds[Local_u8Counter].LED_u8InitState==LED_ON)
				{
					Local_enumErrorState=DIO_enumSetPinValue (Copy_pstrLeds[Local_u8Counter].LED_u8PortID,Copy_pstrLeds[Local_u8Counter].LED_u8PinID,LOW);
				}
				else if (Copy_pstrLeds[Local_u8Counter].LED_u8InitState==LED_OFF)
				{
					Local_enumErrorState=DIO_enumSetPinValue (Copy_pstrLeds[Local_u8Counter].LED_u8PortID,Copy_pstrLeds[Local_u8Counter].LED_u8PinID,HIGH);
				}
				else
				{
					Local_u8Counter=ES_OUT_OF_RANGE;
				}
			}
			else if(Copy_pstrLeds[Local_u8Counter].LED_u8Connection==LED_SOURCE)
			{
				if (Copy_pstrLeds[Local_u8Counter].LED_u8InitState==LED_ON)
				{
					Local_enumErrorState=DIO_enumSetPinValue (Copy_pstrLeds[Local_u8Counter].LED_u8PortID,Copy_pstrLeds[Local_u8Counter].LED_u8PinID,HIGH);
				}
				else if (Copy_pstrLeds[Local_u8Counter].LED_u8InitState==LED_OFF)
				{
					Local_enumErrorState=DIO_enumSetPinValue (Copy_pstrLeds[Local_u8Counter].LED_u8PortID,Copy_pstrLeds[Local_u8Counter].LED_u8PinID,LOW);
				}
				else
				{
					Local_enumErrorState=ES_OUT_OF_RANGE;
				}
			}
			else
			{
				Local_enumErrorState=ES_OUT_OF_RANGE;
			}
		}
	}
	else
	{
		Local_enumErrorState=ES_NULL_POINTER;
	}

	return Local_enumErrorState;
}
ES_T LED_enumLedOn(LED_T* Copy_pstrLed)
{
	ES_T Local_enumErrorState=ES_NOK;

	if (Copy_pstrLed!=NULL)
	{
		if(Copy_pstrLed->LED_u8Connection==LED_SINK)
		{
			Local_enumErrorState=DIO_enumSetPinValue (Copy_pstrLed->LED_u8PortID,Copy_pstrLed->LED_u8PinID,LOW);
		}
		else if(Copy_pstrLed->LED_u8Connection==LED_SOURCE)
		{
			Local_enumErrorState=DIO_enumSetPinValue (Copy_pstrLed->LED_u8PortID,Copy_pstrLed->LED_u8PinID,HIGH);
		}
		else
		{
			Local_enumErrorState=ES_OUT_OF_RANGE;
		}
	}
	else
	{
		Local_enumErrorState=ES_NULL_POINTER;
	}

	return Local_enumErrorState;
}
ES_T LED_enumLedOff(LED_T* Copy_pstrLed)
{
	ES_T Local_enumErrorState=ES_NOK;

	if (Copy_pstrLed!=NULL)
	{
		if(Copy_pstrLed->LED_u8Connection==LED_SINK)
		{
			Local_enumErrorState=DIO_enumSetPinValue (Copy_pstrLed->LED_u8PortID,Copy_pstrLed->LED_u8PinID,HIGH);
		}
		else if(Copy_pstrLed->LED_u8Connection==LED_SOURCE)
		{
			Local_enumErrorState=DIO_enumSetPinValue (Copy_pstrLed->LED_u8PortID,Copy_pstrLed->LED_u8PinID,LOW);
		}
		else
		{
			Local_enumErrorState=ES_OUT_OF_RANGE;
		}
	}
	else
	{
		Local_enumErrorState=ES_NULL_POINTER;
	}

	return Local_enumErrorState;
}

