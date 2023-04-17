/*
 * sii_data.h
 *
 *  Created on: 17 avr. 2023
 *      Author: Lena.savylarigaldie
 */

#ifndef SII_DATA_SII_DATA_H_
#define SII_DATA_SII_DATA_H_

#include "stm32f1xx_hal.h"

#define MESSAGE_LENGHT				249
#define DATAFRAME_LENGHT			7 + MESSAGE_LENGHT
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
	UART_HandleTypeDef* uart;

} SII_DATA_Data_t;

/* Arrays */
extern uint8_t sii_data_rx[MESSAGE_LENGHT];
extern uint8_t sii_morse_message[MESSAGE_LENGHT * MORSE_CHARACTER_LENGHT];

/* Receive */
void SII_DATA_GetFrame(SII_DATA_Data_t* Data, uint8_t* frame, uint8_t size);

/* Transmit */
void SII_DATA_SendMessage(UART_HandleTypeDef* huart, GPIO_TypeDef* PORTx, uint16_t pin);


#endif /* SII_DATA_SII_DATA_H_ */
