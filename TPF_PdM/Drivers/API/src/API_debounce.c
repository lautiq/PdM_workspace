/**
 * @file APIDebounce.c
 * @brief Implementation of functions for debounce handling using a Finite State Machine (FSM).
 *
 * @details This file provides the implementation of functions for handling button debounce
 *          using a FSM (Finite State Machine) and Board Support Package (BSP) for button reading.
 *
 * @date July 13, 2023
 * @author Lautaro Quarin
 */


/* Includes ------------------------------------------------------------------*/
#include "API_debounce.h"
#include "API_delay.h"

/* Private defines -----------------------------------------------------------*/
#define DEBOUNCE_TIME_MS 40



/* Public functions ----------------------------------------------------------*/
/**
 * @brief Initializes the debounce FSM for a button.
 *
 * @note This function initializes the Finite State Machine (FSM) used for button debounce.
 *       It should be called at the beginning of the program before using debounce functions.
 *
 * @note If the button is pressed when the program starts, the error handling function
 *       will be activated, and the built-in LED will be turned on. The program will remain
 *       in this state until restarted.
 *
 * @param button Pointer to the debounceButton_t structure.
 * @return None.
 */
void debounceFSM_init(debounceButton_t *button)
{
	GPIO_PinState buttonState = HAL_GPIO_ReadPin(button->port, button->pin);
	if(buttonState == GPIO_PIN_RESET)
	{
		error_Handler();
	}

	button->currentState = BUTTON_UP;
	delayInit(&(button->debounceDelay), DEBOUNCE_TIME_MS);
}



/**
 * @brief Updates the debounce FSM periodically.
 *
 * @note This function should be called periodically to update the Finite State Machine (FSM)
 *       for button debounce. It checks the button state and performs state transitions
 *       based on the implemented debounce technique.
 *
 * @param button Pointer to the debounceButton_t structure.
 * @return None.
 */
void debounceFSM_update(debounceButton_t *button)
{
	GPIO_PinState buttonState = HAL_GPIO_ReadPin(button->port,button->pin);

	switch(button->currentState){
	case BUTTON_UP:
		if (buttonState == GPIO_PIN_RESET)
		{
			button->currentState = BUTTON_FALLING;
			delayWrite(&(button->debounceDelay), DEBOUNCE_TIME_MS);
		}
	break;

	case BUTTON_FALLING:
		if(delayRead(&(button->debounceDelay)))
		{
			button->currentState = BUTTON_DOWN;
			button->pressedFlag = true;
			button->isPressed = true;
		}
	break;

	case BUTTON_DOWN:
		if(buttonState == GPIO_PIN_SET)
		{
			button->currentState = BUTTON_RAISING;
			delayWrite(&(button->debounceDelay), DEBOUNCE_TIME_MS);
		}
	break;

	case BUTTON_RAISING:
		if(delayRead(&(button->debounceDelay)))
		{
			button->currentState = BUTTON_UP;
			button->pressedFlag= false;
			button->isPressed = true;
		}
	break;

	default:
		button->currentState = BUTTON_UP;
	break;

	}
}

/**
 * @brief Reads the button state after debounce and returns whether it was pressed.
 *
 * @note This function should be called periodically to read the button state after applying
 *       the debounce technique. If the button has been pressed since the last time this
 *       function was called, it returns `TRUE`. Otherwise, it returns `FALSE`.
 *
 * @param button Pointer to the debounceButton_t structure.
 * @return `TRUE` if the button was pressed, `FALSE` otherwise.
 */
bool_t readButton(debounceButton_t *button)
{
	bool_t isButtonPressed = button->pressedFlag;
	button->pressedFlag = false;
	return isButtonPressed;
}


/* Error handling function ----------------------------------------------------*/
/**
 * @brief Error handling function.
 *
 * @note This function is called when an error is detected during FSM initialization.
 *       It is recommended to implement appropriate error handling code for the project.
 *
 * @return None.
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
