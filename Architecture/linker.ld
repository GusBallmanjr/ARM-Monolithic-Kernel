/******************************************************************************
 * File: kernel.ld
 * Description: Linker script for the Monolithic ARM Kernel.
 *              Defines memory layout for text, data, bss, and stack.
 *
 * Sections:
 *   + .text.startup : Startup code
 *   + .text         : All other code sections
 *   + .data         : Initialized data
 *   + .bss          : Zero-initialized data
 *
 * Symbols:
 *   + _KERNEL_BASE_ : Base address of the kernel in memory
 *   + _STACK_END_   : End of kernel stack
 *   + ENTRY(_boot)  : Entry point for the kernel
 *
 * Authors: Gus Ballman
 * Date: 2/8/2026
 *****************************************************************************/


_KERNEL_BASE_ = 0x00100000;

SECTIONS
{
    . = _KERNEL_BASE_;

    .text.startup : {
        KEEP(*(.text.startup))
    }

    .text : {
        *(.text*)
    }

    .data : {
        *(.data*)
    }

    .bss : {
        *(.bss*)
    }

    _STACK_END_ = . + 0x10000;

    ENTRY(_boot);
}
