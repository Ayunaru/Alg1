#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100 // tamanho m�ximo da lista


// Estrutura para uma lista est�tica
struct Lista{
    int item[MAX_SIZE]; // A lista pode ser de qualquer tipo. Nesse caso, � uma lista de int, mas tamb�m pode ser de float, char, string, struct, etc.
    int tam; // quantidade de elementos preenchidos na lista
};

typedef struct Lista Lista; // Renomea��o da estrutura struct Lista

/**----------------------------------------
 *  Declara��o de fun��es da TAD:
 *-----------------------------------------*/

// Fun��o para criar uma lista est�tica
Lista* criar_lista();

// Retorna 1 se a lista est� vazia ou 0, caso contr�rio
int lista_vazia(Lista *l);

// Retorna 1 se a lista est� cheia ou 0, caso contr�rio
int lista_cheia(Lista *l);

// Procura a posi��o de um item com a chave e retorna a sua respectiva posi��o
// Caso o item n�o seja encontrado, � retornado -1
int buscar(Lista *l, int chave);

// Um item � inserido no final da lista caso ela n�o estiver cheia.
// A fun��o retorna 1 se a opera��o for bem sucedida ou 0, caso contr�rio
int inserir(Lista *l, int chave);

// O item procurado e removido da lista caso ela. Para isso, a lista n�o deve estar vazia e o item
// deve existir.
// A fun��o retorna 1 se a opera��o for bem sucedida ou 0, caso contr�rio
int remover(Lista *l, int chave);

// Imprime o conte�do da lista
void imprimir_lista(Lista *l);

// Libera a lista
// Retorna 1 se a opera��o for bem-sucedida ou 0, caso contr�rio
int liberar_lista(Lista *l);

// Resolu��o de exerc�cio: concatena��o
// Retorna uma lista resultante da concatena��o
Lista* concatenar(Lista *l1, Lista *l2);

// Um item � inserido de forma ordenada lista caso ela n�o estiver cheia.
// A fun��o retorna 1 se a opera��o for bem sucedida ou 0, caso contr�rio
int inserir_ordenado(Lista *l, int chave);

/**----------------------------------------------
 * Implementa��o das fun��es da TAD:
 * ----------------------------------------------*/
 // Fun��o para criar uma lista est�tica
Lista* criar_lista(){
    Lista *l = (Lista*) malloc(sizeof(Lista));

    // Ao iniciar a lista, a mesma estar� "vazia"
    l->tam = 0;

    return l;
}

// Retorna 1 se a lista est� vazia ou 0, caso contr�rio
int lista_vazia(Lista *l){
    return (l == NULL) || (l->tam == 0);
}

// Retorna 1 se a lista est� cheia ou 0, caso contr�rio
int lista_cheia(Lista *l){
    return (l != NULL) && (l->tam == MAX_SIZE);
}

// Procura a posi��o de um item com a chave e retorna a sua respectiva posi��o
// Caso o item n�o seja encontrado, � retornado -1
int buscar(Lista *l, int chave){
    int i;

    if (!lista_vazia(l)){
        // Procurar na parte "n�o vazia" da lista
        for (i = 0; i < l->tam; i++)
            if (l->item[i] == chave)
                return i;
    }

    // Se chegou aqui � porque a lista est� vazia ou o item n�o foi encontrado
    return -1;
}

// Um item � inserido no final da lista caso ela n�o estiver cheia.
// A fun��o retorna 1 se a opera��o for bem sucedida ou 0, caso contr�rio
int inserir(Lista *l, int chave){
    // Se a lista for nula, podemos alocar um espa�o para ela, j� que
    // pretendemos fazer uma inser��o nela
    if (l == NULL)
        l = criar_lista();

    if (!lista_cheia(l)){
        // O item � adicionado no final da lista
        l->item[l->tam] = chave;

        // Se foi adicionado um elemento, ent�o a lista cresceu
        l->tam++; // l->tam = l->tam + 1; ou l->tam += 1;

        // A inser��o foi bem-sucedida
        return 1;
    }

    // Se chegou aqui � porque a lista estava cheia (ou nula)
    return 0;
}

// O item procurado e removido da lista caso ela. Para isso, a lista n�o deve estar vazia e o item
// deve existir.
// A fun��o retorna 1 se a opera��o for bem sucedida ou 0, caso contr�rio
int remover(Lista *l, int chave){
    int i, p = buscar(l, chave);

    // A chave foi encontrada
    if (p > -1){
        for (i = p; i < l->tam - 1; i++)
            // Deslocamento de itens da lista para ocupar o espa�o do item removido
            // Se o item a ser removido for o �ltimo, o comando abaixo n�o � executado
            l->item[i] = l->item[i + 1];

        // Se foi removido um elemento, ent�o a lista diminuiu
        l->tam--; // l->tam = l->tam - 1; ou l->tam -= 1;

        // Remo��o bem-sucedida
        return 1;
    }

    return 0;
}

// Imprime o conte�do da lista
void imprimir_lista(Lista *l){
    int i;

    if (!lista_vazia(l)){
        for (i = 0; i < l->tam; i++)
            printf("%d ", l->item[i]);

        printf("\n");
    }
}

// Libera a lista
// Retorna 1 se a opera��o for bem-sucedida ou 0, caso contr�rio
int liberar_lista(Lista *l){
    if (l != NULL){
        free(l);

        return 1;
    }

    return 0;
}


// Resolu��o de exerc�cio: concatena��o
// Retorna uma lista resultante da concatena��o
Lista* concatenar(Lista *l1, Lista *l2){
    Lista *l3 = NULL;
    int i;

    // Verificar se uma das listas est� vazia
    if (l1 == NULL)
        l3 = l2;
    else if (l2 == NULL)
        l3 = l1;
    else if (l1->tam + l2->tam <= MAX_SIZE){
        l3 = criar_lista();

        // Utilizando a fun��o inserir para incluir elementos das listas,
        // fornecidas como par�metros, na lista l3
        for (i = 0; i <  l1->tam; i++)
            inserir(l3, l1->item[i]);

        for (i = 0; i <  l2->tam; i++)
            inserir(l3, l2->item[i]);
    }

    return l3;
}


// Um item � inserido de forma ordenada lista caso ela n�o estiver cheia.
// A fun��o retorna 1 se a opera��o for bem sucedida ou 0, caso contr�rio
int inserir_ordenado(Lista *l, int chave){
    int i;

    // Se a lista for nula, podemos alocar um espa�o para ela, j� que
    // pretendemos fazer uma inser��o nela
    if (l == NULL)
        l = criar_lista();

    if (!lista_cheia(l)){
        // Primeiramente, temos que sinalizar que a lista cresceu, j� que
        // a inser��o � feita de forma ordenada e precisaremos de fazer
        // deslocamento de elementos
        l->tam++;

	// Antes de fazermos a inser��o, temos que deslocar elementos at�
	// encontrarmos a posi��o adequada para o novo item.
	// Por exemplo, o pior cen�rio � quando o elemento a ser inserido
	// � o menor de todos, sendo necess�rio deslocar tam - 1 itens para
	// podermos colocar o novo item na posi��o "0" (zero)
        for (i = l->tam - 1; (i > 0) && (chave < l->item[i - 1]); i--)
            l->item[i] = l->item[i - 1];

        l->item[i] = chave;

        return  1;
    }

    return 0;
}
