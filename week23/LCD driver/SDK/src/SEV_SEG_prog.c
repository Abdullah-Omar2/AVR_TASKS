/*
 * SEV_SEG_prog.c
 *
 *  Created on: Sep 1, 2024
 *      Author: abdullahalazhary
 */
#include "../include/LIB/STDtypes.h"
#include "../include/LIB/Error_State.h"
#include "../include/LIB/BITMATH.h"
#include "../include/MCAL/DIO/DIO_int.h"
#include "../include/HAL/Seven_Segment/SEV_SEG_config.h"
#include "../include/HAL/Seven_Segment/SEV_SEG_priv.h"

extern SEV_SEG_T SEV_SEG_AstrSegments [SEV_SEG_NUM];

ES_T SEV_SEG_enumInit(SEV_SEG_T* Copy_pstrSegments)
{
	ES_T Local_enumErrorState=ES_NOK;
	u8 Local_u8Counter=0;
	if (Copy_pstrSegments!=NULL)
	{
		for (Local_u8Counter=0;Local_u8Counter<SEV_SEG_NUM;Local_u8Counter++)
		{
			Local_enumErrorState=DIO_enumSetPinDirection(Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8APort,Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8APin,OUTPUT);
			if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
			Local_enumErrorState=DIO_enumSetPinDirection(Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8BPort,Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8BPin,OUTPUT);
			if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
			Local_enumErrorState=DIO_enumSetPinDirection(Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8CPort,Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8CPin,OUTPUT);
			if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
			Local_enumErrorState=DIO_enumSetPinDirection(Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8DPort,Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8DPin,OUTPUT);
			if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
			Local_enumErrorState=DIO_enumSetPinDirection(Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8EPort,Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8EPin,OUTPUT);
			if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
			Local_enumErrorState=DIO_enumSetPinDirection(Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8FPort,Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8FPin,OUTPUT);
			if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
			Local_enumErrorState=DIO_enumSetPinDirection(Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8GPort,Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8GPin,OUTPUT);
			if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;

			if(Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8Type==COMMON_CATHODE)
			{
				Local_enumErrorState=DIO_enumSetPinValue(Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8APort,Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8APin,LOW);
				if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
				Local_enumErrorState=DIO_enumSetPinValue(Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8BPort,Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8BPin,LOW);
				if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
				Local_enumErrorState=DIO_enumSetPinValue(Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8CPort,Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8CPin,LOW);
				if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
				Local_enumErrorState=DIO_enumSetPinValue(Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8DPort,Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8DPin,LOW);
				if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
				Local_enumErrorState=DIO_enumSetPinValue(Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8EPort,Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8EPin,LOW);
				if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
				Local_enumErrorState=DIO_enumSetPinValue(Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8FPort,Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8FPin,LOW);
				if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
				Local_enumErrorState=DIO_enumSetPinValue(Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8GPort,Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8GPin,LOW);
				if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
			}
			else if(Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8Type==COMMON_ANODE)
			{
				Local_enumErrorState=DIO_enumSetPinValue(Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8APort,Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8APin,HIGH);
				if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
				Local_enumErrorState=DIO_enumSetPinValue(Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8BPort,Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8BPin,HIGH);
				if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
				Local_enumErrorState=DIO_enumSetPinValue(Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8CPort,Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8CPin,HIGH);
				if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
				Local_enumErrorState=DIO_enumSetPinValue(Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8DPort,Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8DPin,HIGH);
				if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
				Local_enumErrorState=DIO_enumSetPinValue(Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8EPort,Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8EPin,HIGH);
				if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
				Local_enumErrorState=DIO_enumSetPinValue(Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8FPort,Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8FPin,HIGH);
				if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
				Local_enumErrorState=DIO_enumSetPinValue(Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8GPort,Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8GPin,HIGH);
				if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
			}
			else
			{
				Local_enumErrorState=ES_OUT_OF_RANGE;
			}

			if (Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8CMN_Port<=DIO_PORTD
				&&Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8CMN_Pin<=DIO_PIN7)
			{
				Local_enumErrorState=DIO_enumSetPinDirection(Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8CMN_Port,Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8CMN_Pin,OUTPUT);
				if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;

				if(Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8Type==COMMON_CATHODE)
				{
					Local_enumErrorState=DIO_enumSetPinValue(Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8CMN_Port,Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8CMN_Pin,LOW);
					if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
				}
				else if(Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8Type==COMMON_ANODE)
				{
					Local_enumErrorState=DIO_enumSetPinValue(Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8CMN_Port,Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8CMN_Pin,HIGH);
					if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
				}
				else
				{
					Local_enumErrorState=ES_OUT_OF_RANGE;
				}
			}
			else if (Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8CMN_Port==NOT_CONNECTED
					 &&Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8CMN_Pin==NOT_CONNECTED)
			{

			}
			else
			{
				Local_enumErrorState=ES_OUT_OF_RANGE;
			}

			if (Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8DOT_Port<=DIO_PORTD
				&&Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8DOT_Pin<=DIO_PIN7)
			{
				Local_enumErrorState=DIO_enumSetPinDirection(Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8DOT_Port,Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8DOT_Pin,OUTPUT);
				if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;

				if(Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8Type==COMMON_CATHODE)
				{
					Local_enumErrorState=DIO_enumSetPinValue(Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8DOT_Port,Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8DOT_Pin,LOW);
					if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
				}
				else if(Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8Type==COMMON_ANODE)
				{
					Local_enumErrorState=DIO_enumSetPinValue(Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8DOT_Port,Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8DOT_Pin,HIGH);
					if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
				}
				else
				{
					Local_enumErrorState=ES_OUT_OF_RANGE;
				}
			}
			else if (Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8DOT_Port==NOT_CONNECTED
					 &&Copy_pstrSegments[Local_u8Counter].SEV_SEG_u8DOT_Pin==NOT_CONNECTED)
			{

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
ES_T SEV_SEG_enumNUMDisplay(u8 Copy_u8SegmentID,u8 Copy_u8Number)
{
	ES_T Local_enumErrorState=ES_NOK;

	if ((Copy_u8SegmentID<SEV_SEG_NUM)&&((Copy_u8Number>=0&&Copy_u8Number<=9)
		||(Copy_u8Number>='A'&&Copy_u8Number<='F')||(Copy_u8Number>='a'&&Copy_u8Number<='f')))
	{
		if (Copy_u8Number=='a'||Copy_u8Number=='A')Copy_u8Number=10;
		if (Copy_u8Number=='b'||Copy_u8Number=='B')Copy_u8Number=11;
		if (Copy_u8Number=='c'||Copy_u8Number=='C')Copy_u8Number=12;
		if (Copy_u8Number=='d'||Copy_u8Number=='D')Copy_u8Number=13;
		if (Copy_u8Number=='e'||Copy_u8Number=='E')Copy_u8Number=14;
		if (Copy_u8Number=='f'||Copy_u8Number=='F')Copy_u8Number=15;

		if(SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8Type==COMMON_CATHODE)
		{
			Local_enumErrorState=DIO_enumSetPinValue(SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8APort,SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8APin,READ_BIT(SEV_SEG_Au8NumDisplay[Copy_u8Number],0));
			if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
			Local_enumErrorState=DIO_enumSetPinValue(SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8BPort,SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8BPin,READ_BIT(SEV_SEG_Au8NumDisplay[Copy_u8Number],1));
			if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
			Local_enumErrorState=DIO_enumSetPinValue(SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8CPort,SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8CPin,READ_BIT(SEV_SEG_Au8NumDisplay[Copy_u8Number],2));
			if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
			Local_enumErrorState=DIO_enumSetPinValue(SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8DPort,SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8DPin,READ_BIT(SEV_SEG_Au8NumDisplay[Copy_u8Number],3));
			if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
			Local_enumErrorState=DIO_enumSetPinValue(SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8EPort,SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8EPin,READ_BIT(SEV_SEG_Au8NumDisplay[Copy_u8Number],4));
			if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
			Local_enumErrorState=DIO_enumSetPinValue(SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8FPort,SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8FPin,READ_BIT(SEV_SEG_Au8NumDisplay[Copy_u8Number],5));
			if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
			Local_enumErrorState=DIO_enumSetPinValue(SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8GPort,SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8GPin,READ_BIT(SEV_SEG_Au8NumDisplay[Copy_u8Number],6));
			if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
		}
		else if(SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8Type==COMMON_ANODE)
		{
			Local_enumErrorState=DIO_enumSetPinValue(SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8APort,SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8APin,!READ_BIT(SEV_SEG_Au8NumDisplay[Copy_u8Number],0));
			if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
			Local_enumErrorState=DIO_enumSetPinValue(SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8BPort,SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8BPin,!READ_BIT(SEV_SEG_Au8NumDisplay[Copy_u8Number],1));
			if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
			Local_enumErrorState=DIO_enumSetPinValue(SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8CPort,SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8CPin,!READ_BIT(SEV_SEG_Au8NumDisplay[Copy_u8Number],2));
			if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
			Local_enumErrorState=DIO_enumSetPinValue(SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8DPort,SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8DPin,!READ_BIT(SEV_SEG_Au8NumDisplay[Copy_u8Number],3));
			if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
			Local_enumErrorState=DIO_enumSetPinValue(SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8EPort,SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8EPin,!READ_BIT(SEV_SEG_Au8NumDisplay[Copy_u8Number],4));
			if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
			Local_enumErrorState=DIO_enumSetPinValue(SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8FPort,SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8FPin,!READ_BIT(SEV_SEG_Au8NumDisplay[Copy_u8Number],5));
			if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
			Local_enumErrorState=DIO_enumSetPinValue(SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8GPort,SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8GPin,!READ_BIT(SEV_SEG_Au8NumDisplay[Copy_u8Number],6));
			if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
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

	return Local_enumErrorState;
}
ES_T SEV_SEG_enumCMNEnable(u8 Copy_u8SegmentID)
{
	ES_T Local_enumErrorState=ES_NOK;

	if (Copy_u8SegmentID<SEV_SEG_NUM)
	{
		if (SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8CMN_Port<=DIO_PORTD
			&&SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8CMN_Pin<=DIO_PIN7)
		{
			if (SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8Type==COMMON_CATHODE)
			{
				Local_enumErrorState=DIO_enumSetPinValue(SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8CMN_Port,SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8CMN_Pin,LOW);
			}
			else if (SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8Type==COMMON_ANODE)
			{
				Local_enumErrorState=DIO_enumSetPinValue(SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8CMN_Port,SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8CMN_Pin,HIGH);
			}
			else
			{
				Local_enumErrorState=ES_OUT_OF_RANGE;
			}
		}
		else if(SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8CMN_Port==NOT_CONNECTED
				&&SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8CMN_Pin==NOT_CONNECTED)
		{
			Local_enumErrorState=ES_NOK;
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

	return Local_enumErrorState;
}
ES_T SEV_SEG_enumCMNDisable(u8 Copy_u8SegmentID)
{
	ES_T Local_enumErrorState=ES_NOK;

	if (Copy_u8SegmentID<SEV_SEG_NUM)
	{
		if (SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8CMN_Port<=DIO_PORTD
			&&SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8CMN_Pin<=DIO_PIN7)
		{
			if (SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8Type==COMMON_CATHODE)
			{
				Local_enumErrorState=DIO_enumSetPinValue(SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8CMN_Port,SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8CMN_Pin,HIGH);
			}
			else if (SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8Type==COMMON_ANODE)
			{
				Local_enumErrorState=DIO_enumSetPinValue(SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8CMN_Port,SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8CMN_Pin,LOW);
			}
			else
			{
				Local_enumErrorState=ES_OUT_OF_RANGE;
			}
		}
		else if(SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8CMN_Port==NOT_CONNECTED
				&&SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8CMN_Pin==NOT_CONNECTED)
		{
			Local_enumErrorState=ES_NOK;
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

	return Local_enumErrorState;
}
ES_T SEV_SEG_enumDOTEnable(u8 Copy_u8SegmentID)
{
	ES_T Local_enumErrorState=ES_NOK;

	if (Copy_u8SegmentID<SEV_SEG_NUM)
	{
		if (SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8DOT_Port<=DIO_PORTD
			&&SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8DOT_Pin<=DIO_PIN7)
		{
			if (SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8Type==COMMON_CATHODE)
			{
				Local_enumErrorState=DIO_enumSetPinValue(SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8DOT_Port,SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8DOT_Pin,HIGH);
			}
			else if (SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8Type==COMMON_ANODE)
			{
				Local_enumErrorState=DIO_enumSetPinValue(SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8CMN_Port,SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8CMN_Pin,LOW);
			}
			else
			{
				Local_enumErrorState=ES_OUT_OF_RANGE;
			}
		}
		else if(SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8CMN_Port==NOT_CONNECTED
				&&SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8CMN_Pin==NOT_CONNECTED)
		{
			Local_enumErrorState=ES_NOK;
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

	return Local_enumErrorState;
}
ES_T SEV_SEG_enumDOTDisable(u8 Copy_u8SegmentID)
{
	ES_T Local_enumErrorState=ES_NOK;

	if (Copy_u8SegmentID<SEV_SEG_NUM)
	{
		if (SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8DOT_Port<=DIO_PORTD
			&&SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8DOT_Pin<=DIO_PIN7)
		{
			if (SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8Type==COMMON_CATHODE)
			{
				Local_enumErrorState=DIO_enumSetPinValue(SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8DOT_Port,SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8DOT_Pin,LOW);
			}
			else if (SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8Type==COMMON_ANODE)
			{
				Local_enumErrorState=DIO_enumSetPinValue(SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8CMN_Port,SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8CMN_Pin,HIGH);
			}
			else
			{
				Local_enumErrorState=ES_OUT_OF_RANGE;
			}
		}
		else if(SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8CMN_Port==NOT_CONNECTED
				&&SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8CMN_Pin==NOT_CONNECTED)
		{
			Local_enumErrorState=ES_NOK;
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

	return Local_enumErrorState;
}
ES_T SEV_SEG_enumSEGClear(u8 Copy_u8SegmentID)
{
	ES_T Local_enumErrorState=ES_NOK;

	if (Copy_u8SegmentID<SEV_SEG_NUM)
	{
		if (SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8Type==COMMON_CATHODE)
		{
			Local_enumErrorState=DIO_enumSetPinValue(SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8APort,SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8APin,LOW);
			if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
			Local_enumErrorState=DIO_enumSetPinValue(SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8BPort,SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8BPin,LOW);
			if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
			Local_enumErrorState=DIO_enumSetPinValue(SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8CPort,SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8CPin,LOW);
			if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
			Local_enumErrorState=DIO_enumSetPinValue(SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8DPort,SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8DPin,LOW);
			if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
			Local_enumErrorState=DIO_enumSetPinValue(SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8EPort,SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8EPin,LOW);
			if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
			Local_enumErrorState=DIO_enumSetPinValue(SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8FPort,SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8FPin,LOW);
			if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
			Local_enumErrorState=DIO_enumSetPinValue(SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8GPort,SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8GPin,LOW);
			if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;

			if(SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8DOT_Port<=DIO_PORTD
			   &&SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8DOT_Pin<=DIO_PIN7)
			{
				Local_enumErrorState=DIO_enumSetPinValue(SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8DOT_Port,SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8DOT_Pin,LOW);
				if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
			}
			else if (SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8DOT_Port==NOT_CONNECTED
					 &&SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8DOT_Pin<=NOT_CONNECTED)
			{

			}
			else
			{
				Local_enumErrorState=ES_OUT_OF_RANGE;
			}
		}
		else if (SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8Type==COMMON_ANODE)
		{
			Local_enumErrorState=DIO_enumSetPinValue(SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8APort,SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8APin,HIGH);
			if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
			Local_enumErrorState=DIO_enumSetPinValue(SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8BPort,SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8BPin,HIGH);
			if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
			Local_enumErrorState=DIO_enumSetPinValue(SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8CPort,SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8CPin,HIGH);
			if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
			Local_enumErrorState=DIO_enumSetPinValue(SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8DPort,SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8DPin,HIGH);
			if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
			Local_enumErrorState=DIO_enumSetPinValue(SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8EPort,SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8EPin,HIGH);
			if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
			Local_enumErrorState=DIO_enumSetPinValue(SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8FPort,SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8FPin,HIGH);
			if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
			Local_enumErrorState=DIO_enumSetPinValue(SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8GPort,SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8GPin,HIGH);
			if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;

			if(SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8DOT_Port<=DIO_PORTD
			   &&SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8DOT_Pin<=DIO_PIN7)
			{
				Local_enumErrorState=DIO_enumSetPinValue(SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8DOT_Port,SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8DOT_Pin,HIGH);
				if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
			}
			else if (SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8DOT_Port==NOT_CONNECTED
					 &&SEV_SEG_AstrSegments[Copy_u8SegmentID].SEV_SEG_u8DOT_Pin<=NOT_CONNECTED)
			{

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
	else
	{
		Local_enumErrorState=ES_OUT_OF_RANGE;
	}

	return Local_enumErrorState;
}
