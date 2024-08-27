/*
 * SW_int.h
 *
 *  Created on: Aug 26, 2024
 *      Author: abdullahalazhary
 */

#ifndef INCLUDE_HAL_SWITCH_SW_INT_H_
#define INCLUDE_HAL_SWITCH_SW_INT_H_

ES_T SW_enumSwitchsInit(SW_T* Copy_pstrSwitchs);

ES_T SW_enumSwitchGetState(SW_T* Copy_pstrSwitch,u8* Copy_pu8SWState);

#endif /* INCLUDE_HAL_SWITCH_SW_INT_H_ */
