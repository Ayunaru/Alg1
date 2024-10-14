#include<stdio.h>
#include"lista.h"
int main()
{
    int num, tam, pos=0;
    Lista *vetlista = criar_lista();

    scanf("%d", &tam);

    for(int i=0; i < tam; i++)
    {
        scanf("%d", &num);
        inserir(vetlista, num);
    }

    int maior=vetlista->item[0];
    if (tam == 0)
    {
        return 0;
    }
    else
    {
        for (int j = 1; j < vetlista->tam; j++)
        {
            if (vetlista->item[j] > maior)
            {
                maior = vetlista->item[j];
                pos = j;
            }
        }

        printf("%d %d", pos, maior);
    }

    liberar_lista(vetlista);
    return 0;
}
