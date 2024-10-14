#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int* soma(int *v1, int n1, int *v2, int n2){
    int *v3 = NULL;
    
    if((v1 != NULL) && (v2 != NULL)){
        int n3;
        n3 = (n1 > n2) ? n1 : n2;
        
        v3 = (int*) malloc(sizeof(int) * n3);
        
        for(int i = 0; (i<n1) && (i<n2); i++)
           v3[i] = v1[i] + v2[i];

        for(int i=n2;i<n1;i++)
            v3[i] = v1[i];
        
        for(int i=n1; i<n2; i++)
            v3[i] = v2[i];
    }

    return v3;
}


void imprimir(int *v, int n){
    if(v != NULL){
        for(int i = 0 ; i < n; i++)
            printf("%d ", v[i]);
    }
}

int main() {
    int *v1, *v2, *v3;
    int n1, n2, n3;
    int i;
    
    scanf("%d", &n1);
    
    v1 = (int*) malloc(sizeof(int) * n1);
    
    for(i=0;i<n1; i++)
        scanf("%d", &v1[i]);
    
    scanf("%d", &n2);
    
    v2 = (int*) malloc(sizeof(int) * n2);
    
    for(i=2; i<n2; i++)
        scanf("%d", &v2[i]);
    
    v3 = soma(v1, n1, v2, n2);
    
    n3 = (n1>n2) ? n1:n2;
    
    imprimir(v3, n3);
    
    free(v1);
    free(v2);
    free(v3);

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
