#include <stdio.h>
#include <stdlib.h>
#include "pivot.h"
#include <limits.h>
#include <time.h>

// L[] is the input array of length n
// kth smallest element is returned
int select(int L[], int n, int k)
{   
    if (k == 0) return L[0];
    
    if (n <= 5)
    {
        for (int i = 1; i < n; i++)
            for (int j = i-1; j >= 0; j--)
                if (L[j] > L[j+1])
                    swap(L, j, j+1);
                else
                    break;
        return L[k-1];
    }

    // partition L into subsets of five elements each
    //     (there will be n/5 subsets total).
    int numGroups;
    if (n % 5 == 0)
        numGroups = n/5;
    else
        numGroups = n/5 + 1;
    
    int medians[numGroups];
    for (int i = 0; i < numGroups; i++)
    {
        medians[i] = select(L + i*5, min(5, n - i*5), min(5, n - i*5)/2);
    }
    
    int M = select(medians, numGroups, (numGroups+1)/2);
    
    // Partition array into two halves, L1, {M} and L2, such that
    // L1 contains elements <= M, {M} contains one instance of M and L2 contains all elements > M
    
    int mInd;
    for (int i = 0; i < n; i++)
    {
        if (L[i] == M)
        {
            mInd = i;
            break;
        }
    }

//     printf(" %d %d\n", M, mInd);
//     return mInd;
// }
    int pInd = part(L, 0, n-1, mInd);
    
    if (k <= pInd)
        return select(L, pInd, k);
    else if (k > pInd + 1)
        return select(L + pInd + 1, n - pInd - 1, k - pInd - 1);
    else 
        return L[pInd];
}

int pivot(int L[], int lo, int hi) 
{
    int n = hi - lo + 1;
    int k = n / 2; // Choose the median as the pivot
    int pivotEle = select(L + lo, n, k);
    for (int i = lo; i <= hi; i++)
    {
        if (L[i] == pivotEle) return i;
    }
    return lo + select(L + lo, n, k) - 1;
}

// int select(int L[], int lo, int hi) 
// {
//     int n = hi - lo;
//     int k = n / 2; // Choose the median as the select
//     int selectEle = select(L + lo, n, k);
//     for (int i = lo; i <= hi; i++)
//     {
//         if (L[i] == selectEle) return i;
//     }
//     return lo + select(L + lo, n, k) - 1;
// }

// int partition(int arr[], int low, int high) {
//     int pivot = arr[high];
//     int i = low - 1;

//     for (int j = low; j <= high - 1; j++) {
//         if (arr[j] < pivot) {
//             i++;
//             swap(arr, i, j);
//         }
//     }
//     swap(arr, i+1, high);
//     return (i + 1);
// }

// int findMedian(int arr[], int low, int length) {
//     int high = low + length - 1;
//     int median = low + (length / 2);
//     for (int i = low; i <= high; i++) {
//         for (int j = i; j <= high; j++) {
//             if (arr[j] < arr[median]) {
//                 swap(arr, j, median);
//                 median = j;
//             }
//         }
//     }
//     return median;
// }

// int pivot(int Ls[], int lo, int hi) {
//     int length = hi - lo;
//     if (length < 5) {
//         return findMedian(Ls, lo, length);
//     }

//     int numGroups = (length + 4) / 5;
//     int medians[numGroups];
//     for (int i = 0; i < numGroups; i++) {
//         int start = lo + i * 5;
//         int groupLength = (start + 5 < lo + length) ? 5 : (lo + length - start);
//         medians[i] = findMedian(Ls, start, groupLength) - start;
//     }

//     return findMedian(medians, 0, numGroups);
// }

// int main() {
//     int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     int medianIndex = pivot(arr, 0, 15);
//     printf("Index of the median of medians: %d\n", medianIndex);
//     printf("Median of medians: %d\n", arr[medianIndex]);

//     return 0;
// }

// int main()
// {
//     // testing with a fixed length

//     srand(time(NULL));
//     int n = 15;
//     int *arr = (int*) malloc(sizeof(int)*n);
//     for (int i = 0; i < n; i++)
//     {
//        if (i%2 == 0) arr[i] = rand() % 100;
//        else arr[i] = rand() % 50;
//     }

//     printArray(arr, n);
//     int M = pivot(arr, 0, n - 1);
//     printf("The pivot index is %d\n", M);
//     printArray(arr, n);

//     return 0;
// }
