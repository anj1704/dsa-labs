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

// hybrid version - insertion sort used at the end on the partially sorted array
void qs(int Ls[], int lo, int hi)
{
    if (hi - lo < 10)
    {
        return;
    }
    else if (lo < hi)
    {
        int p = pivot(Ls, lo, hi);
        p = part(Ls, lo, hi, p);
        qs(Ls, lo, p);
        qs(Ls, p + 1, hi);
    }

    insertionSort(Ls, 0, hi);
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
    The sorting took 0.000629 seconds to execute on file int0.txt 
    The sorting took 0.000438 seconds to execute on file int1.txt 
    The sorting took 0.000637 seconds to execute on file int2.txt 
    The sorting took 0.006742 seconds to execute on file int3.txt 
    The sorting took 0.000849 seconds to execute on file int4.txt 
    The sorting took 0.000591 seconds to execute on file int5.txt 

    Median of Medians
    The sorting took 0.001155 seconds to execute on file int0.txt 
    The sorting took 0.000707 seconds to execute on file int1.txt 
    The sorting took 0.001065 seconds to execute on file int2.txt 
    The sorting took 37.157562 seconds to execute on file int3.txt 
    The sorting took 0.000962 seconds to execute on file int4.txt 
    The sorting took 0.001057 seconds to execute on file int5.txt 

    Quick Select
    The sorting took 0.000822 seconds to execute on file int0.txt 
    The sorting took 0.002737 seconds to execute on file int1.txt 
    The sorting took 0.000777 seconds to execute on file int2.txt 
    The sorting took 0.359501 seconds to execute on file int3.txt 
    The sorting took 0.002856 seconds to execute on file int4.txt 
    The sorting took 0.000813 seconds to execute on file int5.txt 

    Random Pivot
    The sorting took 0.000741 seconds to execute on file int0.txt 
    The sorting took 0.000625 seconds to execute on file int1.txt 
    The sorting took 0.000720 seconds to execute on file int2.txt 
    The sorting took 0.006975 seconds to execute on file int3.txt 
    The sorting took 0.000674 seconds to execute on file int4.txt 
    The sorting took 0.000741 seconds to execute on file int5.txt 
*/
