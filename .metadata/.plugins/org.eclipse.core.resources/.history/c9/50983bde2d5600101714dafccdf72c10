/*
 * button.h
 *
 *  Created on: Jun 19, 2025
 *      Author: kccistc
 */

#ifndef DRIVER_BUTTON_BUTTON_H_
#define DRIVER_BUTTON_BUTTON_H_


#include "GPIO.h"
#include "SystemClock.h"

typedef enum {
    NO_ACT = 0,
    ACT_PUSHED = 1,
    ACT_RELEASED = 2,
} button_state_t;

typedef	struct{
	GPIO_TypeDef *GPIOx;
	uint32_t PinNum;
	uint32_t preState;
} button_handler_t;

void Button_Init(button_handler_t* hbtn, GPIO_TypeDef* GPIOx, uint32_t PinNum);
int Button_GetState(button_handler_t *button_handlerX);

#endif /* DRIVER_BUTTON_BUTTON_H_ */
