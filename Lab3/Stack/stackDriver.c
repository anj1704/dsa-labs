#include "stack.h"
#include "heap_usage.h"
#include <stdio.h>
#include <sys/time.h>

Element itoe (int i);

int main()
{   

    struct timeval t1,t2;
    double time_taken;

    gettimeofday(&t1, NULL);
    Stack *s = newStack();
    gettimeofday(&t2, NULL);
    if(isEmpty(s))
        printf("Stack is empty\n");
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("The stack creation took %f seconds to execute\n", time_taken);
    printf("Heap memory used so far = %zu\n", heapMemoryAllocated);
    
    gettimeofday(&t1, NULL);
    push(s, itoe(1));
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("Pushing an element took %f seconds to execute\n", time_taken);
    printf("Heap memory used so far = %zu\n", heapMemoryAllocated);

    gettimeofday(&t1, NULL);
    int value = top(s)->int_value;
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("Top of stack is %d\n", value);
    printf("Accesing the top took %f seconds to execute\n", time_taken);
    printf("Heap memory used so far = %zu\n", heapMemoryAllocated);

    push(s, itoe(2));
    value = top(s)->int_value;
    printf("Top of stack is %d\n", value);
    printf("Heap memory used so far = %zu\n", heapMemoryAllocated);

    value = top(s)->int_value;
    printf("Top of stack is %d\n", value);
    printf("Heap memory used so far = %zu\n", heapMemoryAllocated);
    
    gettimeofday(&t1, NULL);
    pop(s);
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("Popping from a stack took %f seconds to execute\n", time_taken);
    printf("Heap memory used so far = %zu\n", heapMemoryAllocated);

    value = top(s)->int_value;
    printf("Top of stack is %d\n", value);
    printf("Pop returned %s\n", pop(s)?"true":"false");
    printf("Heap memory used so far = %zu\n", heapMemoryAllocated);

    printf("Trying to pop an empty stack\n");
    printf("Pop returned %s\n", pop(s)?"true":"false");
    printf("Heap memory used so far = %zu\n", heapMemoryAllocated);

    gettimeofday(&t1, NULL);
    freeStack(s);
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("Freeing the stack took %f seconds to execute\n", time_taken);
    printf("Heap memory used so far = %zu\n", heapMemoryAllocated);

    s = newStack();
    Element e;
    e.int_value = 1;
    e.float_value = 1.0;

    // printf("Checking axioms of Stack ADT\n");
    // printf("isEmpty(newStack()) == TRUE : %s\n", isEmpty(newStack())?"true":"false");
    // printf("isEmpty(push(s,e)) == FALSE : %s\n", isEmpty(push(s,e))?"true":"false");
    // printf("top(push(s,e)) == e : %d\n", top(push(s,e)));
    // printf("pop(push(s,e)) == s : %p\n", pop(push(s,e)));

    return 0;
}
Element itoe (int i)
{
    Element e;
    e.int_value = i;
    e.float_value = 0;
    return e;
}
