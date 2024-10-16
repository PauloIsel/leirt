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

;Simbolos
    .equ ARRAY_SIZE, 7
    .equ MARK, 645

    .text

main:

count_bigger: ; r0 = reference
    push lr

    push r4
    push r5

    mov r4, r0 ;reference
    mov r5, #0 ;index

    ldr r0, counter_addr
    mov r1, #0
    strb r1, [r0] ;counter = 0

count_loop: 
    mov r0, #ARRAY_SIZE
    cmp r5, r0 ;index < ARRAY_SIZE
    bhs count_end

    mov r0, r4 ;reference
    ldr r1, array_addr
    ldr r1, [r1, r5] ;array[index]
    
    bl  compare

    mov r1, #0
    cmp r1, r0 ;0 < tmp
    bge count_loop_end
    ldr r0, counter_addr
    ldrb r1, [r0]
    add r1, r1, #1
    strb r1, [r0] ;counter++
count_loop_end:
    add r5, r5, #1
    b count_loop
count_end:
    pop r5
    pop r4

    pop pc  

compare: ; r0 = reference, r1 = value
    mov r2, #0 ;result = 0

    cmp r0, r1 ;reference < value
    bhs compare_end
    
    mov r2, #MARK & 0xFF
    movt r2, #(MARK >> 8) & 0xFF
    mvn r2, r2 ;result = -MARK
    b compare_end
    
    cmp r1, r0 ;value > reference
    blo compare_end
    mov r2, #MARK & 0xFF
    movt r2, #(MARK >> 8) & 0xFF

compare_end:
    mov r0, r2
    mov pc, lr


counter_addr:
    .word counter

MARK_addr:
    .word MARK

array_addr:
    .word array

    .data 

counter:
    .space 1

    .align
array:
    .word 125, 10, 205, 34, 220, 150, 170

	.equ STACK_SIZE, 64
	.section .stack
	.space STACK_SIZE
stack_top:
