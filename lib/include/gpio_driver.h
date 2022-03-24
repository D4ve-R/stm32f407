/*
 * gpio_driver.h
 *
 *  Created on: 23.03.2022
 *      Author: davidrechkemmer
 */

#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_

#include <stddef.h>
#include <stdint.h>


#ifdef __cplusplus
extern "C" {
#endif

#include <common.h>

#define GPIO_PIN_SET        SET
#define GPIO_PIN_RESET      RESET

#define AHB1PERIPH_BASEADDR		0x40020000U

#define GPIOA_BASEADDR			(AHB1PERIPH_BASEADDR + 0x0000U)
#define GPIOB_BASEADDR			(AHB1PERIPH_BASEADDR + 0x0400U)
#define GPIOC_BASEADDR			(AHB1PERIPH_BASEADDR + 0x0800U)
#define GPIOD_BASEADDR			(AHB1PERIPH_BASEADDR + 0x0C00U)
#define GPIOE_BASEADDR			(AHB1PERIPH_BASEADDR + 0x1000U)
#define GPIOF_BASEADDR			(AHB1PERIPH_BASEADDR + 0x1400U)
#define GPIOG_BASEADDR			(AHB1PERIPH_BASEADDR + 0x1800U)
#define GPIOH_BASEADDR			(AHB1PERIPH_BASEADDR + 0x1C00U)
#define GPIOI_BASEADDR			(AHB1PERIPH_BASEADDR + 0x2000U)
#define GPIOJ_BASEADDR			(AHB1PERIPH_BASEADDR + 0x2400U)
#define GPIOK_BASEADDR			(AHB1PERIPH_BASEADDR + 0x2800U)

#define GPIOA		((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB  		((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC  		((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD  		((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE  		((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF  		((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG  		((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH  		((GPIO_RegDef_t*)GPIOH_BASEADDR)
#define GPIOI  		((GPIO_RegDef_t*)GPIOI_BASEADDR)
#define GPIOJ  		((GPIO_RegDef_t*)GPIOJ_BASEADDR)
#define GPIOK  		((GPIO_RegDef_t*)GPIOK_BASEADDR)

typedef struct
{
  volatile uint32_t MODE_REG;      				/* Address offset: 0x00 */
  volatile uint32_t OUTPUT_TYPE;  				/* Address offset: 0x04 */
  volatile uint32_t OUTPUT_SPEED;  				/* Address offset: 0x08 */
  volatile uint32_t PULL_UP_DOWN;  				/* Address offset: 0x0C */
  volatile uint32_t INPUT_DATA_REG;    			/* Address offset: 0x10 */
  volatile uint32_t OUTPUT_DATA_REG;			/* Address offset: 0x14 */
}GPIO_RegDef_t;

typedef struct
{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;			/*!< mögliche Werte in @GPIO_PIN_MODES >*/
	uint8_t GPIO_PinSpeed;			/*!< mögliche Werte in @GPIO_PIN_SPEED >*/
	uint8_t GPIO_PinPuPdControl;	/*!< mögliche Werte in @GPIO_PIN_PULL_UP_DOWN >*/
	uint8_t GPIO_PinOPType;			/*!< mögliche Werte in @GPIO_OUTPUT_MODES >*/
}GPIO_PinConfig_t;

typedef struct
{
	GPIO_RegDef_t *pGPIOx;       		/* GPIOx */
	GPIO_PinConfig_t GPIO_PinConfig;	/* Pin Config */
}GPIO_Handle_t;

/*
 * @GPIO_PIN_NUMBERS
 * GPIO pin nums
 */
#define GPIO_PIN_NO_0  				0
#define GPIO_PIN_NO_1  				1
#define GPIO_PIN_NO_2  				2
#define GPIO_PIN_NO_3  				3
#define GPIO_PIN_NO_4  				4
#define GPIO_PIN_NO_5  				5
#define GPIO_PIN_NO_6  				6
#define GPIO_PIN_NO_7  				7
#define GPIO_PIN_NO_8  				8
#define GPIO_PIN_NO_9  				9
#define GPIO_PIN_NO_10  			10
#define GPIO_PIN_NO_11 				11
#define GPIO_PIN_NO_12  			12
#define GPIO_PIN_NO_13 				13
#define GPIO_PIN_NO_14 				14
#define GPIO_PIN_NO_15 				15

/*
 * @GPIO_PIN_MODES
 * GPIO pin modes
 */
#define GPIO_MODE_IN 		0		// default
#define GPIO_MODE_OUT 		1
#define GPIO_MODE_ALTFN 	2
#define GPIO_MODE_ANALOG 	3
#define GPIO_MODE_IT_FT     4
#define GPIO_MODE_IT_RT     5
#define GPIO_MODE_IT_RFT    6

/*
 * @GPIO_OUTPUT_MODES
 * GPIO pin output mode
 */
#define GPIO_OP_TYPE_PP   0
#define GPIO_OP_TYPE_OD   1


/*
 * @GPIO_PIN_SPEED
 * GPIO pin output speed settings
 */
#define GPIO_SPEED_LOW			0
#define GPIO_SPEED_MEDIUM		1
#define GPIO_SPEED_FAST			2
#define GPOI_SPEED_HIGH			3


/*
 * @GPIO_PIN_PULL_UP_DOWN
 * GPIO pin pull-up/down configs
 */
#define GPIO_NO_PUPD   		0
#define GPIO_PIN_PU			1
#define GPIO_PIN_PD			2
#define GPIO_RESERVED		3


void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_WriteToOutputPin(GPIO_Handle_t *pGPIO_Handle, uint8_t Value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint16_t pinNumber);

#include "rcc.h"

void GPIO_PeriClockControl(uint8_t port, uint8_t mode);

#ifdef __cplusplus
}
#endif

#endif /* GPIO_DRIVER_H_ */
