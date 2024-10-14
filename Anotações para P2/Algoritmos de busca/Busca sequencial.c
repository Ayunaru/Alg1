#include <stdio.h>
#include <stdlib.h>

// Forma mais simples de busca
// Aplicável em uma tabela organizada como um vetor ou uma lista encadeada
// Percorre-se registro por registro em busca da chave

// Complexidade no pior caso -> O(n)
// Melhor caso é quando a chave é encontrada na primeira comparação -> O(1)

/*Para aumentar a eficiência a tabela é reordenada continuamente de modo que fique de mais fácil acesso os registros já encontrados, assim temos 2 métodos:

    - Mover-Para-Frente -> quando achar a chave ela é mandada para o início da lista
        Desvantagens:
            - uma única recuperação não implica que a chave será frequentemente recuperada
            - métodos mais custoso para arranjos em comparação com listas encadeadas
        Vantagem principal:
            - melhores resultados para quantidades pequenas e média de buscas

    - Transposição -> quando a chave é encontrada, ela é imediatamente trocada com o item anterior
        - mais vantajoso para grande quantidade de buscas
*/

int busca_sequencial(int x, int v[], int n){
	int i;

	for (i = 0; i < n; i++)
		if (x == v[i])
			return i;

	return -1;
}

int busca_sequencial2(int x, int v[], int n){
	int i;
	v[n] = x; // garante que x seja encontrado

	// aqui, um teste a menos é realizado em comparação com
	// o algoritmo implementado anteriormente
	for (i = 0; x != v[i]; i++);

	if (i < n)
		return i;
	else
		return -1;
}

// O vetor deve estar ordenado
int busca_sequencial3(int x, int v[], int n){
	int i;

	for (i = 0; i < n && x > v[i]; i++);

	if ((i < n) && (v[i] == x))
		return i;
	else
		return -1;
}


int busca_sequencial4(int x, int v[], int n){
	int i, j;

	for (i = 0, j = n - 1; (i < j) && (x > v[i])
            	&& (x < v[j]); i++, j--);

	if (v[i] == x)
		return i;
    	else  if (v[j] == x)
        	return j;
	else
		return -1;
}

//Mover-Para-Frente:
int mover_para_frente(int x, int v[], int n){
	int i, aux;

	for (i = 0; i < n && x != v[i]; i++);

	if (i < n){
		aux = v[i];

       	// Os elementos devem ser deslocados para para que o registro
      		// com a chave x possa ser colocado na primeira posição
        	for (i; i > 0; i--)
			v[i] = v[i - 1];

		// i é igual a zero
		v[i] = aux;

		return 0;
	}

	return -1;
}


// Cada vez o registro com chave x é recuperado, o mesmo é deslocado para uma posição anterior
// Por exemplo, se x estiver na posição 5, será deslocado para a posição 4
int transposicao(int x, int v[], int n){
	int i, aux;

	for (i = 0; i < n && x != v[i]; i++);

	// Verificar se o item foi encontrado e se ele já não está na primeira posição
	if (i < n){
		if (i > 0){
			aux = v[i];

			v[i] = v[i - 1];
			v[i - 1] = aux;

			i--;
		}

		return i;
	}

	return -1;
}