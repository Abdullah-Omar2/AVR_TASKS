/*
 * LED_config.c
 *
 *  Created on: Aug 28, 2024
 *      Author: abdullahalazhary
 */
#include "../include/LIB/STDtypes.h"
#include "../include/LIB/Error_State.h"
#include "../include/MCAL/DIO/DIO_int.h"
#include "../include/HAL/LED/LED_priv.h"
#include "../include/HAL/LED/LED_config.h"

LED_T LED_AstrLeds[LED_NUM]=
{
		{DIO_PORTC,DIO_PIN0,LED_SOURCE,LED_OFF},
		{DIO_PORTC,DIO_PIN1,LED_SOURCE,LED_OFF},
		{DIO_PORTC,DIO_PIN2,LED_SOURCE,LED_OFF},
};
