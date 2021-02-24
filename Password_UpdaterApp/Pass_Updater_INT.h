/*
 * Pass_Updater_INT.h
 *
 *  Created on: Jul 9, 2020
 *      Author: Anwar
 */
#ifndef PASS_UPDATER_H_
#define PASS_UPDATER_H_

#include "STD_TYPES.h"

void New_Pass_Update(u8 New_Pass[4],u8 Conf_New_Pass[4]);
u8 u8Compare_Pass(u8 Old_Pass[4],u8 New_Pass[4]);
void Get_Pass_From_Eeprom(u8 u8Get_Pass_from_Eeprom[4]);
void Entered_Pass(u8 Entered_Pass[4]);
void Update_Pass(u8 New_Password[4]);

#endif
