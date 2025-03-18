

#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

#define GPIOA_BASE (0x48000000UL)
#define GPIOB_BASE (0x48000400UL)
#define GPIOC_BASE (0x48000800UL)
#define GPIOD_BASE (0x48000C00UL)
#define GPIOE_BASE (0x48001000UL)
#define GPIOF_BASE (0x48001400UL)
#define GPIOG_BASE (0x48001800UL)
#define GPIOH_BASE (0x48001C00UL)

/**
 * @brief   Represents a GPIO port and its registers
 */
typedef struct
{
    volatile uint32_t MODER;   ///< Mode register
    volatile uint32_t OTYPER;  ///< Output type register
    volatile uint32_t OSPEEDR; ///< Output speed register
    volatile uint32_t PUPDR;   ///< Pull-up/pull-down register
    volatile uint32_t IDR;     ///< Input data register
    volatile uint32_t ODR;     ///< Output data register
    volatile uint32_t BSRR;    ///< Bit set/reset register
    volatile uint32_t LCKR;    ///< Configuration lock register
    volatile uint32_t AFRL;    ///< Alternate function low register
    volatile uint32_t AFRH;    ///< Alternate function high register
    volatile uint32_t BRR;     ///< Bit reset register

} GPIO_TypeDef;

/**
 * @brief   Definitions for GPIO modes
 * @note    | INPUT = Input mode
 *          | OUTPUT = General purpose output mode
 *          | ALTERNATE = Alternate function mode
 *          | ANALOG = Analog mode
 */
typedef enum
{
    INPUT,
    OUTPUT,
    ALTERNATE,
    ANALOG,
} GPIO_Mode;

#define GPIOA ((GPIO_TypeDef *)GPIOA_BASE) ///< GPIOA pointer

void gpioa_set_mode(uint8_t port, GPIO_Mode mode);

#endif /* GPIO_H */