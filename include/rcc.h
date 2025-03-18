

#ifndef RCC_H
#define RCC_H

#include <stdint.h>

#define RCC_BASE 0x40021000

/**
 * @brief   Represents the RCC peripheral and its registers
 */
typedef struct
{
    volatile uint32_t CR;       ///< Clock control register
    volatile uint32_t CFGR;     ///< Clock configuration register
    volatile uint32_t CIR;      ///< Clock interrupt register
    volatile uint32_t APB2RSTR; ///< APB2 peripheral reset register
    volatile uint32_t APB1RSTR; ///< APB1 peripheral reset register
    volatile uint32_t AHBENR;   ///< AHB peripheral clock enable register
    volatile uint32_t APB2ENR;  ///< APB2 peripheral clock enable register
    volatile uint32_t APB1ENR;  ///< APB1 peripheral clock enable register
    volatile uint32_t BDCR;     ///< RTC domain control register
    volatile uint32_t CSR;      ///< Control/status register
    volatile uint32_t AHBRSTR;  ///< AHB peripheral reset register
    volatile uint32_t CFGR2;    ///< Clock configuration register 2
    volatile uint32_t CFGR3;    ///< Clock configuration register 3
} RCC_TypeDef;

#define RCC ((RCC_TypeDef *)RCC_BASE) ///< RCC peripheral pointer

/******************************************************************************
AHB clock enable register bitmasks
******************************************************************************/
#define DMA1EN (1U << 0)   ///< DMA1 clock enable
#define SRAMEN (1U << 2)   ///< SRAM interface clock enable
#define FLITFEN (1U << 4)  ///< FLITF clock enable
#define FMCEN (1U << 5)    ///< FMC clock enable
#define CRCEN (1U << 6)    ///< CRC clock enable
#define GPIOHEN (1U << 16) ///< IO port H clock enable
#define GPIOAEN (1U << 17) ///< IO port A clock enable
#define GPIOBEN (1U << 18) ///< IO port B clock enable
#define GPIOCEN (1U << 19) ///< IO port C clock enable
#define GPIODEN (1U << 20) ///< IO port D clock enable
#define GPIOEEN (1U << 21) ///< IO port E clock enable
#define GPIOFEN (1U << 22) ///< IO port F clock enable
#define GPIOGEN (1U << 23) ///< IO port G clock enable
#define TSCEN (1U << 24)   ///< Touch sensing controller clock enable
#define ADC12EN (1U << 28) ///< ADC1 and ADC2 enable
#define ADC34EN (1U << 29) ///< ADC3 and ADC4 enable

void rcc_enable_gpioa(void);

#endif /* RCC_H */