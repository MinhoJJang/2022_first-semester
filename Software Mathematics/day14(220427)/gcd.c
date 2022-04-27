#include <stdio.h>

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int main()
{
    int A, B;
    scanf("%d %d", &A, &B);

    printf("gcd(a,b) is = %d", gcd(A, B));
    return 0;
}