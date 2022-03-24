/*
 * syscfg.h
 *
 *  Created on: 24.03.2022
 *      Author: davidrechkemmer
 */

#ifndef SYSCFG_H_
#define SYSCFG_H_

#include <stdint.h>

#ifndef APB2_BASEADDR
#define APB2_BASEADDR		0x4001000U
#endif

#define SYSCFG_BASEADDR		(APB2_BASEADDR + 0x3800U)

#define SYSCFG				((SYSCFG_RegDef_t*) SYSCFG_BASEADDR)

typedef struct {
	volatile uint32_t MEMRMP;			/* Address offset: 0x00 */
	volatile uint32_t PMC;				/* Address offset: 0x04 */
	volatile uint32_t EXTICR1;			/* Address offset: 0x08 */
	volatile uint32_t EXTICR2;			/* Address offset: 0x0C */
	volatile uint32_t EXTICR3;			/* Address offset: 0x10 */
	volatile uint32_t EXTICR4;			/* Address offset: 0x14 */
	volatile uint32_t CMPCR;			/* Address offset: 0x18 */
}SYSCFG_RegDef_t;

typedef struct {
	SYSCFG_RegDef_t *pSYSCFG;
}SYSCFG_Handle_t;

void SYSCFG_ConfigExti(uint8_t extiNumber, uint8_t extiConfig);

#endif /* SYSCFG_H_ */
