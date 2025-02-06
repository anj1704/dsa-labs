#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum day{
    monday = 5,
    tuesday = 5,
    friday = 6
};
typedef enum day Day;

int main()
{
    // char *line = "abcd";
    // printf("%c", line[0]);
    // char top = line[0];
    // int c = (int) top;
    // printf("%d", c);
    // char *copy;
    // // copy = (char*) malloc(sizeof(char)*10);
    // strcpy(copy, line);
    // printf("\n%s %s\n", copy, line);

    char *line = "monday";
    if (strcmp(line, monday)==0) printf("%d\n", monday);

    return 0;
}
