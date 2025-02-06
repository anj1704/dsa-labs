#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct name {

    char first[20];
    char last[20];

} Name;

int main(){

    int n;
    printf("Enter size of the array: ");
    scanf("%d", &n);
    Name* arr = calloc(n, sizeof(Name));
    if (arr == NULL){

        printf("Unable to allocate memory\n");
        return -1;
    }

    printf("Enter the names space separated : ");

    for (int i = 0; i < n; i++){

        scanf("%s %s", arr[i].first, arr[i].last);

    }

    printf("\nGiven array of names: ");

    for (int i = 0; i < n; i++){

        printf("%s %s\n", (arr+i)->first, (arr+i)->last);

    }
    printf("\n");

    printf("Adding an element to the array.\n");
    Name newname;
    printf("Enter the name to be added : ");
    scanf("%s %s", newname.first, newname.last);

    arr = realloc(arr, (n+1)*sizeof(Name));

    strcpy(arr[n].first, newname.first);
    strcpy(arr[n].last, newname.last);

    printf("\nModified array: ");
    for (int i = 0; i < n+1; i++){

        printf("%s %s\n", arr[i].first, arr[i].last);

    }
    printf("\n");

    free(arr);

    return 0;

}