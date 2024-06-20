#include <stdint.h>

// RCC
#define RCC_BASE_ADDR			0x40023800U
#define RCC_AHB1ENR_OFFSET		0x30U
#define RCC_AHB1ENR				*(volatile uint32_t *)(RCC_BASE_ADDR+RCC_AHB1ENR_OFFSET)

// GIPOC
#define GPIOC_BASE_ADDR			0x40020800U
#define GPIOC_MODER_OFFSET		0x0U
#define GPIOC_MODER				*(volatile uint32_t *)(GPIOC_BASE_ADDR + GPIOC_MODER_OFFSET)
#define GPIOC_ODR_OFFSET		0x14U
#define GPIOC_ODR				*(volatile uint32_t *)(GPIOC_BASE_ADDR + GPIOC_ODR_OFFSET)

// GIPOA
#define GPIOA_BASE_ADDR			0x40020000U
#define GPIOA_MODER_OFFSET		0x0U
#define GPIOA_MODER				*(volatile uint32_t *)(GPIOA_BASE_ADDR + GPIOA_MODER_OFFSET)
#define GPIOA_PUPDR_OFFSET		0x0CU
#define GPIOA_PUPDR				*(volatile uint32_t *)(GPIOA_BASE_ADDR + GPIOA_PUPDR_OFFSET)
#define GPIOA_IDR_OFFSET		0x10U
#define GPIOA_IDR				*(volatile uint32_t *)(GPIOA_BASE_ADDR + GPIOA_IDR_OFFSET)


int main(void)
{
    RCC_AHB1ENR |= 0x5;			// Habilitar clock GPIOA e GPIOC
    GPIOC_MODER |= (1<<26);		// GPIOC_P13 como saída 2^26 = 1
    GPIOC_MODER &= ~(1<<27);	// GPIOC_P13 como saída 2^27 = 0
    GPIOA_MODER &= ~(1<<0);		// GPIOA_P0 como entrada 2^0 = 0
    GPIOA_MODER &= ~(1<<1);		// GPIOA_P0 como entrada 2^1 = 0
    GPIOA_PUPDR |= (1<<0);    	// GPIOA_P0 como pull-up 2^0 = 1
    GPIOA_PUPDR &= ~(1<<1);		// GPIOA_P0 como pull-up 2^1 = 0

    while(1)
    {
    	if (GPIOA_IDR & (1<<0))
		{
    		GPIOC_ODR |= (1<<13);
		}
    	else
    	{
    		GPIOC_ODR &= (~(1<<13));
    	}
    }
}
