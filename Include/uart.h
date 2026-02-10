/******************************************************************************
 * File: uart.h
 * Description: Header file for UART driver of the Monolithic ARM Kernel.
 *              Defines UART register addresses and declares initialization
 *              and output functions.
 *
 * Authors: Gus Ballman
 * Date: 2/9/2026
 *****************************************************************************/

#ifndef UART_H
#define UART_H

#include <stdint.h>

#define UART_BASE 0xE0001000 // UART1
#define CR_OFFSET 0x00000000
#define MR_OFFSET 0x00000004
#define IER_OFFSET 0x00000008
#define IDR_OFFSET 0x0000000C
#define IMR_OFFSET 0x00000010
#define ISR_OFFSET 0x00000014
#define BAUDGEN_OFFSET 0x00000018
#define rxtout_OFFSET 0x0000001C
#define RXWM_OFFSET 0x00000020
#define SR_OFFSET 0x0000002C
#define FIFO_OFFSET 0x00000030
#define BAUD_RATE_D_OFFSET 0x00000034
#define TX_TRIGGER_OFFSET 0x00000044
#define UART1_SR 0xE000102C	// UART1 Status Reg ister

#define UART_MODE 0x20        // 8 data bits, no parity, 1 stop bit
#define UART_ENABLE_RX_TX 0xC      // RE and TE (bits 2 and 3)
#define UART_BAUDGEN_100MHZ 0x7C // Master clock 100 MHz
#define UART_BAUD_DIV 6


typedef struct uarts
{
    volatile uint32_t* UART_CR;
    volatile uint32_t* UART_MR;
    volatile uint32_t* UART_BAUDGEN;
    volatile uint32_t* UART_BAUD_RATE_D;
    volatile uint32_t* UART_FIFO;
} Uarts;

void UART_Initial(void);
void UART_putc(char c);
void UART_puts(const char* s);
char UART_getc(void);

#endif
