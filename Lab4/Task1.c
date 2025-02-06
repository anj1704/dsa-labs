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
void insertInOrder(person v, person *A, int last);

void insertionSort(person *A, int n){

    for (int j = 1; j < n; j++)
    {

        insertInOrder(*(A + j), A, j);
    }
}

// Pre-condition: (length(A) - 1 > last) & forall j: 0 <= j < last - 1:
// A[j] <= A[j+1]

void insertInOrder(person v, person *A, int last)
{

    int j = last - 1;

    while (j >= 0 && v.height < (A + j)->height)
    {

        A[j + 1] = A[j];
        j--;
    }

    *(A + j + 1) = v;
}

int main(int argc, char **argv)
{

    // person A[5];
    // A[0].id = 1;
    // A[0].name = "Sokka";
    // A[0].age = 15;
    // A[0].height = 150;
    // A[0].weight = 45;

    // A[1].id = 2;
    // A[1].name = "Aang";
    // A[1].age = 112;
    // A[1].height = 137;
    // A[1].weight = 35;

    // A[2].id = 3;
    // A[2].name = "Zuko";
    // A[2].age = 16;
    // A[2].height = 160;
    // A[2].weight = 50;

    // A[3].id = 4;
    // A[3].name = "Katara";
    // A[3].age = 14;
    // A[3].height = 145;
    // A[3].weight = 38;

    // A[4].id = 5;
    // A[4].name = "Toph";
    // A[4].age = 12;
    // A[4].height = 113;
    // A[4].weight = 30;

    // insertionSort(A,5);

    // printf("id name age height weight\n");

    // for (int i = 0; i < 5; i++){

    //     printf("%d %s %d %d %d\n", A[i].id,A[i].name,A[i].age, A[i].height, A[i].weight);

    // }

    // person *A = (person *) malloc(sizeof(person));
    // int k =  0;

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

    insertionSort(A, n);

    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("The tasks took %f seconds to execute\n", time_taken);

    FILE *fptr;

    fptr = fopen("insertionSortBenchmarks.txt", "a");
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
