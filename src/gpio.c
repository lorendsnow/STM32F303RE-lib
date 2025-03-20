/**
 ******************************************************************************
 * @file    gpio.c
 * @author  Loren Snow
 * @brief   GPIO source file.
 *
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2025 Loren Snow
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 ******************************************************************************
 */

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

/**
 * @brief   Enables the on-board LED by setting PA5 to output mode.
 */
void gpioa_enable_led(void)
{
    gpioa_set_mode(5, OUTPUT);
}

/**
 * @brief   Turns on the on-board LED by setting PA5 to 1.
 */
void gpioa_led_on(void)
{
    GPIOA->ODR |= LED_PIN;
}

/**
 * @brief   Turns off the on-board LED by setting PA5 to 0.
 */
void gpioa_led_off(void)
{
    GPIOA->ODR &= ~(LED_PIN);
}

/**
 * @brief   Toggles the on-board LED by XOR'ing PA5.
 */
void gpioa_led_toggle(void)
{
    GPIOA->ODR ^= LED_PIN;
}