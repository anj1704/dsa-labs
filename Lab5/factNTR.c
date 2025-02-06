#include <stdio.h>

int factNTR(int n){

    if (n == 0){

        return 1;

    }

    else
    {

        return n * factNTR(n-1);

    }

}