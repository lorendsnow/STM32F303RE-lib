
#include "gpio.h"

/**
 * @brief       Sets the mode on a GPIOA port
 * @param       port: the port to set (0-16)
 * @param       mode: mode to set the port to
 */
void gpioa_set_mode(uint8_t port, GPIO_Mode mode)
{
    uint8_t lowbit = port * 2;
    uint8_t highbit = lowbit + 1;

    switch (mode)
    {
    case INPUT: /* 00 */
        GPIOA->MODER &= ~(1U << lowbit);
        GPIOA->MODER &= ~(1U << highbit);
        break;
    case OUTPUT: /* 01 */
        GPIOA->MODER |= (1U << lowbit);
        GPIOA->MODER &= ~(1U << highbit);
        break;
    case ALTERNATE: /* 10 */
        GPIOA->MODER &= ~(1U << lowbit);
        GPIOA->MODER |= (1U << highbit);
        break;
    case ANALOG: /* 11 */
        GPIOA->MODER |= (1U << lowbit);
        GPIOA->MODER |= (1U << highbit);
        break;
    default:
        break;
    }
}