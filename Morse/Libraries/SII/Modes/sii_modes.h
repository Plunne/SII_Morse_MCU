/*
 * modes.h
 *
 *  Created on: Apr 16, 2023
 *      Author: plunne
 */

#ifndef MODES_H_
#define MODES_H_

#include "sii_signal.h"

typedef enum { MODE_IDLE, MODE_LOOP , MODE_ITERATE} SII_MODES_Mode_t;

/* Select */
SII_MODES_Mode_t SII_MODES_GetMode(SII_DATA_Data_t* Data);
void SII_MODES_RunMode(SII_DATA_Data_t* Data, uint8_t* message, SII_MODES_Mode_t Mode);

/* Modes */
void SII_MODES_Loop(SII_DATA_Data_t* Data, uint8_t* message);
void SII_MODES_Iterate(SII_DATA_Data_t* Data, uint8_t* message);

#endif /* MODES_H_ */
