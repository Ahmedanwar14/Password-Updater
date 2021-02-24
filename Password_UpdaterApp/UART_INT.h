/*
 * UART_INT.h
 *
 *  Created on: Jul 9, 2020
 *      Author: Anwar
 */

#ifndef UART_INT_H_
#define UART_INT_H_

void Uart_vidInit(void);

void Uart_vidSendByte(u8 Byte);

u8   Uart_u8ReceiveByte(void);

void Uart_u8SendString(char Pu8Data[]);
#endif /* UART_INT_H_ */
