#include "stack.h"
#include <stdlib.h>

#define STACK_SIZE 100

struct Stack{

    int top;
    int data[STACK_SIZE];

};

Stack *newStack(){

    Stack *s = (Stack *)malloc(sizeof(Stack));
    if(s != NULL)
         s->top = -1;
    return s;

}

bool push(Stack *s, int e){

    if(s->top == STACK_SIZE - 1)
        return false;
    s->data[++(s->top)] = e;
    return true;

}

int *top(Stack *s)
{

    if(s->top == -1)
        return NULL;
    return &(s->data[s->top]);

}
int *pop(Stack *s){
    
    if(s->top == -1)
        return NULL;
    s->top--;
    return &(s->data[s->top+1]);

}

bool isEmpty(Stack *s){
    
    if(s->top == -1)
        return true;
    return false;
}

void freeStack(Stack *stack){

    free(stack);

}

