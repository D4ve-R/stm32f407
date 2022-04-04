/*
 * gpio_driver.c
 *
 *  Created on: 23.03.2022
 *      Author: davidrechkemmer
 */

#include "gpio_driver.h"

void GPIO_Init(GPIO_Handle_t *pGPIOHandle){
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG){
		// non interrupt mode
		switch(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode){
        	case GPIO_MODE_OUT:
        		// output mode
        		pGPIOHandle->pGPIOx->MODE_REG |= (1 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

        		if(pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType == GPIO_OP_TYPE_OD)
        			pGPIOHandle->pGPIOx->OUTPUT_TYPE |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);

        		// output speed control
        		switch(pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed){
                	case GPIO_SPEED_MEDIUM:
                		pGPIOHandle->pGPIOx->OUTPUT_SPEED |= (1 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
                		break;
                	case GPIO_SPEED_FAST:
                		pGPIOHandle->pGPIOx->OUTPUT_SPEED |= (1 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber + 1));
                		break;
                	case GPOI_SPEED_HIGH:
                		pGPIOHandle->pGPIOx->OUTPUT_SPEED |= ((1 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)) | (1 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber + 1)));
                		break;
                	case GPIO_SPEED_LOW:
                	default:
                		break;
        		}
        		break;

        	case GPIO_MODE_ALTFN:
        		// alternate function mode
        		pGPIOHandle->pGPIOx->MODE_REG |= (1 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber + 1));
        		break;

        	case GPIO_MODE_ANALOG:
        		// analog mode
        		pGPIOHandle->pGPIOx->MODE_REG |= ((1 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)) | (1 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber + 1)));
        		break;

        	case GPIO_MODE_IN:
        		// input mode
        		pGPIOHandle->pGPIOx->MODE_REG &= ~((1 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)) | (1 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber + 1)));
        		break;
        	default:
        		break;
		}
	}
	else {
		// interrupt mode
		RCC_EnableAPB2(RCC_SYSCFG);
		EXTI_Handle_t exti;

		switch(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode){
			case GPIO_MODE_IT_FT:
		        // interrupt falling trigger
				exti.EXTI_Config.EXTI_FallingTrigger = ENABLE;
		        break;

		    case GPIO_MODE_IT_RT:
		    	// interrupt rising trigger
		    	exti.EXTI_Config.EXTI_RisingTrigger = ENABLE;
		        break;

		    case GPIO_MODE_IT_RFT:
		        // interrupt rising falling trigger
		    	exti.EXTI_Config.EXTI_FallingTrigger = ENABLE;
		    	exti.EXTI_Config.EXTI_RisingTrigger = ENABLE;
		        break;
		    default:
		    	break;
		}

		exti.EXTI_Config.EXTI_InterruptMask = ENABLE;
		exti.EXTI_Config.EXTI_LineNumber = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber;
		EXTI_Init(&exti);
	}

	// pull up/down control
    switch(pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl){
        case GPIO_PIN_PU:
        	// pull-up
            pGPIOHandle->pGPIOx->PULL_UP_DOWN |= (1 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
            break;

        case GPIO_PIN_PD:
        	// pull-down
            pGPIOHandle->pGPIOx->PULL_UP_DOWN |= (1 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber + 1));
            break;

        case GPIO_RESERVED:
            pGPIOHandle->pGPIOx->PULL_UP_DOWN |= ((1 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)) |  (1 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber + 1)));
            break;

        case GPIO_NO_PUPD:
        	pGPIOHandle->pGPIOx->PULL_UP_DOWN &= ~((1 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)) |  (1 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber + 1)));
        	break;
        default:
            break;
    }
}

void GPIO_WriteToOutputPin(GPIO_Handle_t *pGPIO_Handle, uint8_t Value){
    (Value == GPIO_PIN_RESET) ?
        (pGPIO_Handle->pGPIOx->OUTPUT_DATA_REG &= ~(1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber))
	:
        (pGPIO_Handle->pGPIOx->OUTPUT_DATA_REG |= (1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber));
}


void GPIO_ToggleOutputHandler(GPIO_Handle_t *pGPIO_Handle){
	pGPIO_Handle->pGPIOx->OUTPUT_DATA_REG ^= (1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber);
}


void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint16_t pinNumber){
	pGPIOx->OUTPUT_DATA_REG ^= (1 << pinNumber);
}

void GPIO_PeriClockControl(uint8_t port, uint8_t mode){
	// all gpios are connected to AHB1-Bus
	(mode == ENABLE) ?
		RCC_EnableAHB1(port)
	:
		RCC_DisableAHB1(port);
}

void GPIO_IRQHandling(uint8_t pinNumber){
	if(EXTI->PR & (1 << pinNumber))
		EXTI->PR |= (1 << pinNumber);
}

void GPIO_OutputPinFactory(GPIO_Handle_t *pGPIO_Handle, uint8_t pinNumber){
	pGPIO_Handle->pGPIOx = GPIOD;
	pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber = pinNumber;
	pGPIO_Handle->GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	pGPIO_Handle->GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
	pGPIO_Handle->GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	pGPIO_Handle->GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_Init(pGPIO_Handle);
}
