/*
- Ordenação por troca

- Estratégia de divisão e conquista (assunto de alg 2)

- Procedimento:
    - Definir o pivô r e as posições r = p e j = q
    - Enquando i <= j, trocar de posição os maiores elementos (da esquerda), com os menores (da direita) que o pivô
    - pivô = v[(esquerda+direita)/2]
    - quicksort(x, esquerda, j) -> ordena a parte do 0 até o pivô
    - quicksort(x, i, direita) -> ordena do pivô até o final

- No melhor caso e no caso médio, o algoritmo tem custo de tempo de O(n log2 n)

- Dependendo da forma em que o pivô é escolhido e da forma que o arranjo está organizado, o custo pode ser de O(n²) no pior caso

- É um método NÃO ESTÁVEL

*/

void troca(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}


void quicksort(int v[], int esq, int dir){
    int i = esq;
    int j = dir; 
    int pivo = v[(i + j) / 2];

    do{
        while (v[i] < pivo)
            i++;

        while (v[j] > pivo)
            j--;

	if (i <= j){
            troca(&v[i], &v[j]);
            i++;
            j--;
        }
    }while (i <= j);

    if (j > esq)
        quicksort(v, esq, j);
    if (i < dir)
        quicksort(v, i, dir);
}


// Outra implementação do quicksort
//*******************************************
static int particionar(int v[], int esq, int dir){
    int pivo = v[esq];
    int i = esq + 1;
    int j = dir;
    
    while (i <= j){
        while ((v[i] <= pivo) && (i <= dir))
            i++;
        
        while ((v[j] > pivo) && (j >= esq))
            j--;
        
        if (i < j)
            troca(&v[i], &v[j]);
    }
    
    troca(&v[esq], &v[j]);
    
    return j;
}

void quicksort2(int v[], int esq, int dir){
    if (esq < dir){
        int j = particionar(v, esq, dir);
        quicksort2(v, esq, j - 1);
        quicksort2(v, j + 1, dir);
    }
}