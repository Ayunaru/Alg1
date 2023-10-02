#include <stdio.h>

// Definindo um enum chamado "espectro"
enum espectro {
    vermelho, laranja, amarelo, verde, azul, violeta, anil, ultravioleta
};

int main() {
    // Declarando uma vari�vel do tipo "espectro" chamada "banda"
    enum espectro banda;

    // Atribuindo valores do enum � vari�vel "banda"
    banda = azul; // azul � um enumerador v�lido

    // bandas = 2000; // Isso � comentado, pois � inv�lido

    banda = laranja; // laranja � um enumerador v�lido

    // Incrementando a vari�vel "banda"
    banda++; // Isso � v�lido, move de "laranja" para "amarelo"

    // Atribuindo a soma de dois valores de enum ao "banda"
    banda = laranja + vermelho; // laranja + vermelho = amarelo

    // Declarando uma vari�vel "cor" do tipo int e atribuindo um valor de enum a ela
    int cor = azul; // azul (enum) � convertido para int

    // Atribuindo um valor de enum diretamente a "banda"
    banda = 3; // 3 corresponde a "verde" no enum

    // Realizando uma opera��o de adi��o entre int e enum
    cor = 3 + vermelho; // 3 + vermelho = 3 + 0 = 3

    // Tentando usar a sintaxe inv�lida para atribuir um valor ao enum (gerar� erro)
    // banda = espectro(3);

    // Exibindo os valores das vari�veis
    printf("Valor de 'banda': %d\n", banda);
    printf("Valor de 'cor': %d\n", cor);

    return 0;
}
