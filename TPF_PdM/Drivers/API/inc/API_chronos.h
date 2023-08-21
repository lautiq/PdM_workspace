/**
 * @file API_chronosFSM.h
 * @brief Header file for the Chronos Finite State Machine (FSM) module.
 * @author Lautaro Quarin
 */

#ifndef API_INC_API_CHRONOS_H_
#define API_INC_API_CHRONOS_H_

#include "API_debounce.h"
#include "stdio.h"

/**
 * @brief Enumeration of the possible states for the Chronos FSM.
 */
typedef enum {
		CHRONOS_STATE_INIT,
		CHRONOS_STATE_START,
		CHRONOS_STATE_PAUSE,
		CHRONOS_STATE_RESUME,
		CHRONOS_STATE_STOP
}chronosState_t;

/**
 * @brief Structure to hold time in hours, minutes, and seconds.
 */
typedef struct {
	uint8_t hours;
	uint8_t minutes;
	uint8_t seconds;
}chronosTime_t;


void chronosFSM_init();
void chronosFSM_update(bool_t btn1Pressed, bool_t btn2Pressed, bool_t btn3Pressed);


extern debounceButton_t btn1;
extern debounceButton_t btn2;
extern debounceButton_t btn3;


#endif /* API_INC_API_CHRONOS_H_ */
