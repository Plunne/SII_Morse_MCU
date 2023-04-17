/*
 * modes.c
 *
 *  Created on: Apr 16, 2023
 *      Author: plunne
 */


#include "sii_modes.h"

SII_MODES_Mode_t SII_MODES_GetMode(SII_DATA_Data_t* Data)
{
	 if (Data->loop == 1)
	{
		return MODE_LOOP;
	}
	else if (Data->iterate >= 1)
	{
		return MODE_ITERATE;
	}

	return MODE_IDLE;
}

void SII_MODES_RunMode(SII_DATA_Data_t* Data, uint8_t* message, SII_MODES_Mode_t Mode)
{
	switch(Mode)
	{
	case MODE_IDLE:
		break;
	case MODE_LOOP:
		SII_MODES_Loop(Data, message);
		break;
	case MODE_ITERATE:
		SII_MODES_Iterate(Data, message);
		break;
	default:
		break;
	}
}


void SII_MODES_Loop(SII_DATA_Data_t* Data, uint8_t* message)
{
	SII_SIGNAL_MorseSignal(Data, message);
}

void SII_MODES_Iterate(SII_DATA_Data_t* Data, uint8_t* message)
{
	if ((Data->iterate >= 1) && (Data->iterate <= 255))
	{
		SII_SIGNAL_MorseSignal(Data, message);
		Data->iterate--;
	}
}
