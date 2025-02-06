#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "linked_list.h"
#include "heap_usage.h"

#define QUEUE_MAX 100

struct Queue{

    LIST l;

};

Queue *createQueue(){
    
    Queue *q = (Queue*) myalloc(sizeof(Queue));
    q->l = createNewList();
    return q;

}

bool enqueue(Queue *queue, Element element){
    
    if (queue->l->count > QUEUE_MAX) return false;

    NODE n = createNewNode(element);
    insertNodeAtEnd(n,queue->l);
    return true;

}

Element *front(Queue *queue){

    if (queue->l->head == NULL){

        return NULL;

    }

    return &queue->l->head->data;

}

bool dequeue(Queue *queue){
    
    if (queue->l->count == 0) return false;
    removeFirstNode(queue->l);
    return true;

}

bool isEmpty(Queue *queue){

    if (queue->l->head == NULL){

        return true;

    }

    return false;

}

int size(Queue *queue){

    return queue->l->count;

}

void destroyQueue(Queue *queue){

    destroyList(queue->l);
    myfree(queue);

}
