#include "pilha.h"

int main()
{
    Pilha *p1 = criar_pilha();
    Pilha *p2 = criar_pilha();
    int item;
    while (1)
    {
        scanf("%d", &item);
        if (item == -1)
            break;
        else
            empilhar(p1, item);
    }

    while (1)
    {
        scanf("%d", &item);
        if (item == -1)
            break;
        else
            empilhar(p2, item);
    }

    Pilha *p3 = concatenar_pilhas(p1, p2);

    imprimir_pilha(p3);

    liberar_pilha(p3);
    liberar_pilha(p2);
    liberar_pilha(p1);

    return 0;
}
