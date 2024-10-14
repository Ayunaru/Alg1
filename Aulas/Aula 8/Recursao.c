#include<stdio.h>
#include<stdlib.h>

// Funcao que chama a si propria:

//exemplo do fatorial
int fatorial (int n){
    if(n <=1)
        return 1;
    else
        return n*fatorial(n-1);
}
/*Recorrencia:
n! = |1 n
     |n * fatorial (n-1)*/

void hanoi(char de, char para, char via, int n){
    if(n>=1){
        hanoi(de, via, para, n-1);
        //printf("")
    }
}

// Recursividade para sequencia de fibonacci, mas e um codigo ineficiente pois faz 2^n operacoes
int fibo_rec(int n){
    if(n<= 0)
        return 0;
    else if(n == 1)
        return 1;
    else
        return fibo_rec(n-1) + fibo_rec(n-2);
}

int main(void){
    return 0;
}