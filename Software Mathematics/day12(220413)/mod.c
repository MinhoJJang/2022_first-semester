#include <stdio.h>

int main()
{

    int N;
    scanf("%d", &N);

    if (N % 2 == 0 && N > 0)
    {
        printf("even integer\n");
        printf("postive integer\n");
    }
    else if (N >= 0)
    {
        printf("postive integer\n");
    }
    else
    {
        printf("integer\n");
    }
}