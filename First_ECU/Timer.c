/*
 * Timers.c
 *
 *  Created on: Sep 8, 2017
 *      Author: Mahmoud Ewaisha
 */

#include "types.h"
#include "DIO.h"
#include "utils.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"
#include "DIO.h"
#include "Timer.h"

volatile u8 counter;


void timer1_voidInitializeTime(void)
{
	//Enable Fast PWM mode (WGM00 & WGM01)
	Set_Bit(TCCR0,3);
	Set_Bit(TCCR0,6);
	// clock (prescalar)
	/*Set_Bit(TCCR0,0);*/  //da el kan ma3mool (no prescalar) bs fih moshkela ...kol 7aga ba2et batee2a??
	Set_Bit(TCCR0,0);
	Set_Bit(TCCR0,2);
    //Compare output mode: Fast PWM
	//Set OC0 on compare match (COMM0 & COMM1)
    Set_Bit(TCCR0,4);
	Set_Bit(TCCR0,5);

	//Set the value that Timer Counter (TCNT0) will be compared to
	//OCR0 = 25;
}
