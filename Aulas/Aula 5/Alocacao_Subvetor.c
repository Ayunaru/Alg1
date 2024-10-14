#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int* subvetor(int *v, int n, int ini, int fim){
    int *sv = NULL;

    if ((v != NULL) && (ini >= 0) && (ini <= fim) && fim < n){
        sv = (int*) malloc(sizeof(int) * (fim - ini + 1));
        for (int i = ini; i <= fim; i++){
            sv[i - ini] = v[i];
        }
    }
    return sv;
}

void imprimir(int *v, int n){
    if(v != NULL){
        for(int i = 0 ; i < n; i++)
            printf("%d ", v[i]);
    }
}

int main() {   
    int n, i, ini, fim;
    int *v = NULL;
    int *sv = NULL;

    scanf("%d", &n);

    v = (int*) malloc(sizeof(int) * n);

    for (i = 0; i < n; i++)
        scanf("%d", &v[i]);

    scanf("%d %d", &ini, &fim);
    sv = subvetor(v, n, ini, fim);

    imprimir(sv, fim - ini + 1);
    
    return 0;
}
