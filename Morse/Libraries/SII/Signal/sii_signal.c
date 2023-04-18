/*
 * sii_signal.c
 *
 *  Created on: 17 avr. 2023
 *      Author: Lena.savylarigaldie
 */

#include "sii_signal.h"

void SII_SIGNAL_SignalOutput(uint32_t timer, uint8_t output_state)
{
	HAL_GPIO_WritePin(SII_SIGNAL_LED_Port, SII_SIGNAL_LED_Pin, output_state);
	SII_TIMERS_Delays_ms(&htim2, timer * 10);
}

void SII_SIGNAL_SignalCharacter(SII_DATA_Data_t* Data, uint8_t* morse_character)
{
	// If the letter is a space
	if (morse_character[0] == ' ')
	{
		HAL_UART_Transmit(Data->uart,(uint8_t *) &"     ", 5, 100);
		SII_SIGNAL_SignalOutput(Data->timer3, 0); // Wait before next letter
	}
	else
	{
		for (uint8_t i=0; i < MORSE_CHARACTER_LENGHT; i++)
		{
			// Send character LED signal
			switch (morse_character[i])
			{
			case '.':
				HAL_UART_Transmit(Data->uart, (uint8_t *) &".", 1, 100);
				SII_SIGNAL_SignalOutput(Data->timer1, 1);	// Send a dot signal
				break;										// Then go to next character
			case '_':
				HAL_UART_Transmit(Data->uart,(uint8_t *) &"_", 1, 100);
				SII_SIGNAL_SignalOutput(Data->timer2, 1);	// Send a dash signal
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
					SII_SIGNAL_SignalOutput(Data->timer1, 0);	// Wait before next symbol of the same letter
				}
				else
				{
					HAL_UART_Transmit(Data->uart, (uint8_t *) &" ", 1, 100);
					SII_SIGNAL_SignalOutput(Data->timer2, 0);	// Wait before next letter
					return;										// Leave the function
				}
			}
		}
	}
}

void SII_SIGNAL_MorseSignal(SII_DATA_Data_t* Data, uint8_t* morse_message)
{
	for (uint8_t i=0; i < Data->msgSize; i++)
	{
		SII_SIGNAL_SignalCharacter(Data, &morse_message[i * MORSE_CHARACTER_LENGHT]);
	}
}
