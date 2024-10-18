#include "strutils.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
    
/**
 * Descrição:
 * 	Cria a string "dst" a partir da string "src", removendo os espaços iniciais e finais 
 *  e mais do que um espaço entre as palavras da string "src"
 * Parâmetros:
 * 	"src": texto original
 *  "dst": texto sem os espaços "a mais" do texto original
 * Retorno:
 * 	Não tem
 */

void str_trim(char src[], char dst[]) {
    int k, j = 0;
    int space = 1;

    for (k = 0; src[k] != '\0'; k++) {  // cria um loop que passa por todos os valores do array src[].
        if (src[k] != ' ') {            // se não houver espaços, todos os elementos do array src[] passam para o array de saída dst[].
            space = 0;                  // identifica que não existem espaços, ou seja, a condição é false.
            dst[j++] = src[k];          // passa os elementos do array src[] passam para o array de saída dst[].
        } else {
            if (!space) {               // se encontrar espaços, vai eliminá-los
                space = 1;              // identifica que existem espaços, ou seja, a condição é true.
                dst[j++] = ' ';         // coloca um espaço na próxima posição do array.
            }
        }
    }
    if (dst[j-1] == ' ') j = j-1;       // para que o último valor do output não seja um espaço, fazemos com que o array termine um valor antes do suposto valor final.
    dst[j] = '\0';
}


/**
 * Descrição:
 *    a função  "snake_2_camel_case" coloca na string "dst" a conversão da string "src", em formato snake case (ver https://en.wikipedia.org/wiki/Snake_case),
 *    para formato  Camel Case (ver https://en.wikipedia.org/wiki/Camel_case). 
 *    No caso da string "src" começar e/ou acabar por uma sequência de "_" estes caracteres devem ser mantidos na string "dst" 
 * Retorno:
 * 	  Não tem.
 * Exs:
 *    A string em snake case “some_var” será escrita no formato Camel Case como “SomeVar".
 *    A string em snake "case "__var_start_end__with_underscores__" será escrita no formato Camel Case como “__VarStartEndWithUnderscores__".
 *    A string em snake "case "__" será escrita no formato Camel Case como “__".
 */

void snake_2_camel_case(char src[], char dst[]) {

    int length = strlen(src);
    int k, j = 0;
    int uppercasenext = 1;
    int end_str = length;

    for (k = 0; src[k] != '\0'; k++) {              // cria um loop que passa por todos os valores do array src e copia os underscores iniciais para a string dst.
        if (src[k] == '_') {                        
        dst[j++] = src[k];
        } else {
            break;                                  // caso encontre um caractere diferente de underscore, para o loop.
        }    
    }

    for (k = length - 1; k >= 0; k--) {             // loop para encontrar o último underscore da string de origem.
        if (src[k] == '_') {
            end_str = k;
        } else {
            break;                                  // caso encontre um caractere diferente de underscore, para o loop.
        }
    }

    for (k = 0; src[k] != '\0'; k++) {              // Loop para converter snake_case para CamelCase.
        if (src[k] == '_') {
            uppercasenext = 1;                      // define a flag para indicar que o próximo caractere deve ser maiúsculo.
        } else {
            if (uppercasenext) {
                dst[j++] = toupper(src[k]);         // converte o caractere para maiúsculo e o adiciona à string dst.
                uppercasenext = 0;                  // reseta a flag para não converter os próximos caracteres.
            } else {
                dst[j++] = src[k];                  // copia os restantes caracteres para a string dst.
            }
        }
    }

    // adiciona underscores finais.
    if (end_str != 0) {
        for (k = end_str; k < length; k++) {
            dst[j++] = '_';
        }
    }

    dst[j] = '\0'; // termina a string.
}


/**
 * Descrição:
 *		A função "anagram" verifica se as duas strings recebidas em parâmetro são anagramas, 
 * 		ou seja, se têm, exatamente, as mesmas letras (ignorando os espaços), 
 * 		embora os carateres possam estar dispostos  em diferentes posições.
 * 		Na verificação não distinga entre letras maiúsculas e minúsculas. 
 * Parâmetros:
 *		"str1": primeira string a avaliar
 *	    "str2": segunda string a avaliar
 * Retorno:
 *	"true" se as string "str1" e "str2" só contiverem letras (pelo menos duas) e espaços, e forem anagramas, 
 *  "false" caso contrário. 
 * Ex: “setimo ANDAR” e “desmontaria” são anagramas.
 *     "ator" e "rota1" não são anagramas
 */

#define LETTERS_ALPHA 26

bool anagram(char str1[], char str2[]) {
    int k = 0;

    if (strlen(str1) < 2 || strlen(str2) < 2) {     // verifica se algum dos arrays tem menos de 2 caracteres, e se for o caso, retorna true.
        return false;
    }

    int cstr1[LETTERS_ALPHA] = {0};                 // criar um array para cada string onde vamos formatar o string original de modo a ignorar as letras maiusculas.
    int cstr2[LETTERS_ALPHA] = {0};

    for (k = 0; str1[k] != '\0'; k++) {             // verifica se a string é constituida por caracteres do alfabeto, retornando true se esse for o caso.
        if (isalpha(str1[k])) {
            cstr1[tolower(str1[k]) - 'a']++;
        }
        
        // caso não haja nem um caracter alfabético nem um espaço em qualquer ponto da string, retorna falso.
        if (!isalpha(str1[k]) && !isspace(str1[k])) {
            return false;
        }
    }
    
    for (k = 0; str2[k] != '\0'; k++) {             // verifica se a string é constituida por caracteres do alfabeto, retornando true se esse for o caso.
        if (isalpha(str2[k])) {
            cstr2[tolower(str2[k]) - 'a']++;
        } 

        if (!isalpha(str2[k]) && !isspace(str2[k])) {
            return false;
        }
    }

    for (k = 0; k < LETTERS_ALPHA; k++) {           // compara cada valor de ambas as strings de modo a que seja possível concluir se são anagramas ou não.
        if (cstr1[k] != cstr2[k]) {
            return false;
        } 
    }

    return true;
}


/**
 * Descrição:
 *	  Gera o formato alternativo para o nome recebido por parâmetro em que apenas 
 * 	  o primeiro nome e o ultimo apelido são apresentados por extenso, estando os nomes 
 * 	  intermédios apresentado na forma de abreviatura.
 * 	  Espaços iniciais e finais e espaços intermédios a mais devem ser eliminados.
 *    Nomes intermédios com 1 ou 2 caracteres são omitidos
 * 	 
 * Parâmetros:
 * 	"orig": nome a converter
 * 	"result": o nome no formato requerido
 * Retorno:
 * 	"true" se o nome for passível de conversão (tem de ter pelo menos um nome próprio e um 
 *   apelido), "false" caso contrário.
 * Exs: 
 *    Se o nome original for:  "  pedro manuel  vieira   rodrigues  ", a conversão é:  "Pedro M. V. Rodrigues".
 *    Se o nome original for:  "  pedro manuel  de  RODRIGUES  ", a conversão é:  "Pedro M. Rodrigues".
 */

#define MAX_CHAR_RESULT 100

bool name_middle_compressed(char orig[], char result[]) {
    int k, i = 0;
    int end_firstname = 0;
    int start_lastname = 0; 

    // retira os espaços finais e inciais e retira os espaços a mais entre palavras.
    char origf[MAX_CHAR_RESULT] = "";
    str_trim(orig, origf);

    for (k = 0; origf[k] != '\0'; k++) {
        if (end_firstname == 0 && isspace(origf[k])) {
            end_firstname = k;   // encontra o índice do último caractere do primeiro nome.
        }
        
        if (isspace(origf[k])) {
            start_lastname = k;  // encontra o índice do último caractere do primeiro nome.
        }
    }
    
    if (end_firstname == 0) {    // caso não haja primeiro nome, retorna falso.
        return false;
    }

    for (k = 0; origf[k] != '\0'; k++) {
        if (k < end_firstname || k > start_lastname) {
            // adiciona um espaço depois do primeiro nome.
            if (k == start_lastname + 1) result[i++] = ' ';
            //converte a primeira letra da palavra para maiúscula e o resto para minúscula.
            result[i++] = (k == 0 || k == start_lastname + 1) ? toupper(origf[k]) : tolower(origf[k]);
            // abrevia os nomes intermédios e verifica também se têm pelo menos 2 caracteres
        } else if (isalpha(origf[k]) && isspace(origf[k - 1]) && !isspace(origf[k + 1]) && !isspace(origf[k + 2])) {
            result[i++] = ' ';
            result[i++] = toupper(origf[k]);
            result[i++] = '.';
        }
    }

    result[i++] = '\0'; //termina a string de resultado.
    return true;   
}


/**
 * Descrição:
 *    Esta função coloca no array "words" as palavras (word_t) existentes no array "text" 
 * 	  até ao máximo de size palavras
 * Retorno:
 *    A função retorna o total de palavras colocadas no array "words"
 */
int str_split(char text[], word_t words[], int size) {
    int k= 0;
    int wordcount = 0;

    // retira os espaços finais e inciais e retira os espaços a mais entre palavras.
    char textf[MAX_CHARS] = "";
    str_trim(text, textf);

    // percorre a string textf até encontrar o seu fim ou até o número de palavras atingir o tamanho máximo.
    while (textf[k] != '\0' && wordcount < size) { //
        int j = 0;

        // Copiar caracteres alfabéticos para a palavra atual.
        while (isalpha(textf[k]) && j < MAX_CHARS) {
            words[wordcount][j] = textf[k];
            k++;
            j++;
        }

        if (j > 0) {
            words[wordcount][j] = '\0';  // termina a string.
            wordcount++;
        } else {
            k++;  // Avançar para o próximo caractere não alfabético.
        }
    }

    return wordcount;
}