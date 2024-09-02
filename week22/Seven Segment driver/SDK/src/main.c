/*
 * main.c
 *
 *  Created on: Aug 26, 2024
 *      Author: abdullahalazhary
 */
#include <util/delay.h>
#include "../include/LIB/STDtypes.h"
#include "../include/LIB/Error_State.h"
#include "../include/MCAL/DIO/DIO_int.h"
#include "../include/HAL/SWITCH/SW_config.h"
#include "../include/HAL/SWITCH/SW_int.h"
#include "../include/HAL/LED/LED_config.h"
#include "../include/HAL/LED/LED_int.h"
#include "../include/HAL/Seven_Segment/SEV_SEG_config.h"
#include "../include/HAL/Seven_Segment/SEV_SEG_int.h"

extern SW_T SWITCH_AstrSwitchs[SW_NUM];
extern SEV_SEG_T SEV_SEG_AstrSegments [SEV_SEG_NUM];
int main (void)
{
	DIO_enumPortInit();
	SW_enumSwitchsInit(SWITCH_AstrSwitchs);
	SEV_SEG_enumInit(SEV_SEG_AstrSegments);
	SEV_SEG_enumCMNDisable(0);
	SEV_SEG_enumCMNDisable(1);

	u8 x=0,i=0,j=0;
	while(1)
	{
		SW_enumSwitchGetState(&SWITCH_AstrSwitchs[0],&x);
		if (x==0)
		{
			while(x==0)
			{
				SW_enumSwitchGetState(&SWITCH_AstrSwitchs[0],&x);
			}
			j++;
		}
		if (j==10)
		{
			j='a';
		}
		if(j=='g')
		{
			i++;
			j=0;
		}
		if(i==10)
		{
			i='a';
		}
		if (i=='g')
		{
			i=0;
			j=0;
		}
		SEV_SEG_enumCMNDisable(0);
		SEV_SEG_enumNUMDisplay(1,i);
		SEV_SEG_enumCMNEnable(1);
		_delay_ms(10);
		SEV_SEG_enumCMNDisable(1);
		SEV_SEG_enumNUMDisplay(0,j);
		SEV_SEG_enumCMNEnable(0);
		_delay_ms(10);
	}
	return 0;
}

