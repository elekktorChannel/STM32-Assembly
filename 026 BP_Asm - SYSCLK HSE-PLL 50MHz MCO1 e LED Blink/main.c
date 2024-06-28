#include <stdint.h>
#include "stm32f411ceu6.h"

//FLASH
FLASH_ACR_t volatile *FLASH_ACR = (volatile FLASH_ACR_t*)0x40023C00;
//PWR
PWR_CR_t volatile *PWR_CR = (volatile PWR_CR_t*)0x40007000;
//RCC
RCC_CR_t volatile *RCC_CR = (volatile RCC_CR_t*)0x40023800;
RCC_PLLCFGR_t volatile *RCC_PLLCFGR = (volatile RCC_PLLCFGR_t*)0x40023804;
RCC_CFGR_t volatile *RCC_CFGR = (volatile RCC_CFGR_t*)0x40023808;
RCC_AHB1ENR_t volatile *RCC_AHB1ENR = (volatile RCC_AHB1ENR_t*)0x40023830;
RCC_APB1ENR_t volatile *RCC_APB1ENR = (volatile RCC_APB1ENR_t*)0x40023840;
//GPIOA
GPIOx_MODER_t volatile *GPIOA_MODER = (volatile GPIOx_MODER_t*)0x40020000;
GPIOx_OSPEEDR_t volatile *GPIOA_OSPEEDR = (volatile GPIOx_OSPEEDR_t*)0x40020008;
GPIOx_PUPDR_t volatile *GPIOA_PUPDR = (volatile GPIOx_PUPDR_t*)0x4002000C;
GPIOx_ODR_t volatile *GPIOA_ODR = (volatile GPIOx_ODR_t*)0x40020014;
//GPIOC
GPIOx_MODER_t volatile *GPIOC_MODER = (volatile GPIOx_MODER_t*)0x40020800;
GPIOx_ODR_t volatile *GPIOC_ODR = (volatile GPIOx_ODR_t*)0x40020814;
//SysTick
STK_CTRL_t volatile *STK_CTRL = (volatile STK_CTRL_t*)0xE000E010;
STK_LOAD_t volatile *STK_LOAD = (volatile STK_LOAD_t*)0xE000E014;
STK_VAL_t volatile *STK_VAL = (volatile STK_VAL_t*)0xE000E018;

uint32_t vCount = 0;

int main(void)
{
	// 1) Ativa HSE e aguarda por Ready
	RCC_CR->HSEON = 1;
	while(!RCC_CR->HSERDY){};
	// 2) Enable Clock para a Interface POWER
	RCC_APB1ENR->PWREN = 1;
	// 3) Seleção do Regulador de Tensão conforme Clock
	PWR_CR->VOS = 1;
	// 4) Ajusta os fatores da FLASH conforme Clock
	FLASH_ACR->PRFTEN = 1;
	FLASH_ACR->ICEN = 1;
	FLASH_ACR->DCEN = 1;
	FLASH_ACR->LATENCY = 1;
	// 5) Ajusta os Prescallers
	RCC_CFGR->HPRE = 0;
	RCC_CFGR->PPRE1 = 0;
	RCC_CFGR->PPRE2 = 0;
	// 6) Ajusta os fatores do PLL
	RCC_PLLCFGR->PLLM = 24;
	RCC_PLLCFGR->PLLN = 96;
	RCC_PLLCFGR->PLLP = 0;
	// 7) Seleciona o Clock Source para o PLL (HSE)
	RCC_PLLCFGR->PLLSRC = 1;
	// 8) Ativa o PLL e aguarda por Ready
	RCC_CR->PLLON = 1;
	while(!RCC_CR->PLLRDY){};
	// 9) Seleciona o Clock Source principal
	RCC_CFGR->SW = 0x2;
	while (!(RCC_CFGR->SWS == 2)){}

	RCC_AHB1ENR->GPIOAEN = 1;
	RCC_AHB1ENR->GPIOCEN = 1;
	GPIOA_MODER->MODER8 = 0x2;
	GPIOA_OSPEEDR->OSPEEDR8 = 0x3;
	GPIOA_PUPDR->PUPDR8 = 0x0;
	GPIOC_MODER->MODER13 = 0x1;
	RCC_CFGR->MCO1PRE = 0x0;
	RCC_CFGR->MCO1 = 0x3;

    while(1)
    {
    	GPIOC_ODR->ODR13 ^= 1;
    	for (int i = 0; i<1000000; i++);
    }
}
