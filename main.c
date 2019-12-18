/*
 * main.c
 *
 *  Created on: 17 Ara 2019
 *      Author: acakbudak
 */

#include "stm32F4xx.h"



int main(void)
{

	lcd_init();
	lcd_printchar("Hello World");

	while(1);

	return 0;
}
