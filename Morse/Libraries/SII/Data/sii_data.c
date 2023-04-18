/*
 * sii_data.c
 *
 *  Created on: 17 avr. 2023
 *      Author: Lena.savylarigaldie
 */

#include "sii_data.h"

/* Receive */
void SII_DATA_GetFrame(SII_DATA_Data_t* Data, uint8_t* frame, uint8_t size)
{
	if((Data != NULL) && (frame != NULL))
	{
		// Data settings
		Data->loop 		= frame[0];
		Data->iterate 	= frame[1];
		Data->timer1 	= frame[2];
		Data->timer2 	= frame[3];
		Data->timer3 	= frame[4];
		Data->msgSize 	= frame[5];

		// Copy frame [6 to (\n -1)] into Data->message[0 to (\n -1)]
		for (uint8_t i=6; i < (size); i++)
		{
			Data->message[i - 6] = frame[i];
		}

		// Copy last char
		Data->endChar = frame[size];
	}
}

/* Transmit */
void SII_DATA_SendMessage(UART_HandleTypeDef* huart, GPIO_TypeDef* PORTx, uint16_t pin)
{
	uint8_t tx_state = ' ';

	if (!HAL_GPIO_ReadPin(PORTx, pin))
	{
		tx_state = '-';
	}
	else
	{
		tx_state = ' ';
	}

	HAL_UART_Transmit(huart, &tx_state, 1, 10);
}
