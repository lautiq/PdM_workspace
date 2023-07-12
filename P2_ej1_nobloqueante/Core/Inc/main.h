
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif


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

/* USER CODE END Includes */



/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
