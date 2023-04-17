/*
 * morse.h
 *
 *  Created on: Apr 16, 2023
 *      Author: plunne
 */

#ifndef MORSE_H_
#define MORSE_H_

#include "sii_data.h"

uint8_t SII_MORSE_GetMorseChar(uint8_t letter);
void SII_MORSE_CharToMorse(uint8_t *letter, uint8_t index);
void SII_MORSE_MessageToMorse(SII_DATA_Data_t* Data, uint8_t* morse);

#endif /* MORSE_H_ */
