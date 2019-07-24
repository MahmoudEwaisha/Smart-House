/*
 * Interrupts.c
 *
 *  Created on: Nov 24, 2017
 *      Author: Mahmoud Ewaisha
 */

#include "UART.h"

#include "types.h"
#include "utils.h"
#include "DIO_Interface.h"
#include "DIO.h"
#include "DIO_Config.h"
#include "UART.h"
#include "DELAY.h"
#include "External_Interrupts.h"

u8 flag;

//----------------------------------------------------------------------------------------------------------------
void PWM_MOTOR_send(void)
{
	static u8 motor_flag = 0;
	if(motor_flag == 0)
	{
		UART_Send(1);
		motor_flag = 1;
	}
	else if(motor_flag == 1)
	{
		UART_Send(0);
		motor_flag = 0;
	}
}
//----------------------------------------------------------------------------------------------------------------


void __vector_1 (void) __attribute__((signal,__INTR_ATTRS)); //INT0
void __vector_1 (void)  //INT0
{
	UART_Send(3);
	flag = 3;  // 3=deny
}

void __vector_2 (void) __attribute__((signal,__INTR_ATTRS)); //INT1
void __vector_2 (void)  //INT1
{
	if(flag == 2)
	{
		PWM_MOTOR_send();
	}
}



void Interrupt_Init(void)
{
	/* Enable global interrupt */
	Set_Bit(SREG,7);
	/* Enable external interrupt 0 */
	Set_Bit(GICR,6);
	/* Interrupt 0 on low */
	Clr_Bit(MCUCR,0);
	Clr_Bit(MCUCR,1);
	/* Enable external interrupt 1 */
	Set_Bit(GICR,7);
	/* Interrupt 1 on low */
	Clr_Bit(MCUCR,2);
	Clr_Bit(MCUCR,3);
	DIO_voidWritePin(27,1);
	DIO_voidWritePin(26,1);
}




