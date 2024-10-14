#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void troca(int *a, int *b){
    if (*a < *b){
        int aux = *a;
        *a = *b;
        *b = aux;
    }
}
int main()
{
    int n, a, b;
    
    scanf("%d", &n);

    while (n > 0){
        scanf("%d %d", &a, &b);
        troca(&a, &b);
        printf("A=%d B=%d\n", a, b);
        n--;
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
