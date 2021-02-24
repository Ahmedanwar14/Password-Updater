/*
 * I2c_Priv.h
 *
 *  Created on: Jul 8, 2020
 *      Author: Anwar
 */

#define TWCR_reg 		(*(volatile u8*)0x56) //TWI Control Register
#define TWAR_reg 		(*(volatile u8*)0x22) //"slave"Address Register
#define TWDR_reg 		(*(volatile u8*)0x23) //Data REgister
#define TWSR_reg 		(*(volatile u8*)0x21) // Twi status Register
#define TWBR_reg 		(*(volatile u8*)0x20) //Bitrate register
