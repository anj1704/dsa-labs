#include <stdio.h>
#include "pivot.h"
// L[] is the input array of length n
// kth smallest element is returned

int qselect(int L[], int n, int k)
{
    int pivot = 0;
    int lo = 0;
    int hi = n - 1;
    int pInd = part(L, lo, hi, pivot);
    
    if (k <= pInd)
        return qselect(L, pInd, k);
    else if (k > pInd + 1)
        return qselect(L + pInd + 1, n - pInd - 1, k - pInd - 1);
    else
        return L[pInd];
}

int qselectItr(int L[], int n, int k)
{
    int pivot = 0;
    int lo = 0;
    int hi = n - 1;

    int pInd = part(L, lo, hi, pivot);

    while (lo <= hi) {
        int pInd = part(L, lo, hi, lo); // Choose pivot as the leftmost element
        int lenLeft = pInd - lo + 1;

        if (k == lenLeft) {
            return L[pInd];
        } else if (k < lenLeft) {
            hi = pInd - 1; // Update the upper bound for the left subarray
        } else {
            k -= lenLeft; // Adjust k for the right subarray
            lo = pInd + 1; // Update the lower bound for the right subarray
        }
    }

    return -1; // If k is out of bounds
}

int pivot(int L[], int lo, int hi) 
{
    int n = hi - lo + 1;
    int k = n / 2; // Choose the median as the pivot
    int pivotEle = qselectItr(L + lo, n, k);
    for (int i = lo; i <= hi; i++)
    {
        if (L[i] == pivotEle) return i;
    }
    return lo + qselect(L + lo, n, k) - 1;
}
