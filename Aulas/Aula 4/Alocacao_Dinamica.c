#include<stdio.h>
#include<stdlib.h> //malloc, calloc, realloc, free

//Notes 
/*
- Aloca e libera espaco no espaco de memoria "Heap"
- strcat?
*/

int main(){
    //malloc:
    printf("Malloc\n");
    int *p = (int*)malloc (sizeof(int));
    int n = 6; //tamanho do vetor
    int *v = (int*)malloc (sizeof(int) * n);

    for (int i = 0; i < n; i++){
        v[i] = i + 1;
        printf("%d ", v[i]);    
    }

    *p = 2;
    printf("\n%d", *p);

    printf("\n\nCalloc\n");

    //calloc:
    int *p1 = (int*) calloc(1, sizeof(int));
    int n1 = 6;
    int *v1 = (int*)calloc (1, sizeof(int) * n);

    for (int i = 0; i < n1; i++){
        v1[i] = i + 1;
        printf("%d ", v[i]);    
    }

    *p1 = 10;
    printf("\n%d", *p1);

    free(p1);
    free(v1);

    //realloc
    printf("\n\nRealloc\n");

    v = realloc (v, n + sizeof(int));
    v[n] = n*n;

    //free
    free(p);
    free(v);

    return 0;   
}