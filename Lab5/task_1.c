#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int fibonacciRecursive(int n)
{
    if (n == 1) return 1;
    if (n == 2) return 1;

    return fibonacciRecursive(n-1) + fibonacciRecursive(n-2);
}

int fibonacciIterative(int n)
{
    int a = 1;
    int b = 1;
    int c = 1;
    for (int i = 1; i < n-1; i++)
    {   
        c = a + b;
        a = b;
        b = c;
    }

    return c;
}

int main()
{
    struct timeval t1, t2;
    double time_taken;
    int n = 10000;

    gettimeofday(&t1, NULL);
    fibonacciIterative(n);
    gettimeofday(&t2, NULL);
    
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("Iterative fibonacci number finding took %f seconds to execute\n", time_taken);
    
    gettimeofday(&t1, NULL);
    fibonacciRecursive(n);
    gettimeofday(&t2, NULL);
    
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("Recursive fibonacci number finding took %f seconds to execute\n", time_taken);
    
    return 0;
}