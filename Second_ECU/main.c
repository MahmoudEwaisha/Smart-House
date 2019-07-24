/*
 * main.c
 *
 *  Created on: Aug 12, 2017
 *      Author: Mahmoud Ewaisha
 */

#include "types.h"
#include "utils.h"
#include "DIO_Interface.h"
#include "DIO.h"
#include "DIO_Config.h"
#include "DELAY.h"
#include "External_Interrupts.h"
#include "UART.h"
#include "ADC.h"
#include "LCD.h"

extern flag;

void main(void)
{
	u8 Digital_value1, Digital_value2, Analog_value1, Analog_value2;

	u8 temp;
	u8 light;

	u8 i;
	u8 data[] = "TEMP      LIGHT";
	u8 str1[2];
	u8 str2[2];

	/* UART INIT */
	UART_Init();
	Set_Bit(SREG,7); // Global Interrupt Enable

	/* Input on ADC0 & ADC1 */
	DIO_voidSetPinDirection(DIO_PIN0 , DIO_INPUT);
	DIO_voidSetPinDirection(DIO_PIN1 , DIO_INPUT);
	/* ADC initialization */
	ADC_voidInitializeADC();

	/* LCD initialization */
	LCD_Init();

	/* Buzzer */
	DIO_voidSetPinDirection(DIO_PIN3,DIO_OUTPUT); //buzzer

	/* Motor pins */
	DIO_voidSetPinDirection(DIO_PIN16,DIO_OUTPUT);
	DIO_voidSetPinDirection(DIO_PIN17,DIO_OUTPUT);

	while(1)
	{
		if(flag != 2)  // flag = 3 ---> Deny
		{
			LCD_WriteCommand (0x01);
			while(flag != 2);
		}

		for(i=0; i<strlen(data); i++)
		{
			UART_Send(255);
			Delay(1);
			UART_Send(0);
			LCD_WriteData(data[i]);
		}

		while(flag == 2) //flag != 3 ---> Access
		{
			ADMUX=0b01100000;
			Digital_value1 = ADC_u8ReadADC();
			Analog_value1 = (Digital_value1 * 5) / 255;
			temp = (Digital_value1) ^ 0xFF;
			UART_Send(temp);
			Delay(1);

			ADMUX=0b01100001;
			Digital_value2 = ADC_u8ReadADC();
			Analog_value2 = (Digital_value2 * 5) / 255;
			UART_Send(Digital_value2);

			sprintf(str1, "%d",Analog_value1);
			sprintf(str2, "%d",Analog_value2);
			LCD_Display(str1, str2, strlen(str1));
		}
	}
}








