// Programa em Assembly
.syntax unified
.cpu cortex-m4
.fpu softvfp
.thumb
.global main

main:
	//RCC->AHB1ENR bit 2^2 = 1 para habilitar clock para GPIOC
	ldr r0, =0x40023830U
	ldr r1, [r0]
	orr r1, (1<<2)
	str r1, [r0]
	//GPIOC->MODER bit 2^26 = 1 e 2^27 = 0
	ldr r0, =0x40020800U
	ldr r1, [r0]
	orr r1, (1<<26)
	and r1, ~(1<<27)
	str r1, [r0]
	//SYST_RVR - SysTick Reload Value Register
	ldr r0, =0xE000E014U
	mov r1, #15330
	str r1, [r0]
	//SYST_CVR - SysTick Current Value Register
	ldr r0, =0xE000E018U
	mov r1, #0
	str r1, [r0]
	//SYST_CSR - SysTick Control and Status Register
	ldr r2, =0xE000E010U
	ldr r3, [r2]
	orr r3, (1<<0)|(1<<2)
	str r3, [r2]
	//GPIOC->ODR
	ldr r0, =0x40020814U

	mov r4, #0

	loop:
		ldr r3, [r2]
		and r3, (1<<16)
		cmp r3, (1<<16)
		beq incrementa
		b loop
	incrementa:
		add r4, #1
		cmp r4, #350
		beq alterna
		b loop
	alterna:
		//GPIOC->ODR bit 2^13 = toggle bit
		ldr r1, [r0]
		eor r1, (1<<13)
		str r1, [r0]
		mov r4, #0
		b loop


