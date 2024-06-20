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

int main(void)
{
    RCC_AHB1ENR |= (1<<2);
    GPIOC_MODER |= (1<<26);
    GPIOC_MODER &= ~(1<<27);

    while(1)
    {
    	GPIOC_ODR ^= (1<<13);
    	for (int i = 0; i<200000; i++);
    }
}
