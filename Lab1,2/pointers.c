#include <stdio.h>

int main(){

    int var = 20;
    int *ip = NULL;
    printf("Value of null pointer is = %x\n", ip);
    // %x can be replaced by %p here as well
    ip = &var;
    printf("Address of var variable is = %x\n", &var);
    printf("Address in ip is = %x\n", ip);
    printf("Value of *ip variable is = %d\n", *ip);

    return 0;

}