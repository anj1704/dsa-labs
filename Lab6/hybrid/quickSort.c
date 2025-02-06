#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "pivot.h"

void insertionSort(int A[], int lo, int hi)
{   
    int n = hi - lo;
    for (int j = lo + 1; j < n; j++)
    {
        int i = j - 1;
        int v = A[j];
        while (i >= lo && v < A[i])
        {
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = v;
    }
}

// hybrid version - insertion sort used of array size less than 10
void qs(int Ls[], int lo, int hi)
{
    if (hi - lo < 10)
    {
        insertionSort(Ls, lo, hi);
        return;
    }
    else if (lo < hi)
    {
        int p = pivot(Ls, lo, hi);
        p = part(Ls, lo, hi, p);
        qs(Ls, lo, p);
        qs(Ls, p + 1, hi);
    }
}

void runner(char *filename, int n)
{   
    int *arr = (int*) malloc(sizeof(int)*n);
    FILE* fptr = fopen(filename, "r");
    if (!fptr)
    {
        printf("Failed to open file \n");
    }
    char *line = (char *) malloc(sizeof(char)*10);
    for (int i = 0; i < n; i++)
    {
        fscanf(fptr, "%s", line);
        arr[i] = atoi(line);
    }

    struct timeval t1, t2;
    double time_taken;

    gettimeofday(&t1, NULL);
    qs(arr, 0, n);
    gettimeofday(&t2, NULL);

    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;

    printf("The sorting took %f seconds to execute on file %s \n", time_taken, filename);
    
    free(arr);
    fclose(fptr);
}

int main()
{   
    // testing with a fixed length

    // srand(time(NULL));
    // int n = 10;
    // int *arr = (int*) malloc(sizeof(int)*n);
    // for (int i = 0; i < n; i++)
    // {
    //    if (i%2 == 0) arr[i] = rand() % 100;
    //    else arr[i] = rand() % 50;
    // }

    // printArray(arr, n);
    // qs(arr, 0, n);
    // printArray(arr, n);

    // return 0;

    // reading from files

    runner("int0.txt", 1000);
    runner("int1.txt", 1000);
    runner("int2.txt", 1000);
    runner("int3.txt", 1000);
    runner("int4.txt", 1000);
    runner("int5.txt", 1000);

    return 0;
}

/*
    RESULTS :
    
    Median of Threes
    The sorting took 0.000111 seconds to execute on file int0.txt 
    The sorting took 0.000046 seconds to execute on file int1.txt 
    The sorting took 0.000111 seconds to execute on file int2.txt 
    The sorting took 0.001411 seconds to execute on file int3.txt 
    The sorting took 0.000091 seconds to execute on file int4.txt 
    The sorting took 0.000112 seconds to execute on file int5.txt 

    Median of Medians
    The sorting took 0.000695 seconds to execute on file int0.txt 
    The sorting took 0.000314 seconds to execute on file int1.txt 
    The sorting took 0.000669 seconds to execute on file int2.txt 
    The sorting took 37.262461 seconds to execute on file int3.txt 
    The sorting took 0.000556 seconds to execute on file int4.txt 
    The sorting took 0.000663 seconds to execute on file int5.txt 

    Quick Select
    The sorting took 0.000394 seconds to execute on file int0.txt 
    The sorting took 0.002333 seconds to execute on file int1.txt 
    The sorting took 0.000379 seconds to execute on file int2.txt 
    The sorting took 0.353933 seconds to execute on file int3.txt 
    The sorting took 0.002444 seconds to execute on file int4.txt 
    The sorting took 0.000426 seconds to execute on file int5.txt 

    Random Pivot
    The sorting took 0.000162 seconds to execute on file int0.txt 
    The sorting took 0.000133 seconds to execute on file int1.txt 
    The sorting took 0.000168 seconds to execute on file int2.txt 
    The sorting took 0.001652 seconds to execute on file int3.txt 
    The sorting took 0.000122 seconds to execute on file int4.txt 
    The sorting took 0.000163 seconds to execute on file int5.txt 
*/
