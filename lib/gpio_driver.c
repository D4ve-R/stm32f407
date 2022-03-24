/*
 * gpio_driver.c
 *
 *      Author: davidrechkemmer
 */

#include <gpio_driver.h>

void GPIO_Init(GPIO_Handle_t *pGPIOHandle){
    switch(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode){
        case GPIO_MODE_OUT:
            // output mode
            pGPIOHandle->pGPIOx->MODE_REG |= (1 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
            if(pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType == GPIO_OP_TYPE_OD)
                pGPIOHandle->pGPIOx->OUTPUT_TYPE |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);

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
            // alternate mode
            pGPIOHandle->pGPIOx->MODE_REG |= (1 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber + 1));
            break;

        case GPIO_MODE_ANALOG:
            // analog mode
            pGPIOHandle->pGPIOx->MODE_REG |= ((1 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)) | (1 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber + 1)));
            break;

        case GPIO_MODE_IN:
        	// input mode
        default:
            break;
    }

    switch(pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl){
        case GPIO_PIN_PU:
            pGPIOHandle->pGPIOx->PULL_UP_DOWN |= (1 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
            break;

        case GPIO_PIN_PD:
            pGPIOHandle->pGPIOx->PULL_UP_DOWN |= (1 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber + 1));
            break;

        case GPIO_RESERVED:
            pGPIOHandle->pGPIOx->PULL_UP_DOWN |= ((1 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)) |  (1 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber + 1)));
            break;

        case GPIO_NO_PUPD:
        default:
            break;
    }
}

void GPIO_WriteToOutputPin(GPIO_Handle_t *pGPIO_Handle, uint8_t Value){
    if(Value == GPIO_PIN_RESET)
        pGPIO_Handle->pGPIOx->OUTPUT_DATA_REG &= ~(1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber);
    else
        pGPIO_Handle->pGPIOx->OUTPUT_DATA_REG |= (1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber);
}

void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint16_t pinNumber){
	uint16_t bit = pGPIOx->OUTPUT_DATA_REG & (1 << pinNumber);
	if(bit)
		pGPIOx->OUTPUT_DATA_REG &= ~(1 << pinNumber);
	else
		pGPIOx->OUTPUT_DATA_REG |= (1 << pinNumber);
}

void GPIO_PeriClockControl(uint8_t port, uint8_t mode){
	if(mode == ENABLE)
		RCC_EnableAHB1(port);
	else
		RCC_DisableAHB1(port);
}
