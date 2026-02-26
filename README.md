## ARM Monolithic Kernel -> _IN PROGRESS_

This  project is a bare-metal monolithic kernel for ARM boards, specifically tested on the [RealDigital BlackBoard](https://realdigital.org/hardware/blackboard). 
The project includes the hardware initialization for the CPU and the UARTs, and running a simple kernel loop. 
The goal is to learn how a kernel and hardware interact and manage basic I/O without an OS underneath.

---

# Contributors
Gus Ballman (gusballmanjr), and
Jamie Scott (mrthomaslibrary)

---

# Important (to developers):
use arm-none-eabi-as, when as your non-Vitis assembler (i.e. in the terminal)

**To Install:**
sudo apt install gcc-arm-none-eabi

**To Use:**
arm-non-eabi-as <input> -o <output>

---

# Features

+ Bare-metal ARM kernel running directly on the BlackBoard
+ UART initialization with polling I/O
+ Support for multiple UARTs
+ Startup assembly (`startup.S`) and custom GNU linker script (`linker.ld`)
