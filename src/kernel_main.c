/*
  Programmer: Gus Ballman
  Date: 2/9/2026
*/

#include "kernel_main.h"

void kernel_main(void)
{
    UART_Initial();
    while (1)
    {

    }

}

void UART_Initial(void)
{
    volatile uint32_t* UART_CR = (volatile uint32_t*)(UART_BASE + CR_OFFSET); // set up register and cast the address to allow it to be more than a number
    volatile uint32_t* UART_MR = (volatile uint32_t*)(UART_BASE + MR_OFFSET);
    volatile uint32_t* UART_BAUDGEN = (volatile uint32_t*)(UART_BASE + BAUDGEN_OFFSET);
    volatile uint32_t* UART_BAUD_RATE_D = (volatile uint32_t*)(UART_BASE + BAUD_RATE_D_OFFSET);

    *UART_CR = 0b11; // Reset CR
    while (*UART_CR == 0b11);

    *UART_MR = 0x20;
    *UART_CR = 0b1010;
    *UART_BAUDGEN = 0x7C;
    *UART_BAUD_RATE_D = 6;
}
