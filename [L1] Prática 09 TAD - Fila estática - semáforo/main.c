#include "fila.h"

int main()
{
    Fila *E1 = criar_fila();
    Fila *E2 = criar_fila();
    Fila *E3 = criar_fila();
    Fila *R = criar_fila();

    int item;
    while (1)
    {
        scanf("%d", &item);
        if (item == -1)
            break;
        else
            enfileirar(E1, item);
    }
    while (1)
    {
        scanf("%d", &item);
        if (item == -1)
            break;
        else
            enfileirar(E2, item);
    }
    while (1)
    {
        scanf("%d", &item);
        if (item == -1)
            break;
        else
            enfileirar(E3, item);
    }

    Rodovia_Principal(E1, E2, E3, R);

    imprimir_fila(R);

    liberar_fila(E1);
    liberar_fila(E2);
    liberar_fila(E3);
    liberar_fila(R);

    return 0;
}
