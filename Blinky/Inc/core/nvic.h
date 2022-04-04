/*
 * nvic.h
 *
 *  Created on: 25.03.2022
 *      Author: davidrechkemmer
 */

#ifndef NVIC_H_
#define NVIC_H_

#include <stdint.h>

#define NVIC_BASEADDR		0xE000E000U
#define NVIC_ISER			((NVIC_RegDef_SC_t*)(NVIC_BASEADDR + 0x100U))
#define NVIC_ICER			((NVIC_RegDef_SC_t*)(NVIC_BASEADDR + 0x180U))
#define NVIC_ISPR			((NVIC_RegDef_SC_t*)(NVIC_BASEADDR + 0x200U))
#define NVIC_ICPR			((NVIC_RegDef_SC_t*)(NVIC_BASEADDR + 0x280U))
#define NVIC_IABR			((NVIC_RegDef_SC_t*)(NVIC_BASEADDR + 0x300U))
#define NVIC_IPR			((NVIC_RegDef_SC_t*)(NVIC_BASEADDR + 0x400U))
#define NVIC_STIR			((NVIC_RegDef_SC_t*)(NVIC_BASEADDR + 0xF00U))


typedef struct {
	volatile uint32_t REG0;
	volatile uint32_t REG1;
	volatile uint32_t REG2;
	volatile uint32_t REG3;
	volatile uint32_t REG4;
	volatile uint32_t REG5;
	volatile uint32_t REG6;
	volatile uint32_t REG7;
}NVIC_RegDef_SC_t;

typedef struct {
	NVIC_RegDef_SC_t *ISER;
	NVIC_RegDef_SC_t *ICER;
	NVIC_RegDef_SC_t *ISPR;
	NVIC_RegDef_SC_t *ICPR;
	NVIC_RegDef_SC_t *IABR;
}NVIC_Handle_t;

#define NVIC_IRQn_EXTI0			6
#define NVIC_IRQn_EXTI1			7
#define NVIC_IRQn_EXTI2			8
#define NVIC_IRQn_EXTI3			9
#define NVIC_IRQn_EXTI4			10
#define NVIC_IRQn_EXTI9_5		23
#define NVIC_IRQn_EXTI15_10 	40

void NVIC_Init(uint8_t extiLineNo);

#endif /* NVIC_H_ */
