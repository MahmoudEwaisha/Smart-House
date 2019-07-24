/*
 * UART.c
 *
 *  Created on: Sep 16, 2017
 *      Author: Mahmoud Ewaisha
 */

#ifndef UART_C_
#define UART_C_


#include "types.h"
#include "utils.h"
#include "DIO_Interface.h"
#include "DIO.h"
#include "DIO_Config.h"
#include "DELAY.h"
#include "External_Interrupts.h"
#include "UART.h"


u8 UART;
u8 flag;
void __vector_13 (void) __attribute__((signal,__INTR_ATTRS));
void __vector_13 (void)
{
	UART = UDR;
	if(UART == 2)
	{
		flag = 2; //access
	}
	if(UART == 3)
	{
		flag = 3; //deny
	}

	if (UART == 0 || UART == 1)
	{
		DIO_voidWritePin(DIO_PIN16,!UART);
		DIO_voidWritePin(DIO_PIN17,UART);
	}
	if(UART == 0xFF)
	{
		DIO_voidWritePin(DIO_PIN3,DIO_HIGH);
		Delay(23000);
		DIO_voidWritePin(DIO_PIN3,DIO_LOW);
	}
}


void UART_Init(void)
{
	UBRRL = 51;
	UBRRH = 0;
	Set_Bit(UCSRB,7); //receive interrupt enable
	Set_Bit(UCSRB,3); //receive enable
	Set_Bit(UCSRB,4); //transmit enable
	Set_Bit(UCSRC,7); //This bit selects between accessing the UCSRC or the UBRRH Register. set it to one to use UCSRC

	//setting bits 1 and two to one means set character size to 8-bits (page162)
	Set_Bit(UCSRC,1);
	Set_Bit(UCSRC,2);
}


extern void UART_Send(u8 data)
{
	while(Get_Bit(UCSRA,5) == 0); //wait until last byte has been transmitted (UDR is empty)
	UDR = data;
	/*if(Get_Bit(UCSRA,6)!=1)
	{
		UDR = data;
	}
	Set_Bit(UCSRA,6);*/
}

#endif /* UART_C_ */
