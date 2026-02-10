/******************************************************************************
 * File: uart.c
 * Description: UART driver for the Monolithic ARM Kernel.
 *              Provides basic UART initialization and simple character I/O.
 *
 * Functions:
 *   + UART_Initial(): Initializes UART1 with a specific baud rate, mode,
 *                     and control settings. Performs a reset of
 *                     transmitter and receiver, then enables TX/RX.
 *                     Includes a fixed delay to allow hardware reset to complete.
 *
 *   + UART_putc(char c): Sends a single character over UART1.
 *
 *   + UART_puts(const char* s): Sends a null-terminated string over UART1.
 *                               Calls UART_putc() for each character.
 *
 *   + UART_getc(void): Receives a single character from UART1.
 *                     Masks the 32-bit FIFO read with 0xFF to extract
 *                     only the valid 8-bit data from the least significant byte.
 *
 * Notes:
 *   + This driver is designed specifically for UART1; register addresses are
 *     calculated as UART_BASE + offset for each register.
 *
 *   + All registers are accessed via volatile pointers to ensure that the
 *     compiler does not optimize away hardware reads/writes.
 *
 *   + UART FIFO is 32 bits wide, but UART data is 8 bits. Reading from the
 *     FIFO requires masking with 0xFF to get the actual received byte.
 *
 *   + Current implementation of UART_putc() and UART_puts() does not poll.
 *     We should consider adding.
 *
 * Authors: Jamie Scott, Gus Ballman
 * Date: 2/10/2026
 *****************************************************************************/


#include "uart.h"

void UART_Initial(void)
{
    // targeting UART 1
    Uarts uart_reg;
    uart_reg.UART_CR = (volatile uint32_t*)(UART_BASE + CR_OFFSET);
    uart_reg.UART_MR = (volatile uint32_t*)(UART_BASE + MR_OFFSET);
    uart_reg.UART_BAUDGEN = (volatile uint32_t*)(UART_BASE + BAUDGEN_OFFSET);
    uart_reg.UART_BAUD_RATE_D = (volatile uint32_t*)(UART_BASE + BAUD_RATE_D_OFFSET);

    *(uart_reg.UART_CR) = 0b1100; // Reset CR
    for (volatile int i = 0; i < 10000; ++i); // Delay for reset

    *(uart_reg.UART_MR) = UART_MODE;
    *(uart_reg.UART_CR) |= UART_ENABLE_RX_TX;
    *(uart_reg.UART_BAUDGEN) = UART_BAUDGEN_100MHZ; // Master Clock is 100 MHz
    *(uart_reg.UART_BAUD_RATE_D) = UART_BAUD_DIV;
}

void UART_putc(const char c)
{
    Uarts uart_reg;
    uart_reg.UART_FIFO = (volatile uint32_t*)(UART_BASE + FIFO_OFFSET);

    *(uart_reg.UART_FIFO) = c;
}

void UART_puts(const char* s)
{
    Uarts uart_reg;
    int index = 0;
    uart_reg.UART_FIFO = (volatile uint32_t*)(UART_BASE + FIFO_OFFSET);

    while (s[index - 1] != '\0')
    {
        UART_putc(s[index]);
        ++index;
    }
}

char UART_getc(void)
{
    Uarts uart_reg;
    uart_reg.UART_FIFO = (volatile uint32_t*)(UART_BASE + FIFO_OFFSET);

    return (char)(*(uart_reg.UART_FIFO) & 0xFF);
}
