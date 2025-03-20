/**
 ******************************************************************************
 * @file    gpio.h
 * @author  Loren Snow
 * @brief   GPIO header file.
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

#ifndef GPIO_H
#define GPIO_H

#include "stm32f303xe.h"
#include <stdint.h>

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

#define LED_PIN (1U << 5) ///< LED is PA5

void gpioa_set_mode(uint8_t port, GPIO_Mode mode);
void gpioa_enable_led(void);
void gpioa_led_on(void);
void gpioa_led_off(void);
void gpioa_led_toggle(void);

#endif /* GPIO_H */