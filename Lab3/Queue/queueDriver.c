#include "queue.h"
#include "heap_usage.h"
#include <stdio.h>
#include <sys/time.h>

Element itoe (int i);

int main()
{   

    struct timeval t1,t2;
    double time_taken;

    gettimeofday(&t1, NULL);
    Queue *q = createQueue();
    gettimeofday(&t2, NULL);
    if(isEmpty(q))
        printf("Queue is empty\n");
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("The queue creation took %f seconds to execute\n", time_taken);
    printf("Heap memory used so far = %zu\n", heapMemoryAllocated);
    
    gettimeofday(&t1, NULL);
    enqueue(q, itoe(1));
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("Enqueuing an element took %f seconds to execute\n", time_taken);
    printf("Heap memory used so far = %zu\n", heapMemoryAllocated);

    gettimeofday(&t1, NULL);
    int value = front(q)->int_value;
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("Top of stack is %d\n", value);
    printf("Accesing the front took %f seconds to execute\n", time_taken);
    printf("Heap memory used so far = %zu\n", heapMemoryAllocated);

    enqueue(q, itoe(2));
    value = front(q)->int_value;
    printf("Front of queue is %d\n", value);
    printf("Heap memory used so far = %zu\n", heapMemoryAllocated);

    value = front(q)->int_value;
    printf("Front of queue is %d\n", value);
    printf("Heap memory used so far = %zu\n", heapMemoryAllocated);
    
    gettimeofday(&t1, NULL);
    dequeue(q);
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("Dequeuing from a stack took %f seconds to execute\n", time_taken);
    printf("Heap memory used so far = %zu\n", heapMemoryAllocated);

    value = front(q)->int_value;
    printf("Front of queue is %d\n", value);
    printf("Dequeue returned %s\n", dequeue(q)?"true":"false");
    printf("Heap memory used so far = %zu\n", heapMemoryAllocated);

    printf("Trying to dequeue an empty stack\n");
    printf("Dequeue returned %s\n", dequeue(q)?"true":"false");
    printf("Heap memory used so far = %zu\n", heapMemoryAllocated);

    gettimeofday(&t1, NULL);
    destroyQueue(q);
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("Destroying the queue took %f seconds to execute\n", time_taken);
    printf("Heap memory used so far = %zu\n", heapMemoryAllocated);

    return 0;
}
Element itoe (int i)
{
    Element e;
    e.int_value = i;
    e.float_value = 0;
    return e;
}
