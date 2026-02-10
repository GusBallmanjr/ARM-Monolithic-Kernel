#include "uart.h"

void UART_Initial(void)
{
    // targeting UART 1
    volatile uint32_t* UART_CR = (volatile uint32_t*)(UART_BASE + CR_OFFSET); // set up register and cast the address to allow it to be more than a number
    volatile uint32_t* UART_MR = (volatile uint32_t*)(UART_BASE + MR_OFFSET);
    volatile uint32_t* UART_BAUDGEN = (volatile uint32_t*)(UART_BASE + BAUDGEN_OFFSET);
    volatile uint32_t* UART_BAUD_RATE_D = (volatile uint32_t*)(UART_BASE + BAUD_RATE_D_OFFSET);

    *UART_CR = 0b11; // Reset CR
    for(volatile int i = 0; i < 10000; ++i); // Delay for reset

    *UART_MR = 0x20;
    *UART_CR = 0b1010;
    *UART_BAUDGEN = 0x7C;
    *UART_BAUD_RATE_D = 7;
}

void UART_putc(char c)
{
    volatile uint32_t* UART_FIFO = (volatile uint32_t*)(UART_BASE + FIFO_OFFSET);

}
