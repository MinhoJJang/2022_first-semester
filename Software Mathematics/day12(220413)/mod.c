#include <stdio.h>

/*
In C programming, implement the following condition and upload it.
Reads an integer N and do the following:
If N is positive, print “positive integer”
If N is positive and even, print “even integer”
Otherwise “integer”
*/

int main()
{

    int N;
    scanf("%d", &N);

    if (N % 2 == 0 && N > 0)
    {
        printf("even integer\n");
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