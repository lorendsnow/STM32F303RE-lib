/**
 ******************************************************************************
 * @file    i2c.h
 * @author  Loren Snow
 * @brief   I2C header file.
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

#ifndef I2C_H
#define I2C_H

#include "stm32f3xx.h"
#include <stdint.h>

/**
 * @brief   Definitions for setting I2C to standard (100 kHz), fast (400 kHz)
 *          or fast-plus (500 kHz) mode.
 */
typedef enum
{
    Standard,
    Fast,
    Fast_Plus,
} I2C_Mode;

void I2C_init(I2C_TypeDef *I2Cx, I2C_Mode mode);
void I2C_write_bytes(I2C_TypeDef *I2Cx, uint16_t target_addr, char *data, uint32_t len);

#endif /* I2C_H */