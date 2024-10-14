#include <stdio.h>
#include <stdlib.h>

/*
-> Possui uma tabela auxiliar, chamada tabela de índices


Vantagem:
    - os itens na tabelas poderão ser examinados sequencialmente sem que todos os registros precisem ser acessados

Desvantagens:
    - a tabela PRECISA estar ORDENADA
    - exige espaço adicional para armazenas as tabelas de índices   
    
Para montar a tabela de índices:
    - Ordene (se não estiver ordenada)
    - n/m (n é tamanho da tabela e m o tamanho do índice)
    - Montar os índices -> 0*(n/m); 1*(n/m); 2*(n/m) ...
    - Cada elemento do índice representa n/m elementos da tabela

Complexidade:
    -> O(max(m,n/m)) ou O(m + n/m)

*/
