#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pivot.h"

int pivot(int L[], int lo, int hi) 
{   
    srand(time(NULL));
    int r = rand() % (hi - lo) + lo;
    return r;
}
