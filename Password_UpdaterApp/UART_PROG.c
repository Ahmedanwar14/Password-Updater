/*
 * UART_PROG.c
 *
 *  Created on: Jul 9, 2020
 *      Author: Anwar
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Uart_int.h"
#include "Uart_priv.h"
#include "Uart_cfg.h"

void Uart_vidInit(void)
{
	/* Temporary variable to write UCSRC register */
	u8 Temp_u8UcsrcData;

	/* Clear any rubbish values in the variable */
	Temp_u8UcsrcData = 0;

	/* Enable Rx and Tx */
	SET_BIT(UCSRB,4); //Rx
	SET_BIT(UCSRB,3); //Tx

	/* Asynchronous Mode */
	CLR_BIT(Temp_u8UcsrcData,6);

	/* Disable Parity checking */
	CLR_BIT(Temp_u8UcsrcData,5);
	CLR_BIT(Temp_u8UcsrcData,4);

	/* Select 1-Bit Stop */
	CLR_BIT(Temp_u8UcsrcData,3);

	/* Select 8-Bit Character Size */
	CLR_BIT(UCSRB,2);
	SET_BIT(Temp_u8UcsrcData,2);
	SET_BIT(Temp_u8UcsrcData,1);

	/* Update UCSRC register with Temp Data */
	UCSRC = Temp_u8UcsrcData;

	/* Configure "9600" Baudrate */
	CLR_BIT(UCSRA,1);
	UBRRH = 0;
	UBRRL = 51;
}

void Uart_vidSendByte(u8 Byte)
{
	/* Waiting till UDR register is Empty */
	while(GET_BIT(UCSRA,5) == 0);

	/* Update UDR register with the data needs to be sent */
	UDR = Byte;
}

u8   Uart_u8ReceiveByte(void)
{
	/* Waiting till RxC flag raise */
	while(GET_BIT(UCSRA,7) == 0);

	/* Return the received Byte */
	return UDR;
}


void Uart_u8SendString(char Pu8Data[])
{
	u8 u8LoopCtr=0;
	while(Pu8Data[u8LoopCtr]!=0x00)//fakt l gomla dy *(Pu8DAta+u8loopctr) da nzakr pointer aw c ya man b2a
	{
		Uart_vidSendByte(Pu8Data[u8LoopCtr]);
		u8LoopCtr++;

	}
	Uart_vidSendByte('\r');
	Uart_vidSendByte('\n');
}
