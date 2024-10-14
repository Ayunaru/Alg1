#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char nome[20];
    float nota;
    int idade;
} Tipo_REG;

typedef struct {
    Tipo_REG vetor[MAX_SIZE];
    int tam;
} Lista;

Lista* criar_lista() {
    Lista *l = (Lista*) malloc(sizeof(Lista));
    if (l != NULL) {
        l->tam = 0;
    }
    return l;
}

int lista_cheia(Lista *l) {
    return l != NULL && l->tam >= MAX_SIZE;
}

int lista_vazia(Lista *l) {
    return l == NULL || l->tam == 0;
}

int inserir(Lista *l, Tipo_REG registro) {
    if (l == NULL || lista_cheia(l)) {
        return 0;
    }
    l->vetor[l->tam] = registro;
    l->tam++;
    return 1;
}

void imprimir_lista(Lista *l) {
    if (!lista_vazia(l)) {
        for (int i = 0; i < l->tam; i++) {
            printf("%s %.2f %d\n", l->vetor[i].nome, l->vetor[i].nota, l->vetor[i].idade);
        }
    }
}

int liberar_lista(Lista *l) {
    if (l != NULL) {
        free(l);
        return 1;
    }
    return 0;
}

void ordenar_lista(Lista *l) {
    for (int i = 0; i < l->tam - 1; i++) {
        for (int j = 0; j < l->tam - 1 - i; j++) {

            if (l->vetor[j].nota < l->vetor[j + 1].nota ||
                (l->vetor[j].nota == l->vetor[j + 1].nota && l->vetor[j].idade > l->vetor[j + 1].idade)) {


                Tipo_REG *a = &l->vetor[j];
                Tipo_REG *b = &l->vetor[j + 1];


                Tipo_REG temp = *a;
                *a = *b;
                *b = temp;
            }
        }
    }
}
