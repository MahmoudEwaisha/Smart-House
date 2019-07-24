/*
 * External_Interrupts.h
 *
 *  Created on: Aug 25, 2017
 *      Author: Mahmoud Ewaisha
 */

#ifndef EXTERNAL_INTERRUPTS_H_
#define EXTERNAL_INTERRUPTS_H_



/* Bit 7 --> global interrupt enable */
#define SREG     *((u8 volatile *)(0x5F))
/* Sets the condition to fire an interrupt (2 pins for external interrupt 0 and 2 2 pins for external interrupt 1)  see page 66 */
#define MCUCR    *((u8 volatile *)(0x55))
/* Bit 6 --> external interrupt request 0 enable */
#define GICR     *((u8 volatile *)(0x5B))

void Interrupt_Init(void);

#endif /* EXTERNAL_INTERRUPTS_H_ */
