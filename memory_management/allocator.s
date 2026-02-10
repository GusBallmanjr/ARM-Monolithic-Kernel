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

bb_malloc:
  bx lr

bb_dealloc:
  bx lr

bb_calloc:
  bx lr

bb_realloc:
  bx lr

bb_mmap:
  bx lr

bb_munmap:
  bx lr
