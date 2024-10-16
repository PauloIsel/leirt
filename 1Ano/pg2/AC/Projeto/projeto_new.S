; Ficheiro:  projeto.S
; Descricao: Programa para realizacao do projeto de
;            Arquitetura de Computadores.
; Autores:   Daniel Santos e Paulo Magalhaes  
; Data:      05-06-2024

; Definicao dos valores dos simbolos utilizados no programa
;
	.equ	CPSR_BIT_I, 0b010000          ; Mascara para o bit I do registo CPSR

	.equ	STACK_SIZE, 64                ; Dimensao do stack - 64 B

    ; Definicoes do porto de entrada
	.equ	INPORT_ADDRESS, 0xFF80        ; Endereco do porto de entrada

	; Definicoes do porto de saida
	.equ	OUTPORT_ADDRESS, 0xFFC0       ; Endereco do porto de saida

	.equ	OUTPORT_INIT_VAL, 0           ; Valor inicial do porto de saida

	; Definicoes do circuito pTC
	.equ	PTC_ADDRESS,  0xFF40          ; Endereco do circuito pTC

	.equ	PTC_TCR, 0                    ; Deslocamento do registo TCR do pTC
	.equ	PTC_TMR, 2                    ; Deslocamento do registo TMR do pTC
	.equ	PTC_TC,  4                    ; Deslocamento do registo TC do pTC
	.equ	PTC_TIR, 6                    ; Deslocamento do registo TIR do pTC

	.equ	PTC_CMD_START, 0              ; Comando para iniciar a contagem no pTC
	.equ	PTC_CMD_STOP, 1               ; Comando para parar a contagem no pTC

    ; Outras definicoes
    .equ    PEDESTRIAN_BUTTON_MASK, 0x01    ; Mascara para o bit 0
    .equ    CONFIG_MASK, 0x10               ; Mascara para o bit 4
    .equ    TIME_MASK, (0x07 << 5)          ; Mascara para os bits 7, 6 e 5

    .equ    LED_MASK, 0x03                   ; Mascara para os bits 0 e 1

    .equ    SYSCLK_INIT_VAL, 0             ; Valor inicial do sistema de contagem
    .equ    SYSCLK_FREQ, 0x09              ; Intervalo de contagem do circuito pTC
                                            ; que suporta a implementação do sysclk
                                            ; 0x09 -> 100Hz , 0x63 -> 1000Hz

	.equ	BLINK_TIME, 5
	.equ    CROSSING_TIME_INIT_VAL, 0       ; Tempo de travessia predefinido
    .equ    MAX_CROSSING_TIME_NUM, 5 - 1       ; Numero maximo de tempos de travessia

	; Estados do sistema
	.equ	OPERATION_LED_ON, 0
	.equ	OPERATION_LED_OFF, 1

	.equ 	CONFIG_LED_ON, 2
	.equ 	CONFIG_LED_OFF, 3

	.equ	PEDESTRIAN_MODE, 4

; Seccao:    startup
; Descricao: Guarda o código de arranque do sistema
;
	.section startup
	b	_start
	ldr	pc, isr_addr
_start:
	ldr	sp, stack_top_addr
    mov r0, pc
    add lr, r0, #4
	ldr	pc, main_addr
    b   .

stack_top_addr:
	.word	stack_top
main_addr:
	.word	main
isr_addr:
	.word	isr

; Seccao:    text
; Descricao: Guarda o código do programa
;
	.text

; Rotina:    main
; Descricao: Rotina principal do programa
main:
    mov	r0, #OUTPORT_INIT_VAL
    bl	outport_init

    mov	r0, #SYSCLK_FREQ
	bl	sysclk_init

	bl crossing_time_init

    mrs	r0, cpsr
    mov	r1, #CPSR_BIT_I
    orr	r0, r0, r1
    msr	cpsr, r0
operation_mode_entry:
	ldr r1, prev_button_state_addr
	mov r0, #1
	strb r0, [r1]

	; Ligar o LED L3 com luz verde
	mov	r0, #2
	mov	r1, #2
	bl	led_control

	; Ligar o LED L2 com luz vermelha
	mov	r0, #1
	mov	r1, #1
	bl	led_control
operation_led_on_entry:
	; Ligar o LED L1 com luz amarela
	mov	r0, #0
	mov	r1, #3
	bl	led_control

	mov r0, #OPERATION_LED_ON
	bl set_current_state

	bl delay_start
operation_led_on:
	bl delay_check
	mov r1, #BLINK_TIME
	cmp r0, r1
	blo operation_mode
operation_led_off_entry:
	; Desligar o LED L1
	mov	r0, #0
	mov	r1, #0
	bl	led_control

	mov r0, #OPERATION_LED_OFF
	bl set_current_state

	bl delay_start
operation_led_off:
	bl delay_check
	mov r1, #BLINK_TIME
	cmp r0, r1
	blo operation_mode

	b operation_led_on_entry
operation_mode:
	; Saltar para a config
	bl inport_read
    mov r1, #CONFIG_MASK
    and r0, r0, r1
    cmp r0, r1
    beq config_mode_entry

	; Click no botão
	bl inport_read
	mov r1, #PEDESTRIAN_BUTTON_MASK
	and r0, r0, r1
	
	ldr r1, prev_button_state_addr
	ldrb r2, [r1]
	strb r0, [r1]
	
	cmp r2, r0
	blo pedestrian_button_clicks_entry

	bl get_current_state
	mov r1, #PEDESTRIAN_MODE
	cmp r0, r1
	beq pedestrian_button_clicks_loop
	;

	bl get_current_state

	mov r1, #OPERATION_LED_ON
	cmp r0, r1
	beq operation_led_on

	mov r1, #OPERATION_LED_OFF
	cmp r0, r1
	beq operation_led_off

	b operation_mode_entry

prev_button_state_addr:
	.word prev_button_state

pedestrian_button_clicks_entry:
	bl get_current_state
	mov r1, #PEDESTRIAN_MODE
	cmp r0, r1
	beq pedestrian_button_clicks

	; Ligar o LED L1 com luz vermelha
	mov	r0, #0
	mov	r1, #1
	bl	led_control

	; Ligar o LED L2 com luz verde
	mov	r0, #1
	mov	r1, #2
	bl	led_control

	mov r0, #PEDESTRIAN_MODE
	bl set_current_state
pedestrian_button_clicks:
	bl delay_start
pedestrian_button_clicks_loop:
	bl delay_check
	mov r1, r0
	bl crossing_time_get
	cmp r1, r0
	bhs operation_mode_entry

	b operation_mode

; Configuração

config_mode_entry:
	; Ligar o LED L3 com luz amarela
	mov	r0, #2
	mov	r1, #3
	bl	led_control
config_led_on_entry:
	; Ligar o LED L1 com luz amarela
	mov	r0, #0
	mov	r1, #3
	bl	led_control
	
	; Ligar o LED L2 com luz verde
	mov	r0, #1
	mov	r1, #2
	bl	led_control

	mov r0, #CONFIG_LED_ON
	bl set_current_state

	bl delay_start
config_led_on:
	bl delay_check
	mov r1, #BLINK_TIME
	cmp r0, r1
	blo config_mode
config_led_off_entry:
	; Desligar o LED L1
	mov	r0, #0
	mov	r1, #0
	bl	led_control

	; Desligar o LED L2
	mov	r0, #1
	mov	r1, #0
	bl	led_control

	mov r0, #CONFIG_LED_OFF
	bl set_current_state

	bl delay_start
config_led_off:
	bl delay_check
	mov r1, #BLINK_TIME
	cmp r0, r1
	blo config_mode

	b config_led_on_entry
config_mode:
	; Saltar para a operação
	bl inport_read
    mov r1, #CONFIG_MASK
    and r0, r0, r1
    cmp r0, r1
    bne config_mode_exit

	bl get_current_state

	mov r1, #CONFIG_LED_ON
	cmp r0, r1
	beq config_led_on

	mov r1, #CONFIG_LED_OFF
	cmp r0, r1
	beq config_led_off

	b config_mode_entry
config_mode_exit:
	bl inport_read
    mov r1, #TIME_MASK
    and r0, r0, r1
    lsr r0, r0, #5
    bl crossing_time_set

	b operation_mode_entry

; Gestor do estado atual
;

; Rotina:    get_current_state
; Descricao: Devolve o valor corrente do estado do sistema
; Entradas:  -
; Saidas:    R0 - Valor corrente do estado do sistema
; Efeitos:   -
get_current_state:
	ldr r1, current_state_addr
	ldrb r0, [r1]
	mov pc, lr

; Rotina:    set_current_state
; Descricao: Atribui o valor recebido em R0 ao estado do sistema
; Entradas:  R0 - Novo valor do estado do sistema
; Saidas:    -
; Efeitos:   -
set_current_state:
	ldr r1, current_state_addr
	strb r0, [r1]
	mov pc, lr

current_state_addr:
	.word current_state

; Rotina:   led_control
; Descricao: Controla o LED especificado com base no valor fornecido
; Entradas:  r0 - Número do LED a controlar entre 0 e 2
;            r1 - Modo (0, 1, 2, 3) 0 - Desligar LEDs; 1 - Ligar LED vermelho; 2 - Ligar LED verde; 3 - Ligar ambos os LEDs
; Saidas:    -
; Efeitos:   Controla o LED especificado
led_control:
    push lr
    push r4 ; mask
    push r5 ; temp

    mov r4, #LED_MASK

    mov r5, #0
    cmp r0, r5
    beq end_led_control

    mov r5, #1
    cmp r0, r5
    beq led_control_l2

    mov r5, #2
    cmp r0, r5
    beq led_control_l3

    b end_led_control
led_control_l2:
    lsl r4, r4, #2
    lsl r1, r1, #2
    
    b end_led_control
led_control_l3:
    lsl r4, r4, #4
    lsl r1, r1, #4
end_led_control:
    mov r0, r4
    bl outport_write_bits

    pop r5
    pop r4
    pop pc

; Rotina:    crossing_time_init
; Descricao: Inicializa o tempo de travessia
; Entradas:  -
; Saidas:    -
; Efeitos:   -
crossing_time_init:
    push lr

    ldr r1, cur_crossing_time_addr
    mov r0, #CROSSING_TIME_INIT_VAL
    str r0, [r1, #0]

    pop pc

; Rotina:    crossing_time_get
; Descricao: Devolve o tempo de travessia
; Entradas:  -
; Saidas:    r0 - Tempo de travessia
; Efeitos:   -
crossing_time_get:
    push lr
	push r4

    ldr r4, cur_crossing_time_addr
    ldr r0, [r4, #0]
	lsl r0, r0, #1

	ldr r4, crossing_times_addr
	ldr r0, [r4, r0]

	pop r4
    pop pc

; Rotina:    crossing_time_set
; Descricao: Define o tempo de travessia e caso o tempo seja maior que o tempo máximo, o tempo é definido para o tempo máximo
; Entradas:  r0 - Tempo de travessia
; Saidas:    -
; Efeitos:   -
crossing_time_set:
    push lr

    ldr r1, cur_crossing_time_addr
    mov r2, #MAX_CROSSING_TIME_NUM
    cmp r0, r2
    blo set_crossing_time

    mov r0, r2
set_crossing_time:
    str r0, [r1, #0]

    pop pc

cur_crossing_time_addr:
	.word cur_crossing_time

crossing_times_addr:
    .word crossing_times

; Rotina:    isr
; Descricao: Incrementa o valor da variável global sysclk.
; Entradas:  -
; Saidas:    -
; Efeitos:   Incrementa o valor da variável global sysclk
isr: 
	push lr
	push r0
	push r1
	push r2
	push r3

	ldr r1, sysclk_addr
	ldr r0, [r1]
	
	add r0, r0, #1
	str r0, [r1]

	bl ptc_clr_irq

	pop r3
	pop r2
	pop r1
	pop r0
	pop lr
    movs pc, lr


; Rotina:    delay_start
; Descricao: Inicia um atraso.
;            Interface exemplo: void delay_start(  );
; Entradas:  -
; Saidas:    -
; Efeitos:   -
delay_start:
    push	lr
    
    bl sysclk_get_ticks
    ldr		r1, cur_delay_addr
    str r0, [r1, #0]

    pop		pc

; Rotina:    delay_check
; Descricao: Rotina não bloqueante que verifica o tempo que passou usando o valor do cur_sysclk.
;            Interface exemplo: void delay_check();
; Entradas:  R0 - Tempo a esperar, em centenas de milissegundos.
; Saidas:    -
; Efeitos:   -
delay_check:
	push	lr
    push	r4		; time_start

	bl		sysclk_get_ticks

    ldr		r4, cur_delay_addr
    ldr     r4, [r4, #0]
	sub 	r0, r0, r4

	pop		r4
	pop		pc

cur_delay_addr:
    .word	cur_delay

; Rotina:    sysclk_init
; Descricao: Inicia uma nova contagem no periferico pTC com o intervalo de
;            contagem recebido em R0, em ticks, limpando eventuais pedidos de
;            interrupcao pendentes e iniciando com o valor zero a variavel
;            global sysclk.
;            Interface exemplo: void sysclk_init( uint8_t interval );
; Entradas:  R0 - Valor do novo intervalo de contagem, em ticks.
; Saidas:    -
; Efeitos:   Inicia a contagem no periferico a partir do valor zero, limpando
;            eventuais pedidos de interrupcao pendentes e iniciando com o
;            valor zero a variavel global sysclk
sysclk_init:
	push lr

	bl ptc_init

	ldr	r1, sysclk_addr
	mov	r0, #SYSCLK_INIT_VAL
	str r0, [r1]

	pop pc

; Rotina:    sysclk_get_ticks
; Descricao: Devolve o valor corrente da variável global sysclk.
;            Interface exemplo: uint16_t sysclk_get_ticks ( );
; Entradas:  -
; Saidas:    R0 - Valor corrente da variável global sysclk
; Efeitos:   Devolve o valor atual da variável global sysclk
sysclk_get_ticks:
	ldr r1, sysclk_addr
	ldr r0, [r1]

	mov pc, lr

sysclk_addr:
	.word	sysclk

; Gestor de periférico para o porto de entrada
;

; Rotina:    inport_read
; Descricao: Adquire e devolve o valor corrente do porto de entrada.
;            Interface exemplo: uint8_t inport_read( );
; Entradas:  -
; Saidas:    R0 - valor adquirido do porto de entrada
; Efeitos:   -
inport_read:
	ldr	r1, inport_addr
	ldrb	r0, [r1, #0]
	mov	pc, lr

inport_addr:
	.word	INPORT_ADDRESS

; Gestor de periférico para o porto de saída
;

; Rotina:    outport_set_bits
; Descricao: Atribui o valor logico 1 aos bits do porto de saida identificados
;            com o valor 1 em R0. O valor dos outros bits nao e alterado.
;            Interface exemplo: void outport_set_bits( uint8_t pins_mask );
; Entradas:  R0 - Mascara com a especificacao do indice dos bits a alterar.
; Saidas:    -
; Efeitos:   Altera o valor da variavel global outport_img.
outport_set_bits:
	push	lr
	ldr	r1, outport_img_addr
	ldrb	r2, [r1, #0]
	orr	r0, r2, r0
	strb	r0, [r1, #0]
	bl	outport_write
	pop	pc

; Rotina:    outport_clear_bits
; Descricao: Atribui o valor logico 0 aos bits do porto de saida identificados
;            com o valor 1 em R0. O valor dos outros bits nao e alterado.
;            Interface exemplo: void outport_clear_bits( uint8_t pins_mask );
; Entradas:  R0 - Mascara com a especificacao do indice dos bits a alterar.
; Saidas:    -
; Efeitos:   Altera o valor da variavel global outport_img.
outport_clear_bits:
	push	lr
	ldr	r1, outport_img_addr
	ldrb	r2, [r1, #0]
	mvn	r0, r0
	and	r0, r2, r0
	strb	r0, [r1]
	bl	outport_write
	pop	pc

; Rotina:    outport_init
; Descricao: Faz a iniciacao do porto de saida, nele estabelecendo o valor
;            recebido em R0.
;            Interface exemplo: void outport_init( uint8_t value );
; Entradas:  R0 - Valor a atribuir ao porto de saida.
; Saidas:    -
; Efeitos:   Altera o valor da variavel global outport_img.
outport_init:
	push	lr
	ldr	r1, outport_img_addr
	strb	r0, [r1]
	bl	outport_write
	pop	pc

; Rotina:    outport_write_bits
; Descricao: Atribui aos bits do porto de saída o valor dos bits
;            correspondentes do argumento do segundo parametro, no caso dos
;            bits correspondentes do argumento do primeiro parametro
;            apresentarem o valor um. O valor dos restantes bits do porto de
;            saida mantem-se inalterado.
;            Interface exemplo:
;                void outport_write_bits( uint8_t pins_mask, uint8_t value );
; Entradas:  R0 - Mascara com a especificacao do indice dos bits a alterar.
;            R1 - Valor a atribuir aos bits do porto de saida.
; Saidas:    -
; Efeitos:   Atualiza o valor da variavel global outport_img
outport_write_bits: 
	push	lr
	ldr	r2, outport_img_addr
	ldr	r3, [r2, #0] 
	and	r1, r0, r1 
	mvn	r0, r0
	and	r0, r3, r0 
	orr	r0, r0, r1 
	strb	r0, [r2, #0]
	bl	outport_write
	pop	pc

outport_img_addr:
	.word	outport_img

; Rotina:    outport_write
; Descricao: Escreve no porto de saida o valor recebido em R0.
;            Interface exemplo: void outport_write( uint8_t value );
; Entradas:  R0 - valor a atribuir ao porto de saida.
; Saidas:    -
; Efeitos:   -
outport_write:
	ldr	r1, outport_addr
	strb	r0, [r1, #0]
	mov	pc, lr

outport_addr:
	.word	OUTPORT_ADDRESS

; Gestor de periférico para o Pico Timer/Counter (pTC)
;

; Rotina:    ptc_init
; Descricao: Faz a iniciacao do periférico pTC, habilitando o seu funcionamento
;            em modo continuo e com o intervalo de contagem recebido em R0, em
;            ticks.
;            Interface exemplo: void ptc_init( uint8_t interval );
; Entradas:  R0 - Valor do novo intervalo de contagem, em ticks.
; Saidas:    -
; Efeitos:   Inicia a contagem no periferico a partir do valor zero, limpando
;            o pedido de interrupcao eventualmente pendente.
ptc_init:
    push    lr
	ldr	r1, PTC_ADDR
	mov	r2, #PTC_CMD_STOP
	strb	r2, [r1, #PTC_TCR]
	strb	r0, [r1, #PTC_TMR]
    bl  ptc_clr_irq
	mov	r2, #PTC_CMD_START
	strb	r2, [r1, #PTC_TCR]
	pop pc

; Rotina:    ptc_start
; Descricao: Habilita a contagem no periferico pTC.
;            Interface exemplo: void ptc_start( );
; Entradas:  -
; Saidas:    -
; Efeitos:   -
ptc_start:
	ldr	r0, PTC_ADDR
	mov	r1, #PTC_CMD_START
	strb	r1, [r0, #PTC_TCR]
	mov	pc, lr

; Rotina:    ptc_stop
; Descricao: Para a contagem no periferico pTC.
;            Interface exemplo: void ptc_stop( );
; Entradas:  -
; Saidas:    -
; Efeitos:   O valor do registo TC do periferico e colocado a zero.
ptc_stop:
	ldr	r0, PTC_ADDR
	mov	r1, #PTC_CMD_STOP
	strb	r1, [r0, #PTC_TCR]
	mov	pc, lr

; Rotina:    ptc_get_value
; Descricao: Devolve o valor corrente da contagem do periferico pTC.
;            Interface exemplo: uint8_t ptc_get_value( );
; Entradas:  -
; Saidas:    R0 - O valor corrente do registo TC do periferico.
; Efeitos:   -
ptc_get_value:
	ldr	r1, PTC_ADDR
	ldrb	r0, [r1, #PTC_TC]
	mov	pc, lr

; Rotina:    ptc_clr_irq
; Descricao: Sinaliza o periferico pTC que foi atendido um pedido de
;            interrupção.
;            Interface exemplo: void ptc_clr_irq( );
; Entradas:  -
; Saidas:    -
; Efeitos:   -
ptc_clr_irq:
	ldr	r0, PTC_ADDR
	strb	r1, [r0, #PTC_TIR]
	mov	pc, lr

PTC_ADDR:
	.word	PTC_ADDRESS

; Seccao:    data
; Descricao: Guarda as variáveis globais
;
	.data
outport_img:
	.space	1

	.align
current_state:
	.space	1

	.align
prev_button_state:
	.space	1

	.align
cur_delay:
    .space	2
sysclk:
	.space	2
cur_crossing_time:
	.space	2
crossing_times:
    .word 100, 200, 300, 400, 600

; Seccao:    stack
; Descricao: Implementa a pilha com o tamanho definido pelo simbolo STACK_SIZE
;
	.stack
	.space	STACK_SIZE
stack_top:
