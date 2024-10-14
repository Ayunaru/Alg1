#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char* decodifica(char *alfa, int cod[], int n){
    char *str = NULL;
    
    str = (char*) malloc(sizeof(char) * (n+1));
    
    for(int i=0; i<n; i++)
        str[i] = alfa[cod[i] - 1];
    
    return str;
}

int main() {
    char alfa[255];
    char *str = NULL;
    int n=0, x=0;
    int cod[1000];
    
    scanf("%s", alfa);
    
    while(x != -1){
        scanf("%d", &x);
        
        if(x != -1){
            cod[n] = x;
            n++;
        }
    }
    
    str = decodifica(alfa, cod, n);
    
    printf("%s", str);

    free(str);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
