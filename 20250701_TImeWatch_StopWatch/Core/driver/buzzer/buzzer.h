/*
 * buzzer.h
 *
 *  Created on: Jun 26, 2025
 *      Author: kccistc
 */
#include "tim.h"
#include "stm32f4xx_hal.h"

#ifndef DRIVER_BUZZER_BUZZER_H_
#define DRIVER_BUZZER_BUZZER_H_

void Buzzer_Init(TIM_HandleTypeDef* htim, uint32_t channel);
void Buzzer_SetFreq(uint32_t freq);
void Buzzer_Start();
void Buzzer_Stop();

#endif /* DRIVER_BUZZER_BUZZER_H_ */
