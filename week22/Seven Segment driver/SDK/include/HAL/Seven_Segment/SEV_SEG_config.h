/*
 * SEV_SEG_config.h
 *
 *  Created on: Sep 1, 2024
 *      Author: abdullahalazhary
 */

#ifndef INCLUDE_HAL_SEVEN_SEGMENT_SEV_SEG_CONFIG_H_
#define INCLUDE_HAL_SEVEN_SEGMENT_SEV_SEG_CONFIG_H_

#define SEV_SEG_NUM  2

typedef struct
{
	u8 SEV_SEG_u8APort;
	u8 SEV_SEG_u8APin;

	u8 SEV_SEG_u8BPort;
	u8 SEV_SEG_u8BPin;

	u8 SEV_SEG_u8CPort;
	u8 SEV_SEG_u8CPin;

	u8 SEV_SEG_u8DPort;
	u8 SEV_SEG_u8DPin;

	u8 SEV_SEG_u8EPort;
	u8 SEV_SEG_u8EPin;

	u8 SEV_SEG_u8FPort;
	u8 SEV_SEG_u8FPin;

	u8 SEV_SEG_u8GPort;
	u8 SEV_SEG_u8GPin;

	u8 SEV_SEG_u8CMN_Port;
	u8 SEV_SEG_u8CMN_Pin;

	u8 SEV_SEG_u8DOT_Port;
	u8 SEV_SEG_u8DOT_Pin;

	u8 SEV_SEG_u8Type;
}SEV_SEG_T;

#endif /* INCLUDE_HAL_SEVEN_SEGMENT_SEV_SEG_CONFIG_H_ */
