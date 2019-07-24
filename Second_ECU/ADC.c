/*
 * ADC.c
 *
 *  Created on: Mar 11, 2017
 *      Author: Mahmoud Khaled
 */

#include "types.h"
#include "Utils.h"
#include "ADC.h"


extern void ADC_voidInitializeADC (void)
{
	/*Vref=5v - ADC0 - 8-bits ADC*/
	ADMUX=0b01100000;

	/*no interrupt
	 * no auto trigger
	 * prescaler=2
	 * enable ADC*/
	ADCSRA=0b10000000;
}



extern u8 ADC_u8ReadADC (void)
{
	/*Start conversion*/
	Set_Bit(ADCSRA,6);

	/*polling on the ADC flag*/
	while (Get_Bit(ADCSRA,4)==0);

	/*Clear the ADC flag by writing logical one */
	Set_Bit(ADCSRA,4);

	/*return ADCH value*/
	return ADCH;
}
