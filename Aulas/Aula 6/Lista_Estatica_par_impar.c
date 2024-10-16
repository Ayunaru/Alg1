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

int inserir_ordenado(Lista *l, int chave){
    int i;

    if (l == NULL)
        l = criar_lista();

    if (!lista_cheia(l)){

        l->tam++;

        for (i = l->tam - 1; (i > 0) && (chave < l->item[i - 1]); i--)
            l->item[i] = l->item[i - 1];

        l->item[i] = chave;

        return  1;
    }

    return 0;
}

static void concatenar(Lista *l1, Lista *l2){
    for(int i=0; i<l2->tam;i++)
        inserir(l1, l2->item[i]);
}

static int remover_ultimo(Lista *l1){
    int item = l1->item[l1->tam - 1];
    
    l1->tam--;
    
    return item;
}

void organizar(Lista **l){
    if(!lista_vazia(*l)){
        Lista *lp = criar_lista();
        Lista *li = criar_lista();
        int item;
        
        while(!lista_vazia(*l)){
            item=remover_ultimo(*l);
            
            if(item % 2 == 0)
                inserir_ordenado(lp, item);
            else
                inserir_ordenado(li, item);
        }
        
        /*concatenar(l, lp);
        concatenar(l, li);
        
        free(lp);
        free(li);*/
        
        concatenar(lp,li);
        free(*l);
        free(li);
        
        *l = lp;
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
    
    organizar(&l);
    
    imprimir_lista(l);
    
    free(l);
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
