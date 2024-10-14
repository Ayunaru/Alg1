#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    int a;
    char str[100];
    float b;
} nome;

typedef struct {
    int dia, mes, ano;
}data;

int main(void){
    data a;
    a.dia = 22;
    a.mes = 2;
    a.ano = 2004;
    printf("%d %d %d", a.dia, a.mes, a.ano);  
    return 0;
}