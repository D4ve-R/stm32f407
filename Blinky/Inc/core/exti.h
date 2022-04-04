/*
 * exti.h
 *
 *  Created on: 24.03.2022
 *      Author: davidrechkemmer
 */

#ifndef EXTI_H_
#define EXTI_H_

#include <stdint.h>
#include "common.h"
#include "nvic.h"

#ifndef APB2_BASEADDR
#define APB2_BASEADDR		0x40010000U
#endif

#define EXTI_BASEADDR		(APB2_BASEADDR + 0x3C00U)

#define EXTI				((EXTI_RegDef_t*) EXTI_BASEADDR)

typedef struct {
	volatile uint32_t IMR;			/* Address offset: 0x00 */
	volatile uint32_t EMR;			/* Address offset: 0x04 */
	volatile uint32_t RTSR;			/* Address offset: 0x08 */
	volatile uint32_t FTSR;			/* Address offset: 0x0C */
	volatile uint32_t SWIER;		/* Address offset: 0x10 */
	volatile uint32_t PR;			/* Address offset: 0x14 */
}EXTI_RegDef_t;

typedef struct {
	uint8_t EXTI_LineNumber;			/* EXTIx [0 - ? 5 ?] */	//need to check manual
	uint8_t EXTI_RisingTrigger;			/* ENABLE || DISABLE */
	uint8_t EXTI_FallingTrigger;		/* ENABLE || DISABLE */
	uint8_t EXTI_InterruptMask;			/* ENABLE || DISABLE */
	uint8_t EXTI_EventMask;				/* ENABLE || DISABLE */
}EXTI_Config_t;

typedef struct {
	EXTI_RegDef_t *pEXTI;
	EXTI_Config_t EXTI_Config;
}EXTI_Handle_t;


void EXTI_Init(EXTI_Handle_t *pEXTI_Handle);

#endif /* EXTI_H_ */
