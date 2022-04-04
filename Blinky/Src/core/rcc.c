/*
 * rcc.c
 *
 *  Created on: 24.03.2022
 *      Author: davidrechkemmer
 */

#include "core/rcc.h"

#define _setRegister(REG, PORT) ((REG) |= (1 << (PORT)))

void RCC_EnableAHB1(uint8_t port){
	_setRegister(RCC->AHB1ENR, port);
}

void RCC_DisableAHB1(uint8_t port){
	_setRegister(RCC->AHB1RSTR, port);
}

void RCC_EnableAPB2(uint8_t port){
	_setRegister(RCC->APB2ENR, port);

}

void RCC_DisableAPB2(uint8_t port){
	_setRegister(RCC->APB2RSTR, port);
}

