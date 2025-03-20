/**
 ******************************************************************************
 * @file    systick.c
 * @author  Loren Snow
 * @brief   Systick source file.
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

#include "systick.h"

/**
 * @brief       Delays by a number of miliseconds, using the system timer
 * @param[in]   delay: miliseconds to delay
 */
void systick_delay_ms(uint32_t delay)
{
    SysTick->LOAD = ONE_MSEC_LOAD - 1;
    SysTick->VAL = 0;
    SysTick->CTRL = CTRL_CLCKSRC;
    SysTick->CTRL |= CTRL_ENABLE;

    for (int i = 0; i < delay; i++)
    {
        while ((SysTick->CTRL & CTRL_COUNTFLAG) == 0)
        {
        }
    }

    SysTick->CTRL = 0;
}