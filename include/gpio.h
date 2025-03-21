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

#define LED_PIN (1U << 5) ///< LED is PA5

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

/**
 * @brief   Definitions for GPIO output types
 */
typedef enum
{
    PUSH_PULL,
    OPEN_DRAIN,
} Output_Type;

/**
 * @brief   Definitions for GPIO pull-up/pull-down mode
 */
typedef enum
{
    NONE,
    PULL_UP,
    PULL_DOWN,
} PullUp_PullDown;

/**
 * @brief   Definitions for alternate function mapping
 */
typedef enum
{
    AF0,
    AF1,
    AF2,
    AF3,
    AF4,
    AF5,
    AF6,
    AF7,
    AF8,
    AF9,
    AF10,
    AF11,
    AF12,
    AF13,
    AF14,
    AF15,
} Alt_Function;

void gpio_map_alternate_fn(GPIO_TypeDef *GPIOx, uint8_t pin, Alt_Function fn);
void gpio_set_mode(GPIO_TypeDef *GPIOx, uint8_t pin, GPIO_Mode mode);
void gpio_set_output_type(GPIO_TypeDef *GPIOx, uint8_t pin, Output_Type type);
void gpio_set_pullup_pulldown(GPIO_TypeDef *GPIOx, uint8_t pin, PullUp_PullDown pull_t);
void gpioa_enable_led(void);
void gpioa_led_on(void);
void gpioa_led_off(void);
void gpioa_led_toggle(void);
void gpiob_use_I2C(void);

#endif /* GPIO_H */
