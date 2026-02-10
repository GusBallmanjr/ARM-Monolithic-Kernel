/*
* MrThomasLibrary
*
* Initial setup for what will be the memory allocation program. Uses 32,768 blocks of 32 kilobytes each
*/

.text
.global main

//  [output, x, y] Finds indexed memory block (x) and offset (y)
index:
  LDR r3, =32768
  MUL r0, r1, r3
  ADD r0, r0, r2
  bx lr

//  [id]   Sets next empty block to the process (id)
allocate:
  MOV r0, #0
  MOV r2, #0
  
  loop:
  LDR r3, [r0, r2]
  CMP r3, #0
  beq empty
  ADD r2, r2, #3
  b loop
  CMP r2, #32768
  blt finish

  empty:
  STR r1, [r3]
  bx lr

  finish:
  bx lr

main:

.end
