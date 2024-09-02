/*
 * LED_config.h
 *
 *  Created on: Aug 28, 2024
 *      Author: abdullahalazhary
 */

#ifndef INCLUDE_HAL_LED_LED_CONFIG_H_
#define INCLUDE_HAL_LED_LED_CONFIG_H_

#define LED_NUM 3

typedef struct
{
	u8 LED_u8PortID;
	u8 LED_u8PinID;
	u8 LED_u8Connection;
	u8 LED_u8InitState;
}LED_T;

#endif /* INCLUDE_HAL_LED_LED_CONFIG_H_ */
