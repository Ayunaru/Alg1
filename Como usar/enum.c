#include <stdio.h>

// Definindo um enum chamado "espectro"
enum espectro {
    vermelho, laranja, amarelo, verde, azul, violeta, anil, ultravioleta
};

int main() {
    // Declarando uma variável do tipo "espectro" chamada "banda"
    enum espectro banda;

    // Atribuindo valores do enum à variável "banda"
    banda = azul; // azul é um enumerador válido

    // bandas = 2000; // Isso é comentado, pois é inválido

    banda = laranja; // laranja é um enumerador válido

    // Incrementando a variável "banda"
    banda++; // Isso é válido, move de "laranja" para "amarelo"

    // Atribuindo a soma de dois valores de enum ao "banda"
    banda = laranja + vermelho; // laranja + vermelho = amarelo

    // Declarando uma variável "cor" do tipo int e atribuindo um valor de enum a ela
    int cor = azul; // azul (enum) é convertido para int

    // Atribuindo um valor de enum diretamente a "banda"
    banda = 3; // 3 corresponde a "verde" no enum

    // Realizando uma operação de adição entre int e enum
    cor = 3 + vermelho; // 3 + vermelho = 3 + 0 = 3

    // Tentando usar a sintaxe inválida para atribuir um valor ao enum (gerará erro)
    // banda = espectro(3);

    // Exibindo os valores das variáveis
    printf("Valor de 'banda': %d\n", banda);
    printf("Valor de 'cor': %d\n", cor);

    return 0;
}
