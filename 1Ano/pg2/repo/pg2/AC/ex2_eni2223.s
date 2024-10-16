	.section .startup
	b		_start
	b 		.
_start:
	ldr		sp, stack_top_addr
	mov		r0, pc
	add		lr, r0, #4
	ldr		pc, main_addr
	b 		.	
stack_top_addr:
	.word stack_top
main_addr:
	.word	main

    .equ NELEM, 23
    .equ NREF, 10

    .text

count_char:
    push lr

    push r4 ; ref_value
    push r5 ; ref_ix
    push r6 ; sample_ix

    ldr r0, result_addr
    mov r1, #0
    str r1, [r0]

    mov r5, #NREF
count_char_loop:
    mov r0, #0
    cmp r5, r0 ; ref_ix != 0
    beq count_char_end

    sub r5, r5, #1
    
    ldr r0, ref_addr
    ldrb r4, [r0, r5] ; ref_value

    mov r6, #0
count_char_loop2:
    mov r0, #NELEM
    cmp r6, r0 ; sample_ix < NELEM
    bhs count_char_loop

    ldr r0, sample_addr
    ldrb r0, [r0, r6] ; sample[sample_ix]
    mov r1, r4

    bl compare

    ldr r1, result_addr
    ldr r2, [r1]
    add r2, r2, r0
    str r2, [r1]

    add r6, r6, #1
    
    b count_char_loop2
count_char_end:
    pop r6
    pop r5
    pop r4

    pop pc

compare:
    mov r2, #0

    cmp r0, r1
    bne compare_diff
    mov r2, #1
    b compare_end

compare_diff:
    mov r2, #0
compare_end:
    mov r0, r2
    mov pc, lr


result_addr:
    .word result
ref_addr:
    .word ref
sample_addr:
    .word sample 

    .data

sample:
    .asciz "aZqwertyuiopasdfghjklkll"
ref:
    .asciz "Azklqwerty"
result:
    .space 2

    .stack
    .space stack_size
stack_top:
