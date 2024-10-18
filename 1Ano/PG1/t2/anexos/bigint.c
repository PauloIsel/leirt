
#include "bigint.h"

  

/**
 * Descrição:
 * 		retorna o número de dígitos do BIG_INT recebido por parâmetro
 * Parâmetros:
 *     
 * 		b - BIG_INT  
 * Retorno:
 * 		o número de dígitos de "b"
 */
int big_size(const BIG_INT b) {
	return b[0]; // b[0] contém o número de dígitos de b
}


/**
 * Descrição:
 *   A função apresenta no standard output o BIG_INT recebido por parâmetro
 *  
 * Parâmetros:
 *   big - BIG_INT  a apresentar
 * Retorno:
 *   não tem
 */
void big_show(const BIG_INT big) {
	int size = big_size(big);

	for (int i = size; i > 0; --i) { // apresenta os dígitos de big por ordem inversa
		printf("%d", big[i]);
	}
}

/**
 * Descrição:
 * 		copia um BIG_INT
 * Parâmetros:
 *      bsrc - BIG_INT original
 * 		bcopy - BIG_INT cópia
 * Retorno:
 * 		não tem
 */
void big_copy(const BIG_INT bsrc, BIG_INT bcopy) { 
	for (int i = 0; i <= big_size(bsrc); ++i) { // copia todos os dígitos de bsrc para bcopy
		bcopy[i] = bsrc[i];
	}
}

/**
 * Descrição:
 *   A função preenche um BIG_INT a partir de uma string com a representação de um valor inteiro  
 * Parâmetros:
 *   n - string de caracteres numéricos.
 *   big - BIG_INT a construir a partir de "n"
 * Retorno:
 *   A função retorna true se construiu o BIG_INT "big" com sucesso ou false 
 *   se foi encontrado algum caracter não numérico  
 */
bool big_from_string(char n[], BIG_INT big) {
	if (n[0] == '\0') { // string vazia
		return false;
	}

	int n_size = 0;
	while (n[n_size] != '\0') { // determina o tamanho da string
		n_size++;
	}

	big[0] = 0; // inicializa o BIG_INT

	for (int i = n_size; i > 0; --i) { // percorre a string de trás para a frente
		if (n[i - 1] < '0' || n[i - 1] > '9') { // verifica se o caracter é um dígito
			return false;
		}

		big[++big[0]] = n[i - 1] - '0'; // converte o caracter numérico para o seu valor inteiro
	}

	return true;
}

/**
 * Descrição:
 * 		Inicia um BIG_INT com o valor de um inteiro longo
 * Parâmetros:
 *      n   - inteiro cujo valor deve ser colocado no BIG_INT
 * 		big - BIG_INT que vai conter o valor do inteiro "n"
 * Retorno:
 * 		não tem
 */
void big_from_long(long n, BIG_INT big) {
	big[0] = 0; // inicializa o BIG_INT

	while (n > 0) {
		big[++big[0]] = n % 10; // determina o dígito menos significativo de n, e coloca-o no BIG_INT
		n /= 10; // remove o dígito menos significativo de n
	}
}


/**
 * Descrição:
 *   A função compara dois BIG_INT e retorna um valor negativo, zero
 *   ou um valor positivo consoante o primeiro seja menor, igual ou superior ao segundo 
 * Parâmetros:
 *   b1 - primeiro BIG_INT
 *   b2 - segundo BIG_INT
 * Retorno:
 *    valor negativo -> b1 < b2
 *    0              -> b1 == b2
 *    valor positivo -> b1 > b2
 */
int big_cmp(const BIG_INT b1, const BIG_INT b2) {
	int b1_size = big_size(b1);
	int b2_size = big_size(b2);

	int biggest_size = b1_size > b2_size ? b1_size : b2_size; // determina o tamanho do maior BIG_INT

	for (int i = biggest_size; i > 0; --i) {
		if (b1_size >= i && (b1[i] > b2[i] || (b2_size < i && b1[i] > 0))) { // verifica primeiro se b1[i] é válido, pois b1_size pode ser menor que i. Se b1[i] for maior que b2[i], então b1 é maior que b2. Se b2_size < i, então b2[i] é inválido, e b1[i] é maior que 0, então b1 é maior que b2
			return 1;
		} else if (b2_size >= i && (b1[i] < b2[i] || (b1_size < i && b2[i] > 0))) { // verifica primeiro se b2[i] é válido, pois b2_size pode ser menor que i. Se b2[i] for maior que b1[i], então b2 é maior que b1. Se b1_size < i, então b1[i] é inválido, e b2[i] é maior que 0, então b2 é maior que b1
			return -1;
		}
	}

	return 0;
}



/**
 * Descrição:
 *   A função calcula a soma de dois BIG_INT guardando-a num terceiro BIG_INT  
 * Parâmetros:
 *   b1 - primeiro operando BIG_INT  
 *   b2 - segundo  operando BIG_INT  
 *   bm - BIG_INT que guarda  o resultado
 * Retorno:
 *   A função retorna false se ocorrer overflow, isto é, se 
 *   a soma não couber no máximo de dígitos permitido.
 *   A função retorna true se a operação for bem sucedida.
 */
bool big_add(const BIG_INT b1, const BIG_INT b2, BIG_INT bm) {
	int b1_size = big_size(b1);
	int b2_size = big_size(b2);

	int smallest_size = b1_size < b2_size ? b1_size : b2_size; // determina o tamanho do menor BIG_INT

	bm[0] = 1; // inicializa o BIG_INT

	int carry = 0;
	for (int i = 1; i <= smallest_size; ++i) {
		int sum = b1[i] + b2[i] + carry; // soma os dígitos de b1 e b2, e o carry
		carry = sum / 10; // determina o carry da soma
		bm[i] = sum % 10; // determina o dígito da soma
		bm[0] = i; // determina o tamanho do BIG_INT
	}

	if (b1_size > b2_size) { // se b1 for maior que b2, então copia os dígitos de b1 para bm
		for (int i = smallest_size + 1; i <= b1_size; ++i) {
			int sum = b1[i] + carry; // soma o dígito de b1 com o carry
			carry = sum / 10; // determina o carry da soma
			bm[i] = sum % 10; // determina o dígito da soma
			bm[0] = i; // determina o tamanho do BIG_INT
		}
	} else if (b1_size < b2_size) {
		for (int i = smallest_size + 1; i <= b2_size; ++i) {
			int sum = b2[i] + carry; // soma o dígito de b2 com o carry
			carry = sum / 10; // determina o carry da soma
			bm[i] = sum % 10; // determina o dígito da soma
			bm[0] = i; // determina o tamanho do BIG_INT
		}
	}

	if (carry != 0) { // se o carry for diferente de 0, então adiciona-o ao BIG_INT
		if (bm[0] == MAX_DIGITS) { // verifica se o BIG_INT já está cheio
			return false;
		}

		bm[++bm[0]] = carry; // adiciona o carry ao BIG_INT
	}

	return true;
}

/**
 * Descrição:
 *   A função multiplica um BIG_INT por um inteiro (de 0 a 9) guardando
 *   o resultado noutro BIG_INT 
 * Parâmetros:
 *   b - primeiro BIG_INT
 *   n - valor inteiro longo
 *   bres  - resultado da multiplicação
 * Retorno:
 *   A função retorna true ou false se sucesso ou insucesso ("overlfow")
 */	
bool big_mul_dig(const BIG_INT b, int d, BIG_INT bres) {
	if (d < 0 || d > 9) return false; // verifica se d é um dígito válido

	int b_size = big_size(b);

	bres[0] = 1; // inicializa o BIG_INT

	int carry = 0;
	for (int i = 1; i <= b_size; ++i) {
		int mul = b[i] * d + carry; // multiplica o dígito de b por d, e soma o carry
		carry = mul / 10; // determina o carry da multiplicação
		bres[i] = mul % 10; // determina o dígito da multiplicação

		if (mul != 0) bres[0] = i; // determina o tamanho do BIG_INT (se o dígito da multiplicação for 0, então não é contabilizado)
	}

	if (carry != 0) { // se o carry for diferente de 0, então adiciona-o ao BIG_INT
		if (bres[0] == MAX_DIGITS) { // verifica se o BIG_INT já está cheio
			return false;
		}

		bres[++bres[0]] = carry; // adiciona o carry ao BIG_INT
	}

	return true;	
}
 

/**
 * Descrição:
 *   A função  multiplica o bigint "b" por 10
 * Parâmetros
 *   b: bigint a multiplicar por 10
 * Retorno
 *   A função retorna false se ocorrer overflow, isto é, se 
 *   a soma não couber no máximo de dígitos permitido.
 *   A função retorna true se a operação for bem sucedida.
 */
bool big_mul_10(BIG_INT b) {
	int b_size = big_size(b);

	if (b_size + 1 > MAX_DIGITS) { // verifica se o BIG_INT já está cheio
		return false;
	}

	for (int i = b_size; i > 0; --i) {
		b[i + 1] = b[i]; // desloca os dígitos de b para a direita
	}

	b[1] = 0; // adiciona o 0 à esquerda
	b[0]++; // determina o tamanho do BIG_INT

	return true;
}



// AS FUNÇÔES ABAIXO SÂO OPCIONAIS
// SENDO NATURALMENTE VALORIZADA A SUA CORRETA REALIZAÇÂO

/**
 * Descrição:
 *   A função  multiplica o bigint "b" pela potência de 10 de expoente "exp"
 * Parâmetros
 *   b: bigint a multiplicar por 10 elevado a "exp"
 * Retorno
 *   A função retorna false se ocorrer overflow, isto é, se 
 *   a soma não couber no máximo de dígitos permitido.
 *   A função retorna true se a operação for bem sucedida.
 */
bool big_mul_pow_10(BIG_INT b, int exp) {
    int b_size = big_size(b);

	if (b_size + exp > MAX_DIGITS) { // verifica se o BIG_INT já está cheio
		return false;
	}

	for (int i = b_size; i > 0; --i) {
		b[i + exp] = b[i]; // desloca os dígitos de b para a direita, de acordo com o expoente
	}

	for (int i = 1; i <= exp; ++i) {
		b[i] = 0; // adiciona os 0 à esquerda, de acordo com o expoente
	}

	b[0] += exp; // determina o tamanho do BIG_INT

	return true;
}


/**
 * Descrição:
 *   A função recebe três BIG_INT:  os dois primeiros são os operandos da multiplicação
 *   e o resultado é  colocado no terceiro
 * Parâmetros:
 *   b1 - primeiro BIG_INT
 *   b2 - segundo BIG_INT.
 *   bm  - resultado da multiplicação
 * Retorno:
 *   A função retorna true ou false se sucesso ou insucesso ("overflow")
 */	
bool big_mul(const BIG_INT b1, const BIG_INT b2, BIG_INT bm) {
	int b1_size = big_size(b1);
	int b2_size = big_size(b2);

	bm[0] = 1; // inicializa o BIG_INT

	int smallest_size = b1_size < b2_size ? b1_size : b2_size; // determina o tamanho do menor BIG_INT

	for (int i = 1; i <= smallest_size; ++i) {
		BIG_INT bmul = {0}; // inicializa o BIG_INT que vai guardar a multiplicação

		if (b1_size > b2_size) {
			if (!big_mul_dig(b1, b2[i], bmul)) return false; // multiplica o dígito de b2 por b1 porque b1 é maior que b2
		} else {
			if (!big_mul_dig(b2, b1[i], bmul)) return false; // multiplica o dígito de b1 por b2 porque b2 é maior que b1
		}

		if (!big_mul_pow_10(bmul, i - 1)) return false; // multiplica o BIG_INT por 10 elevado a i - 1.

		BIG_INT baux = {0};
		if (!big_add(bm, bmul, baux)) return false; // adiciona o BIG_INT à multiplicação

		big_copy(baux, bm); // copia o resultado para o BIG_INT
	}

	return true;
}
 
 
