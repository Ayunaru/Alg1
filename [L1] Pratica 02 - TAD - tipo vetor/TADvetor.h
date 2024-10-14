
#ifndef TADVETOR_H
#define TADVETOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
        int *item;
            int q;
                int n;
} Vetor;

Vetor *iniciar(int n) {
        Vetor *v = malloc(sizeof(Vetor));
            if (v == NULL) {
                        return NULL;
            }
            
                v->item = malloc(n * sizeof(int));
                    if (v->item == NULL) {
                                free(v);
                                        return NULL;
                    }
                    
                        v->q = 0;
                            v->n = n;
                            
                                return v;
}

int inserir(Vetor *v, int x) {
        if (v->q < v->n) {
                    v->item[v->q++] = x;
                            return 1;
        }
            return 0;
}

Vetor *intercalar(Vetor *v1, Vetor *v2) {
        int total = v1->q + v2->q;
            Vetor *resultado = iniciar(total);
                if (resultado == NULL) {
                            return NULL;
                }
                
                    int i = 0, j = 0, k = 0;
                        while (i < v1->q && j < v2->q) {
                                    resultado->item[k++] = v1->item[i++];
                                            resultado->item[k++] = v2->item[j++];
                        }
                            while (i < v1->q) {
                                        resultado->item[k++] = v1->item[i++];
                            }
                                while (j < v2->q) {
                                            resultado->item[k++] = v2->item[j++];
                                }
                                    resultado->q = total;
                                        return resultado;
}

Vetor *concatenar(Vetor *v1, Vetor *v2) {
        int total = v1->q + v2->q;
            Vetor *resultado = iniciar(total);
                if (resultado == NULL) {
                            return NULL;
                }
                
                    int k = 0;
                        for (int i = 0; i < v1->q; i++) {
                                    resultado->item[k++] = v1->item[i];
                        }
                            for (int i = 0; i < v2->q; i++) {
                                        resultado->item[k++] = v2->item[i];
                            }
                                resultado->q = total;
                                    return resultado;
}

Vetor *subvetor(Vetor *v1, int ini, int fim) {
        if (ini < 0 || ini >= v1->q || fim < ini || fim >= v1->q) {
                    return NULL;
        }
        
            int tamanho = fim - ini + 1;
                Vetor *sub = iniciar(tamanho);
                    if (sub == NULL) {
                                return NULL;
                    }
                    
                        for (int i = ini; i <= fim; i++) {
                                    sub->item[i - ini] = v1->item[i];
                        }
                            sub->q = tamanho;
                                return sub;
}

void liberar_vetor(Vetor *v) {
        if (v != NULL) {
                    free(v->item);
                            free(v);
        }
}


#endif