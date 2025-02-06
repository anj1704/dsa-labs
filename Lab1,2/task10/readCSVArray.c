#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "task.h"
#include <sys/time.h>

student * readArray(){
    
    printf("Reading into dynamically allocated array:\n");
    
    student *A = (student *) malloc(10000*sizeof(student));
    struct timeval t1, t2;
    double time_taken;

    gettimeofday(&t1, NULL);
    FILE* fp = fopen("data.txt", "r");
    
    if (!fp){

        printf("Can't open file\n");

    }
    else{

        for (int k = 0; k < 10000; k++){

            (A+k)->ID = (char *) malloc(13*sizeof(char));
            fscanf(fp, "%[^,],%lf", (A+k)->ID, &(A+k)->CGPA);

        }
        fclose(fp);
    }
    gettimeofday(&t2, NULL);

    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("The tasks took %f seconds to execute\n", time_taken);

    return A;

}
