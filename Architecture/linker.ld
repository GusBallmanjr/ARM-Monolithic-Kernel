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
