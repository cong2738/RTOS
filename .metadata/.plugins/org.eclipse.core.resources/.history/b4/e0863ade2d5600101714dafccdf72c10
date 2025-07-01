/*
 * LedBar.c
 *
 *  Created on: Jun 18, 2025
 *      Author: kccistc
 */
#include "LedBar.h"

typedef struct {
	GPIO_TypeDef* GPIO;
	uint32_t pinNum;
}LedBar_Typedef;

LedBar_Typedef ledBar[8] = {
		{GPIOA,0},
		{GPIOA,1},
		{GPIOA,4},
		{GPIOB,0},
		{GPIOC,1},
		{GPIOC,0},
		{GPIOC,2},
		{GPIOC,3}
};

void LedBar_Init(){
	for (int var = 0; var < 8; var++) {
		GPIO_Init(ledBar[var].GPIO,ledBar[var].pinNum,OUTPUT);
	}
}

void LedBar_SetPorts(uint32_t* portArr){
	for (int var = 0; var < 8; var++) {
		ledBar[var].pinNum = portArr[var];
	}
}

void LedBar_Write(uint8_t data){
	for (int var = 0; var < 8; var++) {
		if ((data & (1<<var)) == 0) {
			GPIO_WritePin(ledBar[var].GPIO, ledBar[var].pinNum, PIN_RESET);
		} else {
			GPIO_WritePin(ledBar[var].GPIO, ledBar[var].pinNum, PIN_SET);
		}
	}
}
