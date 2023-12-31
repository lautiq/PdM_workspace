/*
 * API_debounce.h
 *
 *  Created on: Jul 13, 2023
 *      Author: lauta
 */

#ifndef API_INC_API_DEBOUNCE_H_
#define API_INC_API_DEBOUNCE_H_

#include "API_delay.h"

typedef enum{
	BUTTON_UP,
	BUTTON_FALLING,
	BUTTON_DOWN,
	BUTTON_RAISING,
}debounceState_t;

void debounceFSM_init();
void debounceFSM_update();
void error_Handler();
bool_t readKey();


#endif /* API_INC_API_DEBOUNCE_H_ */
