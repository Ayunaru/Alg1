/*

- Os dados devem estar ordenados em um arranjo

- A busca começa NO MEIO da tabela
    - se a chave for igual ao valor que está no meio, então busca bem sucedida
    - Se menor, busca-se na metade inferior do arranjo
    - Se maior, busca-se na metade superior do arranjo

- Em cada passo, o tamanho do arranjo é dividido por 2

- Complexidade: O(log n)

- Vantagens:
    - Eficiência da busca
    - Fácil implementação

- Desvantagens:
    - O arranjo precisa estar ordenado
    - Exige o uso de um arranjo para armazenar os dados
    - Não pode ser um usado em lista encadeada

*/