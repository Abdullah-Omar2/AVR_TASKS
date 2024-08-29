/*
 * SW_config.h
 *
 *  Created on: Aug 26, 2024
 *      Author: abdullahalazhary
 */

#ifndef INCLUDE_HAL_SWITCH_SW_CONFIG_H_
#define INCLUDE_HAL_SWITCH_SW_CONFIG_H_

#define SW_NUM 3

typedef struct
{
	u8 SW_PortID;
	u8 SW_PinID;
	u8 SW_State;
}SW_T;

#endif /* INCLUDE_HAL_SWITCH_SW_CONFIG_H_ */
