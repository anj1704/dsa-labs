#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct morse_mapping{

    char character;
    char* symbol;

};

const struct morse_mapping map[37] = {

    {'A', ".-"},
    {'B', "-..."},
    {'C', "-.-."},
    {'D', "-.."},
    {'E', "."},
    {'F', "..-."},
    {'G', "--."},
    {'H', "...."},
    {'I', ".."},
    {'J', ".---"},
    {'K', "-.-"},
    {'L', ".-.."},
    {'M', "--"},
    {'N', "-."},
    {'O', "---"},
    {'P', ".--."},
    {'Q', "--.-"},
    {'R', ".-."},
    {'S', "..."},
    {'T', "-"},
    {'U', "..-"},
    {'V', "...-"},
    {'W', ".--"},
    {'X', "-..-"},
    {'Y', "-.--"},
    {'Z', "--.."},
    {'0', "-----"},
    {'1', ".----"},
    {'2', "..---"},
    {'3', "...--"},
    {'4', "....-"},
    {'5', "....."},
    {'6', "-...."},
    {'7', "--..."},
    {'8', "---.."},
    {'9', "----."},
    {' ', "/"}

};

int main(){

    FILE* fptr = fopen("msg.txt","r");
    char* line = (char *) malloc(sizeof(char)*200);

    line = fgets(line, 200, fptr);
    char* words = strtok(line, " ");

    while (words != NULL){

        for (int i = 0; i < 37; ++i) {
            
            if (strcmp(words,map[i].symbol)==0) {
                
                printf("%c", map[i].character);
                break;

            }
        }
        
        words = strtok(NULL," ");

    }

    printf("\n");
    fclose(fptr);

    return 0;
}
