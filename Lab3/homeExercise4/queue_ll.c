#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "linked_list.h"

#define QUEUE_MAX 100

struct Queue{

    LIST l;

};

Queue *createQueue(){
    
    Queue *q = (Queue*) malloc(sizeof(Queue));
    q->l = createNewList();
    return q;

}

bool enqueue(Queue *queue, Process element){
    
    if (queue->l->count > QUEUE_MAX) return false;

    NODE n = createNewNode(element);
    insertNodeAtEnd(n,queue->l);
    return true;

}

Process *front(Queue *queue){

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
    free(queue);

}
