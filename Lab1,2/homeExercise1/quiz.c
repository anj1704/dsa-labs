#include <stdio.h>
#include <stdlib.h>
#include "set.h"

int main(){

    char* answers;
    answers = (char *) malloc(sizeof(char)*10);
    if (answers ==  NULL){
        return 0;
    }
    printf("Enter your 10 answers.\n");
    for (int i = 0; i < 10; i++){

        scanf("%c", (answers+i));

    }

    int score = answer_checker(answers);
    printf("The student has scored %d marks.\n", score);
    free(answers);

    return 0;

}
