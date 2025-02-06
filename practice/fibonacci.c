#include <stdio.h>

int fib(int n)
{
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;
    int sum = fib(n - 1) + fib(n - 2);
    return sum;
}

int trfib(int n, int a, int b)
{
    if (n == 0) return a;
    if (n == 1) return b;
    return trfib(n - 1, b, a + b);
}


int main()
{
    for (int i = 1; i < 10; i++)
    {
        printf("%d\t", fib(i));
    }
    printf("\n");
    for (int i = 1; i < 10; i++)
    {
        printf("%d\t", trfib(i, 0, 1));
    }
    printf("\n");
}
