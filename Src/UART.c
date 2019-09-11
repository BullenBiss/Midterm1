/*
 * UART.c
 *
 *  Created on: 10 juli 2019
 *      Author: Max Pettersson
 */


/********************* Includes **********************/
#include "UART.h"

/********************* Defines **********************/

/***************** Global Variables *****************/

/************* Extern Global Variables **************/

/********************** Private *********************/

/*********************** Public *********************/
UART UART_init(UART_HandleTypeDef *huart){
	UART uart;
	uart.uart = huart;
	uart.rxData = 0;
	return uart;
}

void UART_sendPackage(UART uart, int16_t *accIn, int16_t *gyroIn, int16_t *adc, uint32_t time)
{
	char intOut[200];
	int index = 0;
	index += sprintf(&intOut[index], "%lu,", time);

	for(int i = 0; i < 2; i++)
	{
		index += sprintf(&intOut[index], "%d,", adc[i]);
	}

	for(int j = 0; j < 3; j++)
	{
		index += sprintf(&intOut[index], "%d,", accIn[j]);
	}

	for(int k = 0; k < 3; k++)
	{
		index += sprintf(&intOut[index], "%d,", gyroIn[k]);
	}
	index += sprintf(&intOut[index], "\r\n");


	HAL_UART_Transmit_IT(uart.uart, intOut, index);
}

void UART_transmit_IT(UART uart, uint8_t *pData, uint16_t size)
{
	HAL_UART_Transmit_IT(uart.uart, pData, size);
}

