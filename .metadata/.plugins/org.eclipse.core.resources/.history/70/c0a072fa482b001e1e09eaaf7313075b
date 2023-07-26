/*
 * API_debounce.h
 *
 *  Created on: Jul 13, 2023
 *      Author: lauta
 */

#ifndef API_INC_API_DEBOUNCE_H_
#define API_INC_API_DEBOUNCE_H_


typedef enum{
	BUTTON_UP,
	BUTTON_FALLING,
	BUTTON_DOWN,
	BUTTON_RAISING,
}debounceState_t

debounceState_t initState;

void debounceFSM_init();
void debounceFSM_update();
void buttonPressed();
void buttonReleased();


#endif /* API_INC_API_DEBOUNCE_H_ */
