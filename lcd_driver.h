/*
 * stm32F4_LCD_driver.h
 *
 *  Created on: 16 Ara 2019
 *      Author: acakbudak
 */

/********************Simple_lcd_driver_try***********************************************
 * PA7 corresponds to RS pin
 * PA6 corresponds to RW pin
 * PA5 corresponds to E pin
 * PB15 corresponds to D7 pin
 * PB14 corresponds to D6 pin
 * PB13 corresponds to D5 pin
 * PA12 corresponds to D4 pin
 * PA11 corresponds to D3 pin
 * PA10 corresponds to D2 pin
 * PA9 corresponds to D1 pin
 * PA8 corresponds to D0 pin
 *
 *
 *
 *
 *				0000 0111
 */



#ifndef INC_STM32F4_LCD_DRIVER_H_
#define INC_STM32F4_LCD_DRIVER_H_

#include "stm32F4xx.h"


void lcd_init(void);
void lcd_clear(void);
void lcd_printchar(char string[]);
void lcd_CursorBlink(uint8_t Enordi);


#endif /* INC_STM32F4_LCD_DRIVER_H_ */


