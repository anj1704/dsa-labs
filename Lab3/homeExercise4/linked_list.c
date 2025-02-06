#include "linked_list.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

LIST createNewList(){
    
    LIST l = (LIST) malloc(sizeof(linked_list));
    l->count = 0;
    l->head = NULL;
    l->tail = NULL;
    
    return l;

}

NODE createNewNode(Process data){
    
    NODE n;
    n = (NODE) malloc(sizeof(node));
    n->data = data;
    n->next = NULL;

    return n; 
    
}

void insertNodeIntoList(NODE node, LIST list){
    
    NODE temp = list->head;
    if (temp == NULL) list->tail = node;
    list->head = node;
    node->next = temp;
    list->count++;

}

void removeFirstNode(LIST list){
    
    NODE temp = list->head;
    if (temp == NULL) return;
    
    list->head = temp->next;
    free(temp);
    list->count--;

}

void insertNodeAtEnd(NODE node, LIST list){

    if (list->head == NULL){

        insertNodeIntoList(node, list);
        
    }
    list->tail->next = node;
    node->next = NULL;
    list->tail = node;
    list->count++;

}

void destroyList(LIST list){

    NODE temp = list->head;
    NODE next;

    while(temp != NULL){

        next = temp->next;
        free(temp);
        temp = next;

    }

    free(list);

}
