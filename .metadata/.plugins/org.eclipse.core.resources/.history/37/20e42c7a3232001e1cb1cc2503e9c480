/*
 * API_uart.c
 *
 *  Created on: Jul 27, 2023
 *      Author: lauta
 */
#include "API_uart.h"
#include <string.h>
#include <stdio.h>

// Declaramos la estructura para la UART
UART_HandleTypeDef uartHandle;

//Prototipo de funcion privada
static void printUARTConfig();

bool uartInit()
{
	uartHandle.Instance = USART2;
	uartHandle.Init.BaudRate = 115200;
	uartHandle.Init.WordLength = UART_WORDLENGTH_8B;
	uartHandle.Init.StopBits = UART_STOPBITS_1;
	uartHandle.Init.Parity = UART_PARITY_EVEN;
	uartHandle.Init.Mode = UART_MODE_TX_RX;
	uartHandle.Init.HwFlowCtl = UART_HWCONTROL_NONE;

	if (HAL_UART_Init(&uartHandle) != HAL_OK)
	{
		return false;// Error en la inicialización de la UART
	}
	// Imprimir la configuración de la UART en la terminal serie
	printUARTConfig();
	return true;
}

void uartSendString(uint8_t* pstring)
{

	//HAL_UART_Transmit(huart, pData, Size, Timeout)
	HAL_UART_Transmit(&uartHandle, pstring, strlen((char*)pstring), HAL_MAX_DELAY);

}

void uartSendStringSize(uint8_t* pstring, uint16_t size)
{
	//HAL_UART_Transmit(huart, pData, Size, Timeout)
	HAL_UART_Transmit(&uartHandle, pstring, size, HAL_MAX_DELAY);

}


void uartReceiveStringSize(uint8_t* pstring, uint16_t size)
{
	HAL_UART_Receive(&uartHandle, pstring, size, HAL_MAX_DELAY);
}



static void printUARTConfig()
{
	char msg[100];

	sprintf(msg, "UART Config: BaudRate = %lu, WordLength = %lu, StopBits = %lu, Parity = %lu, Mode = %lu, HwFlowCtl = %lu\r\n",
	        uartHandle.Init.BaudRate, uartHandle.Init.WordLength, uartHandle.Init.StopBits,
	        uartHandle.Init.Parity, uartHandle.Init.Mode, uartHandle.Init.HwFlowCtl);

	uartSendString((uint8_t*)msg);

}
