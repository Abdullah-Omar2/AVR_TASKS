/*
 * LCD_priv.h
 *
 *  Created on: Sep 6, 2024
 *      Author: abdullahalazhary
 */

#ifndef INCLUDE_HAL_LCD_LCD_PRIV_H_
#define INCLUDE_HAL_LCD_LCD_PRIV_H_

#define EIGHT_BIT 0
#define FOUR_BIT 1

#define NOT_CONNECTED 8

static inline ES_T LCD_inlenumSendCommand(u8 Copy_u8Command);

static inline ES_T LCD_inlenumLatch(void);
#endif /* INCLUDE_HAL_LCD_LCD_PRIV_H_ */
