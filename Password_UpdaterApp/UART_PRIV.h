/*
 * UART_PRIV.h
 *
 *  Created on: Jul 9, 2020
 *      Author: Anwar
 */
#ifndef UART_PRIV_H_
#define UART_PRIV_H_

#define UDR      (*(volatile u8*) 0x2C)
#define UCSRA    (*(volatile u8*) 0x2B)
#define UCSRB    (*(volatile u8*) 0x2A)
#define UCSRC    (*(volatile u8*) 0x40)
#define UBRRL    (*(volatile u8*) 0x29)
#define UBRRH    (*(volatile u8*) 0x40)

#endif /* UART_PRIV_H_ */

