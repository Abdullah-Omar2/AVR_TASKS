/*
 * LCD_prog.c
 *
 *  Created on: Sep 6, 2024
 *      Author: abdullahalazhary
 */
#include <util/delay.h>
#include "../include/LIB/STDtypes.h"
#include "../include/LIB/Error_State.h"
#include "../include/LIB/BITMATH.h"
#include "../include/MCAL/DIO/DIO_int.h"
#include "../include/HAL/LCD/LCD_priv.h"
#include "../include/HAL/LCD/LCD_config.h"

ES_T LCD_enumInit(void)
{
	ES_T Local_enumErrorState=ES_NOK;

    _delay_ms(35);
    Local_enumErrorState=DIO_enumSetPinDirection(LCD_RS_PORT,LCD_RS_PIN,OUTPUT);
    if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
    Local_enumErrorState=DIO_enumSetPinDirection(LCD_RW_PORT,LCD_RW_PIN,OUTPUT);
    if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
    Local_enumErrorState=DIO_enumSetPinDirection(LCD_EN_PORT,LCD_EN_PIN,OUTPUT);
    if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;

    Local_enumErrorState=DIO_enumSetPinDirection(LCD_D7_PORT,LCD_D7_PIN,OUTPUT);
    if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
    Local_enumErrorState=DIO_enumSetPinDirection(LCD_D6_PORT,LCD_D6_PIN,OUTPUT);
    if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
    Local_enumErrorState=DIO_enumSetPinDirection(LCD_D5_PORT,LCD_D5_PIN,OUTPUT);
    if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
    Local_enumErrorState=DIO_enumSetPinDirection(LCD_D4_PORT,LCD_D4_PIN,OUTPUT);
    if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;

#if LCD_MODE == EIGHT_BIT

    Local_enumErrorState=DIO_enumSetPinDirection(LCD_D3_PORT,LCD_D3_PIN,OUTPUT);
    if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
    Local_enumErrorState=DIO_enumSetPinDirection(LCD_D2_PORT,LCD_D2_PIN,OUTPUT);
    if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
    Local_enumErrorState=DIO_enumSetPinDirection(LCD_D1_PORT,LCD_D1_PIN,OUTPUT);
    if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
    Local_enumErrorState=DIO_enumSetPinDirection(LCD_D0_PORT,LCD_D0_PIN,OUTPUT);
    if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;

    Local_enumErrorState=LCD_inlenumSendCommand(0x38);
    if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;

#elif LCD_MODE == FOUR_BIT

    Local_enumErrorState=LCD_inlenumSendCommand(0x28);
    if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;

#else

#error"wrong LCD_MODE"

#endif

    _delay_ms(1);

    Local_enumErrorState=LCD_inlenumSendCommand(0x0D);
    if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;

    _delay_ms(1);

    Local_enumErrorState=LCD_inlenumSendCommand(0x01);
    if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;

    _delay_ms(3);

    Local_enumErrorState=LCD_inlenumSendCommand(0x06);
    if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;

    _delay_ms(1);

    Local_enumErrorState=LCD_inlenumSendCommand(0x80);
    if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;

    Local_enumErrorState=ES_OK;

	return Local_enumErrorState;
}

static inline ES_T LCD_inlenumSendCommand(u8 Copy_u8Command)
{
	ES_T Local_enumErrorState=ES_NOK;

    Local_enumErrorState=DIO_enumSetPinValue(LCD_RS_PORT,LCD_RS_PIN,LOW);
    if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
    Local_enumErrorState=DIO_enumSetPinValue(LCD_EN_PORT,LCD_EN_PIN,LOW);
    if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
    Local_enumErrorState=DIO_enumSetPinValue(LCD_RW_PORT,LCD_RW_PIN,LOW);
    if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;

#if LCD_MODE == EIGHT_BIT

    Local_enumErrorState=DIO_enumSetPinValue(LCD_D7_PORT,LCD_D7_PIN,READ_BIT(Copy_u8Command,7));
    if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
    Local_enumErrorState=DIO_enumSetPinValue(LCD_D6_PORT,LCD_D6_PIN,READ_BIT(Copy_u8Command,6));
    if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
    Local_enumErrorState=DIO_enumSetPinValue(LCD_D5_PORT,LCD_D5_PIN,READ_BIT(Copy_u8Command,5));
    if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
    Local_enumErrorState=DIO_enumSetPinValue(LCD_D4_PORT,LCD_D4_PIN,READ_BIT(Copy_u8Command,4));
    if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
    Local_enumErrorState=DIO_enumSetPinValue(LCD_D3_PORT,LCD_D3_PIN,READ_BIT(Copy_u8Command,3));
    if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
    Local_enumErrorState=DIO_enumSetPinValue(LCD_D2_PORT,LCD_D2_PIN,READ_BIT(Copy_u8Command,2));
    if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
    Local_enumErrorState=DIO_enumSetPinValue(LCD_D1_PORT,LCD_D1_PIN,READ_BIT(Copy_u8Command,1));
    if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
    Local_enumErrorState=DIO_enumSetPinValue(LCD_D0_PORT,LCD_D0_PIN,READ_BIT(Copy_u8Command,0));
    if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;

    Local_enumErrorState=LCD_inlenumLatch();
    if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;

#elif LCD_MODE == FOUR_BIT

    Local_enumErrorState=DIO_enumSetPinValue(LCD_D7_PORT,LCD_D7_PIN,READ_BIT(Copy_u8Command,7));
    if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
    Local_enumErrorState=DIO_enumSetPinValue(LCD_D6_PORT,LCD_D6_PIN,READ_BIT(Copy_u8Command,6));
    if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
    Local_enumErrorState=DIO_enumSetPinValue(LCD_D5_PORT,LCD_D5_PIN,READ_BIT(Copy_u8Command,5));
    if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
    Local_enumErrorState=DIO_enumSetPinValue(LCD_D4_PORT,LCD_D4_PIN,READ_BIT(Copy_u8Command,4));
    if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;

    Local_enumErrorState=LCD_inlenumLatch();
    if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;

	Local_enumErrorState=DIO_enumSetPinValue(LCD_D7_PORT,LCD_D7_PIN,READ_BIT(Copy_u8Command,3));
	if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
	Local_enumErrorState=DIO_enumSetPinValue(LCD_D6_PORT,LCD_D6_PIN,READ_BIT(Copy_u8Command,2));
	if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
	Local_enumErrorState=DIO_enumSetPinValue(LCD_D5_PORT,LCD_D5_PIN,READ_BIT(Copy_u8Command,1));
	if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
	Local_enumErrorState=DIO_enumSetPinValue(LCD_D4_PORT,LCD_D4_PIN,READ_BIT(Copy_u8Command,0));
	if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;

	Local_enumErrorState=LCD_inlenumLatch();
    if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;

#else

#error"wrong LCD_MODE"

#endif

	Local_enumErrorState=ES_OK;

	return Local_enumErrorState;
}

static inline ES_T LCD_inlenumLatch(void)
{
	ES_T Local_enumErrorState=ES_NOK;

	Local_enumErrorState=DIO_enumSetPinValue(LCD_EN_PORT,LCD_EN_PIN,HIGH);
	if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
	_delay_ms(2);
	Local_enumErrorState=DIO_enumSetPinValue(LCD_EN_PORT,LCD_EN_PIN,LOW);
	if(Local_enumErrorState!=ES_OK)return Local_enumErrorState;
	_delay_ms(2);

	Local_enumErrorState=ES_OK;

	return Local_enumErrorState;
}

ES_T LCD_enumDisplayChar(u8 Copy_u8Char)
{
	ES_T Local_enumErrorState=ES_NOK;



	return Local_enumErrorState;
}

ES_T LCD_enumSendCommand(u8 Copy_u8Command)
{
	ES_T Local_enumErrorState=ES_NOK;



	return Local_enumErrorState;
}

ES_T LCD_enumDisplayString(u8* Copy_pu8String)
{
	ES_T Local_enumErrorState=ES_NOK;



	return Local_enumErrorState;
}

ES_T LCD_enumGoTOPosition(u8 Copy_u8Row,u8 Copy_u8Col)
{
	ES_T Local_enumErrorState=ES_NOK;



	return Local_enumErrorState;
}

ES_T LCD_enumDisplayIntNum(s32 Copy_u8Num)
{
	ES_T Local_enumErrorState=ES_NOK;



	return Local_enumErrorState;
}

ES_T LCD_enumDisplayFloatNum(f32 Copy_u8Num)
{
	ES_T Local_enumErrorState=ES_NOK;



	return Local_enumErrorState;
}

ES_T LCD_enumDisplayCustomChar(u8* Copy_pu8Char)
{
	ES_T Local_enumErrorState=ES_NOK;



	return Local_enumErrorState;
}

ES_T LCD_enumClear(void)
{
	ES_T Local_enumErrorState=ES_NOK;



	return Local_enumErrorState;
}
