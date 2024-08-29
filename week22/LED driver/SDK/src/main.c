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
#include "../include/HAL/LED/LED_config.h"
#include "../include/HAL/LED/LED_int.h"

extern LED_T LED_AstrLeds[LED_NUM];
extern SW_T SWITCH_AstrSwitchs[SW_NUM];
int main (void)
{
	DIO_enumPortInit();
	SW_enumSwitchsInit(SWITCH_AstrSwitchs);
	LED_enumInit(LED_AstrLeds);

	u8 Local_u8SW1State=0,Local_u8SW2State=0,Local_u8SW3State=0;
	while(1)
	{
		SW_enumSwitchGetState(&SWITCH_AstrSwitchs[0],&Local_u8SW1State);
		SW_enumSwitchGetState(&SWITCH_AstrSwitchs[1],&Local_u8SW2State);
		SW_enumSwitchGetState(&SWITCH_AstrSwitchs[2],&Local_u8SW3State);

		if (Local_u8SW1State==0&&Local_u8SW2State==0&&Local_u8SW3State==0)
		{
			LED_enumLedOn(&LED_AstrLeds[0]);
			LED_enumLedOff(&LED_AstrLeds[1]);
			LED_enumLedOn(&LED_AstrLeds[2]);
		}
		else if (Local_u8SW1State==1&&Local_u8SW2State==1&&Local_u8SW3State==1)
		{
			LED_enumLedOff(&LED_AstrLeds[0]);
			LED_enumLedOn(&LED_AstrLeds[1]);
			LED_enumLedOff(&LED_AstrLeds[2]);
		}
		else
		{
			LED_enumLedOff(&LED_AstrLeds[0]);
			LED_enumLedOff(&LED_AstrLeds[1]);
			LED_enumLedOff(&LED_AstrLeds[2]);
		}
	}
	return 0;
}

