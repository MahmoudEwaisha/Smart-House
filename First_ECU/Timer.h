/*
 * Timer.h
 *
 *  Created on: Sep 8, 2017
 *      Author: Mahmoud Ewaisha
 */

#ifndef TIMER_H_
#define TIMER_H_

//#define TCNT0     *((u8 volatile *)(0x52))
#define TIMSK     *((u8 volatile *)(0x59))
#define TCCR0     *((u8 volatile *)(0x53))
#define OCR0      *((u8 volatile *)(0x5C))
void timer0_voidInitializeTime(void);

#endif /* TIMER_H_ */
