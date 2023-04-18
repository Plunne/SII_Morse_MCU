/*
 * sii_timers.c
 *
 *  Created on: Apr 17, 2023
 *      Author: Malik Berdier
 */
/* Includes ------------------------------------------------------------------*/
#include "sii_timers.h"

/**
  * @brief  This function provides delay in milliseconds based on variable decremente
  * @retval None
  */
void SII_TIMERS_Delays_ms(TIM_HandleTypeDef *htim, uint16_t time_ms)
{
	while(time_ms > 0)
	{
		__HAL_TIM_SET_COUNTER(htim, 0U); // Set value of the timer counter to 0
		time_ms--;
		while (__HAL_TIM_GET_COUNTER(htim) < 1000); // Get value of the timer counter.
	}

}

/**
  * @brief  Blink the led function of the time
  * @retval None
  */
void SII_TIMERS_Blink_Led(uint16_t time_ms)
{
	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
	  SII_TIMERS_Delays_ms(&htim2, time_ms);
}
