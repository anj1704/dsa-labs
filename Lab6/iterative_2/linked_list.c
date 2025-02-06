#include "element.h"
#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

LIST createNewList(){
    
    LIST l = (LIST) malloc(sizeof(linked_list));
    l->count = 0;
    l->head = NULL;
    
    return l;

}

NODE createNewNode(Element data){
    
    NODE n;
    n = (NODE) malloc(sizeof(node));
    n->data = data;
    n->next = NULL;

    return n; 
    
}

void insertNodeIntoList(NODE node, LIST list){
    
    NODE temp = list->head;
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

// void insertNodeAtEnd(NODE node, LIST list); // Not required for stack. Required for Queue
// This function inserts a node at the end of the list.

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
