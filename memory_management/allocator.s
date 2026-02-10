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

@ [~, x, y] -> [location]
index:
  mov r3, #32768
  mul r0, r3, r1
  add r0, r0, r2
  bx lr

bb_brk:
  bx lr

bb_sbrk:
  bx lr

@ [id] -> [location]
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
    mov r2, #0
    bl index
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

@ [location]
bb_calloc:
  mov r2, #0
  bl index
  add r2, r0, #32768
  bbc_loop:
    mov r3, #0
    str r3, [r0]
    add r0, r0, #1
    cmp r0, r2
    blt bbc_loop
  bx lr

bb_realloc:
  bx lr

bb_mmap:
  bx lr

bb_munmap:
  bx lr
