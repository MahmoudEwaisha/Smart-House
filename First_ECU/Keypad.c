/*
 * Keypad.c
 *
 *  Created on: Nov 24, 2017
 *      Author: Mahmoud Ewaisha
 */


#include "types.h"
#include "utils.h"
#include "DIO_Interface.h"
#include "DIO.h"
#include "DIO_Config.h"
#include "DELAY.h"

void Keypad_Init(void)
{
	/* rows */
	DIO_voidSetPinDirection(DIO_PIN16,DIO_OUTPUT);  //PC0
	DIO_voidSetPinDirection(DIO_PIN17,DIO_OUTPUT);  //PC1
	DIO_voidSetPinDirection(DIO_PIN18,DIO_OUTPUT);  //PC2
	DIO_voidSetPinDirection(DIO_PIN19,DIO_OUTPUT);  //PC3
	/* columns */
	DIO_voidSetPinDirection(DIO_PIN20,DIO_INPUT);  //PC4
	DIO_voidSetPinDirection(DIO_PIN21,DIO_INPUT);  //PC5
	DIO_voidSetPinDirection(DIO_PIN22,DIO_INPUT);  //PC6
}

u8 scankp(void)
{
	u8 x = '?';

	DIO_voidWritePin(DIO_PIN16,DIO_HIGH);
	DIO_voidWritePin(DIO_PIN17,DIO_HIGH);
	DIO_voidWritePin(DIO_PIN18,DIO_HIGH);
	DIO_voidWritePin(DIO_PIN19,DIO_HIGH);
	DIO_voidWritePin(DIO_PIN20,DIO_HIGH);
	DIO_voidWritePin(DIO_PIN21,DIO_HIGH);
	DIO_voidWritePin(DIO_PIN22,DIO_HIGH);

	while (x == '?')
	{
		DIO_voidWritePin(DIO_PIN16, DIO_LOW);
		if(! DIO_u8ReadPin(20)){ x = '1'; while(! DIO_u8ReadPin(20));}
		if(! DIO_u8ReadPin(21)){ x = '2'; while(! DIO_u8ReadPin(21));}
		if(! DIO_u8ReadPin(22)){ x = '3'; while(! DIO_u8ReadPin(22));}
		DIO_voidWritePin(DIO_PIN16, DIO_HIGH);


		DIO_voidWritePin(DIO_PIN17, DIO_LOW);
		if(! DIO_u8ReadPin(20)){ x = '4'; while(! DIO_u8ReadPin(20));}
		if(! DIO_u8ReadPin(21)){ x = '5'; while(! DIO_u8ReadPin(21));}
		if(! DIO_u8ReadPin(22)){ x = '6'; while(! DIO_u8ReadPin(22));}
		DIO_voidWritePin(DIO_PIN17, DIO_HIGH);


		DIO_voidWritePin(DIO_PIN18, DIO_LOW);
		if(! DIO_u8ReadPin(20)){ x = '7'; while(! DIO_u8ReadPin(20));}
		if(! DIO_u8ReadPin(21)){ x = '8'; while(! DIO_u8ReadPin(21));}
		if(! DIO_u8ReadPin(22)){ x = '9'; while(! DIO_u8ReadPin(22));}
		DIO_voidWritePin(DIO_PIN18, DIO_HIGH);


		DIO_voidWritePin(DIO_PIN19, DIO_LOW);
		if(! DIO_u8ReadPin(20)){ x = '0'; while(! DIO_u8ReadPin(20));}
		if(! DIO_u8ReadPin(21)){ x = '0'; while(! DIO_u8ReadPin(21));}
		if(! DIO_u8ReadPin(22)){ x = '0'; while(! DIO_u8ReadPin(22));}
		DIO_voidWritePin(DIO_PIN19, DIO_HIGH);
	}
	return x;
}
