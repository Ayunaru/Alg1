/*
- Funcionamento:
    - Classifica um conjunto de registros, inserindo registros em um arquivo classificado
    - Consiste em inserir informações em um conjunto já ordenado

- Utilizado pelo jogadores de cartas

- Eficiente para pequenas entradas

- Deve ser utilizado quando o arquivo está "quase" ordenado

- Desvantagem:
    - Alto custo para movimentar os elementos

- Complexidade no pior caso é O(n²)
    - Pior caso é quando o vetor está ordenado em ordem decrescente
    - Melhor caso é quando o vetor já está ordenado, faz O(n)

*/

// Implementação do método insertion sort
void insertsort(int v[], int n){
	int i, j, x;

	for (i = 1; i < n; i++){
		x = v[i];   // armazena a posição que será comparada
		
		for (j = i - 1; (j >= 0) && (x  < v[j]); j--)   // compara x com os outros elementos anteriores, e o coloca entre o seu antecessor e sucessor
			v[j + 1] = v[j];    // troca o elemento da frente, com o que estava antes, quantas vezes for necessário até que j = 0, que seria o primeiro índice do vetor

		v[j + 1] = x;   // caso j < 0 e x >= v[j], então troca 
	}
}