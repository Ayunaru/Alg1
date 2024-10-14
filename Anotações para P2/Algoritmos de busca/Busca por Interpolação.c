/* 

- É mais eficiente que a busca binária se as chaves estiverem uniformemente distribuídas
    - Com as chaves uniformemente distribuídas, x estará aproximadamente na posição:
        meio = ini + (fim-ini) * ((x-v[ini]) / (v[fim] - v[ini]))

    - E a complexidade nesse caso será de O(log(log n))

- Caso as chaves não estiverem uniformemente distribuídas, a busca por interpolação pode ser tão ruim quanto a busca sequencial, tendo custo de O(n)

*/