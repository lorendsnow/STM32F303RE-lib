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
 * @brief       Map an alternate function to a GPIO pin.
 * @param[in]   GPIOx: a defined GPIO pointer (e.g., GPIOA, GPIOB, etc.)
 * @param[in]   pin: the pin to set
 * @param[in]   fn: alternate function number
 */
void gpio_map_alternate_fn(GPIO_TypeDef *GPIOx, uint8_t pin, Alt_Function fn)
{
    uint8_t hi_lo = pin < 8 ? 0 : 1; /* use AFR[0] for pins 0-7, AFR[1] for pins 8-15 */
    uint8_t bit_0 = pin < 8 ? (pin * 4) : ((pin - 8) * 4);

    switch (fn)
    {
    case AF0:
        GPIOx->AFR[hi_lo] &= ~(1U << bit_0);
        GPIOx->AFR[hi_lo] &= ~(1U << bit_0 + 1);
        GPIOx->AFR[hi_lo] &= ~(1U << bit_0 + 2);
        GPIOx->AFR[hi_lo] &= ~(1U << bit_0 + 3);
        break;
    case AF1:
        GPIOx->AFR[hi_lo] |= (1U << bit_0);
        GPIOx->AFR[hi_lo] &= ~(1U << bit_0 + 1);
        GPIOx->AFR[hi_lo] &= ~(1U << bit_0 + 2);
        GPIOx->AFR[hi_lo] &= ~(1U << bit_0 + 3);
        break;
    case AF2:
        GPIOx->AFR[hi_lo] &= ~(1U << bit_0);
        GPIOx->AFR[hi_lo] |= (1U << bit_0 + 1);
        GPIOx->AFR[hi_lo] &= ~(1U << bit_0 + 2);
        GPIOx->AFR[hi_lo] &= ~(1U << bit_0 + 3);
        break;
    case AF3:
        GPIOx->AFR[hi_lo] |= (1U << bit_0);
        GPIOx->AFR[hi_lo] |= (1U << bit_0 + 1);
        GPIOx->AFR[hi_lo] &= ~(1U << bit_0 + 2);
        GPIOx->AFR[hi_lo] &= ~(1U << bit_0 + 3);
        break;
    case AF4:
        GPIOx->AFR[hi_lo] &= ~(1U << bit_0);
        GPIOx->AFR[hi_lo] &= ~(1U << bit_0 + 1);
        GPIOx->AFR[hi_lo] |= (1U << bit_0 + 2);
        GPIOx->AFR[hi_lo] &= ~(1U << bit_0 + 3);
        break;
    case AF5:
        GPIOx->AFR[hi_lo] |= (1U << bit_0);
        GPIOx->AFR[hi_lo] &= ~(1U << bit_0 + 1);
        GPIOx->AFR[hi_lo] |= (1U << bit_0 + 2);
        GPIOx->AFR[hi_lo] &= ~(1U << bit_0 + 3);
        break;
    case AF6:
        GPIOx->AFR[hi_lo] &= ~(1U << bit_0);
        GPIOx->AFR[hi_lo] |= (1U << bit_0 + 1);
        GPIOx->AFR[hi_lo] |= (1U << bit_0 + 2);
        GPIOx->AFR[hi_lo] &= ~(1U << bit_0 + 3);
        break;
    case AF7:
        GPIOx->AFR[hi_lo] |= (1U << bit_0);
        GPIOx->AFR[hi_lo] |= (1U << bit_0 + 1);
        GPIOx->AFR[hi_lo] |= (1U << bit_0 + 2);
        GPIOx->AFR[hi_lo] &= ~(1U << bit_0 + 3);
        break;
    case AF8:
        GPIOx->AFR[hi_lo] &= ~(1U << bit_0);
        GPIOx->AFR[hi_lo] &= ~(1U << bit_0 + 1);
        GPIOx->AFR[hi_lo] &= ~(1U << bit_0 + 2);
        GPIOx->AFR[hi_lo] |= (1U << bit_0 + 3);
        break;
    case AF9:
        GPIOx->AFR[hi_lo] |= (1U << bit_0);
        GPIOx->AFR[hi_lo] &= ~(1U << bit_0 + 1);
        GPIOx->AFR[hi_lo] &= ~(1U << bit_0 + 2);
        GPIOx->AFR[hi_lo] |= (1U << bit_0 + 3);
        break;
    case AF10:
        GPIOx->AFR[hi_lo] &= ~(1U << bit_0);
        GPIOx->AFR[hi_lo] |= (1U << bit_0 + 1);
        GPIOx->AFR[hi_lo] &= ~(1U << bit_0 + 2);
        GPIOx->AFR[hi_lo] |= (1U << bit_0 + 3);
        break;
    case AF11:
        GPIOx->AFR[hi_lo] |= (1U << bit_0);
        GPIOx->AFR[hi_lo] |= (1U << bit_0 + 1);
        GPIOx->AFR[hi_lo] &= ~(1U << bit_0 + 2);
        GPIOx->AFR[hi_lo] |= (1U << bit_0 + 3);
        break;
    case AF12:
        GPIOx->AFR[hi_lo] &= ~(1U << bit_0);
        GPIOx->AFR[hi_lo] &= ~(1U << bit_0 + 1);
        GPIOx->AFR[hi_lo] |= (1U << bit_0 + 2);
        GPIOx->AFR[hi_lo] |= (1U << bit_0 + 3);
        break;
    case AF13:
        GPIOx->AFR[hi_lo] |= (1U << bit_0);
        GPIOx->AFR[hi_lo] &= ~(1U << bit_0 + 1);
        GPIOx->AFR[hi_lo] |= (1U << bit_0 + 2);
        GPIOx->AFR[hi_lo] |= (1U << bit_0 + 3);
        break;
    case AF14:
        GPIOx->AFR[hi_lo] &= ~(1U << bit_0);
        GPIOx->AFR[hi_lo] |= (1U << bit_0 + 1);
        GPIOx->AFR[hi_lo] |= (1U << bit_0 + 2);
        GPIOx->AFR[hi_lo] |= (1U << bit_0 + 3);
        break;
    case AF15:
        GPIOx->AFR[hi_lo] |= (1U << bit_0);
        GPIOx->AFR[hi_lo] |= (1U << bit_0 + 1);
        GPIOx->AFR[hi_lo] |= (1U << bit_0 + 2);
        GPIOx->AFR[hi_lo] |= (1U << bit_0 + 3);
        break;
    default:
        break;
    }
}

/**
 * @brief       Sets the mode on a GPIO pin.
 * @param[in]   GPIOx: a defined GPIO pointer (e.g., GPIOA, GPIOB, etc.)
 * @param[in]   pin: the pin to set (0-15)
 * @param[in]   mode: mode to set the pin to
 */
void gpio_set_mode(GPIO_TypeDef *GPIOx, uint8_t pin, GPIO_Mode mode)
{
    uint8_t lowbit = pin * 2;
    uint8_t highbit = lowbit + 1;

    switch (mode)
    {
    case INPUT: /* 00 */
        GPIOx->MODER &= ~(1U << lowbit);
        GPIOx->MODER &= ~(1U << highbit);
        break;
    case OUTPUT: /* 01 */
        GPIOx->MODER |= (1U << lowbit);
        GPIOx->MODER &= ~(1U << highbit);
        break;
    case ALTERNATE: /* 10 */
        GPIOx->MODER &= ~(1U << lowbit);
        GPIOx->MODER |= (1U << highbit);
        break;
    case ANALOG: /* 11 */
        GPIOx->MODER |= (1U << lowbit);
        GPIOx->MODER |= (1U << highbit);
        break;
    default:
        break;
    }
}

/**
 * @brief       Sets a GPIOB pin to an output type.
 * @param[in]   GPIOx: a defined GPIO pointer (e.g., GPIOA, GPIOB, etc.)
 * @param[in]   pin: pin number to set (0-15)
 * @param[in]   type: push-pull or open-drain
 */
void gpio_set_output_type(GPIO_TypeDef *GPIOx, uint8_t pin, Output_Type type)
{
    switch (type)
    {
    case PUSH_PULL:
        GPIOx->OTYPER &= ~(1U << pin);
        break;
    case OPEN_DRAIN:
        GPIOx->OTYPER |= (1U << pin);
    default:
        break;
    }
}

/**
 * @brief       Sets a GPIO pin's pull-up/pull-down.
 * @param[in]   GPIOx: a defined GPIO pointer (e.g., GPIOA, GPIOB, etc.)
 * @param[in]   pin: the pin to set
 * @param[in]   pull_t: the type (none, pull-up, or pull-down)
 */
void gpiob_set_pullup_pulldown(GPIO_TypeDef *GPIOx, uint8_t pin, PullUp_PullDown pull_t)
{
    uint8_t lowbit = pin * 2;
    uint8_t highbit = lowbit + 1;

    switch (pull_t)
    {
    case NONE:
        GPIOx->PUPDR &= ~(1U << lowbit);
        GPIOx->PUPDR &= ~(1U << highbit);
        break;
    case PULL_UP:
        GPIOx->PUPDR |= (1U << lowbit);
        GPIOx->PUPDR &= ~(1U << highbit);
        break;
    case PULL_DOWN:
        GPIOx->PUPDR &= ~(1U << lowbit);
        GPIOx->PUPDR |= (1U << highbit);
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
    gpio_set_mode(GPIOA, 5, OUTPUT);
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

/**
 * @brief   Enables I2C1 by setting PB8 and PB9 to alternate mode, open-drain output type,
 *          pull-up and the applicable alternate function.
 */
void gpiob_use_I2C(void)
{
    gpio_set_mode(GPIOB, 8, ALTERNATE);
    gpio_set_mode(GPIOB, 9, ALTERNATE);
    gpio_set_output_type(GPIOB, 8, OPEN_DRAIN);
    gpio_set_output_type(GPIOB, 9, OPEN_DRAIN);
    gpio_set_pullup_pulldown(GPIOB, 8, PULL_UP);
    gpio_set_pullup_pulldown(GPIOB, 9, PULL_UP);
    gpio_map_alternate_fn(GPIOB, 8, AF4);
    gpio_map_alternate_fn(GPIOB, 9, AF4);
}