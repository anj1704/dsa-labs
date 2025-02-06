#include <stdio.h>
#include <stdlib.h>

// typedef struct node* NODE;
// typedef struct node {
//     char d;
//     NODE next;
// } node;

// typedef struct list* LIST;
// typedef struct list {
//     NODE head;
// } list;

// NODE createNewNode(char data) {
//     NODE newNode = (NODE)malloc(sizeof(node));
//     newNode->d = data;
//     newNode->next = NULL;
//     return newNode;
// }

// void insertFirst(LIST myList, char data) {
//     NODE newNode = createNewNode(data);
//     newNode->next = myList->head;
//     myList->head = newNode;
// }

// void sortList(LIST myList) {
//     if (myList->head == NULL || myList->head->next == NULL)
//         return;

//     NODE sorted = NULL;

//     NODE current = myList->head;
//     while (current != NULL) {
//         NODE nextNode = current->next;

//         if (sorted == NULL || current->d < sorted->d) {
//             current->next = sorted;
//             sorted = current;
//         } else {
//             NODE temp = sorted;
//             while (temp->next != NULL && temp->next->d < current->d) {
//                 temp = temp->next;
//             }
//             current->next = temp->next;
//             temp->next = current;
//         }

//         current = nextNode;
//     }

//     myList->head = sorted;
// }

// LIST createNewList() {
//     LIST n = (LIST)malloc(sizeof(list));
//     n->head = NULL;
//     return n;
// }

char* intervalSort(char arr[], int n) {
    int count[128] = {0};

    for (int i = 0; i < n; i++) {
        count[(int)arr[i]]++;
    }

    for (int i = 1; i < 128; i++) {
        count[i] += count[i - 1];
    }

    char* sortedArray = (char*)malloc(n * sizeof(char));
    if (sortedArray == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    for (int i = n - 1; i >= 0; i--) {
        sortedArray[count[(int)arr[i]] - 1] = arr[i];
        count[(int)arr[i]]--;
    }

    return sortedArray;
}

int main() {
    int n;
    printf("Enter the length of String: ");
    scanf("%d", &n);
    char *A = (char *)malloc(n * sizeof(char));
    if (A == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    printf("Enter the String: ");
    scanf("%s", A);

    printf("The sorted array is: ");
    char* sortedA = intervalSort(A, n);
    printf("%s\n", sortedA);

    free(A);
    free(sortedA);

    return 0;
}
