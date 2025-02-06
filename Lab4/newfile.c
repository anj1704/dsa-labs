#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct person
{
    int id;
    char *name;
    int age;
    int height;
    int weight;

};

typedef struct person person;

int main(){
    
    person *A = (person *) malloc(1000*sizeof(person));

    FILE* fp = fopen("dat10.csv", "r");
    
    if (!fp){

        printf("Can't open file\n");

    }
    else{

        for (int k = 0; k < 10; k++){
            (A+k)->name = (char *) malloc(100*sizeof(char));
            fscanf(fp, "%d,%[^,],%d,%d,%d", &(A+k)->id, (A+k)->name, &(A+k)->age, &(A+k)->height, &(A+k)->weight);
            printf("%d %s %d %d %d\n", A[k].id,A[k].name,A[k].age, A[k].height, A[k].weight);
        }
        fclose(fp);
    }


    free(A);
    return 0;
    // if (!fp)
    //     printf("Can't open file\n");
 
    // else {
    //     // Here we have taken size of
    //     // array 1024 you can modify it
    //     char buffer[1024];
 
    //     int row = 0;
    //     int column = 0;
 
    //     while (fgets(buffer,
    //                  1024, fp)) {
    //         column = 0;
    //         row++;
 
    //         // To avoid printing of column
    //         // names in file can be changed
    //         // according to need
    //         // if (row == 1)
    //         //     continue;
 
    //         // Splitting the data
    //         char* value = strtok(buffer, ", ");
 
    //         while (value) {
    //             // Column 1
    //             if (column == 0) {
                   
    //                A[k].id = atoi(value);
    //             }
 
    //             // Column 2 - BREAKS DUE TO SPACE IN NAME
    //             if (column == 1) {
    //                 A[k].name = value;
    //             }
 
    //             // Column 3
    //             if (column == 2) {
    //                 A[k].age = atoi(value);
    //             }

    //             //Column4
    //             if (column == 3){

    //                 A[k].height= atoi(value);
    //             }

    //             //Column5 
    //             if (column == 4){

    //                 A[k].weight= atoi(value);
    //             }
              
    //             value = strtok(NULL, ", ");
    //             column++;
    //         }
    //         printf("%d %s %d %d %d\n", A[k].id,A[k].name,A[k].age, A[k].height, A[k].weight);
    //         k++;
    //         printf("\n");
    //     }
 
    //     // Close the file
    //     fclose(fp);
    // }

}