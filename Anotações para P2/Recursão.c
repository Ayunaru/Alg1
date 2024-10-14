#include<stdio.h>
#include<stdlib.h>

// Recursão é repetição. Uma função que chama a si própria

/*  3 REGRAS PARA RECURSÃO
        - CRITÉRIO DE PARADA (CASO BASE)
        - DECIDIR COMO TRANSFORMAR A ENTRADA DOS DADOS, NO CASO BASE
        - DIVIDIR O PROBLEMA EM SUBPROBLEMAS (CASO INDUTIVO)

*/

int fatorial_recursivo(int n){
    if(n <= 1)  // caso base: 0! ou 1!  (CRITÉRIO DE PARADA)
        return 1;   // retorna 1, e marca o fim da função quando esse n é 1 ou 0;
    else    // caso iterativo: n! = n * fatorial(n - 1);
        return n * fatorial_recursivo(n-1);
}

int somatorio_vetor_recursivo(int* v, int n){
    if(n<1)
        return 0;
    else   
        return v[n-1] + somatorio_vetor_recursivo(v, n-1);
}

void hanoi_recursivo(char de, char para, char via, int n){
    if (n >= 1){ // Caso base: quando n for igual a zero (nada é feito)
        hanoi_recursivo(de, via, para, n - 1);
        printf("disco %d de %c para %c\n", n, de, para);
        hanoi_recursivo(via, para, de, n - 1);
    }
}

int fib_recursiva(int n){ // o termo n é a soma dos 2 termos anteriores (n-1) + (n-2)
    
    if (n <= 0) // Caso base 1: a sequência de fibonacci não é válida para termos não positivos, e o primeiro termo desse sequência sempre é zero
        return 0;
    else if (n == 1) // Caso base 2: o segundo e terceiro termo da sequência são iguais a 1
    	return 1;
    else // Caso iterativo
    	return fib_recursiva(n - 1) + fib_recursiva(n - 2);
}

int fib_iterativa(int n){   // Solução iterativa -> execute menos processos, utilizando menos processamento pois não repete operações diversas vezes
    int fibo1, fibo2, fiboN, i;
    if(n<=0)
        return 0;
    else if(n == 1)
        return 1;
    else{
        fibo1 = 0;
        fibo2 = 1;
        fiboN = 0;
        for (i = 2; i <= n; i++){
            fiboN = fibo1 + fibo2;
            fibo1 = fibo2;
            fibo2 = fiboN;
        }
    return fiboN;
    }
}

int MDC_recursiva(int a, int b){    // Baseado no algoritmo de euclides
    int resto = a%b;
    if(resto == 0)
        return b;
    else
        return MDC_recursiva(b, resto);
}
//MDC_recursiva(18, 60)
int main(){
    //printf("%d", fib_iterativa(5));
    printf("%d", MDC_recursiva(400, 320));
}