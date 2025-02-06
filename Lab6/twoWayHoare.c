#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int arr[], int low, int high)
{   
    // XOR SWAP 
    // X := Y XOR X; // XOR the values and store the result in X
    // Y := X XOR Y; // XOR the values and store the result in Y
    // X := Y XOR X; // XOR the values and store the result in X

    // arr[low] = arr[high] ^ arr[low];
    // arr[high] = arr[high] ^ arr[low];
    // arr[low] = arr[low] ^ arr[high];

    int temp = arr[low];
    arr[low] = arr[high];
    arr[high] = temp;
}

// Ls[lo..hi] is the input array; Ls[pInd] is the pivot
int part(int Ls[], int lo, int hi, int pInd)
{
    swap(Ls, pInd, lo);

    int pivPos, lt, rt, pv;
    lt = lo + 1;
    rt = hi;
    pv = Ls[lo];
    
    while (lt < rt)
    {
        for (; lt <= hi && Ls[lt] <= pv; lt++);
        // Ls[j]<=pv  for j in lo..lt-1
        for (; Ls[rt] > pv; rt--);
        // Ls[j]>pv  for j in rt+1..hi
        if (lt < rt)
        {
            swap(Ls, lt, rt);
            lt++;
            rt--;
        }
    }
    if (Ls[lt] < pv && lt <= hi)
        pivPos = lt;
    else
        pivPos = lt - 1;
    
    swap(Ls, lo, pivPos);
    
    // Postcond.: (Ls[j]<=pv for j in lo..pivPos-1) and (Ls[j]>pv for j in pivPos+1..hi)
    return pivPos;
}

void printArray(int arr[])
{
    printf("The array is : \n");
    for (int i = 0; i < 10; i++)
    {
       printf(" %d", arr[i]);
    }
    printf("\n");
}

int main()
{   
    srand(time(NULL));
    int *arr = (int*) malloc(sizeof(int)*10);
    for (int i = 0; i < 10; i++)
    {
       if (i%2 == 0) arr[i] = rand() % 100;
       else arr[i] = rand() % 50;
    }

    printArray(arr);
    int pivot = rand() % 10;
    int pivotEle = arr[pivot];
    int pivotIndex = part(arr, 0, 9, pivot);

    printArray(arr);
    printf("\nThe pivot index is %d for the pivot %d\n", pivotIndex, pivotEle);

    return 0;
}
