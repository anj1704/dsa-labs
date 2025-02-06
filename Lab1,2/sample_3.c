#include <stdio.h>

int main(){

    FILE *fptr;
    char name1[20], name2[20];
    int ID1, ID2;

    fptr = fopen("test.csv", "r");
    fscanf(fptr, "%[^,],%d\n", name1, &ID1);
    fscanf(fptr, "%[^,],%d\n", name2, &ID2);

    printf("Name 1: %s. ID1 : %d\n", name1, ID1);
    printf("Name 1: %s. ID1 : %d\n", name2, ID2);
    fclose(fptr);

    return 0;
}