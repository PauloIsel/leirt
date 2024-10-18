#include <stdio.h>

int main()
{
    double valor;
    int unidadeDeOrigem, unidadeDeDestino;
    // Solicita ao usuário que digite o valor a ser convertido.
    printf("Digite o valor: ");
    scanf("%lf", &valor);
    // Solicita a unidade de origem ao usuário.
    printf("Digite a unidade de origem (1-7):\n");
    scanf("%d", &unidadeDeOrigem);
    // Solicita a unidade de destino ao usuário.
    printf("Digite a unidade de destino (1-7):\n");
    scanf("%d", &unidadeDeDestino);
    double resultado = 0.0;
    // Realiza a conversão de unidades com base na unidade de origem.
    switch (unidadeDeOrigem)
    {
    case 1: // milímetro
        resultado = valor / 1000.0;
        break;
    case 2: // centímetro
        resultado = valor / 100.0;
        break;
    case 3: // decímetro
        resultado = valor / 10.0;
        break;
    case 4: // metro
        resultado = valor;
        break;
    case 5: // decâmetro
        resultado = valor * 10.0;
        break;
    case 6: // hectómetro
        resultado = valor * 100.0;
        break;
    case 7: // quilómetro
        resultado = valor * 1000.0;
        break;
    default:
        // Se a unidade de origem não estiver no intervalo de 1 a 7, exibe uma mensagem de erro.
        printf("Unidade de origem invalida. Use um valor de 1 a 7.\n");
        return 1; // Encerra o programa com um código de erro.
    }
    // Converter o valor resultante para a unidade de destino.
    switch (unidadeDeDestino)
    {
    case 1: // milímetro
        resultado *= 1000.0;
        break;
    case 2: // centímetro
        resultado *= 100.0;
        break;
    case 3: // decímetro
        resultado *= 10.0;
        break;
    case 4: // metro
        // Nenhuma ação necessária, pois já está em metros.
        break;
    case 5: // decâmetro
        resultado /= 10.0;
        break;
    case 6: // hectómetro
        resultado /= 100.0;
        break;
    case 7: // quilómetro
        resultado /= 1000.0;
        break;
    default:
        // Se a unidade de destino não estiver no intervalo de 1 a 7, mostra uma mensagem de erro.
        printf("Unidade de destino invalida. Use um valor de 1 a 7.\n");
        return 1; // Encerra o programa com um código de erro.
    }
    // Mostra o valor convertido com duas casas decimais.
    printf("O valor convertido e: %.2lf\n", resultado);
    return 0; // Encerra o programa.
}