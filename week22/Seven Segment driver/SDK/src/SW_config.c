/*
 * SW_config.c
 *
 *  Created on: Aug 26, 2024
 *      Author: abdullahalazhary
 */
#include "../include/LIB/STDtypes.h"
#include "../include/LIB/Error_State.h"
#include "../include/MCAL/DIO/DIO_int.h"
#include "../include/HAL/SWITCH/SW_config.h"


SW_T SWITCH_AstrSwitchs[SW_NUM]=
{
		{DIO_PORTA,DIO_PIN7,PULL_UP}
};

