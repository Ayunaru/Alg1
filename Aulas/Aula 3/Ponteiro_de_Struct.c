#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct
{
    char nome[100];
    int *RA, x;
    float coef;
} Aluno;

typedef struct
{
    int x, y;
} Ret;

Ret* soma(Ret r1, Ret r2){
    Ret a;
    Ret *r3 = &a;
    r3->x = r1.x + r2.y;    //operador "->" = acessar o campo de um ponteiro de struct
    r3->y = r1.x + r2.y; 
}

//Comando Union: util para reutilizacao de codigo
typedef union{
    long l;
    int i;
    short s;
    float f;
};

enum alfa{a, b, salvar, copiar=b, quatro=6, f, g}; //simbolos enumerados, baiscamente cada um recebera um numero inteiro que segue uma sequencia definida pelo primeiro num

int main(void)
{
    Aluno a;
    Aluno *p;
    int i = 10;

    p->RA = 112; //(*p).RA = 112;

    a.RA = &i;
    p = &a;

    strcpy((*p).nome, "adalberto"); //?

    // printf("%d", (*p).RA);
     
    // printf("%d", *(*p).RA); // *(*x) = diz que o campo tambem eh um ponteiro
}