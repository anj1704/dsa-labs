#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int** matrixGen(int n){

    int ** mat = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        mat[i] = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat[i][j] = rand() % 100;
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {   
    //         // a[i][j]=a[i][j]+b[i][j];
    //         printf("%d", mat[i][j]);
    //     }
        
    // }
        return mat;
}

void matrixRowAdd(int** a, int** b, int n){

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {   
            a[i][j]=a[i][j]+b[i][j];
            // printf("%d", a[i][j]);
        }
        
    }
    
}

void matrixColAdd(int** a, int** b, int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {   
            a[j][i]=a[j][i]+b[j][i];
        }
        
    }
    
}

int main(void)
{
    int** matA, **matB ;
    int n=10000;
    // scanf("%d", &n);
   matA = matrixGen(n);
    matB = matrixGen(n);

    struct timeval start , end;
    gettimeofday(&start, NULL);
    matrixRowAdd(matA, matB, n);
    gettimeofday(&end, NULL);
    long long totTime= start.tv_sec*1000000+start.tv_usec-end.tv_sec*1000000+end.tv_usec;
    printf("Row: %lld\n", totTime);

    gettimeofday(&start, NULL);
    matrixColAdd(matA, matB, n);
    gettimeofday(&end, NULL);
    totTime= start.tv_sec*1000000+start.tv_usec-end.tv_sec*1000000+end.tv_usec;
    printf("Col: %lld\n", totTime);

}

