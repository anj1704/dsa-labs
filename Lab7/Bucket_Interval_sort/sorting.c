#include <stdio.h>
#include <stdlib.h>

typedef struct node* NODE;
struct node
{

    int ele;
    NODE next;

};

typedef struct linked_list* LIST;
struct linked_list
{

    int count;
    NODE head;

};
LIST createNewList(){
    LIST myList;
    myList = (LIST) malloc(sizeof(struct linked_list));
    if (myList == NULL){

        printf("Unable to allocate memory.\n");
        exit(1);

    }

    myList->count = 0;
    myList->head = NULL;

    return myList;
}
NODE createNewNode(float value){
    NODE myNode;
    myNode = (NODE) malloc(sizeof(struct node));
    if (myNode == NULL){

        printf("Unable to allocate memory.\n");
        exit(1);

    }
    myNode->ele = value;
    myNode->next = NULL;
    return myNode;
}
void insertFirst(NODE value, LIST l1){
    value->next = l1->head;
    l1->head = value;
    l1->count++;
}
void printList(LIST l1){
    NODE temp = l1->head;
    printf("[HEAD] ->");
    while(temp!=NULL){

        printf(" %d ->", temp->ele);
        temp = temp->next;

    }
    printf("[NULL]\n");
}
void sortList(LIST l1){
    NODE temp1 = l1->head;
    int temp;
    NODE temp2;
    while (temp1 != NULL) {
        temp2 = temp1->next;
        while (temp2 != NULL) {
        if (temp1->ele > temp2->ele) {
            temp = temp1->ele;
            temp1->ele = temp2->ele;
            temp2->ele = temp;
        }
        temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
}

int main()
{
    LIST l1 = createNewList();
    insertFirst(createNewNode(1), l1);
    insertFirst(createNewNode(10), l1);
    insertFirst(createNewNode(2), l1);
    insertFirst(createNewNode(9), l1);
    insertFirst(createNewNode(3), l1);
    insertFirst(createNewNode(8), l1);
    insertFirst(createNewNode(4), l1);

    printList(l1);
    sortList(l1);
    printList(l1);

    return 0;
}
