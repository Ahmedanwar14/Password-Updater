/*
  * main.c
 *
 *  Created on: Jul 9, 2020
 *      Author: Anwar
 */
#undef F_CPU
#define F_CPU 8000000
#include"STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART_INT.h"
#include"Eeprom_INT.h"
#include "Pass_Updater_INT.h"
#include "Pass_Updater_PRIV.h"
#include<util/delay.h>

u8 Old_Pass_of_User[4];
u8 Old_Pass_From_Eeprom[4];
u8 New_Pass_Frm_User[4];
u8 Confirmation_Pass[4];
u8 Old_Pass_flag;
	u8 Rec_Data_Uart;
	u8 Comp_Flag;
void main()
{

	Uart_vidInit();
	Eeprom_VidInit();


	Uart_u8SendString("Welcome to Password Updater 1");
		_delay_ms(100);

		Eeprom_u8ReadByte(0,16,&Old_Pass_flag);
		_delay_ms(10);
	if(Old_Pass_flag==1)
	{
		Get_Pass_From_Eeprom(Old_Pass_From_Eeprom);// Reading Old PAssword from EEProm

		Uart_u8SendString("please Enter Your Password 2");
		_delay_ms(100);
		Entered_Pass(Old_Pass_of_User);//the User Enter His Password
		Comp_Flag=u8Compare_Pass(Old_Pass_From_Eeprom,Old_Pass_of_User);

		if(Comp_Flag==1)
		{

					Uart_u8SendString("Do You Want To Update Your Password ? 3");
					_delay_ms(100);
					Uart_u8SendString("Press Y or N 4");
					_delay_ms(100);
					Rec_Data_Uart=Uart_u8ReceiveByte();
					_delay_ms(500);

					if(Rec_Data_Uart=='y')//user send that he want to change his password
					{

						New_Pass_Update(New_Pass_Frm_User,Confirmation_Pass);

						Comp_Flag = u8Compare_Pass(New_Pass_Frm_User,Confirmation_Pass);

						if(Comp_Flag==1)
						{
							Update_Pass(New_Pass_Frm_User);
						}

						else if(Comp_Flag==0)
						{
								while(Comp_Flag==0)
								{
									New_Pass_Update(New_Pass_Frm_User,Confirmation_Pass);
									Comp_Flag=u8Compare_Pass(New_Pass_Frm_User,Confirmation_Pass);
								}
							Update_Pass(New_Pass_Frm_User);
							Comp_Flag=0;
						}


				}
			else if(Rec_Data_Uart=='n')
					{
						Uart_u8SendString("Thank you for Using Password Updater 7");
						_delay_ms(100);

					}

		}
		else // if the user entered his old password wrong
		{
			u8 Wrong_count=0;
			for(u8 i=0;i<3;i++)
			{
				Entered_Pass(Old_Pass_of_User);

				Comp_Flag = u8Compare_Pass(Old_Pass_From_Eeprom,Old_Pass_of_User);

				if(Comp_Flag==1)
					break;
				else
					Wrong_count++; // count how many wrong times he entered the wrong password
			}
			if (Wrong_count==3)
			{
				Uart_u8SendString("Your Account is Blocked Please Enter Admin's Password 10");
				_delay_ms(100);
			}
		}

	}
	else
	{
		New_Pass_Update(New_Pass_Frm_User,Confirmation_Pass);

		Comp_Flag=u8Compare_Pass(New_Pass_Frm_User,Confirmation_Pass);

		if(Comp_Flag==1)
				{
					Update_Pass(New_Pass_Frm_User);
				}
			else if(Comp_Flag==0)
				{
					while(Comp_Flag==0)
						{
							Uart_u8SendString("You password don't match please write it again");

							New_Pass_Update(New_Pass_Frm_User,Confirmation_Pass);

							Comp_Flag = u8Compare_Pass(New_Pass_Frm_User,Confirmation_Pass);
						}
							Uart_u8SendString("Your Password is Updated Successfully");
							_delay_ms(100);
							Comp_Flag=0;
							Eeprom_u8WriteByte(0,16,1);
				}


	}

while(1);
}


