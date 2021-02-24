/*
 * I2C_INT.h
 *
 *  Created on: Jul 8, 2020
 *      Author: Anwar
 */

#include "STD_TYPES.h"
void I2c_VidInit(void);


void I2c_VidSendStart(void);


void I2c_VidSendStop(void);

void I2c_VidSendSlaveAddress(u8 SlaveAddress_W_R);


void I2c_VidSendData(u8 Data);

u8 I2c_u8ReceiveData(void);


u8 I2c_u8CheckStatus(u8 ExpectedStatus);
