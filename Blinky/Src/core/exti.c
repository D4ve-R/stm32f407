/*
 * exti.c
 *
 *  Created on: 24.03.2022
 *      Author: davidrechkemmer
 */

#include "core/exti.h"

void EXTI_Init(EXTI_Handle_t *pEXTI_Handle){
	pEXTI_Handle->pEXTI = EXTI;

	if(pEXTI_Handle->EXTI_Config.EXTI_FallingTrigger == ENABLE){
		pEXTI_Handle->pEXTI->FTSR |= (1 << pEXTI_Handle->EXTI_Config.EXTI_LineNumber);
	}
	if(pEXTI_Handle->EXTI_Config.EXTI_RisingTrigger == ENABLE){
		pEXTI_Handle->pEXTI->RTSR |= (1 << pEXTI_Handle->EXTI_Config.EXTI_LineNumber);
	}
	if(pEXTI_Handle->EXTI_Config.EXTI_InterruptMask == ENABLE){
		pEXTI_Handle->pEXTI->IMR |= (1 << pEXTI_Handle->EXTI_Config.EXTI_LineNumber);
	}
	if(pEXTI_Handle->EXTI_Config.EXTI_EventMask == ENABLE){
		pEXTI_Handle->pEXTI->EMR |= (1 << pEXTI_Handle->EXTI_Config.EXTI_LineNumber);
	}

	// TODO SYSCFG configuration

	NVIC_Init(pEXTI_Handle->EXTI_Config.EXTI_LineNumber);
}


