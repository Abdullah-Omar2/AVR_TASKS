/*
 * main.c
 *
 *  Created on: Aug 26, 2024
 *      Author: abdullahalazhary
 */
#include "../include/LIB/STDtypes.h"
#include "../include/LIB/Error_State.h"
#include "../include/MCAL/DIO/DIO_int.h"
#include "../include/HAL/SWITCH/SW_config.h"
#include "../include/HAL/SWITCH/SW_int.h"

extern SW_T SWITCH_AstrSwitchs[SW_NUM];
int main (void)
{
	DIO_enumPortInit();
	SW_enumSwitchsInit(SWITCH_AstrSwitchs);

	u8 Local_u8SW1State=0,Local_u8SW2State=0,Local_u8SW3State=0;
	while(1)
	{
		SW_enumSwitchGetState(&SWITCH_AstrSwitchs[0],&Local_u8SW1State);
		SW_enumSwitchGetState(&SWITCH_AstrSwitchs[1],&Local_u8SW2State);
		SW_enumSwitchGetState(&SWITCH_AstrSwitchs[2],&Local_u8SW3State);

		if (Local_u8SW1State==0&&Local_u8SW2State==0&&Local_u8SW3State==0)
		{
			DIO_enumSetPinValue(DIO_PORTC,DIO_PIN0,HIGH);
		}
		else
		{
			DIO_enumSetPinValue(DIO_PORTC,DIO_PIN0,LOW);
		}
	}
	return 0;
}

