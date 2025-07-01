/*
 * button.c
 *
 *  Created on: Jun 19, 2025
 *      Author: kccistc
 */
#include "Button.h"

enum {
    PUSHED = 0,
    RELEASED = 1,
};

void Button_Init(button_handler_t* hbtn, GPIO_TypeDef* GPIOx, uint32_t PinNum)
{
	hbtn->GPIOx = GPIOx;
	hbtn->PinNum = PinNum;
	hbtn->preState = RELEASED;
    GPIO_Init(GPIOx, PinNum, INPUT);
}

int Button_GetState(button_handler_t *button_handlerX)
{
    uint32_t curState;
    curState = GPIO_ReadPin(button_handlerX->GPIOx, button_handlerX->PinNum);

    if (button_handlerX->preState == RELEASED && curState == PUSHED) {
        delay(2);
        button_handlerX->preState = curState;
        return ACT_PUSHED;
    } else if (button_handlerX->preState == PUSHED && curState == RELEASED) {
        delay(2);
        button_handlerX->preState = curState;
        return ACT_RELEASED;
    }
    return NO_ACT;
}
