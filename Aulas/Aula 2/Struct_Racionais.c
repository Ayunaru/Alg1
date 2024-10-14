#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    int num, den;
}rac;

rac divisao(rac r1, rac r2){
    rac r3;

    r3.num = r1.num * r2.den;
    r3.den = r1.den * r2.num;

    return r3;
}

int main(){
    rac r1, r2, r3;
    scanf("%d %d", &r1.num, &r1.den);
    scanf("%d %d", &r2.num, &r2.den);

    r3 = divisao(r1, r2);

    printf("%d %d", r3.num, r3.den);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
