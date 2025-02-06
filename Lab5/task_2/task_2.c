#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>

// recursive insertion sort
void insertionSortR(int *arr, int n)
{

    if (n <= 1) return;
    insertionSortR(arr, n-1);
    
    int last = arr[n-1];
    int j = n-2;
    
    while (j >= 0 && arr[j] > last)
    {

        arr[j+1] = arr[j];
        j--;
    
    }
    arr[j+1] = last;

}

// iterative insertion sort
void insertionSortI(int *arr, int n)
{
    
    for (int i = 1; i < n; i++)
    {
        int last = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > last)
        {
        
            arr[j+1] = arr[j];
            j--;
        
        }
    
        arr[j+1] = last;
    
    }

}

int main(int argc, char** argv)
{
    char *filename = (char *) malloc(sizeof(char)*strlen(argv[1]));
    filename = argv[1];

    char substring[strlen(filename) - 7];
    strncpy(substring, argv[1] + 7, strlen(argv[1]) - 3);

    int n = atoi(substring);

    // Reads the numbers stored in numbers1000.txt and stores them into an integer array
    FILE *fp = fopen(filename, "r");
    int numbers_1[n];
    int numbers_2[n];
    
    int i = 0;
    while (fscanf(fp, "%d", &numbers_1[i]) != EOF)
    {
        numbers_2[i] = numbers_1[i];
        i++;
    }
    fclose(fp);

    // Perform some operation on the numbers
    // Example operation: Print the numbers stored in the array
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", numbers_1[i]);
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", numbers_2[i]);
    // }

    struct timeval t1, t2;
    double time_taken;
    
    gettimeofday(&t1, NULL);
    insertionSortI(numbers_1, n);
    gettimeofday(&t2, NULL);
    
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("Iterative insertion sort took %f seconds to execute\n", time_taken);
    
    gettimeofday(&t1, NULL);
    insertionSortR(numbers_2, n);
    gettimeofday(&t2, NULL);
    
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("Recursive insertion sort took %f seconds to execute\n", time_taken);
    
    return 0;
}