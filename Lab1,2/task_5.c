#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *fptr;
    printf("%s", __FILE__);
    fptr = fopen(__FILE__,"r");

    if (fptr == NULL){

        printf("Error opening file");
        exit(1);

    }
    
    char c;
    while ((c = fgetc(fptr)) != EOF){

        printf("%c", c);
    }
    // char* line = (char *) malloc(100*sizeof(char));
    // while (fgets(line, 100, fptr)){

    //     printf("%s\n", line);
    // }

    return 0;

}