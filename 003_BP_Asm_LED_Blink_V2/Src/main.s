// Programa em Assembly
.syntax unified
.cpu cortex-m4
.fpu softvfp
.thumb
.global main

main:
	//RCC->AHB1ENR bit 2^2 = 1 para habilitar clock para GPIOC
	ldr r0, =#0x40023830
	ldr r1, [r0]
	orr r1, (1<<2) //0b00000000000000000000000000000100
	str r1, [r0]
	//GPIOC->MODER bit 2^26 = 1 e 2^27 = 0
	ldr r0, =#0x40020800
	ldr r1, [r0]
	orr r1, (1<<26) //0b00000100000000000000000000000000
	and r1, (~(1<<27)) //0b11110111111111111111111111111111
	str r1, [r0]
	loop:
		//GPIOC->ODR bit 2^13 = toggle bit
		ldr r0, =#0x40020814
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
