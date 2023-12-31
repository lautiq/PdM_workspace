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
#define DEBOUNCE_TIME_MS 40



/* Private variables ---------------------------------------------------------*/
static debounceState_t currentState;
static delay_t debounceDelay;
static bool_t buttonPressedFlag = false;



/* Public functions ----------------------------------------------------------*/
/**
 * @brief  Inicializa la MEF de anti-rebote.
 *
 * @note   Esta función inicializa la Máquina de Estados Finitos (MEF) utilizada
 *         para el anti-rebote del botón. Debe ser llamada al inicio del programa
 *         antes de utilizar las funciones de anti-rebote.
 *
 * @note   Si el botón está presionado al momento de iniciar el programa, se activará
 *         la función de error y el LED incorporado se encenderá. El programa quedará
 *         bloqueado en este estado hasta que se reinicie.
 *
 * @retval None
 */
void debounceFSM_init()
{
	GPIO_PinState buttonState = BSP_PB_GetState(BUTTON_USER);
	if(buttonState == GPIO_PIN_RESET)
	{
		error_Handler();
	}

	currentState = BUTTON_UP;
	delayInit(&debounceDelay, DEBOUNCE_TIME_MS);
}


/**
 * @brief  Actualiza la MEF de anti-rebote periódicamente.
 *
 * @note   Esta función debe ser llamada periódicamente para actualizar la Máquina de Estados
 *         Finitos (MEF) de anti-rebote. Comprueba el estado del botón y realiza las transiciones
 *         de estado necesarias de acuerdo a la técnica de anti-rebote implementada.
 *
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
			delayWrite(&debounceDelay, DEBOUNCE_TIME_MS);
		}
	break;

	case BUTTON_FALLING:
		if(delayRead(&debounceDelay))
		{
			currentState = BUTTON_DOWN;
			buttonPressedFlag = true;
		}
	break;

	case BUTTON_DOWN:
		if(buttonState == GPIO_PIN_SET)
		{
			currentState = BUTTON_RAISING;
			delayWrite(&debounceDelay, DEBOUNCE_TIME_MS);
		}
	break;

	case BUTTON_RAISING:
		if(delayRead(&debounceDelay))
		{
			currentState = BUTTON_UP;
			buttonPressedFlag = false;
		}
	break;

	default:
		currentState = BUTTON_UP;
	break;

	}
}

/**
 * @brief  Lee el estado del botón después del anti-rebote y devuelve si fue presionado.
 *
 * @note   Esta función debe ser llamada periódicamente para leer el estado del botón
 *         después de aplicar la técnica de anti-rebote. Si el botón ha sido presionado
 *         desde la última vez que se llamó a esta función, se devuelve `TRUE`. En caso
 *         contrario, se devuelve `FALSE`.
 *
 * @return `TRUE` si el botón fue presionado, `FALSE` en caso contrario.
 */
bool_t readKey()
{
	bool_t isButtonPressed = buttonPressedFlag;
	buttonPressedFlag = false;
	return isButtonPressed;
}


/* Error handling function ----------------------------------------------------*/
/**
 * @brief  Función de manejo de errores.
 * @note   Esta función es llamada si se detecta un error durante la inicialización
 *         de la MEF. Se recomienda agregar aquí el código de manejo de errores
 *         adecuado para el proyecto.
 * @retval None
 */
void error_Handler()
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
	BSP_LED_Toggle(LED_BUILTIN);
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}






