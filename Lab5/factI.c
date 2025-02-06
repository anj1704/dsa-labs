#include <stdio.h>

int factI(int n)
{
    int acc = 1;
    while (n > 0)
    {
        acc *= n;
        n -= 1;
    }

    return acc;
}

