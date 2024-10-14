#include "lista.h"

#define MAX 100

int main() {
    Lista l1, l2;
    int n, elemento;

    scanf("%d", &n);
    inicializa_lista(&l1);
    for (int i = 0; i < n; i++) {
        scanf("%d", &elemento);
        insere_elemento(&l1, elemento);
    }

    scanf("%d", &n);
    inicializa_lista(&l2);
    for (int i = 0; i < n; i++) {
        scanf("%d", &elemento);
        insere_elemento(&l2, elemento);
    }

    Lista *resultado = intercala_ordenado(&l1, &l2);

    for (int i = 0; i < resultado->tamanho; i++) {
        printf("%d ", resultado->elementos[i]);
    }
    printf("\n");

    free(resultado);

    return 0;
}

