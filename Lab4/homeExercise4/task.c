#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct criminal{
    char *name;
    int age;
    int ID;
    double criminality;
};

typedef struct criminal criminal;

criminal *readCriminals()
{
    FILE *fptr = fopen("criminal_database.txt", "r");
    int n;
    fscanf(fptr, "%d", &n);

    criminal *arr = (criminal*) malloc(sizeof(criminal)*n);
    for (int i = 0; i < n; i++)
    {
        criminal c;
        c.name = (char*) malloc(sizeof(char)*20);
        fscanf(fptr, "%[^,],%d,%d", c.name, &c.age, &c.ID);
        c.criminality = 0.0;
        arr[i] = c;
    }

    fclose(fptr);

    return arr;
}

void mergeAux (criminal *L1, int s1, int e1, criminal *L2, int s2, int e2, criminal *L3, int s3, int e3)
{
    int i,j,k;
    // Traverse both arrays
    i=s1; j=s2; k=s3;

    while (i <= e1 && j <= e2) {

        // Check if current element of first array is smaller
        // than current element of second array
        // If yes, store first array element and increment first
        // array index. Otherwise do same with second array
        
        if (L1[i].criminality > L2[j].criminality)  L3[k++] = L1[i++];
        else L3[k++] = L2[j++];
        
    }
        
    // Store remaining elements of first array
    while (i <= e1) L3[k++] = L1[i++];
    
    // Store remaining elements of second array
    while (j <= e2) L3[k++] = L2[j++];
}

void merge(criminal *A, int s, int mid, int e)
{
    
    criminal *C = (criminal *)malloc(sizeof(criminal) * (e - s + 1));
    mergeAux(A, s, mid, A, mid + 1, e, C, 0, e-s);
    for(int i = 0; i < e - s + 1; i++)
    {
        A[s + i] = C[i];
    }
    free(C); 

}

// Precondition: A is an array indexed from st to en
void mergeSort(criminal *A, int st, int en)
{

    if (en - st < 1)
        return;
    int mid = (st + en) / 2;   // mid is the floor of (st+en)/2
    mergeSort(A, st, mid);     // sort the first half
    mergeSort(A, mid + 1, en); // sort the second half
    merge(A, st, mid, en);     // merge the two halves

}

void findCriminality(criminal *criminals)
{
    FILE *fptr = fopen("crimes.txt", "r");
    int n;
    fscanf(fptr, "%d", &n);
    for (int i = 0; i < n; i++)
    {
        int year;
        int ID;
        char *crime;
        crime = (char*) malloc(sizeof(char)*20);
        fscanf(fptr, "%[^,],%d,%d", crime, &year, &ID);
        int index = (int) ID%100;
        if (strstr(crime, "ARSON") != NULL)
        {   
            if (year - (2023 - criminals[i].age) <= 18)
            {
                criminals[index].criminality += 0.5*10;
            }
            else
            {
                criminals[index].criminality += 10;
            }
        }
        else if (strstr(crime, "ASSAULT"))
        {
            if (year - (2023 - criminals[i].age) <= 18)
            {
                criminals[index].criminality += 0.5*5;
            }
            else
            {
                criminals[index].criminality += 5;
            }
        }
        else if (strstr(crime, "BURGLARY"))
        {
            if (year - (2023 - criminals[i].age) <= 18)
            {
                criminals[index].criminality += 0.5*5;
            }
            else
            {
                criminals[index].criminality += 5;
            }
        }
        else if (strstr(crime, "CRIMINAL MISCHIEF"))
        {
            if (year - (2023 - criminals[i].age) <= 18)
            {
                criminals[index].criminality += 0.5*5;
            }
            else
            {
                criminals[index].criminality += 5;
            }
        }
        else if (strstr(crime, "GRAND LARCENY"))
        {
            if (year - (2023 - criminals[i].age) <= 18)
            {
                criminals[index].criminality += 0.5*10;
            }
            else
            {
                criminals[index].criminality += 10;
            }
        }
        else if (strstr(crime, "GRAND THEFT AUTO"))
        {
            if (year - (2023 - criminals[i].age) <= 18)
            {
                criminals[index].criminality += 0.5*10;
            }
            else
            {
                criminals[index].criminality += 10;
            }
        }
        else if (strstr(crime, "HOMICIDE"))
        {
            if (year - (2023 - criminals[i].age) <= 18)
            {
                criminals[index].criminality += 0.5*20;
            }
            else
            {
                criminals[index].criminality += 20;
            }
        }
        else if (strstr(crime, "BREAKING AND ENTERING"))
        {
            if (year - (2023 - criminals[i].age) <= 18)
            {
                criminals[index].criminality += 0.5*5;
            }
            else
            {
                criminals[index].criminality += 5;
            }
        }
        else if (strstr(crime, "ROBBERY"))
        {
            if (year - (2023 - criminals[i].age) <= 18)
            {
                criminals[index].criminality += 0.5*10;
            }
            else
            {
                criminals[index].criminality += 10;
            }
        }
    }
    fclose(fptr);
}

int main()
{   
    criminal *criminals = readCriminals();
    findCriminality(criminals);
    FILE *fptr = fopen("criminal_database.txt", "r");
    int n;
    fscanf(fptr, "%d", &n);
    fclose(fptr);
    mergeSort(criminals, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        printf("%s %d %d %lf", criminals[i].name, criminals[i].age, criminals[i].ID, criminals[i].criminality);
    }
    FILE *fwriter = fopen("criminals_sorted.txt", "w");
    fprintf(fwriter, "%d", n);
    for (int i = 0; i < n; i++)
    {
        fprintf(fwriter, "%s %d %d %lf", criminals[i].name, criminals[i].age, criminals[i].ID, criminals[i].criminality);
    }
    fclose(fwriter);
    free(criminals);

    return 0;
}
