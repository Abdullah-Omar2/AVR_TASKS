/*
 * LED_int.h
 *
 *  Created on: Aug 28, 2024
 *      Author: abdullahalazhary
 */

#ifndef INCLUDE_HAL_LED_LED_INT_H_
#define INCLUDE_HAL_LED_LED_INT_H_

#include "LED_priv.h"

ES_T LED_enumInit(LED_T* Copy_pstrLeds);
ES_T LED_enumLedOn(LED_T* Copy_pstrLed);
ES_T LED_enumLedOff(LED_T* Copy_pstrLed);

#endif /* INCLUDE_HAL_LED_LED_INT_H_ */
