
#include "rcc.h"

/**
 * @brief   Enables the GPIO port A clock
 */
void rcc_enable_gpioa(void)
{
    RCC->AHBENR |= GPIOAEN;
}