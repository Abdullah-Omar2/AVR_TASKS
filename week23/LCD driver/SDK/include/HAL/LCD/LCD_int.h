/*
 * LCD_int.h
 *
 *  Created on: Sep 6, 2024
 *      Author: abdullahalazhary
 */

#ifndef INCLUDE_HAL_LCD_LCD_INT_H_
#define INCLUDE_HAL_LCD_LCD_INT_H_

#include "LCD_priv.h"

ES_T LCD_enumInit(void);

ES_T LCD_enumSendChar(u8 Copy_u8Char);

ES_T LCD_enumSendCommand(u8 Copy_u8Command);

ES_T LCD_enumSendString(u8* Copy_pu8String);

ES_T LCD_enumSendExtraChar(u8 Copy_u8Row,u8 Copy_u8Col,u8 Copy_u8StartCharNum , u8 Copy_u8EndCharNum , u8 Copy_u8WritingPosition ,u8 *Copy_u8PExtraChar );

ES_T LCD_enumGoTOPosition(u8 Copy_u8Row,u8 Copy_u8Col);

ES_T LCD_enumDisplayIntNum(s32 Copy_u8Num);

ES_T LCD_enumDisplayFloatNum(f32 Copy_u8Num);

ES_T LCD_enumDisplayCustomChar(u8* Copy_pu8Char);

ES_T LCD_enumClear(void);

#endif /* INCLUDE_HAL_LCD_LCD_INT_H_ */
