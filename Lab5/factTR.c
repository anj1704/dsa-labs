#include <stdio.h>

int factTR(int n, int acc)
{
    if (n == 0)
    {
        return acc;
    }
    else
    {
        return factTR(n - 1, n*acc);
    }
}