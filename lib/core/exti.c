/*
 * exti.c
 *
 *  Created on: 24.03.2022
 *      Author: davidrechkemmer
 */

#include <exti.h>

void EXTI_ConfigFallingTrigger(uint8_t lineNumber, uint8_t mode){
	EXTI_Handle_t exti;
	exti.pEXTI = EXTI;
	if(mode == ENABLE){
		exti.pEXTI->FTSR |= (1 << lineNumber);
	}
	else
		exti.pEXTI->FTSR &= ~(1 << lineNumber);
}

void EXTI_ConfigInterruptMask(uint8_t lineNumber, uint8_t mode){
	EXTI_Handle_t exti;
	exti.pEXTI = EXTI;
	if(mode == ENABLE){
		exti.pEXTI->IMR |= (1 << lineNumber);
	}
	else
		exti.pEXTI->IMR &= ~(1 << lineNumber);
}
