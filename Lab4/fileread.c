#include <stdio.h>

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
    
    printf("HI");
    person *A = (person *) malloc(1000*sizeof(person));
    int k =  0;

    FILE* fp = fopen("dat1000.csv", "r");
 
    if (!fp)
        printf("Can't open file\n");
 
    else {
        // Here we have taken size of
        // array 1024 you can modify it
        char buffer[1024];
 
        int row = 0;
        int column = 0;
 
        while (fgets(buffer,
                     1024, fp)) {
            column = 0;
            row++;
 
            // To avoid printing of column
            // names in file can be changed
            // according to need
            if (row == 1)
                continue;
 
            // Splitting the data
            char* value = strtok(buffer, ", ");
 
            while (value) {
                // Column 1
                if (column == 0) {
                   
                   A[k].id = (int) value;
                }
 
                // Column 2
                if (column == 1) {
                    A[k].name = value;
                }
 
                // Column 3
                if (column == 2) {
                    A[k].age = (int) value;
                }

                //Column4
                if (column == 3){

                    A[k].height= (int) value;
                }

                //Column5 
                if (column == 4){

                    A[k].weight= (int) value;
                }
              
                value = strtok(NULL, ", ");
                column++;
            }
            printf("%d %s %d %d %d\n", A[k].id,A[k].name,A[k].age, A[k].height, A[k].weight);
            k++;
            printf("\n");
        }
 
        // Close the file
        fclose(fp);
    }
}
