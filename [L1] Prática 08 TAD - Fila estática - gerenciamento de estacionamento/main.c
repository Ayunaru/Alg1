#include "fila.h"

int main() {
    int item = 0, id;
    Fila *f = criar_fila();

    while(item != -1){
        scanf("%d", &item);
        if(item != -1)
            enfileirar(f,item);
    }

    scanf("%d", &id);
    estacionamento (f, id);
    liberar_fila(f);

    return 0;
}

