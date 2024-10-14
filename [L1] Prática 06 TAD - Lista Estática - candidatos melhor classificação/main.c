#include "lista.h"
int main() {
    int tam = 0;
    char nome[20];
    float nota = 0;
    int idade = 0;
    Tipo_REG reg;

    Lista *entrada = criar_lista();

    scanf("%d", &tam);

    for (int i = 0; i < tam; i++) {
        scanf("%s %f %d", nome, &nota, &idade);
        strcpy(reg.nome, nome);
        reg.nota = nota;
        reg.idade = idade;

        inserir(entrada, reg);
    }
    ordenar_lista(entrada);
    printf("\n");
    imprimir_lista(entrada);

    liberar_lista(entrada);

    return 0;
}
