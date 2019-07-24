/*
 * DIO.h
 *
 *  Created on: Aug 5, 2017
 *      Author: Mahmoud Ewaisha
 */

#ifndef DIO_H_
#define DIO_H_

/* DDRA is port A direction (input/output) .. Range 0:1*/
#define DDRA     *((u8 volatile *)(0x3a))
/* PORTA output data register */
#define PORTA    *((u8 volatile *)(0x3b))
/* PINA input data register */
#define PINA     *((u8 volatile *)(0x39))


/* DDRB is port B direction (input/output) .. Range 0:1*/
#define DDRB     *((u8 volatile *)(0x37))
/* PORTB output data register */
#define PORTB    *((u8 volatile *)(0x38))
/* PINB input data register */
#define PINB     *((u8 volatile *)(0x36))


/* DDRC is port C direction (input/output) .. Range 0:1*/
#define DDRC     *((u8 volatile *)(0x34))
/* PORTC output data register */
#define PORTC    *((u8 volatile *)(0x35))
/* PINC input data register */
#define PINC     *((u8 volatile *)(0x33))


/* DDRD is port A direction (input/output) .. Range 0:1*/
#define DDRD     *((u8 volatile *)(0x31))
/* PORTD output data register */
#define PORTD    *((u8 volatile *)(0x32))
/* PIND input data register */
#define PIND     *((u8 volatile *)(0x30))






#endif /* DIO_H_ */
