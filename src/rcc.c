/**
 ******************************************************************************
 * @file    rcc.c
 * @author  Loren Snow
 * @brief   RCC source file.
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

#include "rcc.h"

/**
 * @brief   Enables the GPIO port A clock.
 */
void rcc_enable_gpioa(void)
{
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
}

/**
 * @brief   Enables the GPIO port B clock.
 */
void rcc_enable_gpiob(void)
{
    RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
}

/**
 * @brief   Enables the I2C1 clock.
 */
void rcc_enable_I2C1(void)
{
    RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;
}
