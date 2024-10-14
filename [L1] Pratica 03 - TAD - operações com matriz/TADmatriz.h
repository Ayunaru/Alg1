#ifndef TADMATRIZ_H
#define TADMATRIZ_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int **arr;
    int l;
    int c;
} Matriz;

Matriz *iniciar(int l, int c) {
    Matriz *m = (Matriz *)malloc(sizeof(Matriz));
    m->l = l;
    m->c = c;
    m->arr = (int **)malloc(l * sizeof(int *));
    for (int i = 0; i < l; i++) {
        m->arr[i] = (int *)malloc(c * sizeof(int));
    }
    return m;
}

void alterar(Matriz *m, int x, int i, int j) {
    if (i >= 0 && i < m->l && j >= 0 && j < m->c) {
        m->arr[i][j] = x;
    }
}

int *obter_linha(Matriz *m, int i) {
    if (i >= 0 && i < m->l) {
        return m->arr[i];
    } else {
        return NULL;
    }
}

int *obter_coluna(Matriz *m, int i) {
    if (i >= 0 && i < m->c) {
        int *coluna = (int *)malloc(m->l * sizeof(int));
        for (int j = 0; j < m->l; j++) {
            coluna[j] = m->arr[j][i];
        }
        return coluna;
    } else {
        return NULL;
    }
}

Matriz *obter_submat(Matriz *m, int li, int ci, int lf, int cf) {
    if (li >= 0 && li < m->l && ci >= 0 && ci < m->c && lf >= 0 && lf < m->l && cf >= 0 && cf < m->c && li <= lf && ci <= cf) {
        Matriz *submat = iniciar(lf - li + 1, cf - ci + 1);
        for (int i = li; i <= lf; i++) {
            for (int j = ci; j <= cf; j++) {
                submat->arr[i - li][j - ci] = m->arr[i][j];
            }
        }
        return submat;
    } else {
        return NULL;
    }
}
#endif
