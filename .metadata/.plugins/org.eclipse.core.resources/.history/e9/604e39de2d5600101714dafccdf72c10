/*
 * AP_main.h
 *
 *  Created on: Jun 19, 2025
 *      Author: kccistc
 */

#ifndef AP_AP_MAIN_H_
#define AP_AP_MAIN_H_

#include "GPIO.h"
#include "LedBar.h"
#include "SystemClock.h"
#include "Button.h"


int ap_run();
void ap_init();

void delay_while(int);

uint32_t count_watcher(uint32_t* count);
void LedBarShift(uint32_t *data, uint32_t ShiftMode);
void ButtonPush(uint32_t btn, uint32_t* pre, uint32_t* mode);
void ButtonRelease(uint32_t btn, uint32_t* pre, uint32_t* mode);
void Event(uint32_t*);

#endif /* AP_AP_MAIN_H_ */
