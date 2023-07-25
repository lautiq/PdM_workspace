/**
  ******************************************************************************
  * @file           : APIDebounce.c
  * @brief          : Implementación de funciones para el manejo de anti-rebote
  *                   utilizando una MEF (Máquina de Estados Finitos) y la BSP
  *                   (Board Support Package) para la lectura del botón.
  *
  *
  ******************************************************************************
  * @attention
  *
  * Copyright (c) [13-07-2023] [Lauta]
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "API_debounce.h"
#include "API_delay.h"

/* Private defines -----------------------------------------------------------*/
#define DEBOUNCE_TIME 40

typedef enum{
	init_error
}ErrorFlag_t;

/* Private variables ---------------------------------------------------------*/
// Variables para el anti-rebote
static debounceState_t currentState;
static delay_t debounceDelay;



/* Public functions ----------------------------------------------------------*/
/**
  * @brief  Inicializa la MEF de anti-rebote.
  * @retval None
  */
void debounceFSM_init()
{
	currentState = BUTTON_UP;
	delayInit(&debounceDelay, DEBOUNCE_TIME);
}


/**
  * @brief  Actualiza la MEF de anti-rebote periódicamente.
  * @retval None
  */
void debounceFSM_update()
{
	GPIO_PinState buttonState = BSP_PB_GetState(BUTTON_USER);

	switch(currentState){
	case BUTTON_UP:
		if (buttonState == GPIO_PIN_RESET)
		{
			currentState = BUTTON_FALLING;
			delayWrite(&debounceDelay, DEBOUNCE_TIME);
		}
	break;

	case BUTTON_FALLING:
		if(delayRead(&debounceDelay))
		{
			currentState = BUTTON_DOWN;
			buttonPressed();
		}
	break;

	case BUTTON_DOWN:
		if(buttonState == GPIO_PIN_SET)
		{
			currentState = BUTTON_RAISING;
			delayWrite(&debounceDelay, DEBOUNCE_TIME);
		}
	break;

	case BUTTON_RAISING:
		if(delayRead(&debounceDelay))
		{
			currentState = BUTTON_UP;
			buttonReleased();
		}
	break;

	default:
		currentState = BUTTON_UP;
	break;

	}
}

/* Private functions ---------------------------------------------------------*/
/**
  * @brief  Acciones cuando el botón es presionado (por ejemplo, invertir el LED1).
  * @retval None
  */
void buttonPressed()
{
	BSP_LED_TOGGLE(LED1);
}

/**
  * @brief  Acciones cuando el botón es liberado (por ejemplo, invertir el LED3).
  * @retval None
  */
void buttonReleased()
{
	BSP_LED_TOGGLE(LED3);
}













