@ MrThomasLibrary
@ 02.10.2026
@ Allocation program for the BlackBoard Kernel
@ List of functions

.section .data
.align 3

free_list: .quad 0

.text
.global bb_brk
.global bb_sbrk
.global bb_malloc
.global bb_dealloc
.global bb_calloc
.global bb_realloc
.global bb_mmap
.global bb_munmap

bb_brk:
  bx lr

bb_sbrk:
  bx lr

@ [id]
@ Allocates the closest free block from 0 to the process @ id
bb_malloc:
  mov r2, #0
  bbm_loop:
    ldr r1, [r2]
    cmp r1, #0
    beq bbm_allocate
    add r2, r2, #1
    cmp r2, #32768
    blt bbm_loop
    b bbm_finish
  bbm_allocate:
    str r0, [r1]
  bbm_finish:
    bx lr

@ [id]
@ Deallocates the furthest block from 0 of the id
@ Deallocate means to set the process assigned to the block to 0
bb_dealloc:
  mov r2, #32768
  bbd_loop:
    ldr r1, [r2]
    cmp r0, r2
    beq bbd_deallocate
    sub r2, r2, #1
    cmp r2, #0
    bgt bd_loop
    b bbd_finish
  bbd_deallocate:
    mov r1, #0
    str r1, [r2]
  bbd_finish:
    bx lr

bb_calloc:
  bx lr

bb_realloc:
  bx lr

bb_mmap:
  bx lr

bb_munmap:
  bx lr
