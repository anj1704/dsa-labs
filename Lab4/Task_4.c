#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>

struct person
{
    int id;
    char *name;
    int age;
    int height;
    int weight;
};

typedef struct person person;

void mergeAux (person *L1, int s1, int e1, person *L2, int s2, int e2, person *L3, int s3, int e3)
{
    int i,j,k;
    // Traverse both arrays
    i=s1; j=s2; k=s3;

    while (i <= e1 && j <= e2) {

        // Check if current element of first array is smaller
        // than current element of second array
        // If yes, store first array element and increment first
        // array index. Otherwise do same with second array
        
        if (L1[i].height < L2[j].height)  L3[k++] = L1[i++];
        else L3[k++] = L2[j++];
        
    }
        
    // Store remaining elements of first array
    while (i <= e1) L3[k++] = L1[i++];
    
    // Store remaining elements of second array
    while (j <= e2) L3[k++] = L2[j++];
}

void merge(person *A, int s, int mid, int e)
{
    
    person *C = (person *)malloc(sizeof(person) * (e - s + 1));
    mergeAux(A, s, mid, A, mid + 1, e, C, 0, e-s);
    for(int i = 0; i < e - s + 1; i++)
    {
        A[s + i] = C[i];
    }
    free(C); 

}

// Precondition: A is an array indexed from st to en
void mergeSort(person *A, int st, int en)
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

    char *filename = (char *) malloc(sizeof(char)*strlen(argv[1]));
    filename = argv[1];

    char substring[strlen(filename) - 3];
    strncpy(substring, argv[1] + 3, strlen(argv[1]) - 3);

    int n = atoi(substring);

    person *A = (person *)malloc(n * sizeof(person));

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

    struct timeval t1, t2;
    double time_taken;
    gettimeofday(&t1, NULL);
    // Perform the tasks whose execution time is to be measured

    mergeSort(A, 0, n-1);

    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("The tasks took %f seconds to execute\n", time_taken);
    
    FILE *fptr;

    fptr = fopen("iterativeMergeSortBenchmarks.txt", "a");
    if (fptr == NULL)
    {

        printf("Error opening the file.");
        exit(1);
    }

    fprintf(fptr, "%d,%f\n", n, time_taken);
    fclose(fptr);

    free(A);
    return 0;
}
