//********************************
// POWER

typedef struct
{
	uint32_t LPDS:1;
	uint32_t PDDS:1;
	uint32_t CWUF:1;
	uint32_t CSBF:1;
	uint32_t PVDE:1;
	uint32_t PLS:3;
	uint32_t DBP:1;
	uint32_t FPDS:1;
	uint32_t LPLVDS:1;
	uint32_t MRLVDS:1;
	uint32_t Reserved1:1;
	uint32_t ADCDC1:1;
	uint32_t VOS:2;
	uint32_t Reserved2:4;
	uint32_t FMSSR:1;
	uint32_t FISSR:1;
	uint32_t Reserved3:10;
} PWR_CR_t;

typedef struct
{
	uint32_t WUF:1;
	uint32_t SBF:1;
	uint32_t PVDO:1;
	uint32_t BRR:1;
	uint32_t Reserved1:4;
	uint32_t EWUP:1;
	uint32_t BRE:1;
	uint32_t Reserved2:4;
	uint32_t VOSRDY:1;
	uint32_t Reserved3:17;
} PWR_CSR_t;

//********************************
// FLASH Registers
typedef struct
{
	uint32_t LATENCY:4;
	uint32_t Reserved1:4;
	uint32_t PRFTEN:1;
	uint32_t ICEN:1;
	uint32_t DCEN:1;
	uint32_t ICRST:1;
	uint32_t DCRST:1;
	uint32_t Reserved2:19;
} FLASH_ACR_t;

//********************************
// RCC Registers
typedef struct
{
	uint32_t HSION:1;
	uint32_t HSIRDY:1;
	uint32_t Reserved1:1;
	uint32_t HSITRIM:5;
	uint32_t HSICAL:8;
	uint32_t HSEON:1;
	uint32_t HSERDY:1;
	uint32_t HSEBYP:1;
	uint32_t CSSON:1;
	uint32_t Reserved2:4;
	uint32_t PLLON:1;
	uint32_t PLLRDY:1;
	uint32_t PPLI2SON:1;
	uint32_t PPLI2SRDY:1;
	uint32_t Reserved3:4;
} RCC_CR_t;

typedef struct
{
	uint32_t PLLM:6;
	uint32_t PLLN:9;
	uint32_t Reserved1:1;
	uint32_t PLLP:2;
	uint32_t Reserved2:4;
	uint32_t PLLSRC:1;
	uint32_t Reserved3:1;
	uint32_t PPLQ:4;
	uint32_t Reserved4:4;
} RCC_PLLCFGR_t;

typedef struct
{
	uint32_t SW:2;
	uint32_t SWS:2;
	uint32_t HPRE:4;
	uint32_t Reserved1:2;
	uint32_t PPRE1:3;
	uint32_t PPRE2:3;
	uint32_t RTCPRE:5;
	uint32_t MCO1:2;
	uint32_t I2SSCR:1;
	uint32_t MCO1PRE:3;
	uint32_t MCO2PRE:3;
	uint32_t MCO2:2;
} RCC_CFGR_t;

typedef struct
{
	uint32_t LSIRDYF:1;
	uint32_t LSERDYF:1;
	uint32_t HSIRDYF:1;
	uint32_t HSERDYF:1;
	uint32_t PLLRDYF:1;
	uint32_t PLLI2SRDYF:1;
	uint32_t Reserved1:1;
	uint32_t CSSF:1;
	uint32_t LSIRDYIE:1;
	uint32_t LSERDYIE:1;
	uint32_t HSIRDYIE:1;
	uint32_t HSERDYIE:1;
	uint32_t PLLRDYIE:1;
	uint32_t PLLI2SRDYIE:1;
	uint32_t Reserved2:2;
	uint32_t LSIRDYC:1;
	uint32_t LSERDYC:1;
	uint32_t HSIRDYC:1;
	uint32_t HSERDYC:1;
	uint32_t PLLRDYC:1;
	uint32_t PLLI2SRDYC:1;
	uint32_t Reserved3:1;
	uint32_t CSSC:1;
	uint32_t Reserved4:8;
} RCC_CIR_t;

typedef struct
{
	uint32_t GPIOARST:1;
	uint32_t GPIOBRST:1;
	uint32_t GPIOCRST:1;
	uint32_t GPIODRST:1;
	uint32_t GPIOERST:1;
	uint32_t Reserved1:2;
	uint32_t GPIOHRST:1;
	uint32_t Reserved2:4;
	uint32_t CRCRST:1;
	uint32_t Reserved3:8;
	uint32_t DMA1RST:1;
	uint32_t DMA2RST:1;
	uint32_t Reserved4:9;
} RCC_AHB1RSTR_t;

typedef struct
{
	uint32_t Reserved1:7;
	uint32_t OTGFSRST:1;
	uint32_t Reserved2:24;
} RCC_AHB2RSTR_t;

typedef struct
{
	uint32_t TIM2RST:1;
	uint32_t TIM3RST:1;
	uint32_t TIM4RST:1;
	uint32_t TIM5RST:1;
	uint32_t Reserved1:7;
	uint32_t WWDGRST:1;
	uint32_t Reserved2:2;
	uint32_t SPI2RST:1;
	uint32_t SPI3RST:1;
	uint32_t Reserved3:1;
	uint32_t USART2RST:1;
	uint32_t Reserved4:3;
	uint32_t I2C1RST:1;
	uint32_t I2C2RST:1;
	uint32_t I2C3RST:1;
	uint32_t Reserved5:4;
	uint32_t PWRRST:1;
	uint32_t Reserved6:3;
} RCC_APB1RSTR_t;

typedef struct
{
	uint32_t TIM1RST:1;
	uint32_t Reserved1:3;
	uint32_t USART1RST:1;
	uint32_t USART6RST:1;
	uint32_t Reserved2:2;
	uint32_t ADC1RST:1;
	uint32_t Reserved3:2;
	uint32_t SDIORST:1;
	uint32_t SPI1RST:1;
	uint32_t SPI4RST:1;
	uint32_t SYSCFGRST:1;
	uint32_t Reserved4:1;
	uint32_t TIM9RST:1;
	uint32_t TIM10RST:1;
	uint32_t TIM11RST:1;
	uint32_t Reserved5:1;
	uint32_t SPI5RST:1;
	uint32_t Reserved6:11;
} RCC_APB2RSTR_t;

typedef struct
{
	uint32_t GPIOAEN:1;
	uint32_t GPIOBEN:1;
	uint32_t GPIOCEN:1;
	uint32_t GPIODEN:1;
	uint32_t GPIOEEN:1;
	uint32_t Reserved1:2;
	uint32_t GPIOHEN:1;
	uint32_t Reserved2:4;
	uint32_t CRCEN:1;
	uint32_t Reserved3:8;
	uint32_t DMA1EN:1;
	uint32_t DMA2EN:1;
	uint32_t Reserved4:9;
} RCC_AHB1ENR_t;

typedef struct
{
	uint32_t Reserved1:7;
	uint32_t OTGFSEN:1;
	uint32_t Reserved2:24;
} RCC_AHB2ENR_t;

typedef struct
{
	uint32_t TIM2EN:1;
	uint32_t TIM3EN:1;
	uint32_t TIM4EN:1;
	uint32_t TIM5EN:1;
	uint32_t Reserved1:7;
	uint32_t WWDGEN:1;
	uint32_t Reserved2:2;
	uint32_t SPI2EN:1;
	uint32_t SPI3EN:1;
	uint32_t Reserved3:1;
	uint32_t USART2EN:1;
	uint32_t Reserved4:3;
	uint32_t I2C1EN:1;
	uint32_t I2C2EN:1;
	uint32_t I2C3EN:1;
	uint32_t Reserved5:4;
	uint32_t PWREN:1;
	uint32_t Reserved6:3;
} RCC_APB1ENR_t;

typedef struct
{
	uint32_t TIM1EN:1;
	uint32_t Reserved1:3;
	uint32_t USART1EN:1;
	uint32_t USART6EN:1;
	uint32_t Reserved2:2;
	uint32_t ADC1EN:1;
	uint32_t Reserved3:2;
	uint32_t SDIOEN:1;
	uint32_t SPI1EN:1;
	uint32_t SPI4EN:1;
	uint32_t SYSCFGEN:1;
	uint32_t Reserved4:1;
	uint32_t TIM9EN:1;
	uint32_t TIM10EN:1;
	uint32_t TIM11EN:1;
	uint32_t Reserved5:1;
	uint32_t SPI5EN:1;
	uint32_t Reserved6:11;
} RCC_APB2ENR_t;

typedef struct
{
	uint32_t GPIOALPEN:1;
	uint32_t GPIOBLPEN:1;
	uint32_t GPIOCLPEN:1;
	uint32_t GPIODLPEN:1;
	uint32_t GPIOELPEN:1;
	uint32_t Reserved1:2;
	uint32_t GPIOHLPEN:1;
	uint32_t Reserved2:4;
	uint32_t CRCLPEN:1;
	uint32_t Reserved3:8;
	uint32_t DMA1LPEN:1;
	uint32_t DMA2LPEN:1;
	uint32_t Reserved4:9;
} RCC_AHB1LPENR_t;

typedef struct
{
	uint32_t Reserved1:7;
	uint32_t OTGFSLPEN:1;
	uint32_t Reserved2:24;
} RCC_AHB2LPENR_t;

typedef struct
{
	uint32_t TIM2LPEN:1;
	uint32_t TIM3LPEN:1;
	uint32_t TIM4LPEN:1;
	uint32_t TIM5LPEN:1;
	uint32_t Reserved1:7;
	uint32_t WWDGLPEN:1;
	uint32_t Reserved2:2;
	uint32_t SPI2LPEN:1;
	uint32_t SPI3LPEN:1;
	uint32_t Reserved3:1;
	uint32_t USART2LPEN:1;
	uint32_t Reserved4:3;
	uint32_t I2C1LPEN:1;
	uint32_t I2C2LPEN:1;
	uint32_t I2C3LPEN:1;
	uint32_t Reserved5:4;
	uint32_t PWRLPEN:1;
	uint32_t Reserved6:3;
} RCC_APB1LPENR_t;

typedef struct
{
	uint32_t TIM1LPEN:1;
	uint32_t Reserved1:3;
	uint32_t USART1LPEN:1;
	uint32_t USART6LPEN:1;
	uint32_t Reserved2:2;
	uint32_t ADC1LPEN:1;
	uint32_t Reserved3:2;
	uint32_t SDIOLPEN:1;
	uint32_t SPI1LPEN:1;
	uint32_t SPI4LPEN:1;
	uint32_t SYSCFGLPEN:1;
	uint32_t Reserved4:1;
	uint32_t TIM9LPEN:1;
	uint32_t TIM10LPEN:1;
	uint32_t TIM11LPEN:1;
	uint32_t Reserved5:1;
	uint32_t SPI5LPEN:1;
	uint32_t Reserved6:11;
} RCC_APB2LPENR_t;

typedef struct
{
	uint32_t LSEON:1;
	uint32_t LSERDY:1;
	uint32_t LSEBYP:1;
	uint32_t LSEMOD:1;
	uint32_t Reserved1:4;
	uint32_t RTCSEL:2;
	uint32_t Reserved2:5;
	uint32_t RTCEN:1;
	uint32_t BDRST:1;
	uint32_t Reserved3:15;
} RCC_BDCR_t;

typedef struct
{
	uint32_t LSION:1;
	uint32_t LSIRDY:1;
	uint32_t Reserved1:14;
	uint32_t Reserved2:8;
	uint32_t RMVF:1;
	uint32_t BORRSTF:1;
	uint32_t PINRSTF:1;
	uint32_t PORRSTF:1;
	uint32_t SFTRSTF:1;
	uint32_t IWDGRSTF:1;
	uint32_t WWDGRSTF:1;
	uint32_t LPWRRSTF:1;
} RCC_CSR_t;

typedef struct
{
	uint32_t MODPER:13;
	uint32_t INCSTEP:15;
	uint32_t Reserved1:2;
	uint32_t SPREADSEL:1;
	uint32_t SSCGEN:1;
} RCC_SSCGR_t;

typedef struct
{
	uint32_t PLLI2SM:6;
	uint32_t PLLI2SN:9;
	uint32_t Reserved1:13;
	uint32_t PLLI2SR0:1;
	uint32_t PLLI2SR1:1;
	uint32_t PLLI2SR2:1;
	uint32_t Reserved2:1;
} RCC_PLLI2SCFGR_t;

typedef struct
{
	uint32_t Reserved1:24;
	uint32_t TIMPRE:1;
	uint32_t Reserved2:7;
} RCC_DCKCFGR_t;

//********************************
// GPIO Registers
typedef struct
{
	uint32_t MODER0:2;
	uint32_t MODER1:2;
	uint32_t MODER2:2;
	uint32_t MODER3:2;
	uint32_t MODER4:2;
	uint32_t MODER5:2;
	uint32_t MODER6:2;
	uint32_t MODER7:2;
	uint32_t MODER8:2;
	uint32_t MODER9:2;
	uint32_t MODER10:2;
	uint32_t MODER11:2;
	uint32_t MODER12:2;
	uint32_t MODER13:2;
	uint32_t MODER14:2;
	uint32_t MODER15:2;
} GPIOx_MODER_t;

typedef struct
{
	uint32_t OT0:1;
	uint32_t OT1:1;
	uint32_t OT2:1;
	uint32_t OT3:1;
	uint32_t OT4:1;
	uint32_t OT5:1;
	uint32_t OT6:1;
	uint32_t OT7:1;
	uint32_t OT8:1;
	uint32_t OT9:1;
	uint32_t OT10:1;
	uint32_t OT11:1;
	uint32_t OT12:1;
	uint32_t OT13:1;
	uint32_t OT14:1;
	uint32_t OT15:1;
	uint32_t Reserved:16;
} GPIOx_OTYPER_t;

typedef struct
{
	uint32_t OSPEEDR0:2;
	uint32_t OSPEEDR1:2;
	uint32_t OSPEEDR2:2;
	uint32_t OSPEEDR3:2;
	uint32_t OSPEEDR4:2;
	uint32_t OSPEEDR5:2;
	uint32_t OSPEEDR6:2;
	uint32_t OSPEEDR7:2;
	uint32_t OSPEEDR8:2;
	uint32_t OSPEEDR9:2;
	uint32_t OSPEEDR10:2;
	uint32_t OSPEEDR11:2;
	uint32_t OSPEEDR12:2;
	uint32_t OSPEEDR13:2;
	uint32_t OSPEEDR14:2;
	uint32_t OSPEEDR15:2;
} GPIOx_OSPEEDR_t;

typedef struct
{
	uint32_t PUPDR0:2;
	uint32_t PUPDR1:2;
	uint32_t PUPDR2:2;
	uint32_t PUPDR3:2;
	uint32_t PUPDR4:2;
	uint32_t PUPDR5:2;
	uint32_t PUPDR6:2;
	uint32_t PUPDR7:2;
	uint32_t PUPDR8:2;
	uint32_t PUPDR9:2;
	uint32_t PUPDR10:2;
	uint32_t PUPDR11:2;
	uint32_t PUPDR12:2;
	uint32_t PUPDR13:2;
	uint32_t PUPDR14:2;
	uint32_t PUPDR15:2;
} GPIOx_PUPDR_t;

typedef struct
{
	uint32_t IDR0:1;
	uint32_t IDR1:1;
	uint32_t IDR2:1;
	uint32_t IDR3:1;
	uint32_t IDR4:1;
	uint32_t IDR5:1;
	uint32_t IDR6:1;
	uint32_t IDR7:1;
	uint32_t IDR8:1;
	uint32_t IDR9:1;
	uint32_t IDR10:1;
	uint32_t IDR11:1;
	uint32_t IDR12:1;
	uint32_t IDR13:1;
	uint32_t IDR14:1;
	uint32_t IDR15:1;
	uint32_t Reserved:16;
} GPIOx_IDR_t;

typedef struct
{
	uint32_t ODR0:1;
	uint32_t ODR1:1;
	uint32_t ODR2:1;
	uint32_t ODR3:1;
	uint32_t ODR4:1;
	uint32_t ODR5:1;
	uint32_t ODR6:1;
	uint32_t ODR7:1;
	uint32_t ODR8:1;
	uint32_t ODR9:1;
	uint32_t ODR10:1;
	uint32_t ODR11:1;
	uint32_t ODR12:1;
	uint32_t ODR13:1;
	uint32_t ODR14:1;
	uint32_t ODR15:1;
	uint32_t Reserved:16;
} GPIOx_ODR_t;

typedef struct
{
	uint32_t BS0:1;
	uint32_t BS1:1;
	uint32_t BS2:1;
	uint32_t BS3:1;
	uint32_t BS4:1;
	uint32_t BS5:1;
	uint32_t BS6:1;
	uint32_t BS7:1;
	uint32_t BS8:1;
	uint32_t BS9:1;
	uint32_t BS10:1;
	uint32_t BS11:1;
	uint32_t BS12:1;
	uint32_t BS13:1;
	uint32_t BS14:1;
	uint32_t BS15:1;
	uint32_t BR0:1;
	uint32_t BR1:1;
	uint32_t BR2:1;
	uint32_t BR3:1;
	uint32_t BR4:1;
	uint32_t BR5:1;
	uint32_t BR6:1;
	uint32_t BR7:1;
	uint32_t BR8:1;
	uint32_t BR9:1;
	uint32_t BR10:1;
	uint32_t BR11:1;
	uint32_t BR12:1;
	uint32_t BR13:1;
	uint32_t BR14:1;
	uint32_t BR15:1;
} GPIOx_BSRR_t;

typedef struct
{
	uint32_t LCK0:1;
	uint32_t LCK1:1;
	uint32_t LCK2:1;
	uint32_t LCK3:1;
	uint32_t LCK4:1;
	uint32_t LCK5:1;
	uint32_t LCK6:1;
	uint32_t LCK7:1;
	uint32_t LCK8:1;
	uint32_t LCK9:1;
	uint32_t LCK10:1;
	uint32_t LCK11:1;
	uint32_t LCK12:1;
	uint32_t LCK13:1;
	uint32_t LCK14:1;
	uint32_t LCK15:1;
	uint32_t LCKK:1;
	uint32_t Reserved:15;
} GPIOx_LCKR_t;

typedef struct
{
	uint32_t AFRL0:4;
	uint32_t AFRL1:4;
	uint32_t AFRL2:4;
	uint32_t AFRL3:4;
	uint32_t AFRL4:4;
	uint32_t AFRL5:4;
	uint32_t AFRL6:4;
	uint32_t AFRL7:4;
} GPIOx_AFRL_t;

typedef struct
{
	uint32_t AFRH8:4;
	uint32_t AFRH9:4;
	uint32_t AFRH10:4;
	uint32_t AFRH11:4;
	uint32_t AFRH12:4;
	uint32_t AFRH13:4;
	uint32_t AFRH14:4;
	uint32_t AFRH15:4;
} GPIOx_AFRH_t;

//********************************
// System Timer Registers (SysTick)
typedef struct
{
	uint32_t ENABLE:1;
	uint32_t TICKINT:1;
	uint32_t CLKSOURCE:1;
	uint32_t Reserved1:13;
	uint32_t COUNTFLAG:1;
	uint32_t Reserved2:15;
} STK_CTRL_t;

typedef struct
{
	uint32_t RELOAD:24;
	uint32_t Reserved1:8;
} STK_LOAD_t;

typedef struct
{
	uint32_t CURRENT:24;
	uint32_t Reserved1:8;
} STK_VAL_t;

//********************************
// TIMx
typedef struct
{
	uint16_t CEN:1;
	uint16_t UDIS:1;
	uint16_t URS:1;
	uint16_t OPM:1;
	uint16_t DIR:1;
	uint16_t CMS:2;
	uint16_t ARPE:1;
	uint16_t CKD:2;
	uint16_t Reserved1:6;
} TIMx_CR1_t;

typedef struct
{
	uint16_t Reserved1:3;
	uint16_t CCDS:1;
	uint16_t MMS:3;
	uint16_t TI1S:1;
	uint16_t Reserved2:8;
} TIMx_CR2_t;

typedef struct
{
	uint16_t SMS:3;
	uint16_t Reserved1:1;
	uint16_t TS:3;
	uint16_t MSM:1;
	uint16_t ETF:4;
	uint16_t ETPS:2;
	uint16_t ECE:1;
	uint16_t ETP:1;
} TIMx_SMCR_t;

typedef struct
{
	uint16_t UIE:1;
	uint16_t CC1IE:1;
	uint16_t CC2IE:1;
	uint16_t CC3IE:1;
	uint16_t CC4IE:1;
	uint16_t Reserved1:1;
	uint16_t TIE:1;
	uint16_t Reserved2:1;
	uint16_t UDE:1;
	uint16_t CC1DE:1;
	uint16_t CC2DE:1;
	uint16_t CC3DE:1;
	uint16_t CC4DE:1;
	uint16_t Reserved3:1;
	uint16_t TDE:1;
	uint16_t Reserved4:1;
} TIMx_DIER_t;

typedef struct
{
	uint16_t UIF:1;
	uint16_t CC1IF:1;
	uint16_t CC2IF:1;
	uint16_t CC3IF:1;
	uint16_t CC4IF:1;
	uint16_t Reserved1:1;
	uint16_t TIF:1;
	uint16_t Reserved2:2;
	uint16_t CC1OF:1;
	uint16_t CC2OF:1;
	uint16_t CC3OF:1;
	uint16_t CC4OF:1;
	uint16_t Reserved3:3;
} TIMx_SR_t;

typedef struct
{
	uint16_t UG:1;
	uint16_t CC1G:1;
	uint16_t CC2G:1;
	uint16_t CC3G:1;
	uint16_t CC4G:1;
	uint16_t Reserved1:1;
	uint16_t TG:1;
	uint16_t Reserved2:9;
} TIMx_EGR_t;

typedef struct
{
	uint16_t CC1S:2;
	uint16_t IC1PSC:2;
	uint16_t IC1F:4;
	uint16_t CC2S:2;
	uint16_t IC2PSC:2;
	uint16_t IC2F:4;
} TIMx_CCMR1_t;

typedef struct
{
	uint16_t CC3S:2;
	uint16_t IC3PSC:2;
	uint16_t IC3F:4;
	uint16_t CC4S:2;
	uint16_t IC4PSC:2;
	uint16_t IC4F:4;
} TIMx_CCMR2_t;

typedef struct
{
	uint16_t CC1E:1;
	uint16_t CC1P:1;
	uint16_t Reserved1:1;
	uint16_t CC1NP:1;
	uint16_t CC2E:1;
	uint16_t CC2P:1;
	uint16_t Reserved2:1;
	uint16_t CC2NP:1;
	uint16_t CC3E:1;
	uint16_t CC3P:1;
	uint16_t Reserved3:1;
	uint16_t CC3NP:1;
	uint16_t CC4E:1;
	uint16_t CC4P:1;
	uint16_t Reserved4:1;
	uint16_t CC4NP:1;
} TIMx_CCER_t;

typedef struct
{
	uint32_t VALUE:32;
} TIMx_CNT_t;

typedef struct
{
	uint16_t VALUE:16;
} TIMx_PSC_t;

typedef struct
{
	uint32_t VALUE:32;
} TIMx_ARR_t;

typedef struct
{
	uint32_t LVALUE:16;
	uint32_t HVALUE:16;
} TIMx_CCR1_t;

typedef struct
{
	uint32_t LVALUE:16;
	uint32_t HVALUE:16;
} TIMx_CCR2_t;

typedef struct
{
	uint32_t LVALUE:16;
	uint32_t HVALUE:16;
} TIMx_CCR3_t;

typedef struct
{
	uint32_t LVALUE:16;
	uint32_t HVALUE:16;
} TIMx_CCR4_t;

typedef struct
{
	uint16_t DBA:5;
	uint16_t Reserved1:3;
	uint16_t DBL:5;
	uint16_t Reserved2:3;
} TIMx_DCR_t;

typedef struct
{
	uint16_t DMAB:16;
} TIMx_DMAR_t;

typedef struct
{
	uint16_t Reserved1 :10;
	uint16_t ITR1_RMP:2;
	uint16_t Reserved2:4;
} TIM2_OR_t;

typedef struct
{
	uint16_t Reserved1 :10;
	uint16_t TI4_RMP:2;
	uint16_t Reserved2:4;
} TIM5_OR_t;
