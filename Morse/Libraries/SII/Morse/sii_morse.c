/*
 * morse.c
 *
 *  Created on: Apr 16, 2023
 *      Author: plunne
 */

#include "sii_morse.h"

uint8_t sii_morse_letterList[NB_MORSE_CHARACTERS] = {
	'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
	'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
	'U', 'V', 'W', 'X', 'Y', 'Z', ' '
};

uint8_t sii_morse_morseList[NB_MORSE_CHARACTERS][MORSE_CHARACTER_LENGHT] = {
	"_____", ".____", "..___", "...__", "...._", ".....", "_....", "__...", "___..", "____.",
	".__  ", "_... ", "_._. ", "_..  ", ".    ", ".._. ", "__.  ", ".... ", "..   ", ".___ ",
	"_._  ", "._.. ", "__   ", "_.   ", "___  ", ".__. ", "__._ ", "._.  ", "...  ", "_    ",
	".._  ", "..._ ", ".__  ", "_.._ ", "_.__ ", "__.. ", "     "
};

/* Message to Morse */
uint8_t SII_MORSE_GetMorseChar(uint8_t letter)
{
	// Scan if input letter is in the letter list
	for (uint8_t i=0; i < NB_MORSE_CHARACTERS; i++)
	{
		/* Lower to Upper */
		if ((letter >= 'a') && (letter <= 'z')) // If Lowercase
		{
			letter -= 32; // Convert to Uppercase
		}
		// If the input letter is in the letter list
		if (letter == sii_morse_letterList[i])
		{
			return i;	// return the respective morse character of the letter
		}
	}

	return (NB_MORSE_CHARACTERS - 1);
}

void SII_MORSE_CharToMorse(uint8_t *letter, uint8_t index)
{
	for (uint8_t i=0; i < MORSE_CHARACTER_LENGHT; i++)
	{
		letter[i] = sii_morse_morseList[index][i];
	}
}

void SII_MORSE_MessageToMorse(SII_DATA_Data_t* Data, uint8_t* morse)
{
	if ((Data->message != NULL) && (morse != NULL))
	{
		// For each character of the message
		for (uint8_t i=0; i < Data->msgSize; i++)
		{
			SII_MORSE_CharToMorse(&morse[i * MORSE_CHARACTER_LENGHT], SII_MORSE_GetMorseChar(Data->message[i]));
		}
	}
}

