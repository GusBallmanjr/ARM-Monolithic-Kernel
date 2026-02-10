.section .text.startup, "ax"
.global _boot

.extern _KERNEL_BASE_
.extern _STACK_TOP_
.extern _bss_start_
.extern _bss_end_

_boot:
    ldr sp, =_STACK_TOP_
    ldr r0, =_bss_start_
    ldr r1, =_bss_end_
    mov r2, #0
    b _bss_clear

_bss_clear:
    cmp r0, r1
    bhs kernel_main
    str r2, [r0], #4 @ Post indexing allows for one word to be cleared at a time
    b _bss_clear

.end
