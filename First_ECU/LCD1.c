/*
 * LCD.c

 *
 *      @created on: Dec 31, 2016
 *      @author: Mahmoud Khaled
 *      @file  LCD function
 *      @see
 */

#include"types.h"
#include"Utils.h"
#include"DIO.h"
#include "DIO_Interface.h"
#include"Delay.h"
#include"LCD.h"

/* Compares contents of two strings, returns 1 if they're the same */
u8 string_cmp(u8 *str1, u8 *str2, u8 size1, u8 size2)
{
	u8 i;
	if(size1 != size2)return 0;
	for (i=0; i<strlen(str1); i++)
	{
		if(*(str1+i) == *(str2+i))continue;
		if(*(str1+i) != *(str2+i))return 0;
	}
	return 1;
}

/* LCD initialization */
extern void LCD_Init(void)
{
	/* Pins initialization */
	DIO_voidSetPinDirection(DIO_PIN4, DIO_OUTPUT);   //PA4
	DIO_voidSetPinDirection(DIO_PIN5, DIO_OUTPUT);   //PA5
	DIO_voidSetPinDirection(DIO_PIN6, DIO_OUTPUT);   //PA6
	DIO_voidSetPinDirection(DIO_PIN7, DIO_OUTPUT);   //PA7

	DIO_voidSetPinDirection(DIO_PIN0, DIO_OUTPUT);   //PA0
	DIO_voidSetPinDirection(DIO_PIN1, DIO_OUTPUT);   //PA1
	DIO_voidSetPinDirection(DIO_PIN2, DIO_OUTPUT);   //PA2
	/*-----------------------------------------------------------------*/

	/* Start init process (follow the datasheet */
    //delay more than 30 ms
	Delay(100);

	//LCD_WriteCommand (0x20);
	//LCD_WriteCommand (0x20);

	LCD_WriteCommand (0x02);

	//write a command 0b00101000  N=1, F=0 4-bits
	LCD_WriteCommand (0x28);
	// Delay more than 39 us
	Delay(50);

	//LCD_WriteCommand (0x00);
	//write a command 0b0000 1100 ; // D=1, C=0 , B=0
	LCD_WriteCommand (0x0C);
	//delay more than 39 us
	Delay(50);

	//LCD_WriteCommand (0x00);
	// write a command  0b 00000001; // clear lcd
	LCD_WriteCommand (0x01);
	//delay at least 1.5 ms
	Delay(100);
	LCD_WriteCommand (0x80);
}



extern void LCD_WriteData (u8 data)
{
	// RS=1
	Set_Bit(PORTA,0);
	//R/W=0
	Clr_Bit(PORTA,1);
	// Data bus = data
	//PORTA= (Get_Hnibble(data))<<4 ;
	DIO_voidWritePin(DIO_PIN4,(Get_Bit(data,4)));
	DIO_voidWritePin(DIO_PIN5,(Get_Bit(data,5)));
	DIO_voidWritePin(DIO_PIN6,(Get_Bit(data,6)));
	DIO_voidWritePin(DIO_PIN7,(Get_Bit(data,7)));



	//E=1
	Set_Bit(PORTA,2);
	// Delay 2ms

	Delay(20);
	//E=0
	Clr_Bit(PORTA,2);

	Delay(100);

	// RS=1
	Set_Bit(PORTA,0);
	//R/W=0
	Clr_Bit(PORTA,1);
	// Data bus = data
	//PORTA= (Get_Lnibble(data))<<4 ;
	DIO_voidWritePin(DIO_PIN4,(Get_Bit(data,0)));
	DIO_voidWritePin(DIO_PIN5,(Get_Bit(data,1)));
	DIO_voidWritePin(DIO_PIN6,(Get_Bit(data,2)));
	DIO_voidWritePin(DIO_PIN7,(Get_Bit(data,3)));


	//E=1
	Set_Bit(PORTA,2);
	// Delay 2ms

	Delay(20);
	//E=0
	Clr_Bit(PORTA,2);

	Delay(100);
}



extern void LCD_WriteCommand (u8 command)
{
	// RS=0
	Clr_Bit(PORTA,0);
	//R/W=0
	Clr_Bit(PORTA,1);
	// Data bus = command
	//PORTA = (Get_Hnibble(command))<<4 ;
	DIO_voidWritePin(DIO_PIN4,(Get_Bit(command,4)));
	DIO_voidWritePin(DIO_PIN5,(Get_Bit(command,5)));
	DIO_voidWritePin(DIO_PIN6,(Get_Bit(command,6)));
	DIO_voidWritePin(DIO_PIN7,(Get_Bit(command,7)));


	//E=1
	Set_Bit(PORTA,2);
	// Delay 2ms
	Delay(20);
	//E=0
	Clr_Bit(PORTA,2);

	Delay(100);

	// RS=0
	Clr_Bit(PORTA,0);
	//R/W=0
	Clr_Bit(PORTA,1);
	// Data bus = command
	//PORTA = (Get_Lnibble(command))<<4 ;
	DIO_voidWritePin(DIO_PIN4,(Get_Bit(command,0)));
	DIO_voidWritePin(DIO_PIN5,(Get_Bit(command,1)));
	DIO_voidWritePin(DIO_PIN6,(Get_Bit(command,2)));
	DIO_voidWritePin(DIO_PIN7,(Get_Bit(command,3)));


	//E=1
	Set_Bit(PORTA,2);
	// Delay 2ms
	Delay(20);
	//E=0
	Clr_Bit(PORTA,2);
	Delay(100);
}



