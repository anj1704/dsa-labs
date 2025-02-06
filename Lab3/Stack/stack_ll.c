#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "linked_list.h"
#include "heap_usage.h"

#define STACK_MAX 100

struct Stack{

    LIST l;

};

Stack *newStack(){
    
    Stack *s = (Stack*) myalloc(sizeof(Stack));
    s->l = createNewList();
    return s;

}

bool push(Stack *stack, Element element){
    
    if (stack->l->count > STACK_MAX) return false;

    NODE n = createNewNode(element);
    insertNodeIntoList(n,stack->l);
    return true;

}

Element *top(Stack *stack){

    if (stack->l->head == NULL){

        return NULL;

    }

    return stack->l->head;

}

Element *pop(Stack *stack){
    
    Element *ele = stack->l->head;
    removeFirstNode(stack->l);
    return ele;

}

bool isEmpty(Stack *stack){

    if (stack->l->head == NULL){

        return true;

    }

    return false;

}

void freeStack(Stack *stack){

    destroyList(stack->l);
    myfree(stack);

}
