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

int threePart(int Ls[], int lo, int hi, int pInd)
{
    swap(Ls, pInd, hi - 1);
    
    int pivPos, lt, rt, mid, pv;
    lt = lo;
    rt = hi - 2;
    mid = lo;
    pv = Ls[hi - 1];
    
    while (mid <= rt)
    {
        if (Ls[mid] < pv)
        {
            swap(Ls, lt, mid);
            lt++;
            mid++;
        }
        else if (Ls[mid] > pv)
        {
            swap(Ls, mid, rt);
            rt--;
        }
        else
        {
            mid++;
        }
    }
    
    swap(Ls, mid, hi - 1);
    
    return mid;
}

void printArray(int arr[], int n)
{
    printf("The array is : \n");
    for (int i = 0; i < n; i++)
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

    printArray(arr, 10);
    int pivot = rand() % 10;
    int pivotEle = arr[pivot];
    int pivotIndex = threePart(arr, 0, 10, pivot);

    printArray(arr, 10);
    printf("\nThe pivot index is %d for the pivot %d\n", pivotIndex, pivotEle);

    return 0;
}
