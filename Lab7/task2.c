#include <stdio.h>
#include <stdlib.h>

// https://www.quora.com/What-is-an-algorithm-that-given-n-integers-in-the-range-0-to-k-preprocesses-its-input-and-then-answers-any-query-about-how-many-of-the-n-integers-fall-into-a-range-a-b-in-O-1-time
// Function to take input an array A and return an array B after performing counting sort on it with array C

// Doesn't work fix it 

int main()
{   
    FILE *fptr = fopen("n_integers.txt", "r");
    int length;
    printf("Enter the number of arrays you want to test\n");
    scanf("%d", &length);

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
        
        int k = arr[0];
        for (int i = 1; i < n; i++) 
        {
            if (arr[i] > k) 
            {
                k = arr[i];
            }
        }
        
        // Initialize array C with all 0s
        int C[k];
        for (int i = 0; i < k; i++) 
        {
            C[i] = 0;
        }

        // Count the number of times each element occurs in A and store it in C
        for (int j = 0; j < n; j++) 
        {
            C[arr[j]]++;
        }
        
        // Place the elements of A in B in the correct position
        for (int i = 1; i < k; i++) 
        {
            C[i] = C[i] + C[i - 1];
        }

        int a,b,target;

        printf("Enter the integer and target range it should lie in\n");
        scanf("%d %d %d", &target, &a, &b);

        if (target < C[b] && target > C[a-1])
        {
            printf("Target is present in given range ! \n");
        }
        else
        {
            printf("Target not found in desired range. \n");
        }
    }

    return 0;
}