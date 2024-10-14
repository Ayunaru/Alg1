#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Lista Lista;

struct Lista{
    int item[MAX_SIZE];
    int tam;
};


Lista* criar_lista(){
    Lista *l = (Lista*) malloc(sizeof(Lista));

    l->tam = 0;

    return l;
}


int lista_vazia(Lista *l){
    if (l == NULL)
        return -1;
    else if (l->tam > 0)
        return 0;
    else
        return 1;
}


int lista_cheia(Lista *l){
    if (l == NULL)
        return -1;
    else if (l->tam < MAX_SIZE)
        return 0;
    else
        return 1;
}


int buscar(Lista *l, int chave){
    int i;

    if (!lista_vazia(l)){
        for (i = 0; i < l->tam; i++)
            if (l->item[i] == chave)
                return i;
    }

    return -1;
}

int inserir(Lista *l, int chave){
    if (!lista_cheia(l)){
        l->item[l->tam] = chave;

        l->tam++;

        return 1;
    }

 
    return 0;
}

int remover(Lista *l, int chave){
    int i, p = buscar(l, chave);

    if (p > -1){
        for (i = p; i < l->tam - 1; i++)
            l->item[i] = l->item[i + 1];

        l->tam--;

        return 1;
    }

    return 0;
}


void imprimir_lista(Lista *l){
    int i;

    if (!lista_vazia(l)){
        for (i = 0; i < l->tam; i++)
            printf("%d ", l->item[i]);

        printf("\n");
    }
}

void inverter(Lista *l){
    if(!lista_vazia(l)){
        int i, j, item;
        
        for(i=0, j = l->tam - 1; i<j; i++, j--){
            item = l->item[i];
            l->item[i] = l->item[j];
            l->item[j] = item;
        }
    }
}

int main() {
    Lista *l = criar_lista();
    int item = 0;
    
    while(item != -1){
        scanf("%d", &item);
        
        if(item!=-1)
            inserir(l, item);       
    }
    
    inverter(l);
    imprimir_lista(l);
    free(l);

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
