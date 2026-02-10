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

void UART_Initial(void);
void UART_putc(char c);

#endif
