#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO a lot of stuff
typedef struct node* NODE;
struct node{

    int ele;
    NODE next;

};

typedef struct linked_list* LIST;
struct linked_list{

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

NODE createNewNode(int value){

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

void deleteFirst(LIST l1){

    if(l1->head == NULL){

        printf("Empty list\n");
        return;

    }
    else{

        NODE temp = l1->head;
        NODE prev = temp;
        temp = temp->next;
        free(prev);
        l1->head = temp;
        l1->count--;

    }
}

LIST createNum(char* num){

    LIST myNumber = createNewList();

    int len = strlen(num);

    for (int i = 0; i < len; i++){

        insertFirst(createNewNode((int) *(num+i)), myNumber);

    }

    return myNumber;

}

void printList(LIST l1){

    char* output = (char *) malloc(sizeof(char)*l1->count);
    int i = 0;
    NODE temp = l1->head;
    printf("[HEAD] ->");

    while(temp!=NULL){

        output[l1->count-i-1] = temp->ele;
        printf(" %c ->", temp->ele);
        temp = temp->next;
        i++;

    }
    printf("[NULL]\n");
    printf("%s\n", output);

}

LIST add(LIST n1, LIST n2){

    int carry = 0;
    int index = 0;

    NODE temp1 = n1->head;
    NODE temp2 = n2->head;

    if (n1->count > n2->count){

        while (temp2->next != NULL){

            temp2 = temp2->next;

        }
        for (int i = 0; i < (n1->count-n2->count); i++){

            temp2->next = createNewNode(0);
            temp2 = temp2->next;
            n2->count++;

        }
        printf("Checking if condition :\n");
        printList(n2);

    }

    else if (n1->count < n2->count){

        while (temp1->next != NULL){

            temp1 = temp1->next;

        }
        for (int i = 0; i < (n2->count-n1->count); i++){

            temp1->next = createNewNode(0);
            temp1 = temp1->next;
            n1->count++;

        }

    }

    printList(n1);
    printf("\n");
    printList(n2);

    char* output = (char *) malloc(sizeof(char)*n1->count);
    temp1 = n1->head;
    temp2 = n2->head;

    while(index != n1->count){

        int sum = temp1->ele + temp2->ele + carry;
        if (sum > 10){

            carry = 1;
            sum -= 10;

        }
        else {

            carry = 0;

        }
        output[index] = (char) sum;
        index++;

    }
    if (carry == 1){

        output = realloc(output, strlen(output+1)*sizeof(char));
        output[index] = '1';

    }

    return createNum(output);

}

int main(){

    LIST num1 = createNum("11111");
    LIST num2 = createNum("1111");

    printList(num1);
    printList(num2);

    LIST sum = add(num1, num2);
    printList(sum);

    return 0;
    
}
