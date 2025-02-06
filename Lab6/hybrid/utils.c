#include <stdio.h>

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

void printArray(int arr[], int n)
{
    printf("The array is : \n");
    for (int i = 0; i < n; i++)
    {
       printf(" %d", arr[i]);
    }
    printf("\n");
}

int min(int a, int b)
{
    return a<b ? a : b;
}

// Ls[lo..hi] is the input array; Ls[pInd] is the pivot - using the lomuto method
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
