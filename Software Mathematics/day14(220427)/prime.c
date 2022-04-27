#include <stdio.h>
#include <math.h>

#define PRIME 1
#define NOTPRIME 0

int findPrimeNumber(int N)
{
    int flag = PRIME;
    int squareRoot = sqrt(N);

    if (N == 1)
    {
        flag = NOTPRIME;
        return flag;
    }

    if (N == 2)
    {
        return flag;
    }

    for (int i = 2; i <= squareRoot; i++)
    {
        if (K % i == 0)
        {
            flag = NOTPRIME;
            break;
        }
    }

    return flag;
}

int main()
{
    int N;
    scanf("%d", &N);
    if (findPrimeNumber(N) == PRIME)
    {
        printf("%d is Prime Number", N);
    }
    else
    {
        printf("%d is Not Prime Number", N);
    }
    return 0;
}