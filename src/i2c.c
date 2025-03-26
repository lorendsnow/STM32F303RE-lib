/**
 ******************************************************************************
 * @file    i2c.c
 * @author  Loren Snow
 * @brief   I2C source file.
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

#include "i2c.h"

/**
 * @brief       Initiates an I2C as controller
 * @param[in]   I2Cx: a defined I2C pointer (i.e., I2C1, I2C2, or I2C3)
 * @param[in]   mode: Standard, Fast or Fast_Plus
 */
void I2C_init(I2C_TypeDef *I2Cx, I2C_Mode mode)
{
    /* see figure 298.I2C in reference manual for initialization flow, page 838 */

    if (I2Cx == I2C1)
    {
        RCC->APB1RSTR |= (1U << 21); // reset I2C1
    }
    else if (I2Cx == I2C2)
    {
        RCC->APB1RSTR |= (1U << 22); // reset I2C2
    }
    else
    {
        RCC->APB1RSTR |= (1U << 30); // reset I2C3
    }

    switch (mode)
    {
    case Standard:
        I2C_set_standard_timing(I2Cx);
        break;
    case Fast:
        I2C_set_fast_timing(I2Cx);
        break;
    case Fast_Plus:
        I2C_set_fast_plus_timing(I2Cx);
        break;
    default:
        break;
    }

    I2Cx->CR1 |= (1U << 0); // set peripheral enable bit
}

/**
 * @brief       Sets necessary I2C registers to perform a write operation.
 * @param[in]   I2Cx: a defined I2C pointer (i.e., I2C1, I2C2, or I2C3)
 * @param[in]   addr: target device 7 or 10-bit address
 */
static void I2C_set_CR2_reg_for_write(I2C_TypeDef *I2Cx, uint16_t addr)
{
    if (addr > 127) // we're using 10-bit addressing
    {
        I2Cx->CR2 |= I2C_CR2_ADD10;
        I2Cx->CR2 |= ((uint32_t)addr);   // set I2C->CR2 bits 9:0 to target address
        I2Cx->CR2 &= ~(I2C_CR2_HEAD10R); // send 10-bit address header
    }
    else // we're using 7-bit addressing
    {
        I2Cx->CR2 &= ~(I2C_CR2_ADD10);
        I2Cx->CR2 |= ((uint32_t)addr << 1); // set I2C->CR2 bits 7:1 to target address
        I2Cx->CR2 |= I2C_CR2_HEAD10R;       // send 7-bit address header
    }

    I2Cx->CR2 &= ~(I2C_CR2_RD_WRN); // 0 = controller requests a write transfer
}

/**
 * @brief       Set timing registers for an I2C instance to fast mode (400 kHz).
 * @param[in]   I2Cx: a defined I2C pointer (i.e., I2C1, I2C2, or I2C3)
 */
static void I2C_set_fast_timing(I2C_TypeDef *I2Cx)
{
    /*
     * I2C1 uses 8 MHz HSI clock by default; can use SYSCLOCK by setting bit 4 on RCC->CFGR3.
     * See table 149 in reference manual, page 862, for timing calculations using 8 MHz I2CCLK
     *
     * Note - PRESC[3:0] is 0x0 in fast mode.
     */

    I2Cx->TIMINGR |= (1U << 16); // SDADEL[3:0] (bits 19:16) = 0x1 = 0001

    I2Cx->TIMINGR |= (1U << 20); // SCLDEL[3:0] (bits 23:20) = 0x3 = 0011
    I2Cx->TIMINGR |= (1U << 21);

    I2Cx->TIMINGR |= (1U << 8); // SCLH[7:0] (bits 15:8) = 0x3 = 0000 0011
    I2Cx->TIMINGR |= (1U << 9);

    I2Cx->TIMINGR |= (1U << 0); // SCLL[7:0] (bits 7:0) = 0x9 = 0000 1001
    I2Cx->TIMINGR |= (1U << 3);
}

/**
 * @brief       Set timing registers for an I2C instance to fast-plus mode (500 kHz).
 * @param[in]   I2Cx: a defined I2C pointer (i.e., I2C1, I2C2, or I2C3)
 */
static void I2C_set_fast_plus_timing(I2C_TypeDef *I2Cx)
{
    /*
     * I2Cx uses 8 MHz HSI clock by default; can use SYSCLOCK by setting bit 4 on RCC->CFGR3.
     * See table 149 in reference manual, page 862, for timing calculations using 8 MHz I2CCLK
     *
     * Note - PRESC[3:0] and SDADEL[3:0] are both 0x0 in fast-plus mode.
     */

    I2Cx->TIMINGR |= (1U << 20); // SCLDEL[3:0] (bits 23:20) = 0x1 = 0001

    I2Cx->TIMINGR |= (1U << 8); // SCLH[7:0] (bits 15:8) = 0x3 = 0000 0011
    I2Cx->TIMINGR |= (1U << 9);

    I2Cx->TIMINGR |= (1U << 1); // SCLL[7:0] (bits 7:0) = 0x6 = 0000 0110
    I2Cx->TIMINGR |= (1U << 2);
}

/**
 * @brief       Set timing registers for an I2C instance to standard mode (100 kHz).
 * @param[in]   I2Cx: a defined I2C pointer (i.e., I2C1, I2C2, or I2C3)
 */
static void I2C_set_standard_timing(I2C_TypeDef *I2Cx)
{
    /*
     * I2C1 uses 8 MHz HSI clock by default; can use SYSCLOCK by setting bit 4 on RCC->CFGR3.
     * See table 149 in reference manual, page 862, for timing calculations using 8 MHz I2CCLK
     */
    I2Cx->TIMINGR |= (1U << 28); // PRESC[3:0] (bits 31:28) = 0x1 = 0001

    I2Cx->TIMINGR |= (1U << 17); // SDADEL[3:0] (bits 19:16) = 0x2 = 0010

    I2Cx->TIMINGR |= (1U << 22); // SCLDEL[3:0] (bits 23:20) = 0x4 = 0100

    I2Cx->TIMINGR |= (1U << 8); // SCLH[7:0] (bits 15:8) = 0xF = 0000 1111
    I2Cx->TIMINGR |= (1U << 9);
    I2Cx->TIMINGR |= (1U << 10);
    I2Cx->TIMINGR |= (1U << 11);

    I2Cx->TIMINGR |= (1U << 0); // SCLL[7:0] (bits 7:0) = 0x13 = 0001 0011
    I2Cx->TIMINGR |= (1U << 1);
    I2Cx->TIMINGR |= (1U << 4);
}

/**
 * @brief       Writes a number of bytes to the target device.
 * @param[in]   I2Cx: a defined I2C pointer (i.e., I2C1, I2C2, or I2C3)
 * @param[in]   target_addr: the target device's 7 or 10-bit device address
 * @param[in]   data: address of data array to send
 * @param[in]   len: length of data array
 */
void I2C_write_bytes(I2C_TypeDef *I2Cx, uint16_t target_addr, char *data, uint32_t len)
{
    if (target_addr > 1023)
    {
        return; // address is more than 10 bits; invalid
    }

    I2C_set_CR2_reg_for_write(I2Cx, target_addr);

    I2C_recursive_transmit(I2Cx, data, len);
}

/**
 * @brief       Recursively sends bytes to a target device until all data has been sent.
 * @note        We use a recursive function because the F303RE NBYTES register is only 8 bits. So,
 *              if we are sending 256 or more bytes, we need to continually reload NBYTES every 255
 *              bytes until we have less than 256 bytes left to send.
 * @param[in]   I2Cx: a defined I2C pointer (i.e., I2C1, I2C2, or I2C3)
 * @param[in]   data: address of data array to send
 * @param[in]   len: length of remaining data array (or full length of data array on initial
 *              function call)
 */
static void I2C_recursive_transmit(I2C_TypeDef *I2Cx, char *data, uint32_t len)
{
    uint8_t n_bytes;

    if (len < 0x100) // base case - we have less than 256 bytes left to send
    {
        n_bytes = len;
        I2Cx->CR2 &= ~(I2C_CR2_RELOAD); // clear reload bit
        I2Cx->CR2 |= I2C_CR2_AUTOEND;   // set automatic end mode to send STOP signal after n_bytes have been sent
    }
    else
    {
        n_bytes = 0xFF;
    }

    I2Cx->CR2 |= ((uint32_t)n_bytes << 16);
    I2Cx->CR2 |= I2C_CR2_START;

    for (int i = 0; i < n_bytes; i++)
    {
        if (I2Cx->ISR & I2C_ISR_NACKF) // error - we got a NACK from the target
        {
            return;
        }

        while (!(I2Cx->ISR & I2C_ISR_TXE)) // TXDR is not empty
        {
            ; // wait for previous bits in TXDR to send and clear
        }

        I2Cx->TXDR = *data++; // put next byte in the TXDR register
    }

    if ((n_bytes < 0xFF) || (len - n_bytes == 0)) // those were the last bytes
    {
        return;
    }

    I2C_recursive_transmit(I2Cx, data, len - 0xFF);
}
