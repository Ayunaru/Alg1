#include <stdio.h>

int div(int n1, int n2)
{
    if (n1 < n2)
    {
        return n1;
    }

    return div(n1 - n2, n2);
}

int main()
{
    int n, i, n1, n2, res;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &n1, &n2);

        if (n2 == 0)
        {
            return -1;
        }

        else
        {
            res = div(n1, n2);
            printf("%d \n", res);
        }
    }

    return 0;
}
