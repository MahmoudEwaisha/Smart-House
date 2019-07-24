/*
 * UART.h
 *
 *  Created on: Sep 15, 2017
 *      Author: Mahmoud Ewaisha
 */

#ifndef UART_H_
#define UART_H_

#define UDR       *((u8 volatile *)(0x2C))
#define UBRRH     *((u8 volatile *)(0x40))
#define UBRRL     *((u8 volatile *)(0x29))
#define UCSRA     *((u8 volatile *)(0x2B))
#define UCSRB     *((u8 volatile *)(0x2A))
#define UCSRC     *((u8 volatile *)(0x40))



#endif /* UART_H_ */
