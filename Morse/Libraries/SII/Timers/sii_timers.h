/*
 * sii_timers.h
 *
 *  Created on: Apr 17, 2023
 *      Author: Malik Berdier
 */

#ifndef SII_TIMERS_SII_TIMERS_H_
#define SII_TIMERS_SII_TIMERS_H_
/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

extern TIM_HandleTypeDef htim2;

void SII_TIMERS_Delays_ms(TIM_HandleTypeDef* htim, uint16_t time_ms);
void SII_TIMERS_Blink_Led(uint16_t time_ms);

#endif /* SII_TIMERS_SII_TIMERS_H_ */
