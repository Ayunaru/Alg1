#include <stdio.h>
#include <stdlib.h>

float soma(float i, float j, float k)
{
    if (i > j)
    {
        return 0;
    }
    return i + soma(i + k, j, k);
}

void imprime(float i, float j, float k) {
    if (i > j)
    {
    }
    else
    {
    printf("%.2f ", i);
    imprime(i + k, j, k);
    }
}

float serie(int n)
{
    if (n == 1)
    {
        return 2;
    }
    return ((1.0f + (n * n)) / n) + serie(n - 1);
}

int main()
{
    float i, j, k;
    int num;

    scanf("%f %f %f", &i, &j, &k);
    scanf("%d", &num);

    printf("%.4f\n", soma(i, j, k));

    imprime(i, j, k);
    printf("\n");

    printf("%.5f\n", serie(num));

    return 0;
}
