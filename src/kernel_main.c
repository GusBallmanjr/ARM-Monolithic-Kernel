/******************************************************************************
 * File: kernel_main.c
 * Description: Entry point for the Monolithic ARM Kernel.
 *              Initializes essential peripherals.
 *
 * Functions:
 *   + kernel_main(): Initializes the UART subsystem and enters
 *                    the main kernel loop.
 *
 * Notes:
 *   + This file is part of a collaborative project to build a 
 *     simple monolithic ARM kernel.
 *   + The main loop is currently empty and will be expanded
 *     as additional kernel services are implemented.
 *
 * Authors: Gus Ballman, Jamie Scott
 * Date: 2/8/2026
 *****************************************************************************/

#include "kernel_main.h"

void kernel_main(void)
{
    UART_Initial(); // Initialize UARTs
    while (1) // Main Kernel Loop
    {
      //TODO -> Build kernel loop
    }

}
