#include "TADvetor.h"
int main() {
        int n, valor, ini, fim;
        
            scanf("%d", &n);
                Vetor *v1 = iniciar(n);
                    if (v1 == NULL) {
                                return 1;
                    }
                        for (int i = 0; i < n; i++) {
                                    scanf("%d", &valor);
                                            inserir(v1, valor);
                        }
                        
                            scanf("%d", &n);
                                Vetor *v2 = iniciar(n);
                                    if (v2 == NULL) {
                                                liberar_vetor(v1);
                                                        return 1;
                                    }
                                        for (int i = 0; i < n; i++) {
                                                    scanf("%d", &valor);
                                                            inserir(v2, valor);
                                        }
                                        
                                            scanf("%d %d", &ini, &fim);
                                            
                                                Vetor *resultado_intercalacao = intercalar(v1, v2);
                                                    Vetor *resultado_concatenacao = concatenar(v1, v2);
                                                        Vetor *sub = subvetor(v1, ini, fim);
                                                        
                                                            char *msg_limite_invalido = NULL;
                                                            
                                                                if (resultado_intercalacao == NULL || resultado_concatenacao == NULL || sub == NULL) {
                                                                            msg_limite_invalido = "limite invalido!";
                                                                                }
                                                                                
                                                                                    if (resultado_intercalacao != NULL) {
                                                                                                for (int i = 0; i < resultado_intercalacao->q; i++) {
                                                                                                                printf("%d ", resultado_intercalacao->item[i]);
                                                                                                                        }
                                                                                                                                printf("\n");
                                                                                                                                    }
                                                                                                                                    
                                                                                                                                        if (resultado_concatenacao != NULL) {
                                                                                                                                                    for (int i = 0; i < resultado_concatenacao->q; i++) {
                                                                                                                                                                    printf("%d ", resultado_concatenacao->item[i]);
                                                                                                                                                                            }
                                                                                                                                                                                    printf("\n");
                                                                                                                                                                                        }
                                                                                                                                                                                        
                                                                                                                                                                                            if (sub != NULL) {
                                                                                                                                                                                                        for (int i = 0; i < sub->q; i++) {
                                                                                                                                                                                                                        printf("%d ", sub->item[i]);
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                        printf("\n");
                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                            
                                                                                                                                                                                                                                                printf("%s", msg_limite_invalido);
                                                                                                                                                                                                                                                
                                                                                                                                                                                                                                                    liberar_vetor(v1);
                                                                                                                                                                                                                                                        liberar_vetor(v2);
                                                                                                                                                                                                                                                            liberar_vetor(resultado_intercalacao);
                                                                                                                                                                                                                                                                liberar_vetor(resultado_concatenacao);
                                                                                                                                                                                                                                                                    liberar_vetor(sub);
                                                                                                                                                                                                                                                                    
                                                                                                                                                                                                                                                                        return 0;
                                                                                                                                                                                                                                                                        }