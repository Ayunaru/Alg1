#include<stdio.h>
#include<stdlib.h>

/*
Recusos necessários para execução de um algoritmo:
    - Tempo
    - Espaço

Cálculo do tempo de Execução e número de instruções:
    Instruções simples: soma, multiplicação, comparação, atribuição, etc;
        Assumimos que consomem apenas uma unidade de tempo;
    Operações complexas como inversão de matrizes e ordenação de valores, não são realizadas em apenas uma unidade de tempo;

    Repetições:
        Exemplo 1 -> [3n + 2] instruções
            for(i = 0; i <= n; i++) // [1 inicialização de i (i = 0)] + [n * (1 comparação (i <= n) + 1 atribuição de i (1++) + 1 atribuição de k (k = 0))] + 
                k = 0;                                             + [1 comparação quando o laço for dá errado)]
            
            Somatório: 1 + n(1+1+1) + 1 = 3n + 1;

        Exemplo 2 -> [4n + 3] intruções
            if(i<j) 
                i = i + 1   //1 atribuição [i = i+1] = 1 instruções
            else{ 
                for(k = 1; k<=n; k++)   // [1 inicalização (k = 1)] + [n*(1 comparação entre k e n + 1 atribuição de i + 1 multiplicação de i * k + 1 incremento de k)] 
                    i = i * k;                                              + [1 comparação quando o laço for dá errado)]
            }   
            Somatório: 1 + 1 + n(1+1+1+1) + 1 = 4n + 3;

Notação O (Big Oh):
    - Quando dizemos que um alg possui um custo de O(n²), significa que no pior caso, o alg nunca terá custo maior que n²


*/

int main(){

}