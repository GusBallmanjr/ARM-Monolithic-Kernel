
--Contributors--
Gus Ballman (gusballmanjr), and
Jamie Scott (mrthomaslibrary)

Important (to developers):
use arm-none-eabi-as, when as your non-Vitis assembler (ie in the terminal)

To Install:
sudo apt install gcc-arm-none-eabi

To Use:
arm-non-eabi-as <input> -o <output>

# ARM Monolithic Kernel -> IN PROGRESS (Expected April 2026)

This  project is a bare-metal monolithic kernel for ARM boards, specifically tested on the RealDigital BlackBoard (realdigital.org). 
The project includes the hardware initialization for the CPU and the UARTs, and running a simple kernel loop. 
The goal is to learn how a kernel and hardware interact and manage basic I/O without an OS underneath.

## Features

- Bare-metal ARM kernel running directly on the BlackBoard
- UART initialization with polling I/O
- Support for multiple UARTs
- Startup assembly (`startup.S`) and custom GNU linker script (`linker.ld`)


