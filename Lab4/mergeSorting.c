#include <stdio.h>

void mergeAux(int L1[], int s1, int e1, int L2[], int s2, int e2, int L3[], int s3, int e3)
{

    if (L1[s1] > L2[s2])
    {

        L3[s3] = L2[s2];
        mergeAux(L1, s1, e1, L2, s2 + 1, e2, L3, s3 + 1, e3);

    }
    else
    {
        L3[s3] = L1[s1];
        mergeAux(L1, s1 + 1, e1, L2, s2, e2, L3, s3 + 1, e3);
    }
    while (s1<=e1)
    {
        L3[s3] = L1[s1];
        s3++;
        s1++;
    }
    while (s2<=e2)
    {
        L3[s3] = L2[s2];
        s3++;
        s2++;
    }
}

void merge(int A[], int s, int mid, int e)
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
