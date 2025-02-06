#include <stdio.h>
#include <stdlib.h>

int main(){

    int n = 10;
    int* p = (int *) malloc(n);
    if(p == NULL){

        printf("Unable to allocate memory\n");
        return -1;

    }

    printf("Allocated %d bytes of memory\n", n);
    free(p);

    float *q;
    q = (float *) malloc(10*sizeof(float));

    if (q == NULL){

        return 1;

    }

    for (int i = 0; i < 10; i++){

        q[i] = (float) i/10;

    }

    for (int i = 0; i < 10; i++){

        printf("%f\n", *(q+i));

    }

    free(q);

    // memory leak 
    int* a; int* b;
    a = (int*) malloc(1000*sizeof(int));
    b = (int*) malloc(sizeof(int));
    a = b;

    
    return 0;
    
}