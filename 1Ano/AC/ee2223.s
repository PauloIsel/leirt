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
    .equ MAX_LEN, 500

    .text

main:
    push lr 

    mov r0, #14
    ldr r1, strg_addr
    bl count_vowels

    pop pc

strg_addr:
    .word strg
vowels_addr:
    .word vowels

count_vowels: ; r0 = len, r1 = str
    push lr
    mov r7, #0 ;i = 0
    mov r4, r0 ;len
    mov r5, r1 ;str

    mov r0, #MAX_LEN_addr
    ldr r0, [r0]
    cmp r0, r4 ;MAX_LEN < len
    blo vowels_if
    mov r6, #0 ;vowels = 0
    b vowels_loop

vowels_if:
    mov r4, r0 ;len = MAX_LEN

vowels_loop:
    cmp r7, r4 ;i < len
    bhs vowels_end
    ldrb r0, [r5, r7] ;r3 = str[i]
    mov r1, #0
    cmp r0, r1 ;str[i] != 0
    beq vowels_end

    bl is_vowel
    mov r1, #0
    cmp r1, r0 ;0 < tmp
    bge vowels_inc
    add r6, r6, #1
vowels_inc: 
    add r7, r7, #1
    b vowels_loop

vowels_end:
    mov r0, r7
    pop pc

tmp_addr:
    .word tmp

is_vowel:
; r3 = -1
    mov r1, #0
    mvn r1, r1

    mov r2, #97
    cmp r0, r2
    beq set1

    mov r2, #101
    cmp r0, r2
    beq set2

    mov r2, #105
    cmp r0, r2
    beq set3

    mov r2, #111
    cmp r0, r2
    beq set4

    mov r2, #117
    cmp r0, r2
    beq set5

    b is_vowel_end
set1:
    mov r1, #1
    b is_vowel_end
set2:
    mov r1, #2
    b is_vowel_end
set3:
    mov r1, #3
    b is_vowel_end
set4:
    mov r1, #4
    b is_vowel_end
set5:
    mov r1, #5
    b is_vowel_end
is_vowel_end:
    mov r0, r1
    mov pc, lr



MAX_LEN_addr:
    .word MAX_LEN

;Variaveis globais
    .data

strg:
    .asciz "Hello World!"
    .align

vowels: 
    .space 2

tmp:
    .space 1

    .align

	.equ STACK_SIZE, 64
	.section .stack
	.space STACK_SIZE
stack_top:
