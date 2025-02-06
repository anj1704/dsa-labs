#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>

struct person
{
    int id;
    char *name;
    int age;
    int height;
    int weight;
};
typedef struct person person;

void swap(person arr[], int low, int high)
{   
    // XOR SWAP 
    // X := Y XOR X; // XOR the values and store the result in X
    // Y := X XOR Y; // XOR the values and store the result in Y
    // X := Y XOR X; // XOR the values and store the result in X

    // arr[low] = arr[high] ^ arr[low];
    // arr[high] = arr[high] ^ arr[low];
    // arr[low] = arr[low] ^ arr[high];

    person temp = arr[low];
    arr[low] = arr[high];
    arr[high] = temp;
}

void fileRead(char *filename, int n, person *A)
{
    FILE *fp = fopen(filename, "r");

    if (!fp)
    {
        printf("Can't open file\n");
    }
    else
    {
        for (int k = 0; k < n; k++)
        {
            (A + k)->name = (char *)malloc(100 * sizeof(char));
            fscanf(fp, "%d,%[^,],%d,%d,%d", &(A + k)->id, (A + k)->name, &(A + k)->age, &(A + k)->height, &(A + k)->weight);
        }
        fclose(fp);
    }
}

// Ls[lo..hi] is the input array; Ls[pInd] is the pivot
int twoWayHoare(person Ls[], int lo, int hi, int pInd)
{   
    swap(Ls, pInd, lo);

    int pivPos, lt, rt, pv;
    lt = lo + 1;
    rt = hi;
    pv = Ls[lo].height;
    
    while (lt < rt)
    {
        for (; lt <= hi && Ls[lt].height <= pv; lt++);
        // Ls[j]<=pv  for j in lo..lt-1
        for (; Ls[rt].height > pv; rt--);
        // Ls[j]>pv  for j in rt+1..hi
        if (lt < rt)
        {
            swap(Ls, lt, rt);
            lt++;
            rt--;
        }
    }
    if (Ls[lt].height < pv && lt <= hi)
        pivPos = lt;
    else
        pivPos = lt - 1;
    
    swap(Ls, lo, pivPos);
    
    // Postcond.: (Ls[j]<=pv for j in lo..pivPos-1) and (Ls[j]>pv for j in pivPos+1..hi)
    return pivPos;
}

// Ls[lo..hi] is the input array; Ls[pInd] is the pivot
int lumotu(person Ls[], int lo, int hi, int pInd)
{
    int i = lo - 1;
    int j = lo;
    int pivot = Ls[pInd].height;
    swap(Ls, pInd, hi-1);

    for (; j < hi-1; j++)
    {
        if (Ls[j].height <= pivot)
        {
            i++;
            swap(Ls, i, j);
        }
    }
    swap(Ls, i+1, hi - 1);

    return i+1;
}

int threePartHoare(person Ls[], int lo, int hi, int pInd)
{
    swap(Ls, pInd, hi - 1);
    
    int pivPos, lt, rt, mid, pv;
    lt = lo;
    rt = hi - 2;
    mid = lo;
    pv = Ls[hi - 1].height;
    
    while (mid <= rt)
    {
        if (Ls[mid].height < pv)
        {
            swap(Ls, lt, mid);
            lt++;
            mid++;
        }
        else if (Ls[mid].height > pv)
        {
            swap(Ls, mid, rt);
            rt--;
        }
        else
        {
            mid++;
        }
    }
    
    swap(Ls, mid, hi - 1);
    
    return mid;
}

void printArray(person arr[], int n)
{
    printf("The array is : \n");
    for (int i = 0; i < n; i++)
    {
       printf(" %d", arr[i].height);
    }
    printf("\n");
}

int main(int argc, char **argv)
{   
    srand(time(NULL));
    char *filename = (char *) malloc(sizeof(char)*strlen(argv[1]));
    filename = argv[1];

    char substring[strlen(filename) - 3];
    strncpy(substring, argv[1] + 3, strlen(argv[1]) - 3);

    int n = atoi(substring);

    person *A = (person *)malloc(n * sizeof(person));
    fileRead(filename, n, A);
    person *B = (person *)malloc(n * sizeof(person));
    fileRead(filename, n, B);
    person *C = (person *)malloc(n * sizeof(person));
    fileRead(filename, n, C);

    int pivot = rand() % n;
    person pivotEle = A[pivot];

    struct timeval t1, t2, t3, t4, t5, t6;
    double time_taken;

    gettimeofday(&t1, NULL);
    int pivotIndex = twoWayHoare(A, 0, n-1, pivot);
    gettimeofday(&t2, NULL);

    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    
    printf("\nThe pivot index is %d for the pivot %d\n", pivotIndex, pivotEle.height);
    printf("The two way hoare took %f seconds to execute\n", time_taken);

    gettimeofday(&t3, NULL);
    pivotIndex = lumotu(B, 0, n, pivot);
    gettimeofday(&t4, NULL);

    time_taken = (t4.tv_sec - t3.tv_sec) * 1e6;
    time_taken = (time_taken + (t4.tv_usec - t3.tv_usec)) * 1e-6;

    printf("\nThe pivot index is %d for the pivot %d\n", pivotIndex, pivotEle.height);
    printf("The lumotu took %f seconds to execute\n", time_taken);

    gettimeofday(&t5, NULL);
    pivotIndex = threePartHoare(C, 0, n, pivot);
    gettimeofday(&t6, NULL);

    time_taken = (t6.tv_sec - t5.tv_sec) * 1e6;
    time_taken = (time_taken + (t6.tv_usec - t5.tv_usec)) * 1e-6;

    printf("\nThe pivot index is %d for the pivot %d\n", pivotIndex, pivotEle.height);
    printf("The three way hoare took %f seconds to execute\n", time_taken);

    return 0;
}
