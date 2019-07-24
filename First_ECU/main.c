/*
 * main.c
 *
 *  Created on: Aug 12, 2017
 *      Author: Mahmoud Ewaisha
 */

#include "string.h"
#include "types.h"
#include "utils.h"
#include "DIO_Interface.h"
#include "DIO.h"
#include "DIO_Config.h"
#include "DELAY.h"
#include "Keypad.h"
#include "LCD.h"
#include "External_Interrupts.h"
#include "Timer.h"

extern flag;
extern temp;
extern light;

u8 welcome1[] = "Welcome Mahmoud";
u8 welcome2[] = "Welcome Peter";
u8 welcome3[] = "Welcome Shady";
u8 wrong [] = "WRONG PASSWORD";
u8 pass1 [] = "123";
u8 pass2 [] = "456";
u8 pass3 [] = "789";
u8 last1[] = "Last Entered: Mahmoud";
u8 last2[] = "Last Entered: Shady";
u8 last3[] = "Last Entered: peter";


void main(void)
{
	u8 i, x, counter = 0;
	/* Interrupts (0&1) INIT */
	Interrupt_Init();

	/* UART INIT */
	UART_Init();

	/* LCD initialization */
	LCD_Init();

	/* KEYPAD INIT */
	Keypad_Init();

	DIO_voidSetPinDirection(DIO_PIN8,DIO_OUTPUT);  //LED
	DIO_voidSetPinDirection(DIO_PIN23,DIO_OUTPUT); //buzzer

	/**/
	DIO_voidSetPinDirection(DIO_PIN13,DIO_OUTPUT);
	DIO_voidSetPinDirection(DIO_PIN14,DIO_OUTPUT);
	DIO_voidSetPinDirection(DIO_PIN15,DIO_OUTPUT);

	/* Timer INIT */
	timer1_voidInitializeTime();
	DIO_voidSetPinDirection(DIO_PIN11,DIO_OUTPUT);

	u8 str_in[4];
	u8 password[] = "Password: ";

	OCR0 = 255;

	while(1)
	{
		while (1) //while loop for password , if the entered pass is correct, break to the main while loop
		{
			LCD_WriteCommand (0x01);
			for(i=0; i<strlen(password); i++)
			{
				LCD_WriteData(password[i]);
			}

			for(i=0; i<3; i++)
			{
				x = scankp();
				str_in[i] = x;
				LCD_WriteData('*');
			}

			if(string_cmp(str_in, pass1, strlen(str_in), strlen(pass1)))
			{
				LCD_WriteCommand(0xC0);
				for(i=0; i<strlen(welcome1); i++)
				{
					LCD_WriteData(welcome1[i]);
				}
				break;
			}

			else if(string_cmp(str_in, pass2, strlen(str_in), strlen(pass2)))
			{
				LCD_WriteCommand(0xC0);
				for(i=0; i<strlen(welcome2); i++)
				{
					LCD_WriteData(welcome2[i]);
				}
				break;
			}

			else if(string_cmp(str_in, pass3, strlen(str_in), strlen(pass3)))
			{
				LCD_WriteCommand(0xC0);
				for(i=0; i<strlen(welcome3); i++)
				{
					LCD_WriteData(welcome3[i]);
				}
				break;
			}

			else
			{
				counter++;
				if(counter == 3)
				{
					LCD_WriteCommand(0xC0);
					for(i=0; i<strlen(wrong); i++)
					{
						LCD_WriteData(wrong[i]);
					}
					DIO_voidWritePin(DIO_PIN23,DIO_HIGH);
					UART_Send(0xFF); //trigger buzzer in second led
					Delay(23000); //10 sec delay
					DIO_voidWritePin(DIO_PIN23,DIO_LOW);
					counter = 0;
				}
				else
				{
					LCD_WriteCommand(0xC0);
					for(i=0; i<strlen(wrong); i++)
					{
						LCD_WriteData(wrong[i]);
					}
					Delay(3500);
				}
			}
		}

		flag = 2; // 2 = access
		UART_Send(flag);
		while(flag != 3) //main loop, it'll be 3 in the interrupt associated with a switch
		{
			OCR0 = temp;
			if (light < 20)
			{
				DIO_voidWritePin(DIO_PIN13 , DIO_LOW);
				DIO_voidWritePin(DIO_PIN14 , DIO_LOW);
				DIO_voidWritePin(DIO_PIN15 , DIO_LOW);
			}
			else if (light >= 20 && light < 100)
			{
				DIO_voidWritePin(DIO_PIN13 , DIO_HIGH);
				DIO_voidWritePin(DIO_PIN14 , DIO_LOW);
				DIO_voidWritePin(DIO_PIN15 , DIO_LOW);
			}
			else if (light >= 100 && light < 190)
			{
				DIO_voidWritePin(DIO_PIN13 , DIO_HIGH);
				DIO_voidWritePin(DIO_PIN14 , DIO_HIGH);
				DIO_voidWritePin(DIO_PIN15 , DIO_LOW);
			}
			else if (light >= 190)
			{
				DIO_voidWritePin(DIO_PIN13 , DIO_HIGH);
				DIO_voidWritePin(DIO_PIN14 , DIO_HIGH);
				DIO_voidWritePin(DIO_PIN15 , DIO_HIGH);
			}
		}
		OCR0 = 255;
		DIO_voidWritePin(DIO_PIN13 , DIO_LOW);
		DIO_voidWritePin(DIO_PIN14 , DIO_LOW);
		DIO_voidWritePin(DIO_PIN15 , DIO_LOW);
	}
}





