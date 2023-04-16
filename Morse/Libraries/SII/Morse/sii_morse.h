/*
 * morse.h
 *
 *  Created on: Apr 16, 2023
 *      Author: plunne
 */

#ifndef MORSE_H_
#define MORSE_H_

#include "stm32f1xx_hal.h"

#define MESSAGE_LENGHT				249
#define MORSE_CHARACTER_LENGHT		6
#define NB_MORSE_CHARACTERS			37

/* Data */
typedef struct {
	uint8_t loop;
	uint8_t iterate;
	uint8_t timer1;
	uint8_t timer2;
	uint8_t timer3;
	uint8_t msgSize;
	uint8_t message[MESSAGE_LENGHT];
	uint8_t endChar;

} SII_MORSE_Data_t;

/* Init */
void SII_MORSE_GetMessage(SII_MORSE_Data_t* Data, uint8_t* message);

/* Message to Morse */
uint8_t SII_MORSE_GetMorseChar(uint8_t letter);
void SII_MORSE_CharToMorse(uint8_t *letter, uint8_t index);
void SII_MORSE_MessageToMorse(SII_MORSE_Data_t* Data, uint8_t* morse);

/* Signal */
void SII_MORSE_SignalOutput(uint32_t timer, uint8_t output_state);
void SII_MORSE_SignalCharacter(SII_MORSE_Data_t* Data, uint8_t* morse_character);
void SII_MORSE_MorseSignal(SII_MORSE_Data_t* Data, uint8_t* morse);

#endif /* MORSE_H_ */
