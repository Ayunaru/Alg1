#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void frac(float n, int* in, float* fr){
    *in = n;
    *fr = n - (float) *in;
}

int main(){
    int m, in;
    float n, fr;

    scanf("%d", &m);

    while (m > 0)
    {
        scanf("%f", &n);
        frac(n,&in, &fr);
        printf("N=%.3f I=%d F=%.3f\n", n, in, fr);
        m--;
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
