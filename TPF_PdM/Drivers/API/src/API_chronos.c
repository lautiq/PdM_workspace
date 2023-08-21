/*
 * API_chronosFSM.c
 *
 *  Created on: Aug 17, 2023
 *      Author: Lauti
 */


#include "API_chronos.h"
#include "API_SSD1306.h"
#include "API_debounce.h"


static chronosState_t currentState = CHRONOS_STATE_INIT;
static uint32_t startTime = 0;
static uint32_t pausedTime = 0;
static uint32_t elapsedTime = 0;

SSD1306_t ssd1306;


// Función para calcular y llenar la estructura chronosTime_t
void calculateElapsedTime(uint32_t timeMs, chronosTime_t *time) {
    time->hours = timeMs / 3600000;
    time->minutes = (timeMs / 60000) % 60;
    time->seconds = (timeMs / 1000) % 60;
}

// Mostrar el tiempo en pantalla
void displayTimeOnScreen(uint32_t time) {
    chronosTime_t timeStruct;
    calculateElapsedTime(time, &timeStruct);

    char timeStr[20];
    snprintf(timeStr, sizeof(timeStr), "%02u:%02u:%02u", timeStruct.hours, timeStruct.minutes, timeStruct.seconds);
    oledSetCursor(0, 20);
    oledWriteString(timeStr, White);
    updateScreen();
}

void chronosFSM_init()
{

	currentState = CHRONOS_STATE_START;
	startTime = 0;
	pausedTime = 0;
	elapsedTime = 0;
}

void chronosFSM_update()
{
	debounceFSM_update(&btn1);
	debounceFSM_update(&btn2);
	debounceFSM_update(&btn3);

    uint32_t currentTime = HAL_GetTick();

	switch (currentState){

	case CHRONOS_STATE_INIT:
		  cleanScreen(Black);
		  oledSetCursor(0,0);
		  oledWriteString("ESTADO INIT", White);
		  updateScreen();
	break;

	case CHRONOS_STATE_START:
		//cleanScreen(Black);
		  //oledSetCursor(0,0);
		 // oledWriteString("START", White);
		  //updateScreen();
		//update elapsedTime
		elapsedTime = currentTime - startTime;

		//display elapsed time :
		oledSetCursor(0, 0);
		oledWriteString("tiempo:", White);
		displayTimeOnScreen(elapsedTime);
		updateScreen();
	break;

	case CHRONOS_STATE_PAUSE:
        cleanScreen(Black);
        oledSetCursor(0, 0);
        oledWriteString("PAUSA", White);
        updateScreen();

        // Display paused time
        oledSetCursor(0, 20);
        oledWriteString("Tiempo pausado:", White);
        displayTimeOnScreen(pausedTime);
        updateScreen();
        break;

	break;


	case CHRONOS_STATE_RESUME:
		cleanScreen(Black);
		oledSetCursor(0, 0);
		oledWriteString("RESUMEN", White);
		updateScreen();

		 // Update startTime for resumed state
		 startTime += currentTime - pausedTime;

		 // Display elapsed time
		 oledSetCursor(0, 20);
		 oledWriteString("Tiempo:", White);
		 displayTimeOnScreen(elapsedTime);
		 updateScreen();
		 break;

	break;

	case CHRONOS_STATE_STOP:
		cleanScreen(Black);
		oledSetCursor(0, 0);
		oledWriteString("DETENIDO", White);
		updateScreen();

		// Display elapsed time
		oledSetCursor(0, 20);
		oledWriteString("Tiempo transcurrido:", White);
		displayTimeOnScreen(elapsedTime);
		updateScreen();

		if (elapsedTime >= 20000) {
			currentState = CHRONOS_STATE_INIT;
			startTime = 0;
			pausedTime = 0;
			elapsedTime = 0;
		}
	break;
	}

	updateScreen();

}
