/*
 * LCD.h
 *
 *  Created on: Jun 25, 2025
 *      Author: kccistc
 */

#ifndef LCD_LCD_H_
#define LCD_LCD_H_

#include "stm32f4xx_hal.h"
#include "i2c.h"

void LCD_Init(I2C_HandleTypeDef* hi2c1);
void LCD_backLightOn();
void LCD_backLightOff();
void LCD_sendData(uint8_t data);
void LCD_writeCmdData(uint8_t data);
void LCD_writeCharData(uint8_t data);
void LCD_writeStringData(char* data);
void LCD_writeStringData(char* data);
void LCD_gotoXY(uint8_t row, uint8_t col);
void LCD_WriteStringXY(uint8_t row, uint8_t col, char* str);

#endif /* LCD_LCD_H_ */
