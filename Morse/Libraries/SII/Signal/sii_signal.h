/*
 * sii_signal.h
 *
 *  Created on: 17 avr. 2023
 *      Author: Lena.savylarigaldie
 */

#ifndef SII_SIGNAL_SII_SIGNAL_H_
#define SII_SIGNAL_SII_SIGNAL_H_

#include "sii_morse.h"

void SII_SIGNAL_SignalOutput(uint32_t timer, uint8_t output_state);
void SII_SIGNAL_SignalCharacter(SII_DATA_Data_t* Data, uint8_t* morse_character);
void SII_SIGNAL_MorseSignal(SII_DATA_Data_t* Data, uint8_t* morse_message);

#endif /* SII_SIGNAL_SII_SIGNAL_H_ */
