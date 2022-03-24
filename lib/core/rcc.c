/*
 * rcc.c
 *
 *      Author: davidrechkemmer
 */

#include <rcc.h>

void _RCC_SetRegister(volatile uint32_t *reg, uint8_t port){
	*reg |= (1 << port);
}

void RCC_EnableAHB1(uint8_t port){
	RCC_Handle_t rcc;
	rcc.pRCC = RCC;
	//uint32_t *reg = &rcc.pRCC->AHB1ENR;
	_RCC_SetRegister(&rcc.pRCC->AHB1ENR, port);
}

void RCC_DisableAHB1(uint8_t port){
	RCC_Handle_t rcc;
	rcc.pRCC = RCC;
	//uint32_t *reg = &rcc.pRCC->AHB1RSTR;
	_RCC_SetRegister(&rcc.pRCC->AHB1RSTR, port);
}

void RCC_EnableAPB2(uint8_t port){
	RCC_Handle_t rcc;
	rcc.pRCC = RCC;
	_RCC_SetRegister(&rcc.pRCC->APB2ENR, port);

}

void RCC_DisableAPB2(uint8_t port){
	RCC_Handle_t rcc;
	rcc.pRCC = RCC;
	_RCC_SetRegister(&rcc.pRCC->APB2RSTR, port);
}

