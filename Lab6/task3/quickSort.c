#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "pivot.h"

void qs(int Ls[], int lo, int hi)
{
    if (lo < hi)
    {
        int p = pivot(Ls, lo, hi); // Ls[p] is the pivot
        // printf("The pivot element is %d\n", p);
        p = part(Ls, lo, hi, p); // Ls[p] is the pivot
        /*
        (Ls[j]<=Ls[p] for j in lo..pPos-1) and
        (Ls[j]>Ls[p] for j in pPos+1..hi)
        */
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

    srand(time(NULL));
    int n = 15;
    int *arr = (int*) malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++)
    {
       if (i%2 == 0) arr[i] = rand() % 100;
       else arr[i] = rand() % 50;
    }
    // for (int i = 0; i < 15; i++)
    // {
    //     if (i % 2 == 0) arr[i] = 15-i;
    //     arr[i] = i;
    // }

    printArray(arr, n);
    qs(arr, 0, n);
    printArray(arr, n);

    return 0;

    // reading from files

    // runner("int0.txt", 1000);
    // runner("int1.txt", 1000);
    // runner("int2.txt", 1000);
    // runner("int3.txt", 1000);
    // runner("int4.txt", 1000);
    // runner("int5.txt", 1000);

    // return 0;
}

/*
    RESULTS :
    
    Median of Threes
    The sorting took 0.000164 seconds to execute on file int0.txt 
    The sorting took 0.000083 seconds to execute on file int1.txt 
    The sorting took 0.000165 seconds to execute on file int2.txt 
    The sorting took 0.001406 seconds to execute on file int3.txt 
    The sorting took 0.000124 seconds to execute on file int4.txt 
    The sorting took 0.000165 seconds to execute on file int5.txt 

    Median of Medians
    The sorting took 0.000779 seconds to execute on file int0.txt 
    The sorting took 0.000376 seconds to execute on file int1.txt 
    The sorting took 0.000757 seconds to execute on file int2.txt 
    The sorting took 37.135665 seconds to execute on file int3.txt 
    The sorting took 0.000642 seconds to execute on file int4.txt 
    The sorting took 0.000741 seconds to execute on file int5.txt 

    Quick Select
    The sorting took 0.000491 seconds to execute on file int0.txt 
    The sorting took 0.002422 seconds to execute on file int1.txt 
    The sorting took 0.000467 seconds to execute on file int2.txt 
    The sorting took 0.353779 seconds to execute on file int3.txt 
    The sorting took 0.002549 seconds to execute on file int4.txt 
    The sorting took 0.000512 seconds to execute on file int5.txt 

    Random Pivot
    The sorting took 0.000413 seconds to execute on file int0.txt 
    The sorting took 0.000386 seconds to execute on file int1.txt 
    The sorting took 0.000424 seconds to execute on file int2.txt 
    The sorting took 0.001650 seconds to execute on file int3.txt 
    The sorting took 0.000376 seconds to execute on file int4.txt 
    The sorting took 0.000428 seconds to execute on file int5.txt 
*/
