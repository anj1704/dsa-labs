#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

int factNTR(int n){

    if (n == 0){

        return 1;

    }

    else
    {

        return n * factNTR(n-1);

    }

}

int factTR(int n, int acc)
{
    if (n == 0)
    {
        return acc;
    }
    else
    {
        return factTR(n - 1, n*acc);
    }
}

int factI(int n)
{
    int acc = 1;
    while (n > 0)
    {
        acc *= n;
        n -= 1;
    }

    return acc;
}

int main(int argc, char** argv)
{
    struct timeval t1, t2;
    double time_taken;
    int n = atoi(argv[1]);

    gettimeofday(&t1, NULL);
    factNTR(n);
    gettimeofday(&t2, NULL);
    
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("non-tail recursive factorial finding took %f seconds to execute\n", time_taken);
    
    gettimeofday(&t1, NULL);
    factTR(n, 1);
    gettimeofday(&t2, NULL);
    
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("Tail recursive factorial finding took %f seconds to execute\n", time_taken);

    gettimeofday(&t1, NULL);
    factI(n);
    gettimeofday(&t2, NULL);
    
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("Iterative factorial finding took %f seconds to execute\n", time_taken);
    
    return 0;
}