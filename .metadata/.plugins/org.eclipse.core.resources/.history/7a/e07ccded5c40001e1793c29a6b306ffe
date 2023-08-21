/*
 * API_chronosFSM.h
 *
 *  Created on: Aug 17, 2023
 *      Author: Lauti
 */

#ifndef API_INC_API_CHRONOS_H_
#define API_INC_API_CHRONOS_H_

#include "API_debounce.h"
#include "stdio.h"

typedef enum {
		CHRONOS_STATE_INIT,
		CHRONOS_STATE_START,
		CHRONOS_STATE_PAUSE,
		CHRONOS_STATE_RESUME,
		CHRONOS_STATE_STOP
}chronosState_t;

typedef struct {
	uint8_t hours;
	uint8_t minutes;
	uint8_t seconds;
}chronosTime_t;

void chronosFSM_init();
void chronosFSM_update();

extern debounceButton_t btn1;
extern debounceButton_t btn2;
extern debounceButton_t btn3;


#endif /* API_INC_API_CHRONOS_H_ */
