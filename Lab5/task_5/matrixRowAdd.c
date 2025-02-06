#include <stdio.h>
#include <sys/time.h>
#include "matrix.h"

void add(){

    // Row-by-row (or row-wise) addition

    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int M1[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            M1[i][j] = rand() % 100;
        }
    }

    int M2[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            M2[i][j] = rand() % 100;
        }
    }

    int M3[n][n];

    struct timeval start, end;
    gettimeofday(&start, NULL);
    for (int i=0; i<n; i++){

        for(int j=0; j<n; j++){

            M3[i][j] = M2[i][j] + M1[i][j];

        }
    }
    gettimeofday(&end, NULL);
    
    printf("Time taken for row addition: %ld microseconds\n",
    ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 +
    start.tv_usec)));

}