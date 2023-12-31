/*
 * API_delay.c
 *
 *  Created on: Jul 11, 2023
 *      Author: lauta
 */

#include "API_delay.h"



void delayInit(delay_t *delay, tick_t duration)
{
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
