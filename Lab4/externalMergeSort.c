#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

void mergeFiles(FILE *f1, FILE *f2, FILE *final, int size)
{
    int countOne = 0;
    int countTwo = 0;

    while (countOne < size && countTwo < size)
    {      
        person *one = (person *)malloc(size * sizeof(person));
        person *two = (person *)malloc(size * sizeof(person));
        while (countTwo >= size){

            one->name = (char *)malloc(100 * sizeof(char));
            fscanf(f1, "%d,%[^,],%d,%d,%d", &one->id, one->name, &one->age, &one->height, &one->weight);
            fprintf(final, "%d,%s,%d,%d,%d\n", one->id, one->name, one->age, one->height, one->weight);
            countOne++;

        }

        while (countOne >= size){

            two->name = (char *)malloc(100 * sizeof(char));
            fscanf(f2, "%d,%[^,],%d,%d,%d", &   two->id,   two->name, &two->age, &two->height, &two->weight);
            fprintf(final, "%d,%s,%d,%d,%d\n", two->id, two->name, two->age, two->height, two->weight);
            countOne++;
            
        }

        one->name = (char *)malloc(100 * sizeof(char));
        two->name = (char *)malloc(100 * sizeof(char));
        fscanf(f1, "%d,%[^,],%d,%d,%d", &one->id, one->name, &one->age, &one->height, &one->weight);
        fscanf(f2, "%d,%[^,],%d,%d,%d\n", &two->id, two->name, &two->age, &two->height, &two->weight);
    
        if (one->height > two->height){

            fprintf(final, "%d,%s,%d,%d,%d\n", one->id, one->name, one->age, one->height, one->weight);
            countOne++;

        }
        else{

            fprintf(final, "%d,%s,%d,%d,%d\n", two->id, two->name, two->age, two->height, two->weight);
            countTwo++;

        }
        
        free(one);
        free(two);
    }

    while (countOne < size){

        person *one = (person *)malloc(size * sizeof(person));
        one->name = (char *)malloc(100 * sizeof(char));
        fscanf(f1, "%d,%[^,],%d,%d,%d", &one->id, one->name, &one->age, &one->height, &one->weight);
        fprintf(final, "%d,%s,%d,%d,%d\n", one->id, one->name, one->age, one->height, one->weight);
        countOne++;
        free(one);

    }

    while (countTwo < size){

        person *two = (person *)malloc(size * sizeof(person));
        two->name = (char *)malloc(100 * sizeof(char));
        fscanf(f2, "%d,%[^,],%d,%d,%d", &   two->id,   two->name, &two->age, &two->height, &two->weight);
        fprintf(final, "%d,%s,%d,%d,%d\n", two->id, two->name, two->age, two->height, two->weight);
        countOne++;
        free(two);

    }

}

int main(int argc, char **argv)
{   
    char *filename;
    filename = (char *) malloc(sizeof(char)*strlen(argv[1]));
    strcpy(filename, argv[1]);

    char substring[strlen(filename) - 3];
    strncpy(substring, argv[1] + 3, strlen(argv[1]) - 3);

    int n = atoi(substring);
    int size = n/10;

    FILE *final = fopen("sorted.csv", "w");
    FILE *fp = fopen(filename, "r");


    for (int i = 0; i < 10; i++)
    {

        char *sortfile;
        sortfile = (char*) malloc(sizeof(char)*100);
        sprintf(sortfile, "sorted%d.csv", i);
        // printf("%s\n", sortfile);
        // printf("HIHIHIH");
        person *A = (person *)malloc(size * sizeof(person));

        if (!fp)
        {
            printf("Can't open file\n");
        }
        else
        {
            for (int k = 0; k < size; k++)
            {
                (A + k)->name = (char *)malloc(100 * sizeof(char));
                fscanf(fp, "%d,%[^,],%d,%d,%d", &(A + k)->id, (A + k)->name, &(A + k)->age, &(A + k)->height, &(A + k)->weight);
            }
        }

        mergeSort(A, 0, size-1);
        FILE *fwriter = fopen(sortfile, "w");

        if (fwriter == NULL){

            printf("Error opening file");
            exit(1);

        }
    
        char* line = (char *) malloc(100*sizeof(char));
        for (int k = 0; k < size; k++){

            fprintf(fwriter, "%d,%s,%d,%d,%d\n", (A + k)->id, (A + k)->name, (A + k)->age, (A + k)->height, (A + k)->weight);
        
        }

        fclose(fwriter);
        free(A);

    }

    for (int i = 0; i < 9; i+=2)
    {

        char *sortfile1;
        char *sortfile2;
        sortfile1 = (char*) malloc(sizeof(char)*12);
        sortfile2 = (char*) malloc(sizeof(char)*12);
        sprintf(sortfile1, "sorted%d.csv", i);
        sprintf(sortfile2, "sorted%d.csv", i+1);

        FILE *f1 = fopen(sortfile1, "r");
        FILE *f2 = fopen(sortfile2, "r");
        if (f1 != NULL && f2 != NULL){

            mergeFiles(f1, f2, final, size);

        }
        else{

            printf("File failed to open\n");
            return 0;

        }
        
        fclose(f1);
        fclose(f2);

    }

    fclose(fp);
    fclose(final);

    return 0;
}
