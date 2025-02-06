#include <stdio.h>
#include <stdlib.h>
#include "pivot.h"

int pivot(int Ls[], int lo, int hi)
{
    int left = lo;
    int center = (lo + hi)/2;
    int right = hi - 1;

    // finding the median
    if (Ls[left] >= Ls[right] && Ls[left] >= Ls[center])
    {
        if (Ls[right] >= Ls[center]) return right;
        else return center;
    }
    else if (Ls[right] >= Ls[left] && Ls[right] >= Ls[center])
    {
        if (Ls[left] >= Ls[center]) return left;
        else return center;
    }
    else if (Ls[center] >= Ls[right] && Ls[center] >= Ls[left])
    {
        if (Ls[right] >= Ls[left]) return right;
        else return left;
    }

    return center; // random
}
