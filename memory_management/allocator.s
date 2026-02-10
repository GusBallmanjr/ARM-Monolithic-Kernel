@ MrThomasLibrary
@ 02.10.2026
@ Allocation program for the BlackBoard Kernel
@ List of functions

.section .data
.align 4
memory_pool: .skip 32768
free_list: .word memory_pool

.text
.global _start

@ [~, x, y] -> [location]
index:
  mov r3, #32768
  mul r0, r3, r1
  add r0, r0, r2
  bx lr

@ [id] -> [location]
@ Allocates the closest free block from 0 to the process @ id
bb_malloc:
  push {r4, lr}
  ldr r4, =memory_pool
  mov r2, #0

  bbm_loop:
    ldr r1, [r4, r2]
    cmp r1, #0
    beq bbm_allocate
    add r2, r2, #4
    cmp r2, #32768
    blt bbm_loop
    b bbm_finish

  bbm_allocate:
    str r0, [r4, r2]
    add r0, r4, r2

  bbm_finish:
    pop {r4, pc}

@ [id]
@ Deallocates the furthest block from 0 of the id
@ Deallocate means to set the process assigned to the block to 0
bb_dealloc:
  push {r4, lr}
  ldr r4, =memory_pool
  mov r2, #32764

  bbd_loop:
    ldr r1, [r4, r2]
    cmp r1, r0
    beq bbd_deallocate

    subs r2, r2, #4
    bge bbd_loop
    b bbd_finish

  bbd_deallocate:
    mov r1, #0
    str r1, [r4, r2]

  bbd_finish:
    pop {r4, pc}

@ [location]
bb_calloc:
  push {r4, r5, lr}
  bl index
  ldr r4, =memory_pool
  add r4, r4, r0

  mov r3, #0
  mov r5, #0

  bbc_loop:
    str r3, [r4, r5]
    add r5, r5, #4
    cmp r5, #32768
    blt bbc_loop
  
    pop {r4, r5, pc}

@ [size] -> [failed]
bb_realloc:
  mov r1, #32768
  cmp r0, r1
  bhi bbr_failed

  mov r0, #0
  bx lr

  bbr_failed:
    mov r0, #1
    bx lr
