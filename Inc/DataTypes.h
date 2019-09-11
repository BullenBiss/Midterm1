/*
 * DataTypes.h
 *
 *  Created on: 17 dec. 2018
 *      Author: Viktor
 */

#ifndef DATATYPES_H_
#define DATATYPES_H_

#include "stm32f4xx_hal.h"


typedef enum{false, true}bool;
typedef enum{NOMINE, MINE, RIGHT, LEFT, OUTSIDE} MineEvaluate;

typedef struct{
	GPIO_TypeDef *port;
	uint16_t pin;
}IOPin;

typedef struct{
	int32_t x;
	int32_t y;
	int32_t z;
}Coordinates;


#endif /* DATATYPES_H_ */
