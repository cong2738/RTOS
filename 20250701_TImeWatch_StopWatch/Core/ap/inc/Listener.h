/*
 * Listener.h
 *
 *  Created on: Jun 24, 2025
 *      Author: rhoblack
 */

#ifndef AP_LISTENER_H_
#define AP_LISTENER_H_
#include "stm32f4xx_hal.h"
#include <my_queue.h>
#include "Model_Watch.h"
#include "Controller.h"
#include "Button.h"

void Listener_Init();
void Listener_Excute();
void Listener_UartCallBack();
uint16_t Listener_GetStoredDistance(void);

#endif /* AP_LISTENER_H_ */
