/*
 * Pass_Updater_Prog.c
 *
 *  Created on: Jul 9, 2020
 *      Author: Anwar
 */
#include "Pass_Updater_INT.h"
#include <util/delay.h>
#include "UART_INT.h"
#include "Eeprom_INT.h"
#include "Pass_Updater_PRIV.h"

void New_Pass_Update(u8 New_Pass[4],u8 Conf_Pass[4])
{
					Uart_u8SendString("Please Enter Your New Password AAA");
					for(u8 i=0 ; i<4 ; i++)
					{
						New_Pass[i]=Uart_u8ReceiveByte();
						Uart_vidSendByte(New_Pass[i]);
						Uart_vidSendByte('\r');
						Uart_vidSendByte('\n');
						_delay_ms(10);
					}
					Uart_u8SendString("Please Re-Enter Your New PAssword BBB");
					for(u8 i=0 ; i<4 ; i++)
					{
						Conf_Pass[i]=Uart_u8ReceiveByte();
						Uart_vidSendByte(Conf_Pass[i]);
						Uart_vidSendByte('\r');
						Uart_vidSendByte('\n');
						_delay_ms(10);
					}

}

void Entered_Pass(u8 Entered_Pass[4])
{
	Uart_u8SendString("Please Enter Your Password....");
						for(u8 i=0 ; i<4 ; i++)
						{
							Entered_Pass[i]=Uart_u8ReceiveByte();
							Uart_vidSendByte(Entered_Pass[i]);
													Uart_vidSendByte('\r');
													Uart_vidSendByte('\n');
						}
}
u8 u8Compare_Pass(u8 Old_Pass[4],u8 New_Pass[4])
{
	u8 Count=0;
	u8 Flag;
	for(u8 i=0 ; i<4 ; i++)
		{

		if(Old_Pass[i]==New_Pass[i])
			{
				Count++;
				Uart_vidSendByte(Old_Pass[i]);
				Uart_vidSendByte('\r');
				Uart_vidSendByte('\n');
			}

		}
	if(Count==4)
	{
		Flag=1;
	}
	else
	{
		Flag=0;
	}
	return Flag;

}
void Get_Pass_From_Eeprom(u8 u8Get_Pass_from_Eeprom[4])
{
	Uart_u8SendString("Now i'm geeting your PAssword from EEProm");
	Uart_vidSendByte('\r');
	Uart_vidSendByte('\n');
	u8 Received_data;
	for(u8 i=0;i<4;i++)
	{
		Eeprom_u8ReadByte(0,(i+Pass_Location_start),&Received_data);
		_delay_ms(10);
			u8Get_Pass_from_Eeprom[i]=Received_data;
			_delay_ms(10);
			Uart_vidSendByte(u8Get_Pass_from_Eeprom[i]);
			Uart_vidSendByte('\r');
			Uart_vidSendByte('\n');
			Uart_vidSendByte(Received_data);
			Uart_vidSendByte('\r');
			Uart_vidSendByte('\n');
			_delay_ms(10);
	}



}

void Update_Pass(u8 New_Password[4])
{

						for(u8 i=0;i<4;i++)
							{

								u8 Data=New_Password[i];
								Eeprom_u8WriteByte(0,i+Pass_Location_start,Data);
								_delay_ms(10);
								Uart_vidSendByte(Data);
							}
								Uart_u8SendString("Your Password is Updated Successfully");
								_delay_ms(100);
								Eeprom_u8WriteByte(0,Old_Pass_flag_location,'1');
}
