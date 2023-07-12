/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"


UART_HandleTypeDef huart2;

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);

#define DELAYTIME1 100
#define DELAYTIME2 500
#define DELAYTIME3 1000
#define onTime 200


int main(void)
{

  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */

  //Inicializo estructura de delay para cada led:
  delay_t delayLED1, delayLED2, delayLED3;

  delayInit(&delayLED1, DELAYTIME1);
  delayInit(&delayLED2, DELAYTIME2);
  delayInit(&delayLED3, DELAYTIME3);

  //Inicializo los LEDs
  BSP_LED_Init(LED1); //Led yellow
  BSP_LED_Init(LED2); //Led built-in
  BSP_LED_Init(LED3); //Led green

  // Variables de estado para controlar el encendido y apagado de los LEDs
  bool_t led1On = false;
  bool_t led2On = false;
  bool_t led3On = false;



  while (1)
    {
      // Actualizar los retardos no bloqueantes
      bool_t led1State = delayRead(&delayLED1);
      bool_t led2State = delayRead(&delayLED2);
      bool_t led3State = delayRead(&delayLED3);

      // Controlar los LEDs en base al estado de los retardos
      if (led1State)
      {
        if (led1On)
        {
          BSP_LED_Off(LED1); // Apagar LED1
          led1On = false;
          delayWrite(&delayLED1, DELAYTIME1); // Reiniciar el retardo
        }
        else
        {
          BSP_LED_On(LED1); // Encender LED1
          led1On = true;
          delayWrite(&delayLED1, onTime); // Establecer el tiempo de encendido del LED1 a 200 ms
        }
      }

      if (led2State)
      {
        if (led2On)
        {
          BSP_LED_Off(LED2); // Apagar LED2
          led2On = false;
          delayWrite(&delayLED2, DELAYTIME2); // Reiniciar el retardo
        }
        else
        {
          BSP_LED_On(LED2); // Encender LED2
          led2On = true;
          delayWrite(&delayLED2, onTime); // Establecer el tiempo de encendido del LED2 a 200 ms
        }
      }

      if (led3State)
      {
        if (led3On)
        {
          BSP_LED_Off(LED3); // Apagar LED3
          led3On = false;
          delayWrite(&delayLED3, DELAYTIME3); // Reiniciar el retardo
        }
        else
        {
          BSP_LED_On(LED3); // Encender LED3
          led3On = true;
          delayWrite(&delayLED3, onTime); // Establecer el tiempo de encendido del LED3 a 200 ms
        }
      }
    }
  }

void delayInit(delay_t *delay, tick_t duration)
{

	//Agregar un error de inicializacion (buenas practicas) .
	if(delay == NULL || duration <= 0)
		Error_Handler();


	delay->duration = duration;
	delay->running = false;
}

bool_t delayRead(delay_t *delay)
{
	if(!delay->running)
	{
		delay->startTime = HAL_GetTick();  	//Obtengo marca de tiempo
		delay->running = true;				//cambio estado de running.
	} else
	{
		tick_t tiempoActual = HAL_GetTick();
		if(tiempoActual - (delay->startTime) >= (delay->duration))
		{
			delay->running = false;  //se cumplio el retardo, cambio running.
			return true;
		} else
		{
			return false;		//no se cumple retardo, sigo contando (run permanece en 1).
		}
	}
	return false; //agregado para solucionar: Warning: control reaches end of non-void function[-Wreturn-type] (tiene que haber retorno en todos los caminos posibles).
}

void delayWrite(delay_t *delay, tick_t duration)
{
	if(delay == NULL || duration <= 0)
		Error_Handler();

	delay->duration = duration;
}




/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LD2_Pin|GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LD2_Pin PA6 PA7 */
  GPIO_InitStruct.Pin = LD2_Pin|GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
