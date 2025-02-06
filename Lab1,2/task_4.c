#define MAX 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int add_end(char** arr, int n){

    char* x = (char*) malloc(MAX*sizeof(char));
    printf("Enter the string to be added : ");
    scanf("%s", x);

    arr = realloc(arr, (n+1)*sizeof(char*));
    arr[n] = (char*) malloc(MAX*sizeof(char));

    strcpy(arr[n], x);

    return n+1;

}

int add_start(char** arr, int n){

    char* y = (char*) malloc(MAX*sizeof(char));
    printf("Enter the name to be added : ");
    scanf("%s", y);

    char** arr_new = malloc((n+1)*sizeof(char*));
    for (int i = 0; i < n+1; i++){

        arr_new[i] = (char*) malloc(MAX*sizeof(char));
    }
    if (arr_new == NULL){

        printf("Unable to allocate memory\n");
        return -1;
    }

    for (int i = 0; i < n+1; i++){

        if (arr_new[i] == NULL){

            printf("Unable to allocate memory\n");
            return -1;

        }

    }


    for (int i = 1; i < n+1; i++){

        arr_new[i] = arr[i-1];

    }
    strcpy(arr_new[0], y);
    free(arr);
    arr = arr_new;

    return n+1;
}

int delete_index(char** arr, int n){

    int index;
    printf("Enter the index to delete : ");
    scanf(" %d", &index);
    if (index > n-1 || index < 0){

        printf("Invalid index !\n");
        return n;

    }
    for(int i = index; i < n; i++){

        arr[i] = arr[i+1];

    }

    return n-1; 

}

void display_len(char** arr, int n){

    printf("The length is %d\n", n);

}

void display_all(char** arr, int n){

    for (int i = 0; i < n; i++){

        printf("%s\n", arr[i]);

    }
    printf("\n");
}


int main(){

    int n;
    printf("Enter size of the array: ");
    scanf("%d", &n);

    char** arr = (char **) malloc(n*sizeof(char*));
    for (int i = 0; i < n; i++){

        arr[i] = (char*) malloc(MAX*sizeof(char));
    }
    if (arr == NULL){

        printf("Unable to allocate memory\n");
        return -1;
    }

    for (int i = 0; i < n; i++){

        if (arr[i] == NULL){

            printf("Unable to allocate memory\n");
            return -1;

        }

    }

    printf("Enter the  strings (will terminate at white space): ");

    for (int i = 0; i < n; i++){

        scanf("%s", arr[i]);

    }

    int flag = -1;

    while(flag != 0){

        printf("\nWhat would you like to do ?\n");
        printf("1. Add a string to the end of the array.\n");
        printf("2. Add a string to the beginning of the array.\n");
        printf("3. Delete the element at index \'x\' (taken as input) of the array.\n");
        printf("4. Display the length of the array.\n");
        printf("5. Display all elements of the array in sequence.\n");
        printf("0. Exit.\n");

        printf("Enter your input.\n");
        scanf(" %d", &flag);

        switch(flag){

            case 1:
                n = add_end(arr, n);
                break;
            case 2:
                n = add_start(arr, n);
                break;
            case 3:
                n = delete_index(arr, n);
                break;
            case 4:
                display_len(arr, n);
                break;
            case 5:
                display_all(arr, n);
                break;
            case 0:
                break;
            default:
                printf("Invalid input !\n");
                break;

        }

    }

    free(arr);
    return 0;

}
