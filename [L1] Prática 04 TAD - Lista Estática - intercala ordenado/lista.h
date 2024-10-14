#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int elementos[MAX];
    int tamanho;
} Lista;

void inicializa_lista(Lista *l) {
    l->tamanho = 0;
}

void insere_elemento(Lista *l, int elemento) {
    if (l->tamanho < MAX) {
        int i = l->tamanho - 1;
        while (i >= 0 && l->elementos[i] > elemento) {
            l->elementos[i + 1] = l->elementos[i];
            i--;
        }
        l->elementos[i + 1] = elemento;
        l->tamanho++;
    }
}

Lista* intercala_ordenado(Lista *l1, Lista *l2) {
    Lista *resultado = (Lista*)malloc(sizeof(Lista));
    inicializa_lista(resultado);

    int i = 0, j = 0;

    while (i < l1->tamanho && j < l2->tamanho) {
        if (l1->elementos[i] < l2->elementos[j]) {
            insere_elemento(resultado, l1->elementos[i]);
            i++;
        } else {
            insere_elemento(resultado, l2->elementos[j]);
            j++;
        }
    }

    while (i < l1->tamanho) {
        insere_elemento(resultado, l1->elementos[i]);
        i++;
    }

    while (j < l2->tamanho) {
        insere_elemento(resultado, l2->elementos[j]);
        j++;
    }

    return resultado;
}


#endif
N
