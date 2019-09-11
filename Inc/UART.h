/*
 * UART.h
 *
 *  Created on: 10 juli 2019
 *      Author: Max Pettersson
 */


#ifndef INC_UART_H_
#define INC_UART_H_

/******************** Includes **********************/
#include "DataTypes.h"
#include "stm32f4xx_hal.h"


/******************** Structs ***********************/
typedef struct{
	UART_HandleTypeDef *uart;
	uint8_t rxData;
}UART;


/*************** Function prototypes ****************/

/* Function: UART_init
 * Usage: UART_init().
 * Description: Returns an initialized UART. */
UART UART_init(UART_HandleTypeDef *huart);
void UART_sendPackage(UART uart, int16_t *accIn, int16_t *gyroIn, int16_t *adc, uint32_t time);
void UART_transmit_IT(UART uart, uint8_t *pData, uint16_t size);

/* Function:
 * Usage:
 * Description: */

#endif /* INC_UART_H_ */
