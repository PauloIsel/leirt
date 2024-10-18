#include <stdio.h>
#include <stdlib.h>


int main() {
    int cartas[] = {1, 2, 3, 4, 5, 6, 7, 10, 11, 12, 13}; 
    int pontuacaoJogador = 0; 
    int pontuacaoComputador = 0; 
    int cartaJogador, cartaComputador;
    
    
    while (1) {
        
        printf("Sua pontuação: %d\n", pontuacaoJogador);
        printf("Pontuação do computador: %d\n", pontuacaoComputador);

        printf("Escolha uma carta para jogar (1-13): ");
        scanf("%d", &cartaJogador);

        if (cartaJogador < 1 || cartaJogador > 13 ) {
            printf("Carta inválida. Escolha uma carta de 1 a 13.\n");
            continue;
        }
        cartaComputador = cartas[rand() % 11];
        printf("O computador jogou a carta %d\n", cartaComputador);
        
        pontuacaoJogador += cartaJogador;
        pontuacaoComputador += cartaComputador;
        
        if (pontuacaoJogador >= 31) {
            printf("Você passou dos 31 pontos e perdeu!\n");
            break; 
        } else if (pontuacaoComputador >= 31) {
            printf("O computador passou dos 31 pontos e você venceu!\n");
            break; 
        }
    }
    return 0;
}
