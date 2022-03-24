/*
 * interrupt.c
 *
 *  Created on: 24.03.2022
 *      Author: davidrechkemmer
 */

#include <interrupt.h>

void INTERRUPT_EnableInterrupt(){
	EXTI_ConfigFallingTrigger(0, DISABLE);
	EXTI_ConfigInterruptMask(0, RESET);
	RCC_EnableAPB2(RCC_SYSCFG);
	SYSCFG_ConfigExti(0, 0);
}

// TODO