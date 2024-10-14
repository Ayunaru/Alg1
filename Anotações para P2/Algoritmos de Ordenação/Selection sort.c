/*
- Funcionamento:
    - Escolhe o MAIOR ou MENOR elemento do conjunto A CADA ITERAÇÃO e o coloca em sua devida posição
    - Pega o maior ou menor elemento -> troca com o último elemento, ou primeiro, depende -> faz a mesma coisa para os n-1, n-2 ... elementos

- Complexidade no Pior caso O(n²)
    - Pior caso é quando o vetor está ordenado em ordem decrescente

- É um método ESTÁVEL

- Rápido para ordenação de vetores pequenos

- Um dos mais lentos para grandes vetores

*/

// Implementação do selection sort
void selectsort(int v[], int n){
	int i, j, p, aux;
	
	for (i = n - 1; i >= 1;  i--){  // Nesse caso começa no último elemento, e ordena o maior elemento
		p = i;  // Armazena o maior elemento em uma variável pra poder comparar, e depois faz isso para os valores decrementados n-1, n-2 ... n-k
	
		for (j = 0; j < i; j++) // Compara os elementos do vetor com o último elemento
			if (v[j] > v[p])    // vê se algum elemento do vetor é maior que o último 
				p = j;  // se for maior, p recebe a posição desse elemento
		
		if (p != i){    // se p != i, quer dizer que o elemento não está na posição correta, então troca
			aux = v[i]; // 21, 22 e 23 faz a troca do elemento
			v[i] = v[p];
			v[p] = aux;
		}
	}
}

// Segunda implementação do selection sort
// Provavelmente a forma ordenação simples mais implementada
void selectsort2(int v[], int n){   // Mesma coisa do código anterior, mas começa do menor elemento (FORMA MAIS IMPLEMENTADA)
	int i, j, p, aux;
	
	for (i = 0; i < n - 1;  i++){   // Começa no primeiro elemento, para ordenar o menor elemento nos primeiros índices
		p = i;
	
		for (j = i + 1; j < n; j++) // verifica o resto do vetor, para ver se tem algum valor que é menor que o primeiro elemento
			if (v[j] < v[p])    // se for menor, troca o pivô
				p = j;
		
		if (p != i){
			aux = v[i];
			v[i] = v[p];
			v[p] = aux;
		}
	}
}
