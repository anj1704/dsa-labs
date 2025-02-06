#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO addition of number of different lengths
typedef struct Node {
    int digit;
    struct Node* next;
} NODE;

typedef struct LinkedList {
    int count;
    NODE* head;
} LIST;

LIST* createNewList() {
    LIST* myList = (LIST*)malloc(sizeof(LIST));
    if (myList == NULL) {
        printf("Unable to allocate memory.\n");
        exit(1);
    }
    myList->count = 0;
    myList->head = NULL;
    return myList;
}

NODE* createNewNode(int value) {
    NODE* myNode = (NODE*)malloc(sizeof(NODE));
    if (myNode == NULL) {
        printf("Unable to allocate memory.\n");
        exit(1);
    }
    myNode->digit = value;
    myNode->next = NULL;
    return myNode;
}

void insertFirst(NODE* value, LIST* l1) {
    value->next = l1->head;
    l1->head = value;
    l1->count++;
}

void printList(LIST* l1) {
    NODE* temp = l1->head;
    printf("[HEAD] -> ");
    while (temp != NULL) {
        printf("%d -> ", temp->digit);
        temp = temp->next;
    }
    printf("[NULL]\n");
}

LIST* add(LIST* n1, LIST* n2) {
    int carry = 0;
    LIST* sum = createNewList();

    NODE* temp1 = n1->head;
    NODE* temp2 = n2->head;

    while (temp1 != NULL || temp2 != NULL) {
        int d1 = (temp1 != NULL) ? temp1->digit : 0;
        int d2 = (temp2 != NULL) ? temp2->digit : 0;

        int digitSum = d1 + d2 + carry;
        carry = digitSum / 10;
        digitSum %= 10;

        NODE* newNode = createNewNode(digitSum);
        insertFirst(newNode, sum);

        if (temp1 != NULL) temp1 = temp1->next;
        if (temp2 != NULL) temp2 = temp2->next;
    }

    if (carry > 0) {
        NODE* newNode = createNewNode(carry);
        insertFirst(newNode, sum);
    }

    return sum;
}

int main() {
    LIST* num1 = createNewList();
    LIST* num2 = createNewList();

    char num1Str[] = "9";
    char num2Str[] = "1";

    for (int i = strlen(num1Str) - 1; i >= 0; i--) {
        NODE* newNode = createNewNode(num1Str[i] - '0');
        insertFirst(newNode, num1);
    }

    for (int i = strlen(num2Str) - 1; i >= 0; i--) {
        NODE* newNode = createNewNode(num2Str[i] - '0');
        insertFirst(newNode, num2);
    }

    printf("Number 1: ");
    printList(num1);
    printf("Number 2: ");
    printList(num2);

    LIST* result = add(num1, num2);

    printf("Sum: ");
    printList(result);

    return 0;
}

