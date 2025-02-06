#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "set.h"

int answer_checker(char* answers){

    char key[10];
    for (int i = 0; i < 10; i++){

        key[i] = 'A';

    }

    int score = 0;

    for (int i = 0; i < 10; i++){

        if (toupper(*(answers+i))=='N'){

            continue;

        }

        else if (toupper(*(answers+i))==key[i]){

            score += 4;

        }
        else{

            score += -1;

        }
    }

    if (score>=0) return score; 
    else return 0;

}

