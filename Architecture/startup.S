.section .text.startup, "ax"
.global _boot

.extern _KERNEL_BASE_
.extern _STACK_TOP_
.extern _bss_start_
.extern _bss_end_

_boot:
    ldr sp,= _STACK_TOP_
    ldr r0, =_bss_start_
    ldr r1, =_bss_end_
    b _bss_clear

_bss_clear:
    cmp r0, r1
    bhs kernel_main
    str r2, [r0], #4
    b _bss_clear

.end
