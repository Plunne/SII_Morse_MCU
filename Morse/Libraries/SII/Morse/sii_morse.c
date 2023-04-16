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

/* Init */
void SII_MORSE_GetMessage(SII_MORSE_Data_t* Data, uint8_t* message)
{
	if (Data->msgSize <= MESSAGE_LENGHT)
	{
		for (uint8_t i=0; i < Data->msgSize; i++)
		{
			Data->message[i] = message[i];
		}

	}
}

/* Message to Morse */
uint8_t SII_MORSE_GetMorseChar(uint8_t letter)
{
	// Scan if input letter is in the letter list
	for (uint8_t i=0; i < NB_MORSE_CHARACTERS; i++)
	{
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

void SII_MORSE_MessageToMorse(SII_MORSE_Data_t* Data, uint8_t* morse)
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

/* Signal */
void SII_MORSE_SignalOutput(uint32_t timer, uint8_t output_state)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, output_state);
	HAL_Delay(timer * 10);
}

void SII_MORSE_SignalCharacter(SII_MORSE_Data_t* Data, uint8_t* morse_character)
{
	// If the letter is a space
	if (morse_character[0] == ' ')
	{
		SII_MORSE_SignalOutput(Data->timer3, 0); // Wait before next letter
	}
	else
	{
		for (uint8_t i=0; i < MORSE_CHARACTER_LENGHT; i++)
		{
			// Send character LED signal
			switch (morse_character[i])
			{
			case '.':
				SII_MORSE_SignalOutput(Data->timer1, 1);	// Send a dot signal
				break;										// Then go to next character
			case '_':
				SII_MORSE_SignalOutput(Data->timer2, 1);	// Send a dash signal
				break;										// Then go to next character
			default:
				return;	// Leave the function
			}

			// If next character isn't the last
			if (i < (MORSE_CHARACTER_LENGHT - 2))
			{
				// If next character is a dot or a dash
				if ((morse_character[i+1] == '.') || (morse_character[i+1] == '_'))
				{
					SII_MORSE_SignalOutput(Data->timer1, 0);	// Wait before next symbol of the same letter
				}
				else
				{
					SII_MORSE_SignalOutput(Data->timer2, 0);	// Wait before next letter
					return;										// Leave the function
				}
			}
		}
	}
}

void SII_MORSE_MorseSignal(SII_MORSE_Data_t* Data, uint8_t* morse)
{
	for (uint8_t i=0; i < Data->msgSize; i++)
	{
		SII_MORSE_SignalCharacter(Data, &morse[i * MORSE_CHARACTER_LENGHT]);
	}
}
