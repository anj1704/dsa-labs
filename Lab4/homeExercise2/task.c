#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void mergeAux (int *L1, int s1, int e1, int *L2, int s2, int e2, int *L3, int s3, int e3)
{
    int i,j,k;
    // Traverse both arrays
    i=s1; j=s2; k=s3;

    while (i <= e1 && j <= e2) {

        // Check if current element of first array is smaller
        // than current element of second array
        // If yes, store first array element and increment first
        // array index. Otherwise do same with second array
        
        if (L1[i] < L2[j])  L3[k++] = L1[i++];
        else L3[k++] = L2[j++];
        
    }
        
    // Store remaining elements of first array
    while (i <= e1) L3[k++] = L1[i++];
    
    // Store remaining elements of second array
    while (j <= e2) L3[k++] = L2[j++];
}

void merge(int *A, int s, int mid, int e)
{
    
    int *C = (int *)malloc(sizeof(int) * (e - s + 1));
    mergeAux(A, s, mid, A, mid + 1, e, C, 0, e-s);
    for(int i = 0; i < e - s + 1; i++)
    {
        A[s + i] = C[i];
    }
    free(C); 

}

// Precondition: A is an array indexed from st to en
void mergeSort(int *A, int st, int en)
{

    if (en - st < 1)
        return;
    int mid = (st + en) / 2;   // mid is the floor of (st+en)/2
    mergeSort(A, st, mid);     // sort the first half
    mergeSort(A, mid + 1, en); // sort the second half
    merge(A, st, mid, en);     // merge the two halves

}

int main(int argc, char **argv)
{

    int n;
    printf("Enter the size of the array.\n");
    scanf("%d", &n);

    int *A = (int *)malloc(n * sizeof(int));
    printf("Enter %d elements : \n", n);
    for (int k = 0; k < n; k++)
    {
       scanf("%d", A + k);
    }

    mergeSort(A, 0, n-1);

    int count;
    
    for (int i = 0; i < n-1; i++){
        
        if (A[i] == A[i+1]) continue;
        if (n - i - 1 == A[i]){

            printf("%d\n", A[i]);
            free(A);
            return 0;
        }
        
    }

    printf("Not found\n");
    free(A);
    return 0;
}
