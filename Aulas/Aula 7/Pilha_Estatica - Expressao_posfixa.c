#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

#define TAM_MAX 100

typedef struct Pilha Pilha;

struct Pilha{
    int item[TAM_MAX];
    int topo;
};


Pilha* criar_pilha(){
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));

    p->topo = -1;

    return p;
}


int pilha_cheia(Pilha *p){
    if (p == NULL)
        return -1;
    else if (p->topo >= (TAM_MAX - 1))
        return 1;
    else
        return 0;
}


int pilha_vazia(Pilha *p){
    if (p == NULL)
        return -1;
    else if (p->topo < 0)
        return 1;
    else
        return 0;
}


int empilhar(Pilha *p, int item){
    if (p == NULL)
        p = criar_pilha();

    if (!pilha_cheia(p)){
        p->topo++;

        p->item[p->topo] = item;

        return 1;
    }

    return 0;
}


int desempilhar (Pilha *p){
    int item = INT_MIN;

    if (!pilha_vazia(p)){
        item = p->item[p->topo];

        p->topo--;
    }

    return item;
}


void imprimir_pilha(Pilha *p){
    Pilha aux = *p;
    int item;

    while (!pilha_vazia(&aux)){
        item = desempilhar(&aux);

        printf("%d", item);
    }
    
    printf("\n");
}

void liberar_pilha(Pilha *p){
    if (p != NULL)
        free(p);
}

int obter_posicao_topo(Pilha *p){
    if (!pilha_vazia(p))
        return p->topo;
    else
        return -1;
}

int acessar_valor_topo(Pilha *p){
    if (!pilha_vazia(p))
        return p->item[p->topo];
    else
        return INT_MIN;
}

int calc(int a, int b, char op){
    switch (op)
    {
    case '+':
        return a+b;
    case '-':
        return a-b;
    case '*':
        return a*b;
    case '/':
        return a/b;    
    default:
        pritnf("Operador desconhecido");
        return 0;
    }
}

int resolver(char *str){
    Pilha *p = criar_pilha();
    int res = 0;

    for(int i = 0; i<strlen(str); i++){
        if((str[i] >= '0') && (str[i] <= '9'))
            empilhar(p, str[i] - '0');
        else{
            int b = desempilhar(p);
            int a = desempilhar(p);
            empilhar(p, calc(a, b, str[i]));
        }
    }

    res = desempilhar(p);
    liberar_pilha(p);
}

int main() {
    char *str = (char*) malloc(sizeof(char) * 50);

    scanf("%s", str);
    printf("%d", resolver(str));
    free(str);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
