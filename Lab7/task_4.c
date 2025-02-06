#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int arr[], int low, int high)
{   
    int temp = arr[low];
    arr[low] = arr[high];
    arr[high] = temp;
}

void convert_to_binary(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        int m = A[i];
        int bin = 0;
        int digit = 1;

        while (m > 0)
        {
            int rem = m%2;
            bin += rem * digit;
            m = m/2;
            digit *= 10;
        }
        A[i] = bin;
    }
}

void convert_from_binary(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        int m = A[i];
        int dec = 0;
        int digit = 1;

        while (m > 0)
        {
            int rem = m%10;
            dec += rem * digit;
            m = m/10;
            digit *= 2;
        }
        A[i] = dec;
    }
}

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void radix_exchange_sort_helper(int Ls[], int lo, int hi, int place, int places)
{
    if (place > 0)
    {
        int i = lo;
        int j = hi - 1;

        while (i <= j)
        {   
            int down = (Ls[i]%(place*10))/place;
            int up = (Ls[j]%(place*10))/place;
            
            if (up == 0 && down == 1)
            {
                swap(Ls, i, j);
                i++;
                j--;
            }
            else if (down == 0) i++;
            else if (up == 1) j--;
        }

        // printArray(Ls, hi);
        radix_exchange_sort_helper(Ls, lo, i, place/10, places);
        radix_exchange_sort_helper(Ls, i, hi, place/10, places);
    }
    else
    {
        return;
    }
}

void radix_exchange_sort(int* A, int n)
{      
    convert_to_binary(A, n);
    int max = -1;
    for (int i = 0; i < n; i++)
    {
        if (A[i] > max) max = A[i];
    }

    int places = 1;
    while (max > 0)
    {
        places *= 10;
        max = max/10;
    }

    // printf("Places = %d\n", places);
    radix_exchange_sort_helper(A, 0, n, places/10, places);
    convert_from_binary(A, n);
}

int main(int argc, char** argv)
{   
    // int arr[7] = {7, 1, 6, 2, 5, 3, 4};
    // printArray(arr, 7);
    // radix_exchange_sort(arr, 7);
    // printArray(arr, 7);

    // testing with a fixed length and random elements

    // srand(time(NULL));
    // int n = 10;
    // int *arr = (int*) malloc(sizeof(int)*n);
    // for (int i = 0; i < n; i++)
    // {
    //    if (i%2 == 0) arr[i] = rand() % 30;
    //    else arr[i] = rand() % 20;
    // }

    // printArray(arr, n);
    // radix_exchange_sort(arr, n);
    // printArray(arr, n);

    printf("Enter the number of arrays to test \n");
    int length;
    scanf("%d", &length);

    FILE *fptr = fopen("n_integers.txt" , "r");
    if (fptr == NULL){

        printf("Error opening file");
        exit(1);

    }

    for (int j = 0; j < length; j++)
    {
        int n;
        char *num = (char *) malloc(sizeof(int));
        fscanf(fptr, "%[^,],[", num);
        char *line = (char*) malloc(sizeof(int)); 
        n = atoi(num);

        int *arr = (int*) calloc(n, sizeof(int));
        
        for (int i = 0; i < n-1; i++){

            fscanf(fptr, "%s", line);
            arr[i] = atoi(line);

        }
        fscanf(fptr, "%s]\n", line);
        arr[n-1] = atoi(line);

        printArray(arr, n);
        radix_exchange_sort(arr, n);
        printArray(arr, n);
        free(arr);
        free(line);
        free(num);
    }

    fclose(fptr);
    return 0;
}
