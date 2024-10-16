/* Secção de arranque: código de inicialização
 * 1. Estabelece vetores (entry point após reset e de interrupção)
 * 2. Inicia stack pointer
 * 3. Chama main
 * 4. Retém a execução do CPU após o retorno do main
*/
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
	
/* Constantes */
    .equ RED_SCALE, 2
    .equ AMBAR_SCALE, 1
    .equ GREEN_SCALE, 0
	.equ SCALES, 3
    .equ WARNING_TIME, 300
    .equ CRITICAL_TIME, 150

/* Secção com código aplicacional (programa) */
	.text

/*
int16_t main ( void ) {
    uint16_t i = 0;

    while ( i < 3 ) {
        color_histogram [ i ++] = 0;
    }
    test_color_scale ( times , color_histogram , 10 ) ;
    return 0;
}
*/
main:
	; salva LR se função não folha
	push	lr

	mov r0, #0 ; i = 0
	mov r1, #0 ; color_histogram [ i ++] = 0
	mov r2, #3 ; i < 3

while:
	cmp r0, r2 ; i < 3
	bge end_while
	lsl r3, r0, #1 ; r3 = i * 2
	ldr r4, color_histogram_addr ; load address of color_histogram into r4
	str r1, [r4, r3] ; color_histogram [ i ++] = 0
	add r0, r0, #1 ; i++
	b while

end_while:
	ldr r0, times_addr ; load address of times into r0
	ldr r1, color_histogram_addr ; load address of color_histogram into r1
	mov r2, #10 ; 10
	bl test_color_scale ; test_color_scale ( times , color_histogram , 10 ) ;

	mov r0, #0 ; return 0

	; retorna desempilhando endereço de retorno se função não folha
	pop		pc

/*
uint8_t color_scale ( uint16_t t ) {
    uint8_t c = GREEN_SCALE ;

    if ( t >= CRITICAL_TIME && t <= WARNING_TIME ) {
        c = AMBAR_SCALE ;
    } else if ( t < CRITICAL_TIME ) {
    c = RED_SCALE ;
    }
    return c ;
}
*/
color_scale:
	mov r1, #GREEN_SCALE ; c = GREEN_SCALE
	ldr r2, critical_time_addr ; load address of CRITICAL_TIME into r2
	cmp r0, r2 ; t >= CRITICAL_TIME
	bhs check_warning_time ; t >= CRITICAL_TIME
	blo scale_for_red ; t < CRITICAL_TIME
check_warning_time:
	ldr r2, warning_time_addr ; load address of WARNING_TIME into r2
	cmp r2, r0 ; t <= WARNING_TIME
	blo scale_for_end
scale_for_ambar:
	mov r2, #AMBAR_SCALE ; c = AMBAR_SCALE
	mov r1, r2 ; c = AMBAR_SCALE
	b scale_for_end
scale_for_red:
	mov r2, #RED_SCALE ; c = RED_SCALE
	mov r1, r2 ; c = RED_SCALE
	b scale_for_end

scale_for_end:
	mov pc, lr

/*
void test_color_scale ( uint16_t array_t [] , uint8_t array_c [] ,int16_t array_t_size ) {
    int16_t i ;

    for ( i = 0; i < array_t_size ; i ++ ) {
        array_c [color_scale (array_t [i])]++;
    }
}
*/

test_color_scale:
	push lr
	
	push r4 ; array_t
	push r5 ; array_c
	push r6 ; array_t_size
	push r7 ; i

	mov r7, #0 ; i = 0
	mov r4, r0 ; array_t
	mov r5, r1 ; array_c
	mov r6, r2 ; array_t_size

	b test_color_scale_for_ctrl
test_color_scale_for_body:
	ldr r0, [r4, r7] ; array_t [i]
	bl color_scale ; color_scale (array_t [i])
	ldrb r2, [r5, r1] ; array_c [color_scale (array_t [i])]
	add r2, r2, #1 ; array_c [color_scale (array_t [i])]++
	strb r2, [r5, r1] ; array_c [color_scale (array_t [i])]
test_color_scale_for_update:
	add r7, r7, #1 ; i++
test_color_scale_for_ctrl:
	cmp r7, r6 ; i < array_t_size
	bge test_color_scale_for_end
	b test_color_scale_for_body
test_color_scale_for_end:
	pop r7 ; i
	pop r6 ; array_t_size
	pop r5 ; array_c
	pop r4 ; array_t

	pop pc

warning_time_addr:
	.word WARNING_TIME
critical_time_addr:
	.word CRITICAL_TIME
color_histogram_addr:
	.word color_histogram
times_addr:
	.word times

/* Dados globais do programa iniciados */ 
	.data

/*
uint8_t color_histogram [3];
uint16_t times [] = { 65535 , 500 , 301 , 300 , 299 , 151 , 150 , 149 , 1 , 0 };
*/
color_histogram:
	.space SCALES * 2 ; criada variavel 'SCALES' para designar as 3 escalas:
	; RED, AMBAR e GREEN
times:
	.word 65535 , 500 , 301 , 300 , 299 , 151 , 150 , 149 , 1 , 0 

/* Stack: pilha com dados temporários */

	.equ STACK_SIZE, 64
	.section .stack
	.space STACK_SIZE
stack_top:
