#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(){

    int hobbit = 0;

    FILE* fptr = fopen("LOTR.txt","r");
    if (fptr == NULL){

        printf("Unable to read LOTR.txt.\n");
        exit(1);

    }

    char* line = (char *) malloc(100*sizeof(char));

    while (fgets(line, 100, fptr)){

        char* words = strtok(line, " ");
        // this will assign the first word to words (first instance of encountering delimiter)
        // it replaces the delimiter with \0 or NULL
        // we call strtok in loop again to continue where we left off from

        while (words!=NULL){

            // Convert each word to lowercase for case-insensitive comparison
            for (int i = 0; words[i] != '\0'; i++) {
                words[i] = tolower(words[i]);
            }

            // char *strstr(const char *haystack, const char *needle)
            // Finds the first occurrence of the entire string needle (not including the terminating null character) which appears in the string haystack.
            if (strstr(words,"hobbit")) hobbit++;
            words = strtok(NULL," ");

        }
    }

    printf("The number of hobbits in LOTR = %d", hobbit);
    fclose(fptr);
    free(line);

    return 0;

}
