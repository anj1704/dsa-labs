#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_NAME_LENGTH 64

int main(int argc, char** argv) {
    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: file not found\n");
        return 1;
    }

    // char buffer[1024];
    // char* buffer = (char*)malloc(1024 * sizeof(char));

    // for (int i = 0; i < 1000; ++i) {
    //     int id, age, height, weight;
    //     // char name[1024];
    //     char* name = (char*)malloc(1024 * sizeof(char));
    //     fscanf(fp, "%d,%[^,],%d,%d,%d", &id, name, &age, &height, &weight);

    //     printf("--------------------\n");
    //     printf("Iteration %d\n", i);
    //     printf("Name : %s\n", name);
    //     printf("ID : %d\n", id);
    //     printf("Age : %d\n", age);
    //     printf("Height : %d\n", height);
    //     printf("Weight : %d\n", weight);
    //     printf("--------------------\n");
    // }

    // char buffer[1024];
    char* buffer = (char*)malloc(1024 * sizeof(char));
    while (fgets(buffer, 1024, fp) != NULL) {
        int id, age, height, weight;
        char name[1024];
        sscanf(buffer, "%d,%[^,],%d,%d,%d", &id, name, &age, &height, &weight);

        printf("--------------------\n");
        printf("Name : %s\n", name);
        printf("ID : %d\n", id);
        printf("Age : %d\n", age);
        printf("Height : %d\n", height);
        printf("Weight : %d\n", weight);
        printf("--------------------\n");
    }
    // char line[MAX_LINE_LENGTH];
    // char* token;
    // const char* delimiter = ",";

    // while (fgets(line, sizeof(line), fp) != NULL) {
    //     printf("--------------------\n");
        
    //     token = strtok(line, delimiter);
    //     int field_count = 0;
        
    //     while (token != NULL) {
    //         switch(field_count) {
    //             case 0:
    //                 printf("ID: %s\n", token);
    //                 break;
    //             case 1:
    //                 printf("Name: %s\n", token);
    //                 break;
    //             case 2:
    //                 printf("Age: %s\n", token);
    //                 break;
    //             case 3:
    //                 printf("Height: %s\n", token);
    //                 break;
    //             case 4:
    //                 printf("Weight: %s\n", token);
    //                 break;
    //             default:
    //                 printf("Extra field: %s\n", token);
    //         }
            
    //         token = strtok(NULL, delimiter);
    //         field_count++;
    //     }
        
    //     printf("--------------------\n");
    // }

    fclose(fp);
    return 0;
}
