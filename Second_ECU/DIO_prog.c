/*
 * DIO_prog.c
 *
 *  Created on: Aug 10, 2017
 *      Author: Mahmoud Ewaisha
 */

#include "types.h"
#include "DIO.h"
#include "utils.h"


#include "DIO_Interface.h"
#include "DIO_Config.h"



extern void DIO_voidSetPinDirection (u8 Copy_u8PinNumber, u8 Copy_u8PinDirection)
{
	if(Copy_u8PinNumber>=0 && Copy_u8PinNumber<=7)
	{
		Assign_Bit(DDRA,(Copy_u8PinNumber%8),Copy_u8PinDirection);
	}

	else if(Copy_u8PinNumber>=8 && Copy_u8PinNumber<=15)
	{
		Assign_Bit(DDRB,(Copy_u8PinNumber%8) , Copy_u8PinDirection);
	}

	else if(Copy_u8PinNumber>=16 && Copy_u8PinNumber<=23)
	{
		Assign_Bit(DDRC,(Copy_u8PinNumber%8) , Copy_u8PinDirection);
	}
	else if(Copy_u8PinNumber>=24 && Copy_u8PinNumber<=31)
	{
		Assign_Bit(DDRD,(Copy_u8PinNumber%8) , Copy_u8PinDirection);
	}
}

extern void DIO_voidWritePin (u8 Copy_u8PinNumber, u8 Copy_u8PinValue)
{
	if(Copy_u8PinNumber>=0 && Copy_u8PinNumber<=7)
	{
		Assign_Bit(PORTA,(Copy_u8PinNumber%8),Copy_u8PinValue);
	}

	else if(Copy_u8PinNumber>=8 && Copy_u8PinNumber<=15)
	{
		Assign_Bit(PORTB,(Copy_u8PinNumber%8) , Copy_u8PinValue);
	}

	else if(Copy_u8PinNumber>=16 && Copy_u8PinNumber<=23)
	{
		Assign_Bit(PORTC,(Copy_u8PinNumber%8) , Copy_u8PinValue);
	}
	else if(Copy_u8PinNumber>=24 && Copy_u8PinNumber<=31)
	{
		Assign_Bit(PORTD,(Copy_u8PinNumber%8) , Copy_u8PinValue);
	}
}


extern u8 DIO_u8ReadPin (u8 Copy_u8PinNumber)
{
	u8 Local_u8ReadPin = 0;

	if(Copy_u8PinNumber>=0 && Copy_u8PinNumber<=7)
	{
		Local_u8ReadPin = Get_Bit(PINA,((Copy_u8PinNumber)%8));
	}

	if(Copy_u8PinNumber>=8 && Copy_u8PinNumber<=15)
	{
		Local_u8ReadPin = Get_Bit(PINB,((Copy_u8PinNumber)%8));
	}

	if(Copy_u8PinNumber>=16 && Copy_u8PinNumber<=23)
	{
		Local_u8ReadPin = Get_Bit(PINC,((Copy_u8PinNumber)%8));
	}

	if(Copy_u8PinNumber>=24 && Copy_u8PinNumber<=31)
	{
		Local_u8ReadPin = Get_Bit(PIND,((Copy_u8PinNumber)%8));
	}
	return Local_u8ReadPin;
}











