#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "pivot.h"

// partially iterative quick sort
void qs(int Ls[], int lo, int hi)
{
   while (lo < hi)
    {
        int pInd = pivot(Ls, lo, hi);
        int p = part(Ls, lo, hi, pInd);
        qs(Ls, lo, p - 1);
        lo = p + 1;
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
    // int n = 5;
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
    The sorting took 0.000143 seconds to execute on file int0.txt 
    The sorting took 0.000065 seconds to execute on file int1.txt 
    The sorting took 0.000143 seconds to execute on file int2.txt 
    The sorting took 0.001426 seconds to execute on file int3.txt 
    The sorting took 0.000103 seconds to execute on file int4.txt 
    The sorting took 0.000140 seconds to execute on file int5.txt 

    Median of Medians
    The sorting took 0.000746 seconds to execute on file int0.txt 
    The sorting took 0.000361 seconds to execute on file int1.txt 
    The sorting took 0.000723 seconds to execute on file int2.txt 
    The sorting took 37.374548 seconds to execute on file int3.txt 
    The sorting took 0.000610 seconds to execute on file int4.txt 
    The sorting took 0.000733 seconds to execute on file int5.txt 

    Quick Select
    The sorting took 0.000451 seconds to execute on file int0.txt 
    The sorting took 0.002378 seconds to execute on file int1.txt 
    The sorting took 0.000431 seconds to execute on file int2.txt 
    The sorting took 0.357881 seconds to execute on file int3.txt 
    The sorting took 0.002534 seconds to execute on file int4.txt 
    The sorting took 0.000500 seconds to execute on file int5.txt 

    Random Pivot
    The sorting took 0.000360 seconds to execute on file int0.txt 
    The sorting took 0.000258 seconds to execute on file int1.txt 
    The sorting took 0.000302 seconds to execute on file int2.txt 
    The sorting took 0.001597 seconds to execute on file int3.txt 
    The sorting took 0.000248 seconds to execute on file int4.txt 
    The sorting took 0.000304 seconds to execute on file int5.txt
*/
