/*
 * I2C_Cfg.h
 *
 *  Created on: Jul 8, 2020
 *      Author: Anwar
 */
/*TWCR Register Bits*/
#define TWINT			7 //Interrupt enable
#define TWEA			6 //Enable ACK. Bit
#define TWSTA			5 //Start Condition bit
#define TWSTO			4 // Stop condition bit Could be used in slave mode to make the slave invisible if slave detect an error
#define TWWC			3 // Write collision flag
#define TWEN			2 // I2c Enable Bit
#define TWEIE			0 //Interrupt Enable


