#include <stdio.h>
#include <stdlib.h>

char* counting_sort(char* A, char* B, int k, int n) 
{
    // Initialize array C with all 0s
    int C[k];
    for (int i = 0; i < k; i++) 
    {
        C[i] = 0;
    }

    // Count the number of times each element occurs in A and store it in C
    for (int j = 0; j < n; j++) 
    {
        C[A[j]-97]++;
    }
    
    // Place the elements of A in B in the correct position
    for (int i = 1; i < k; i++) 
    {
        C[i] = C[i] + C[i - 1];
    }
    for (int j = n - 1; j >= 0; j--) 
    {
        B[C[A[j]-97] - 1] = A[j];
        C[A[j]-97]--;
    }
    return B;
}

int main()
{
    int n;
    printf("Enter the number of elements in the string \n");
    scanf("%d", &n);

    char *str = (char*) malloc(sizeof(char)*n);
    printf("Enter the string \n");
    scanf("%s", str);

    int k = str[0];
    for (int i = 1; i < n; i++) 
    {
        if (str[i] > k) 
        {
            k = str[i];
        }
    }
    k = k - 97;

    char *B = (char*) malloc(sizeof(char)*n);
    counting_sort(str, B, k + 1, n);
    printf("The sorted array is: ");
    printf("%s \n", B);
    return 0;
}