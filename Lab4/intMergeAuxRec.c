#include <stdio.h>
#include "intMerge.h"
#include "intMergeAux.h"

void mergeAux(int L1[], int s1, int e1, int L2[], int s2, int e2, int L3[], int s3, int e3)
{
    if(s3 > e3) return;
    if (s2 > e2)
    {
        L3[s3] = L1[s1];
        mergeAux(L1, s1 + 1, e1, L2, s2, e2, L3, s3 + 1, e3);
    }
    else if (s1 > e1)
    {
        L3[s3] = L2[s2];
        mergeAux(L1, s1, e1, L2, s2 + 1, e2, L3, s3 + 1, e3);
    }
    else if (L1[s1] >= L2[s2])
    {

        L3[s3] = L2[s2];
        mergeAux(L1, s1, e1, L2, s2 + 1, e2, L3, s3 + 1, e3);

    }
    else if (L1[s1] < L2[s2])
    {
        L3[s3] = L1[s1];
        mergeAux(L1, s1 + 1, e1, L2, s2, e2, L3, s3 + 1, e3);
    }
    
    return;
}
