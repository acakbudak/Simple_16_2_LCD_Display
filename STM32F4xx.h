/*
 * stm32F4xx.h
 *
 *  Created on: 17 Ara 2019
 *      Author: lenovo
 */

/*****************************************************************
 **************MCU Specific Header File************************
 **************************************************************/


#ifndef INC_STM32F4XX_H_
#define INC_STM32F4XX_H_

#include<stdint.h>
#include<string.h>
#define __vo volatile

/*
 * base addresses of Flash and SRAM memories
 */

#define FLASH_BASEADDR            0x00000000U      /* memory base address for flash  */
#define SRAM1_BASEADDR            0x20000000U      /* explain the macro here */
#define SRAM2_BASEADDR            0x20001C00U      /* explain the macro here */
#define SRAM                      SRAM1_BASEADDR   /* explain the macro here */
#define ROM                       0X1FFF0000U      /* explain the macro here */

/*
 * AHBx and APBx Bus Peripheral base addresses
 */

#define PERIPH_BASE              0x40000000U
#define APB1PERIPH_BASE          PERIPH_BASE
#define APB2PERIPH_BASE          0x40010000U
#define AHB1PERIPH_BASE          0x40020000U
#define AHB2PERIPH_BASE          0x50000000U

/*
 * Peripheral base addresses hanging on AHB1 Bus
 */

#define GPIOA_BASEADDR           (AHB1PERIPH_BASE + 0x0000)
#define GPIOB_BASEADDR           (AHB1PERIPH_BASE + 0x0400)
#define GPIOC_BASEADDR           (AHB1PERIPH_BASE + 0x0800)
#define GPIOD_BASEADDR           (AHB1PERIPH_BASE + 0x0C00)
#define GPIOE_BASEADDR           (AHB1PERIPH_BASE + 0x1000)
#define GPIOF_BASEADDR           (AHB1PERIPH_BASE + 0x1400)
#define GPIOG_BASEADDR           (AHB1PERIPH_BASE + 0x1800)
#define GPIOH_BASEADDR           (AHB1PERIPH_BASE + 0x1C00)
#define GPIOI_BASEADDR           (AHB1PERIPH_BASE + 0x2000)
#define RCC_BASEADDR             (AHB1PERIPH_BASE + 0x3800)


typedef struct
{
		__vo uint32_t MODER;        							                    /* OFFSET VALUE IS 0x00 HERE */
		__vo uint32_t OTYPER;                                                       /* OFFSET VALUE IS 0x04 HERE */
		__vo uint32_t OSPEEDR;                                                      /* OFFSET VALUE IS 0x0C HERE */
		__vo uint32_t PUPDR;                                                        /* OFFSET VALUE IS 0x10 HERE */
		__vo uint32_t IDR;                                                          /* OFFSET VALUE IS 0x14 HERE */
		__vo uint32_t ODR;                                                          /* OFFSET VALUE IS 0x18 HERE */
		__vo uint32_t BSRR;                                                         /* OFFSET VALUE IS 0x1C HERE */
		__vo uint32_t LCKR;                                                         /* OFFSET VALUE IS 0x20 HERE */
		__vo uint32_t AFR[2];                                                       /* OFFSET VALUE IS 0x24 HERE */

}GPIO_RegDef_t;

typedef struct
{
	__vo uint32_t CR;
		__vo uint32_t PLLCFGR;
		__vo uint32_t CFGR;
		__vo uint32_t CIR;
		__vo uint32_t AHB1RSTR;
		__vo uint32_t AHB2RSTR;
		__vo uint32_t AHB3RSTR;
		uint32_t      RESERVED;
		__vo uint32_t APB1RSTR;
		__vo uint32_t APB2RSTR;
		uint32_t      RESERVED1[2];
		__vo uint32_t AHB1ENR;
		__vo uint32_t AHB2ENR;
		__vo uint32_t AHB3ENR;
		uint32_t      RESERVED2;
		__vo uint32_t APB1ENR;
		__vo uint32_t APB2ENR;
		uint32_t      RESERVED3[2];
		__vo uint32_t AHB1LPENR;
		__vo uint32_t AHB2LPENR;
		__vo uint32_t AHB3LPENR;
		uint32_t      RESERVED4;
		__vo uint32_t APB1LPENR;
		__vo uint32_t APB2LPENR;
		uint32_t	  RESERVED5[2];
		__vo uint32_t BDCR;
		__vo uint32_t CSR;
		__vo uint32_t RESERVED6[2];
		__vo uint32_t SSCGR;
		__vo uint32_t PLLI2CCFGR;
		__vo uint32_t PLLSAICFGR;
		__vo uint32_t DCKCFGR;
		__vo uint32_t CKGATENR;
		__vo uint32_t DCKCFGR2;

}RCC_RegDef_t;


/*
 * Peripheral definitions (Peripheral base addresses typecasted to xxx_RefDef_t)
 */

#define GPIOA     ((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB     ((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC     ((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD     ((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE     ((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF     ((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG     ((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH     ((GPIO_RegDef_t*)GPIOH_BASEADDR)
#define GPIOI     ((GPIO_RegDef_t*)GPIOI_BASEADDR)


#define RCC       ((RCC_RegDef_t*)RCC_BASEADDR)

/*
 * Clock enable macros for GPIOx peripherals
 */

#define GPIOA_PCLK_EN()        ( RCC->AHB1ENR |= (1 << 0) )
#define GPIOB_PCLK_EN()        ( RCC->AHB1ENR |= (1 << 1) )
#define GPIOC_PCLK_EN()        ( RCC->AHB1ENR |= (1 << 2) )
#define GPIOD_PCLK_EN()        ( RCC->AHB1ENR |= (1 << 3) )
#define GPIOE_PCLK_EN()        ( RCC->AHB1ENR |= (1 << 4) )
#define GPIOF_PCLK_EN()        ( RCC->AHB1ENR |= (1 << 5) )
#define GPIOG_PCLK_EN()        ( RCC->AHB1ENR |= (1 << 6) )
#define GPIOH_PCLK_EN()        ( RCC->AHB1ENR |= (1 << 7) )
#define GPIOI_PCLK_EN()        ( RCC->AHB1ENR |= (1 << 8) )


//Some generic macros

#define ENABLE            1
#define DISABLE 		  0
#define SET     		  ENABLE
#define RESET  			  DISABLE
#define GPIO_PIN_SET      SET
#define GPIO_PIN_RESET    RESET

#include "stm32F4_LCD_driver.h"

#endif /* INC_STM32F4XX_H_ */


