#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *fptr;
    fptr = fopen("text1.txt","r");

    if (fptr == NULL){

        printf("Error opening file");
        exit(1);

    }

    FILE *fwriter;
    fwriter = fopen("text2.txt","w");

    if (fwriter == NULL){

        printf("Error opening file");
        exit(1);

    }
    
    char* line = (char *) malloc(100*sizeof(char));
    while (fgets(line, 100, fptr)){

        fprintf(fwriter, "%s", line);
    }

    fclose(fptr);
    fclose(fwriter);

    FILE *delete;
    delete = fopen("text1.txt","w");
    fclose(delete);

    return 0;
}