// Programa em Assembly
.syntax unified
.cpu cortex-m4
.fpu softvfp
.thumb
.global main

main:
	//RCC->AHB1ENR bit 2^2=1 e 2^0=1 para habilitar GPIOC e GPIOA
	ldr r0, =#0x40023830
	ldr r1, [r0]
	orr r1, #5
	str r1, [r0]
	//GPIOC->MODER PC13 bit 2^26=1 e 2^27=0 (output)
	ldr r0, =#0x40020800
	ldr r1, [r0]
	orr r1, (1<<26)
	and r1, ~(1<<27)
	str r1, [r0]
	//GPIOA->MODER PA0 bit 2^0=0 e 2^1=0 (input)
	ldr r0, =#0x40020000
	ldr r1, [r0]
	and r1, ~(1<<0)
	and r1, ~(1<<1)
	str r1, [r0]
	//GPIOA->PUPDR PA0 bit 2^0=1 e 2^1=0
	ldr r0, =#0x4002000C
	ldr r1, [r0]
	orr r1, (1<<0)
	and r1, ~(1<<1)
	str r1, [r0]
	//GPIOC->ODR PC13
	ldr r0, =#0x40020814
	//GPIOA->IDR PA0
	ldr r2, =#0x40020010

	loop:
		ldr r3, [r2]
		and r3, (1<<0)
		cmp r3, #0
		beq	acende
		//apaga LED PC13=1
		ldr r1, [r0]
		orr r1, (1<<13)
		str r1, [r0]
		b loop
	acende:
		//acende LED PC13=0
		and r1, ~(1<<13)
		str r1, [r0]
		b loop
