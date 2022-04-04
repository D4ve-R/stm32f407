/*
 * nvic.c
 *
 *  Created on: 25.03.2022
 *      Author: davidrechkemmer
 */

#include "core/nvic.h"

void NVIC_Init(uint8_t extiLineNo){

	if(extiLineNo < 5){
		switch(extiLineNo){
			case 0:
				NVIC_ISER->REG0 |= (1 << NVIC_IRQn_EXTI0);
				break;
			case 1:
				NVIC_ISER->REG0 |= (1 << NVIC_IRQn_EXTI1);
				break;
			case 2:
				NVIC_ISER->REG0 |= (1 << NVIC_IRQn_EXTI2);
				break;
			case 3:
				NVIC_ISER->REG0 |= (1 << NVIC_IRQn_EXTI3);
				break;
			case 4:
				NVIC_ISER->REG0 |= (1 << NVIC_IRQn_EXTI4);
				break;
			default:
				break;
		}
	}
	else if(extiLineNo < 10){
		NVIC_ISER->REG0 |= (1 << NVIC_IRQn_EXTI9_5);
	}
}

