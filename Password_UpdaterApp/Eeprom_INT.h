/*
 * Eeprom_INT.h
 *
 *  Created on: Jul 9, 2020
 *      Author: Anwar
 */
#ifndef EEPROM_INT_H
#define EEPROM_INT_H

void Eeprom_VidInit(void);

//this funcction will return stautus if the job is done or not

u8 Eeprom_u8WriteByte(u8 DeviceId, u16 Location, u8 Byte);


/*******************************************************************************************
 * this funcction will return stautus if the job is done or not
 *  we used pointer to Byte as we return Status so no function can return two variables so we
 * return the status and the Data i read from Eeprom to a variable by pointer
 *********************************************************************************************/

u8 Eeprom_u8ReadByte(u8 DeviceId, u16 Location, u8* pByte);

#endif /*EEPROM_INT_H*/

