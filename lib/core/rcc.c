/*
 * rcc.c
 *
 *      Author: davidrechkemmer
 */

#include <rcc.h>

void RCC_EnableAHB1(uint8_t port){
	RCC_Handle_t rcc;
	rcc.pRCC = RCC;
	switch(port){
			case RCC_PORTA:
				rcc.pRCC->AHB1ENR |= (1 << RCC_PORTA);
				break;
			case RCC_PORTB:
				rcc.pRCC->AHB1ENR |= (1 << RCC_PORTB);
				break;
			case RCC_PORTC:
				rcc.pRCC->AHB1ENR |= (1 << RCC_PORTC);
				break;
			case RCC_PORTD:
				rcc.pRCC->AHB1ENR |= (1 << RCC_PORTD);
				break;
			case RCC_PORTE:
				rcc.pRCC->AHB1ENR |= (1 << RCC_PORTE);
				break;
			case RCC_PORTF:
				rcc.pRCC->AHB1ENR |= (1 << RCC_PORTF);
				break;
			case RCC_PORTG:
				rcc.pRCC->AHB1ENR |= (1 << RCC_PORTG);
				break;
			case RCC_PORTH:
				rcc.pRCC->AHB1ENR |= (1 << RCC_PORTH);
				break;
			case RCC_PORTI:
				rcc.pRCC->AHB1ENR |= (1 << RCC_PORTI);
				break;
			case RCC_PORTJ:
				rcc.pRCC->AHB1ENR |= (1 << RCC_PORTJ);
				break;
			case RCC_PORTK:
				rcc.pRCC->AHB1ENR |= (1 << RCC_PORTK);
				break;
			default:
				break;
		}
}

void RCC_DisableAHB1(uint8_t port){
	return;
}

void RCC_EnableAPB2(uint8_t port){
	RCC_Handle_t rcc;
	rcc.pRCC = RCC;
	switch(port){
		case RCC_SYSCFG:
			rcc.pRCC->APB2ENR |= (1 << RCC_SYSCFG);
			break;
		default:
			break;
	}

}

void RCC_DisableAPB2(){

}

