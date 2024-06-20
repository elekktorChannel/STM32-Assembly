// Programa em Assembly
.syntax unified
.cpu cortex-m4
.fpu softvfp
.thumb
.global main

.equ RCC_BASE_ADDRESS, 0x40023800U
.equ RCC_AHB1ENR_OFFSET, 0x30U
.equ RCC_AHB1ENR, (RCC_BASE_ADDRESS + RCC_AHB1ENR_OFFSET)
.equ GPIOC_BASE_ADDRESS, 0x40020800U
.equ GPIOC_MODER_OFFSET, 0x0U
.equ GPIOC_MODER, (GPIOC_BASE_ADDRESS + GPIOC_MODER_OFFSET)
.equ GPIOC_ODR_OFFSET, 0x14U
.equ GPIOC_ODR, (GPIOC_BASE_ADDRESS + GPIOC_ODR_OFFSET)

main:
	//RCC->AHB1ENR bit 2^2 = 1 para habilitar clock para GPIOC
	ldr r0, =RCC_AHB1ENR
	ldr r1, [r0]
	orr r1, (1<<2) //0b00000000000000000000000000000100
	str r1, [r0]
	//GPIOC->MODER bit 2^26 = 1 e 2^27 = 0
	ldr r0, =GPIOC_MODER
	ldr r1, [r0]
	orr r1, (1<<26) //0b00000100000000000000000000000000
	str r1, [r0]
	ldr r1, [r0]
	and r1, (~(1<<27)) //0b11110111111111111111111111111111
	str r1, [r0]
	loop:
		//GPIOC->ODR bit 2^13 = toggle bit
		ldr r0, =GPIOC_ODR
		ldr r1, [r0]
		eor r1, (1<<13) //0b00000000000000000010000000000000
		str r1, [r0]
		ldr r3, =1000000U
		bl delay
		bl loop

	delay:
		subs r3, r3, #1
		bne delay
		bx lr
