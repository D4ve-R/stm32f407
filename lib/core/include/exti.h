/*
 * exti.h
 *
 *      Author: davidrechkemmer
 */

#ifndef EXTI_H_
#define EXTI_H_

#include <stdint.h>
#include <common.h>

#ifndef APB2_BASEADDR
#define APB2_BASEADDR		0x4001000U
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
	EXTI_RegDef_t *pEXTI;
}EXTI_Handle_t;

void EXTI_ConfigFallingTrigger(uint8_t lineNumber, uint8_t mode);
void EXTI_ConfigInterruptMask(uint8_t lineNumber, uint8_t mode);

#endif /* EXTI_H_ */
