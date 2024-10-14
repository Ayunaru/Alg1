#include "TADmatriz.h"

int main() {
    int l, c;
    scanf("%d %d", &l, &c);

    Matriz *mat = iniciar(l, c);

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &mat->arr[i][j]);
        }
    }

    int pl, pc;
    scanf("%d %d", &pl, &pc);

    int li, ci, lf, cf;
    scanf("%d %d %d %d", &li, &ci, &lf, &cf);

    int *linha = obter_linha(mat, pl);
    int *coluna = obter_coluna(mat, pc);
    Matriz *submat = obter_submat(mat, li, ci, lf, cf);

    for (int i = 0; i < c; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", linha[i]);
    }
    printf("\n");

    for (int i = 0; i < l; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", coluna[i]);
    }
    printf("\n");

    for (int i = 0; i < submat->l; i++) {
        for (int j = 0; j < submat->c; j++) {
            if (j > 0) {
                printf(" ");
            }
            printf("%d", submat->arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
