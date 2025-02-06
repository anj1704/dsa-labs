#include <stdio.h>

void insertionSort(int A[], int n){

    for (int j = 1; j < n; j++){

        insertInOrder(A[j], A, j);

    }

}

// Pre-condition: (length(A) - 1 > last) & forall j: 0 <= j < last - 1:
// A[j] <= A[j+1]

void insertInOrder(int v, int A[], int last){

    int j = last - 1;
    
    while(j >= 0 && v < A[j]){

        A[j+1] = A[j];
        j--;
    
    }
    
    A[j+1] = v;

}
// Post-condition: forall j: 0 <= j < last - 1: A[j] <= A[j+1]
