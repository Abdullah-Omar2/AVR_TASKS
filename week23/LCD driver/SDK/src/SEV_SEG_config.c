/*
 * SEV_SEG_config.c
 *
 *  Created on: Sep 1, 2024
 *      Author: abdullahalazhary
 */
#include "../include/LIB/STDtypes.h"
#include "../include/LIB/Error_State.h"
#include "../include/MCAL/DIO/DIO_int.h"
#include "../include/HAL/Seven_Segment/SEV_SEG_config.h"
#include "../include/HAL/Seven_Segment/SEV_SEG_priv.h"

SEV_SEG_T SEV_SEG_AstrSegments [SEV_SEG_NUM]=
{
		{DIO_PORTA,DIO_PIN0,  //a
		 DIO_PORTB,DIO_PIN0,  //b
		 DIO_PORTC,DIO_PIN0,  //c
		 DIO_PORTD,DIO_PIN0,  //d
		 DIO_PORTA,DIO_PIN1,  //e
		 DIO_PORTB,DIO_PIN1,  //f
		 DIO_PORTC,DIO_PIN1,  //g
		 DIO_PORTD,DIO_PIN7,  //common
		 NOT_CONNECTED,NOT_CONNECTED,  //dot
		 COMMON_CATHODE            //type
		},  //segment 0

		{DIO_PORTA,DIO_PIN0,  //a
		 DIO_PORTB,DIO_PIN0,  //b
		 DIO_PORTC,DIO_PIN0,  //c
		 DIO_PORTD,DIO_PIN0,  //d
		 DIO_PORTA,DIO_PIN1,  //e
		 DIO_PORTB,DIO_PIN1,  //f
		 DIO_PORTC,DIO_PIN1,  //g
		 DIO_PORTD,DIO_PIN6,  //common
		 NOT_CONNECTED,NOT_CONNECTED,  //dot
		 COMMON_ANODE            //type
		},  //segment 1

};
