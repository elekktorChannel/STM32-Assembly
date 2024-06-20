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

// SysTick
#define SYST_CSR				*(volatile uint32_t *)(0xE000E010U)	//SysTick Control and Status Register
#define SYST_RVR				*(volatile uint32_t *)(0xE000E014U)	//SysTick Reload Value Register
#define SYST_CVR				*(volatile uint32_t *)(0xE000E018U)	//SysTick Current Value Register

uint32_t vCount = 0;

int main(void)
{
    RCC_AHB1ENR |= (1<<2);
    GPIOC_MODER |= (1<<26);
    GPIOC_MODER &= ~(1<<27);
    SYST_RVR	= (15330-1);	//calibrado -> (15330)
    SYST_CSR	|= 0x5;

    while(1)
    {
    	if (SYST_CSR & (1<<16)) vCount++;

    	if (vCount >= 500)
		{
    		GPIOC_ODR ^= (1<<13);
    		vCount = 0;
		}
    }
}
