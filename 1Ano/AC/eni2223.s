.equ stack_size, 32

.equ INPORT_ADDRESS, 0x6001
.equ OUTPORT_ADDRESS, 0x4000

    .section startup

    .text

main:
    ldr r0, INPORT_ADDRESS
    ldr r1, OUTPORT_ADDRESS
loop:
    ldrb r2, [r0]
    strb r2, [r1, #1]
    mvn r2, r2
    strb r2, [r1]

    b loop

import_addr:
    .word INPORT_ADDRESS
outport_addr:
    .word OUTPORT_ADDRESS

    .stack
    .space stack_size
stack_top:
