#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void insertAfter(int searchEle, NODE n1, LIST l1){

    if(l1->head == NULL){

        l1->head = n1;
        n1->next = NULL;
        l1->count++;

    }
    else{

        NODE temp = l1->head;
        NODE prev = temp;
        while(temp != NULL){

            if(temp->ele == searchEle) break;
            prev = temp;
            temp = temp->next;

        }
        if (temp == NULL){

            printf("Element not found.\n");
            return;

        }
        else{

            if(temp->next == NULL){

                temp->next = n1;
                n1->next = NULL;
                l1->count++;

            }

            else{

                prev = temp;
                temp = temp->next;
                prev->next = n1;
                n1->next = temp;
                l1->count++;

            }

            return;

        }
    }

    return;
    
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

void deleteAt(int searchEle,LIST l1){

    if(l1->head == NULL){

        printf("Empty list\n");
        return;

    }
    else{

        NODE temp = l1->head;
        NODE prev = temp;
        if (temp->ele == searchEle){

            l1->head = temp->next;
            return;

        }
        while(temp!=NULL){

            if (temp->ele == searchEle){

                prev->next = temp->next;
                free(temp);
                l1->count--;
                return;

            }

            prev = temp;
            temp = temp->next;
        }

        printf("Element not found.\n");
        return;

    }

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

int search(int searchEle, LIST l1){

    if(l1->head == NULL){

        printf("Empty list.\n");

    }
    else{

        int count = 0;
        NODE temp = l1->head;
        NODE prev = temp;
        while(temp != NULL){

            if(temp->ele == searchEle) return count;
            prev = temp;
            temp = temp->next;
            count++;

        }
        if (temp == NULL){

            return -1;

        }
        
    }

    return -1;

}

//task 8 
void rotate(int k, LIST l1){

    NODE temp = l1->head;
    while (temp->next!= NULL){

        temp = temp->next;

    }
    temp->next = l1->head;

    NODE flag = l1->head;
    NODE prev = flag;

    while(k--){

        prev = flag;
        flag = flag->next;

    }

    l1->head = flag;
    prev->next = NULL;

}

bool hasCycle(LIST l1){

    if(l1->head == NULL){

        printf("Empty list.\n");
        return false;

    }
    NODE hare = l1->head;
    NODE tortoise = l1->head;
    while(hare != NULL && tortoise != NULL && hare->next != NULL){

        hare = hare->next->next;
        tortoise = tortoise->next;
        if (hare == tortoise) return true;

    }
    return false;
}

void circularLLCycleCheck(LIST l1){

    NODE temp = l1->head;
    while (temp->next!= NULL){

        temp = temp->next;

    }
    temp->next = l1->head;

    printf("Circular linked list created.\n");
    printf("Detecting cycle - should give true :\n");
    hasCycle(l1) ? printf("Cycle present\n") : printf("Cycle absent");
    printf("Disconnecting circular linked list.\n");
    temp->next = NULL;
    printf("Testing :\n");
    hasCycle(l1) ? printf("Cycle present\n") : printf("Cycle absent");

}

void reverse(LIST l1){

    // home exercise 5
    if (l1->head == NULL || l1->head->next == NULL){

        return;

    }

    NODE curr, prev, nex;
    curr = l1->head;
    prev = NULL;
    nex = NULL;

    while (curr != NULL){

        nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nex;

    }
    l1->head = prev;

    return;

}

int main(){

    LIST ll = createNewList();
    int a,b,c,d,f,k;
    int flag = -1;

    while(flag != 0){

        printf("\nWhat would you like to do ?\n");
        printf("1. Add a node and insert after node with a given value.\n");
        printf("2. Delete an element with its value.\n");
        printf("3. Insert at first node.\n");
        printf("4. Delete at first node.\n");
        printf("5. Display all elements.\n");
        printf("6. Search for an element with its value.\n");
        printf("7. Rotate the linked list by k steps.\n");
        printf("8. Check for a cycle.\n");
        printf("9. Demo test on a cyclic linked list.\n");
        printf("10. Reverse the linked list.\n");
        printf("0. Exit.\n");

        printf("Enter your input.\n");
        scanf(" %d", &flag);

        switch(flag){

            case 1:
                printf("Enter value of node and search value.\n");
                scanf("%d %d", &a, &b);
                insertAfter(b, createNewNode(a),ll);
                break;
            case 2:
                printf("Enter value of node to delete.\n");
                scanf("%d", &c);
                deleteAt(c,ll);
                break;
            case 3:
                printf("Enter value of node to add at first position.\n");
                scanf("%d", &d);
                insertFirst(createNewNode(d), ll);
                break;
            case 4:
                deleteFirst(ll);
                break;
            case 5:
                printList(ll);
                break;
            case 6:
                printf("Enter value of element to search for.\n");
                scanf("%d", &f);
                printf("Node is present at location = %d\n", search(f, ll));
                break;
            case 7:
                printf("Enter number of steps to rotate linked list by.\n");
                scanf("%d", &k);
                rotate(k, ll);
                break;
            case 8:
                hasCycle(ll) ? printf("Cycle present\n") : printf("Cycle absent");
                break;
            case 9:
                circularLLCycleCheck(ll);
                break;
            case 10:
                reverse(ll);
                break;
            case 0:
                break;
            default:
                printf("Invalid input !\n");
                break;

        }

    }

    return 0;
}

