/*
- Ordenção por troca;

- Em cada comparação pode haver troca de posição entre os itens

- O arquivo é percorrido sequencialmente várias vezes
    - Cada elemento é comparado com seu sucessor

- Um dos métodos menos eficientes

- ESTÁVEL (Significa que não realiza troca entre elementos iguais)

- É vantajoso em conjuntos pré-ordenados

- número de operações máximas total = (n² - n)/2

- Complexidade no pior caso: O(n²)
    - O pior caso é quando o vetor está ordenado ao contrário, em ordem decrescente
*/

#include <stdio.h>
#include <stdlib.h>

//Implementação ingênua do bubblesort
void bubblesort(int v[], int n){    // arranjo / tamanho do arranjo
	int i, j, x;

	for (i = 0; i < n - 1; i++) // determina as vezes que todo o vetor foi percorrido, se é a primeira, segunda, etc vez que o código percorre o vetor
		for (j = 0; j < n - i - 1; j++) // determina a posição dos itens no vetor, por isso v[j]
			if (v[j] > v[j + 1]){ // compara a chave a n com a sua sucessora n+1
				x = v[j];   // as linhas 26, 27 e 28 fazem a troca da posição das chaves
				v[j] = v[j + 1];
				v[j + 1] = x;
			}
}


// Melhoria do bubblesort, faz com que não seja feito nada se o vetor já estiver ordenado
void bubblesort_V2(int v[], int n){
	int i, j, x, troca = 1;

	for (i = 0; (i < n - 1) && (troca); i++){   // variável troca garante que se o vetor já estiver ordenado, o código não faz nada
		troca = 0;  // primeira vez que o código roda, sempre entra no primeiro for para verificar se está ordenado

		for (j = 0; j < n - i - 1; j++)
			if (v[j] > v[j + 1]){
				x = v[j];
				v[j] = v[j + 1];
				v[j + 1] = x;
				troca = 1;  // se trocou algum valor, quer dizer que não estava ordenado, logo troca = 1, e a condição do primeiro for fica correta
			}
	}
}

// TESTE USANDO UMA FUNÇÃO PARA TROCAR OS VALORES (NOTA: FUNCIONA, MAS PRECISA PASSAR O ENDEREÇO NA FUNÇÃO TROCA (&))
void trocanum(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

void bubblesortTESTE(int v[], int n){    // arranjo / tamanho do arranjo
	int i, j, x;

	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (v[j] > v[j + 1])
                trocanum(&v[j], &v[j+1]);
}

void imprime_vetor(int tam, int vet[]){
    for(int i = 0; i < tam; i++)
        printf("%d ", vet[i]);
}

int main() {
    int tam, i = 0;
    scanf("%d", &tam);
    
    int* v; 
    v = (int*)malloc(sizeof(int) * tam);
    
    while(i < tam){
        scanf("%d", &v[i]);
        i++;
    }

    bubblesortTESTE(v, tam);
    imprime_vetor(tam, v);

    free(v);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
