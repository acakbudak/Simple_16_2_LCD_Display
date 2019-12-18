/*
 * stm32F4_LCD_driver.c
 *
 *  Created on: 16 Ara 2019
 *      Author: acakbudak
 */

#include "stm32F4xx.h"

static void delay(uint32_t ms)
{
	for(uint32_t i=0; i<ms ; i++);
}

static void GPIO_A_B_PORT_RESET(void)
{
	for(uint32_t i=0; i<16 ;i++)
	GPIOA->ODR &= ~(1 << i);
	for(uint32_t j=0; j<16 ;j++)
	GPIOB->ODR &= ~(1 << j);


}

static void lcd_cmdwrite(uint8_t cmd)
{
	GPIOA->ODR |= (3 << 5);
	delay(1000);
	GPIOA->ODR &= ~(1 << 5);
	delay(100);
	uint8_t read = (GPIOB->IDR) & 0x0004;
	while(read); //wait till busy flag cleared

	uint8_t cmd1= cmd & (uint8_t)0x1F;
	uint8_t cmd2= cmd & (uint8_t)0xE0;

	GPIOB->ODR |= (cmd2 << 8);
	GPIOA->ODR |= (cmd1 << 8);
	GPIOA->ODR &= ~(0x3 << 6);
	GPIOA->ODR |= (1 << 5);
	delay(1000);
	GPIOA->ODR &= ~(1 << 5);
	delay(100);



}

static void lcd_datawrite(uint8_t data)
{
	GPIOA->ODR |= (3 << 5);
	delay(1000);
	GPIOA->ODR &= ~(1 << 5);
	delay(100);

	uint8_t read = (GPIOB->IDR) & 0x0004;
	while(read); //wait till busy flag cleared

	uint8_t data1= data & (uint8_t)0x1F;
	uint8_t data2= data & (uint8_t)0xE0;

	GPIOB->ODR |= (data2 << 8);
	GPIOA->ODR |= (data1 << 8);
	GPIOA->ODR |= (1 << 7);
	GPIOA->ODR &= ~(1 << 6);
	GPIOA->ODR |= (1 << 5);
	delay(1000);
	GPIOA->ODR &= ~(1 << 5);
	delay(100);


}

void lcd_init(void)
{
	//GPIA Port initializing
	GPIOA_PCLK_EN();
	GPIOA->MODER |= 0x01555400;
	GPIOA->OTYPER |= 0x00000000;
	GPIOA->OSPEEDR |= 0x02AAA800;
	GPIOA->PUPDR |= 0x01555400;
	//GPIB Port initializing
	GPIOB_PCLK_EN();
	GPIOB->MODER |= 0x54000000;
	GPIOB->OTYPER |= 0x00000000;
	GPIOB->OSPEEDR |= 0xA8000020;
	GPIOB->PUPDR |= 0x54000020;

	//clear display
	lcd_cmdwrite(0x01);
	GPIO_A_B_PORT_RESET();
	delay(100000);
	//return home
	lcd_cmdwrite(0x02);
	GPIO_A_B_PORT_RESET();
	delay(100000);
	//display on/off control
	lcd_cmdwrite(0x0E);
	GPIO_A_B_PORT_RESET();
    //entry mode set
	lcd_cmdwrite(0x06);
	GPIO_A_B_PORT_RESET();
	//fraction set
	lcd_cmdwrite(0x38);
	GPIO_A_B_PORT_RESET();
	//Move the cursor to beginning of first line
	lcd_cmdwrite(0x80);
	GPIO_A_B_PORT_RESET();

}

void lcd_clear(void)
{
	lcd_cmdwrite(0x01);
	GPIO_A_B_PORT_RESET();

}

void lcd_CursorBlink(uint8_t Enordi)
{
	if(Enordi == DISABLE)
		lcd_cmdwrite(0x0A);
	else if(Enordi == ENABLE)
		lcd_cmdwrite(0x0E);
}

void lcd_printchar(char string[])
{
	GPIO_A_B_PORT_RESET();
	uint8_t *pBuffer=(uint8_t*)string;
//	for(uint8_t i=0; i<strlen(string) ; i++)
//	lcd_datawrite((uint8_t)string[i]);
//	lcd_cmdwrite(0x06);
//	GPIO_A_B_PORT_RESET();


	for(uint32_t i=0; i<16; i++)
	{
		lcd_datawrite(*pBuffer & (uint8_t)0xFF);
		pBuffer++;
		GPIO_A_B_PORT_RESET();
		lcd_cmdwrite(0x06);
		GPIO_A_B_PORT_RESET();
	}

}
