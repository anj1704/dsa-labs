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
    int i = lo - 1;
    int j = lo;
    int pivot = Ls[pInd];
    swap(Ls, pInd, hi-1);

    for (; j < hi; j++)
    {
        if (Ls[j] < pivot)
        {
            i++;
            swap(Ls, i, j);
        }
    }
    swap(Ls, i+1, hi - 1);

    return i+1;
}

void printArray(int arr[], int n)
{
    printf("the array is : \n");
    for (int i = 0; i < n; i++)
    {
       printf(" %d", arr[i]);
    }
    printf("\n");
}

int main()
{   
    srand(time(NULL));
    int n = 30;
    int *arr = (int*) malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++)
    {
       arr[i] = rand() % 3;
    }

    printf("Originally ");
    printArray(arr, n);
    int pivot;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            pivot = i;
            break;
        }
    }
    int pivotIndex = part(arr, 0, n, pivot);

    // arranging 0s 
    printf("After pushing all 0s to the left ");
    printArray(arr, n);

    for (int i = pivotIndex; i < n; i++)
    {
        if (arr[i] == 2)
        {
            pivot = i;
            break;
        }
    }
    pivotIndex = part(arr, 0, n, pivot);
    
    // arranging 1s and 2s
    printf("After pushing all 2s to the right ");
    printArray(arr, n);

    return 0;
}


