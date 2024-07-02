// Programa em Assembly
.syntax unified
.cpu cortex-m4
.fpu softvfp
.thumb
.global main

//FLASH and POWER
.equ FLASH_ACR, 				0x40023C00U
 .equ PWR_CR, 						0x40007000U
//RCC
.equ RCC_CR, 						0x40023800U
.equ RCC_PLLCFGR,				0x40023804U
.equ RCC_CFGR,					0x40023808U
.equ RCC_AHB1ENR, 			0x40023830U
.equ RCC_APB1ENR, 			0x40023840U
//GPIOA
.equ GPIOA_MODER,			0x40020000U
.equ GPIOA_OSPEEDR,		0x40020008U
.equ GPIOA_PUPDR,			0x4002000CU
//GPIOC
.equ GPIOC_MODER, 			0x40020800U
.equ GPIOC_ODR,				0x40020814U

main:
		/* 1) Ativa HSE e aguarda por Ready
			RCC_CR->HSEON = 1;
		 	while(!RCC_CR->HSERDY){}; */
		ldr 			r0, =RCC_CR
		ldr 			r1, [r0]
		orr 			r1, (1<<16)
		str 			r1, [r0]
_loop1:
		ldr 			r1, [r0]
		ands		r1, (1<<17)
		beq		_loop1
		/* 2) Enable Clock para a Interface POWER
			RCC_APB1ENR->PWREN = 1; 	*/
		ldr 			r0, = RCC_APB1ENR
		ldr 			r1, [r0]
		orr 			r1, (1<<28)
		str 			r1, [r0]
		/* 3) Seleção do Regulador de Tensão conforme Clock
			PWR_CR->VOS = 1; */
		ldr 			r0, =PWR_CR
		ldr 			r1, [r0]
		and			r1, ~(1<<15)
		str			r1, [r0]
		ldr 			r1, [r0]
		orr 			r1, (1<<14)
		str 			r1, [r0]
		/* 4) Ajusta os fatores da FLASH conforme Clock
			FLASH_ACR->PRFTEN = 1;
			FLASH_ACR->ICEN = 1;
			FLASH_ACR->DCEN = 1;
			FLASH_ACR->LATENCY = 1; */
		ldr 			r0, =FLASH_ACR
		ldr 			r1, [r0]
		orr 			r1, (7<<8)
		str 			r1, [r0]
		ldr 			r1, [r0]
		and			r1, ~(7<<1)
		str 			r1, [r0]
		ldr 			r1, [r0]
		orr 			r1, (1<<0)
		str 			r1, [r0]
		/*  5) Ajusta os Prescallers
			RCC_CFGR->HPRE = 0;
			RCC_CFGR->PPRE1 = 0;
			RCC_CFGR->PPRE2 = 0; */
		ldr 			r0, =RCC_CFGR
		ldr 			r1, [r0]
		and			r1, ~(0xf<<4)
		str 			r1, [r0]
		ldr 			r1, [r0]
		and			r1, ~(7<<10)
		str 			r1, [r0]
		ldr 			r1, [r0]
		and			r1, ~(7<<13)
		str 			r1, [r0]
		/* 6) Ajusta os fatores do PLL
			RCC_PLLCFGR->PLLM = 24;
			RCC_PLLCFGR->PLLN = 96;
			RCC_PLLCFGR->PLLP = 0; */
		ldr 			r0, =RCC_PLLCFGR
		ldr 			r1, [r0]
		and			r1, ~(0x3f<<0)
		str 			r1, [r0]
		ldr 			r1, [r0]
		orr 			r1, (24<<0)
		str 			r1, [r0]
		ldr 			r1, [r0]
		and			r1, ~(0xff<<6)
		str 			r1, [r0]
		ldr 			r1, [r0]
		and			r1, ~(1<<14)
		str 			r1, [r0]
		ldr 			r1, [r0]
		orr 			r1, (96<<6)
		str 			r1, [r0]
		ldr 			r1, [r0]
		and			r1, ~(3<<16)
		str 			r1, [r0]
		/* 7) Seleciona o Clock Source para o PLL (HSE)
			RCC_PLLCFGR->PLLSRC = 1; */
		ldr 			r0, =RCC_PLLCFGR
		ldr 			r1, [r0]
		orr 			r1, (1<<22)
		str 			r1, [r0]
		/* 8) Ativa o PLL e aguarda por Ready
			RCC_CR->PLLON = 1;
			while(!RCC_CR->PLLRDY){}; */
		ldr 			r0, =RCC_CR
		ldr 			r1, [r0]
		orr 			r1, (1<<24)
		str 			r1, [r0]
_loop2:
		ldr 			r1, [r0]
		ands		r1, (1<<25)
		beq		_loop2
		/* 9) Seleciona o Clock Source principal
		//RCC_CFGR->SW = 0x2;
		//while (!(RCC_CFGR->SWS == 2)){}; */
		ldr 			r0, =RCC_CFGR
		ldr 			r1, [r0]
		orr 			r1, (2<<0)
		str 			r1, [r0]
_loop3:
		ldr 			r1, [r0]
		ands		r1, (2<<2)
		beq		_loop3

		//RCC->AHB1ENR bit 2^2 = 1 para habilitar clock para GPIOC e 2^0=1 para habilitar GPIOA
		ldr 			r0, =RCC_AHB1ENR
		ldr 			r1, [r0]
		orr 			r1, (1<<2) | (1<<0)
		str 			r1, [r0]
		//GPIOA->MODER bit 2^16 = 0 e 2^17 = 1 (alternate function - MCO1)
		ldr 			r0, =GPIOA_MODER
		ldr 			r1, [r0]
		and			r1, ~(1<<16)
		str 			r1, [r0]
		ldr			 r1, [r0]
		orr 			r1, (1<<17)
		str 			r1, [r0]
		//GPIOA->OSPEEDR bit 2^16 = 1 e 2^17 = 1 (high speed)
		ldr 			r0, =GPIOA_OSPEEDR
		ldr			 r1, [r0]
		orr 			r1, (3<<16)
		str 			r1, [r0]
		//GPIOA->PUPDR bit 2^16 = 0 e 2^17 = 0  (no pull-up, no pull-down)
		ldr 			r0, =GPIOA_PUPDR
		ldr 			r1, [r0]
		and			r1, ~(3<<16)
		str 			r1, [r0]
		//GPIOC->MODER bit 2^26 =  e 2^27 = 0
		ldr 			r0, =GPIOC_MODER
		ldr 			r1, [r0]
		and			r1, ~(3<<26)
		str 			r1, [r0]
		ldr			 r1, [r0]
		orr 			r1, (1<<26)
		str 			r1, [r0]
		//RCC_CFGR->MCO1PRE = 0x0
		ldr 			r0, =RCC_CFGR
		ldr 			r1, [r0]
		and 		r1, ~(7<<24)
		str 			r1, [r0]
		//RCC_CFGR->MCO1 = 0x3
		ldr 			r0, =RCC_CFGR
		ldr 			r1, [r0]
		orr 			r1, (3<<21)
		str 			r1, [r0]
_loop4:
		//GPIOC->ODR bit 2^13 = toggle bit
		ldr 			r0, =GPIOC_ODR
		ldr 			r1, [r0]
		eor 		r1, (1<<13)
		str 			r1, [r0]
		ldr 			r3, =2000000U
		bl		 	_delay
		bl 			_loop4

_delay:
		subs 		r3, r3, #1
		bne		 _delay
		bx 			lr
