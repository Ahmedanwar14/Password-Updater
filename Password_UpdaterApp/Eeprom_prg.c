/*
 * Eeprom_prg.c
 *
 *  Created on: Jul 9, 2020
 *      Author: Anwar
 */
#include "I2C_INT.h"

#include "Eeprom_INT.h"
#include "Eeprom_Cfg.h"
#include "Eeprom_Priv.h"

void Eeprom_VidInit(void)
{
	/*Intialize I2c*/
	I2c_VidInit();
}

u8 Eeprom_u8WriteByte(u8 DeviceId, u16 Location, u8 Byte)
{
	/***********************************************
	 * 1- Send start
	 * 2- check status
	 * 3- send slave address with write
	 * 4- Check status
	 * 5- Send location on data register
	 * 6- Check status
	 * 7- Send data "byte"
	 * 8- Check status
	 * 9- Send Stop
	 *
	 ***********************************************/
	 u8 SLA;
	 if(DeviceId==0)
	 {

		SLA=EEPROM_u8DEVICE_ADDRESS_0 | ((Location>>8)<<1);

	 }
	 else if(DeviceId==1)
	 {

		SLA=EEPROM_u8DEVICE_ADDRESS_1 | ((Location>>8)<<1);
	 }

	 	 I2c_VidSendStart();
	 	 if(I2c_u8CheckStatus(0x08)==1)
	 	 {
	 		 I2c_VidSendSlaveAddress(SLA);

	 		if(I2c_u8CheckStatus(0x18)==1)
	 		{
	 			I2c_VidSendData((u8)Location);//CAsting u16 values fa hya5od least 8 bits

	 			if(I2c_u8CheckStatus(0x28)==1)
	 			{
	 				I2c_VidSendData(Byte);

	 				if(I2c_u8CheckStatus(0x28)==1)
	 				{
	 					I2c_VidSendStop();
	 					return 1;
	 				}
	 			}
	 		}
	 	 }

return 0;
}



u8 Eeprom_u8ReadByte(u8 DeviceId, u16 Location, u8* pByte)
{
	/***********************************************
		 * 1- Send start
		 * 2- check status
		 * 3- Send slave address with write "Dummy Write"
		 * 4- Check status
		 * 5- Send location on data register
		 * 6- Check status
		 * 7- Send start "Repeated Start"
		 * 8-Check status
		 * 9- Send Slave Address with Read
		 * 10- Check status
		 * 11-Read the recevied byte
		 * 13- Send Stop
		 *
		 ***********************************************/
	 u8 SLA;
	 if(DeviceId==0)
	 {

		SLA=EEPROM_u8DEVICE_ADDRESS_0 | ((Location>>8)<<1);

	 }
	 else if(DeviceId==1)
	 {

		SLA=EEPROM_u8DEVICE_ADDRESS_1 | ((Location>>8)<<1);
	 }

	 	 I2c_VidSendStart();
	 	 if(I2c_u8CheckStatus(0x08)==1)
	 	 {
	 		 I2c_VidSendSlaveAddress(SLA);

	 		if(I2c_u8CheckStatus(0x18)==1)
	 		{
	 			I2c_VidSendData((u8)Location);//Casting u16 values fa hya5od least 8 bits

	 			if(I2c_u8CheckStatus(0x28)==1)
	 			{
	 				I2c_VidSendStart();

	 				if(I2c_u8CheckStatus(0x10)==1)
	 				{
	 					I2c_VidSendSlaveAddress(SLA | 0x01);//Set Slave address to do Read Operation

	 					if(I2c_u8CheckStatus(0x40)==1)
	 					{
	 						*pByte=I2c_u8ReceiveData();
	 						I2c_VidSendStop();
	 						return 1;
	 					}
	 				}
	 			}
	 		}
	 	 }

	 	 return 0;
}
