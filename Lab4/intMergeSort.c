#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "intMerge.h"
#include "intMergeAux.h"

void merge(int A[], int s, int mid, int e)
{
    
    int *C = (int *)myalloc(sizeof(int) * (e - s + 1));
    mergeAux(A, s, mid, A, mid + 1, e, C, 0, e-s);
    for(int i = 0; i < e - s + 1; i++)
    {
        A[s + i] = C[i];
    }
    // myfree(C); 

}

// Precondition: A is an array indexed from st to en
void mergeSort(int A[], int st, int en)
{

    if (en - st < 1)
        return;
    int mid = (st + en) / 2;   // mid is the floor of (st+en)/2
    mergeSort(A, st, mid);     // sort the first half
    mergeSort(A, mid + 1, en); // sort the second half
    merge(A, st, mid, en);     // merge the two halves

}
// Postcondition: forall j: st<=j<en-1 --> A[j]<=A[j+1]

int main(){

    // int A[10] = {34,76,12,87,34,76,23,90,11,1};
    // mergeSort(A, 0, 9);

    // printf("Sorted array :\n ");
    // for (int i = 0; i < 10; i++){

    //     printf("%d ", A[i]);

    // }
    // printf("\n");

    FILE* fptr = fopen("marks.txt","r");
    char *line = (char*) malloc(sizeof(char)*10);
    // int A[1000];
    int *A = (int*) myalloc(sizeof(int)*1000);
    int i = 0;

    while (fgets(line, 10, fptr) != NULL && i <1000){

        A[i++] = atoi(line);

    }

    struct timeval t1,t2;
    float time_taken;

    gettimeofday(&t1, NULL);
    mergeSort(A, 0, 999);
    gettimeofday(&t2, NULL);

    // printf("Sorted array :\n ");
    // for (int i = 0; i < 1000; i++){

    //     printf("%d ", A[i]);

    // }
    // printf("\n");

    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("The sorting took %f seconds to execute\n", time_taken);
    printf("Heap space used is %zu\n", heapMemoryAllocated);
    myfree(A);

    return 0;
}
