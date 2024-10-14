#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

#define TAM_MAX 10

typedef struct Fila Fila;

struct Fila
{
    int item[TAM_MAX];
    int ini;
    int fim;
    int tam;
};

Fila *criar_fila()
{
    Fila *f = (Fila *)malloc(sizeof(Fila));

    f->ini = -1;
    f->fim = -1;
    f->tam = 0;

    return f;
}

int fila_cheia(Fila *f)
{

    if (f == NULL)
        return -1;
    else if (f->tam < TAM_MAX)
        return 0;
    else
        return 1;
}

int fila_vazia(Fila *f)
{
    if (f == NULL)
        return -1;
    else if (f->tam > 0)
        return 0;
    else
        return 1;
}

int enfileirar(Fila *f, int chave)
{
    if (f == NULL)
        f = criar_fila();

    if (!fila_cheia(f))
    {
        if (f->ini < 0)
            f->ini = 0;

        if (f->fim < TAM_MAX - 1)
            f->fim++;
        else
            f->fim = 0;

        f->item[f->fim] = chave;

        f->tam++;

        return 1;
    }

    return 0;
}

int desenfileirar(Fila *f)
{
    int item = INT_MIN;

    if (!fila_vazia(f))
    {
        item = f->item[f->ini];

        if (f->ini < TAM_MAX - 1)
            f->ini++;
        else
            f->ini = 0;

        f->tam--;

        if (f->tam == 0)
        {
            f->ini = -1;
            f->fim = -1;
        }
    }

    return item;
}

void imprimir_fila(Fila *f)
{
    Fila aux = *f;
    int item;

    while (!fila_vazia(&aux))
    {
        item = desenfileirar(&aux);

        printf("%d ", item);
    }

    printf("\n");
}

void liberar_fila(Fila *f)
{
    if (f != NULL)
        free(f);
}

int tamanho_fila(Fila *f)
{
    if (f != NULL)
        return f->tam;
    else
        return 0;
}

int verificar_inicio(Fila *f)
{
    if (!fila_vazia(f))
        return f->item[f->ini];
    else
        return INT_MIN;
}

int verificar_fim(Fila *f)
{
    if (!fila_vazia(f))
        return f->item[f->fim];
    else
        return INT_MIN;
}

void Rodovia_Principal(Fila *E1, Fila *E2, Fila *E3, Fila *R)
{
    int semaforo = 1;

    while (!fila_vazia(E1) || !fila_vazia(E2) || !fila_vazia(E3))
    {
        Fila *estrada = NULL;
        if (semaforo == 1)
        {
            estrada = E1;
        }
        else if (semaforo == 2)
        {
            estrada = E2;
        }
        else
        {
            estrada = E3;
        }

        int fila_carros = 0;

        if ((semaforo == 1 && estrada == E1) || (semaforo == 2 && estrada == E2) || (semaforo == 3 && estrada == E3))
        {
            while (fila_carros < 3 && !fila_vazia(estrada))
            {
                int carro = desenfileirar(estrada);
                enfileirar(R, carro);
                fila_carros++;
            }
        }

        if (fila_vazia(E1) && fila_vazia(E2) && fila_vazia(E3))
            break;

        if (semaforo == 1)
        {
            semaforo = 2;
        }
        else if (semaforo == 2)
        {
            semaforo = 3;
        }
        else
        {
            semaforo = 1;
        }
    }
}
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
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
