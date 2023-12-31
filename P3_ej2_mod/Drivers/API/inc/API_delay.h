/*
 * API_delay.h
 *
 *  Created on: Jul 11, 2023
 *      Author: lauta
 */

#ifndef API_INC_API_DELAY_H_
#define API_INC_API_DELAY_H_

#include "stm32f4xx_hal.h"
#include "stm32f4xx_nucleo_144.h"
#include <stdint.h>
#include <stdbool.h> 	//Se incluye para utilizar el tipo de dato bool.


/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
	typedef uint32_t tick_t;
	typedef bool bool_t;

	typedef struct{
		tick_t startTime;
		tick_t duration;
		bool_t running;
	}delay_t;

	void delayInit(delay_t *delay, tick_t duration);
	bool_t delayRead(delay_t *delay);
	void delayWrite(delay_t *delay, tick_t duration);

#endif /* API_INC_API_DELAY_H_ */
