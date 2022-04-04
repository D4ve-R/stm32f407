/*
 * rcc.h
 *
 *  Created on: 23.03.2022
 *      Author: davidrechkemmer
 */

#ifndef RCC_H_
#define RCC_H_

#include<stdint.h>

#ifndef AHB1PERIPH_BASEADDR
#define AHB1PERIPH_BASEADDR		0x40020000U
#endif

#define RCC_BASEADDR			(AHB1PERIPH_BASEADDR + 0x3800U)
#define RCC						((RCC_RegDef_t*) RCC_BASEADDR)

#define RCC_PORTA 0
#define RCC_PORTB 1
#define RCC_PORTC 2
#define RCC_PORTD 3
#define RCC_PORTE 4
#define RCC_PORTF 5
#define RCC_PORTG 6
#define RCC_PORTH 7
#define RCC_PORTI 8
#define RCC_PORTJ 9
#define RCC_PORTK 10

#define RCC_SYSCFG 14

typedef struct {
	volatile uint32_t CR;				/* Address offset: 0x00 */
	volatile uint32_t PLLCFGR;			/* Address offset: 0x04 */
	volatile uint32_t CFGR;				/* Address offset: 0x08 */
	volatile uint32_t CIR;				/* Address offset: 0x0C */
	volatile uint32_t AHB1RSTR;			/* Address offset: 0x10 */
	volatile uint32_t AHB2RSTR;			/* Address offset: 0x14 */
	volatile uint32_t AHB3RSTR;			/* Address offset: 0x18 */
	uint32_t RESERVED0;					/* Address offset: 0x1C */
	volatile uint32_t APB1RSTR;			/* Address offset: 0x20 */
	volatile uint32_t APB2RSTR;			/* Address offset: 0x24 */
	uint32_t RESERVED1[2];				/* Address offset: 0x28 - 0x2C */
	volatile uint32_t AHB1ENR;			/* Address offset: 0x30 */
	volatile uint32_t AHB2ENR;			/* Address offset: 0x34 */
	volatile uint32_t AHB3ENR;			/* Address offset: 0x38 */
	uint32_t RESERVED2;					/* Address offset: 0x3C */
	volatile uint32_t APB1ENR;			/* Address offset: 0x40 */
	volatile uint32_t APB2ENR;			/* Address offset: 0x44 */
	uint32_t RESERVED3[2];				/* Address offset: 0x48 - 0x4C */
	volatile uint32_t AHB1LP_ENR;		/* Address offset: 0x50 */
	volatile uint32_t AHB2LP_ENR;		/* Address offset: 0x54 */
	volatile uint32_t AHB3LP_ENR;		/* Address offset: 0x58 */
	uint32_t RESERVED4;					/* Address offset: 0x5C */
	volatile uint32_t APB1LP_ENR;		/* Address offset: 0x60 */
	volatile uint32_t APB2LP_ENR;		/* Address offset: 0x64 */
	uint32_t RESERVED5[2];				/* Address offset: 0x68 - 0x6C */
	volatile uint32_t BDCR;				/* Address offset: 0x70 */
	volatile uint32_t CSR;				/* Address offset: 0x74 */
	uint32_t RESERVED6[2];				/* Address offset: 0x78 - 0x7C */
	volatile uint32_t SSCGR;			/* Address offset: 0x80 */
	volatile uint32_t PLLI2SCFGR;		/* Address offset: 0x84 */
}RCC_RegDef_t;

typedef struct {
	RCC_RegDef_t *pRCC;
}RCC_Handle_t;

void RCC_EnableAHB1(uint8_t port);
void RCC_DisableAHB1(uint8_t port);
void RCC_EnableAPB2(uint8_t port);
void RCC_DisableAPB2(uint8_t port);

#endif /* RCC_H_ */
