#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectSort(int *arr, int start, int size)
{
    if (start == size - 1) return;
    else 
    {
        int min = start;
        for (int i = start + 1; i < size; i++)
        {
            if (arr[min] > arr[i]) min = i;
        }

        swap(&arr[start], &arr[min]);
        return selectSort(arr, start + 1, size);
    }
}

int main()
{   
    int size = 10;
    int *arr = (int *) malloc(sizeof(int)*size);
    for (int i = 0; i < size; i++)
    {   
        arr[i] = size - i;
        printf(" %d ", arr[i]);
    }
    printf("\n");
    selectSort(arr, 0, size);
    for (int i = 0; i < size; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");

    return 0;
}
