/*
 * SW_prog.c
 *
 *  Created on: Aug 26, 2024
 *      Author: abdullahalazhary
 */
#include "../include/LIB/Error_State.h"
#include "../include/LIB/STDtypes.h"
#include "../include/MCAL/DIO/DIO_int.h"
#include "../include/HAL/SWITCH/SW_config.h"

ES_T SW_enumSwitchsInit(SW_T* Copy_pstrSwitchs)
{
	ES_T Local_enumErrorState=ES_NOK;
	u8 Local_u8Counter=0;

	if (Copy_pstrSwitchs!=NULL)
	{
		for (Local_u8Counter=0;Local_u8Counter<SW_NUM;Local_u8Counter++)
		{
			Local_enumErrorState=DIO_enumSetPinDirection(Copy_pstrSwitchs[Local_u8Counter].SW_PortID,Copy_pstrSwitchs[Local_u8Counter].SW_PinID,INPUT);
			Local_enumErrorState=DIO_enumSetPinValue(Copy_pstrSwitchs[Local_u8Counter].SW_PortID,Copy_pstrSwitchs[Local_u8Counter].SW_PinID,Copy_pstrSwitchs[Local_u8Counter].SW_State);
		}
		Local_enumErrorState=ES_NOK;
	}
	else
	{
		Local_enumErrorState=ES_NULL_POINTER;
	}

	return Local_enumErrorState;
}
ES_T SW_enumSwitchGetState(SW_T* Copy_pstrSwitch,u8* Copy_pu8SWState)
{
	ES_T Local_enumErrorState=ES_NOK;

	if (Copy_pstrSwitch!=NULL&&Copy_pu8SWState!=NULL)
	{
		Local_enumErrorState=DIO_enumGetPinValue(Copy_pstrSwitch->SW_PortID,Copy_pstrSwitch->SW_PinID,Copy_pu8SWState);
	}
	else
	{
		Local_enumErrorState=ES_NULL_POINTER;
	}

	return Local_enumErrorState;
}
