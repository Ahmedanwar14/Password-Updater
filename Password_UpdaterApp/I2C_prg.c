/*
 * I2C_prg.c
 *
 *  Created on: Jul 8, 2020
 *      Author: Anwar
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "I2C_INT.h"
#include "I2C_Cfg.h"
#include "I2c_Priv.h"


void I2c_VidInit(void)
{
	/*Enable I2c*/
	SET_BIT(TWCR_reg,TWEN);

	/*Enable REceiver acknowledge*/
	SET_BIT(TWCR_reg,TWEA);

	/*SCL=Fcpu/(16+(2xTWBRx4^TWPS))=250 khz*/
	TWBR_reg=2;
	CLR_BIT(TWSR_reg,1);
	CLR_BIT(TWSR_reg,0);

	/* Device's Own address = 1 and disable General call*/
	TWAR_reg=2; //0b00000010


}

void I2c_VidSendStart(void)
{
	/*Send Start Condition & Clear flag*/
	TWCR_reg= (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);

	/*wait till this job done*/
	while(GET_BIT(TWCR_reg,7)==0);

}

void I2c_VidSendStop(void)
{

	/*Send Stop Condition & Clear flag*/
		TWCR_reg= (1<<TWINT) | (1<<TWSTO) | (1<<TWEN);

}
void I2c_VidSendSlaveAddress(u8 SlaveAddress_W_R)
{
	/*Load Slave Address in TWDR*/
	TWDR_reg=SlaveAddress_W_R;

	/*Clear flag to start the next job*/
	TWCR_reg= (1<<TWINT) | (1<<TWEN);

	/*wait till this job done*/
		while(GET_BIT(TWCR_reg,7)==0);
}

void I2c_VidSendData(u8 Data)
{
	/*Load Data in TWDR*/
		TWDR_reg=Data;

		/*Clear flag to start the next job*/
		TWCR_reg= (1<<TWINT) | (1<<TWEN);

		/*wait till this job done*/
		while(GET_BIT(TWCR_reg,7)==0);
}
u8 I2c_u8ReceiveData(void)
{

	/*Clear flag to start the next job*/
		TWCR_reg= (1<<TWINT) | (1<<TWEN);

	/*wait till this job done*/
		while(GET_BIT(TWCR_reg,7)==0);

	/*Return the received data*/
		return TWDR_reg;

}

u8 I2c_u8CheckStatus(u8 ExpectedStatus)
{
	if(ExpectedStatus == (TWSR_reg & 0xF8))
	{
		return 1;
	}
	else
	{
		return 0;
	}

}
