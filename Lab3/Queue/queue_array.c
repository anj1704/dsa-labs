#include "element.h"
#include "queue.h"
#include "heap_usage.h"
#include <stdlib.h>

#define QUEUE_SIZE 100

struct Queue{

    int size;
    Element data[QUEUE_SIZE];

};

Queue *createQueue(){

    Queue *q = (Queue *)myalloc(sizeof(Queue));
    if(q != NULL)
         q->size = 0;
    return q;

}

bool enqueue(Queue *q, Element e){

    if(q->size == QUEUE_SIZE)
        return false;
    q->data[q->size++] = e;
    return true;

}

bool dequeue(Queue *q){

    if(q->size == 0)
        return false;
    for (int i = 0; i < q->size-1; i++){
        q->data[i] =  q->data[i+1]; 
    }
    q->size--;
    return true;

}

int size(Queue *q)
{

   return q->size;

}

Element *front(Queue *q){
    
    if(q->size == 0)
        return NULL;
    return &(q->data[0]);

}

bool isEmpty(Queue *q){
    
    if(q->size == 0)
        return true;
    return false;
}

void destroyQueue(Queue *queue){

    myfree(queue);

}

