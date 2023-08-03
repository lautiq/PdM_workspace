/*
 * API_uart.h
 *
 *  Created on: Jul 27, 2023
 *      Author: lauta
 */

#ifndef API_INC_API_UART_H_
#define API_INC_API_UART_H_


#include "stm32f4xx_hal.h"
#include <stdint.h>
#include <stdbool.h>

bool uartInit();
void uartSendString(uint8_t* pstring);
void uartSendStringSize(uint8_t* pstring, uint16_t size);
void uartReceiveStringSize(uint8_t* pstring, uint16_t size);



#endif /* API_INC_API_UART_H_ */
