#include <stdio.h>
#include <stdlib.h>

void modified_counting_sort(int* A, int k, int n, int place) 
{   
    int *B = (int*) malloc(sizeof(int)*n);

    // Initialize array C with all 0s
    int C[k];
    for (int i = 0; i < k; i++) 
    {
        C[i] = 0;
    }

    // Count the number of times each element occurs in A and store it in C
    for (int j = 0; j < n; j++) 
    {
        C[(A[j]%(place*10))/place]++;
    }
    
    // Place the elements of A in B in the correct position
    for (int i = 1; i < k; i++) 
    {
        C[i] = C[i] + C[i - 1];
    }
    for (int j = n - 1; j >= 0; j--) 
    {
        B[C[(A[j]%(place*10))/place] - 1] = A[j];
        C[(A[j]%(place*10))/place]--;
    }

    // Copy sorted elements from B back to A
    for (int i = 0; i < n; i++)
    {
        A[i] = B[i];
    }

    free(B);
}

void radix(int* A, int n)
{   
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
    
    for (int i = 1; i < places; i *= 10)
    {   
        modified_counting_sort(A, 10, n, i);
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

int main(int argc, char** argv)
{   
    // int arr[7] = {329, 457, 657, 839, 436, 720, 355};
    // printArray(arr, 7);
    // radix(arr,7);
    // printArray(arr, 7);

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
        radix(arr, n);
        printArray(arr, n);
        free(arr);
        free(line);
        free(num);
    }

    fclose(fptr);
    return 0;
}
