
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "arrays.h"

/**
 * Descrição:
 *    Procura o valor "v" no array "nums"
 * Retorna:
 *    a posição onde o valor foi encontrado
 *    -1 caso o valor não exista no array
 */ 
int a_search(int nums[], int size, int v) {
    for(int i= 0; i < size; i++) {
        if (nums[i] == v) return i;
    }
    return -1;
}

/**
 * Descrição:
 *    remove o valor "to_remove" do array "vals"
 * Retorna:
 *    true se o valor foi removido
 *    false caso o valor não exista no array
 */
bool a_remove0(int vals[], int size, int to_remove) {
    for(int i=0; i < size; i++) {
         if (vals[i] == to_remove) {
             // remove element
             vals[i] = 0;
             i++;
             return true;
         }
    }
    return false;
        
}


/**
 * Descrição:
 *    remove o valor "to_remove" do array "vals"
 *     Nesta versão é usada a função search
 * Retorna:
 *    true se o valor foi removido
 *    false caso o valor não exista no array
 */
bool a_remove(int vals[], int size, int to_remove) {
    int idx = a_search(vals, size, to_remove);
    if (idx == -1) return false;
    // remove element
    vals[idx] = vals[size - 1];
    return true;
}

/**
 * Descrição:
 *    remove o valor "to_remove" do array "vals"
 *    Nesta versão assume-se que a ordem dos valores no array não se pode alterar
 * Retorna:
 *    true se o valor foi removido
 *    false caso o valor não exista no array
 */
bool a_remove_ordered(int vals[], int size, int to_remove) {
    int idx = a_search(vals, size, to_remove);
    if (idx == -1) return false;
    // remove element
    for(int i= idx + 1; i < size; ++i) vals[i-1] = vals[i];
    return true;
}


// FUNÇÔES A IMPLEMENTAR NA PRÀTICA DE 18/10


/**
 * Descrição:
 *    Roda todos os elemmentos do array uma casa para a esquerda
 *    O primeiro elemento passa para último
 * Retorna:
 *    a nova dimensão do array após a remoção dos repetidos
 */
void a_rotate_left(int vals[], int size) {

    int temp = vals[0];
    for(int i = 0; i < size - 1; i++) {
        vals[i] = vals [i+1];

    }
    vals[size - 1] = temp;
}

/**
 * Descrição:
 *    Roda todos os elemmentos do array uma casa para a direita
 *    O último elemento passa para primeiro.
 * Retorna:
 *    a nova dimensão do array após a remoção dos repetidos
 */
void a_rotate_right(int vals[], int size) {
    
    int temp = vals[size - 1];
    for (int i = size - 1; i >= 0; i--) {
        vals[i] = vals[i-1];
    }
    vals[0] = temp;

}
/**
 * Descrição:
 *    remove todas as repetições de valores encontrados em "vals"
 * Retorna:
 *    a nova dimensão do array após a remoção dos repetidos
 */
int a_remove_reps(int vals[], int size) {
    return false;
}


/**
 * Descrição:
 *		Gera o formato do nome que corresponde ao último apelido 
 *      (primeira letra em maíuscula e as restantes em minusculas),
 * 		seguido da primeira letra (em maíuscula) do primeiro nome, seguido de ponto.
 * 		Assuma que não existem espaços iniciais e finais na string original.
 * 		Ex: se o nome for "Carlos  Manuel  SANtos" ou resultado é "Santos C."
 * Parâmetros:
 * 		"orig": nome a converter
 * 		"result": o nome no formato requerido
 * Retorno:
 * 		"true" se o nome for passível de conversão 
 *      (tem de ter pelo menos um nome proprio e um apelido com pelo menos dois caracteres)
 * 		"false" caso contrário.
 */
bool name_compressed(char orig[], char result[]) {
    printf("TO IMPLEMENT!\n");
    return false;
}
