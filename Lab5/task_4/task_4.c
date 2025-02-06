#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

typedef struct node * NODE;
struct node{
    int ele;
    NODE next;
};


typedef struct linked_list * LIST;
struct linked_list{
    int count;
    NODE head;
};


LIST createNewList()
{
    LIST myList;
    myList = (LIST) malloc(sizeof(struct linked_list));
    myList->count=0;
    myList->head=NULL;
    return myList;
}


NODE createNewNode(int value)
{
    NODE myNode;
    myNode = (NODE) malloc(sizeof(struct node));
    myNode->ele=value;
    myNode->next=NULL;
    return myNode;
}

int llSumNTR(NODE head)
{
    if (head == NULL)
        return 0;
    return head->ele + llSumNTR(head->next); 
}

int llSumNTRWrapper(LIST list)
{
    return llSumNTR(list->head);
}

int llSumTR(NODE head, int sum)
{
    if (head == NULL)
        return sum;
    return llSumTR(head->next, sum + head->ele); 
}

int llSumTRWrapper(LIST list)
{
    return llSumTR(list->head, 0);
}

int llSumIter(NODE head)
{   
    int sum = 0;
    NODE temp = head;
    while (temp->next != NULL)
    {
        sum += temp->ele;
        temp = temp->next;
    }
    
    return sum;
}

int llSumIterWrapper(LIST list)
{
    return llSumIter(list->head);
}

int main(int argc, char** argv)
{   
    char *filename = (char *) malloc(sizeof(char)*strlen(argv[1]));
    filename = argv[1];

    char substring[strlen(filename) - 7];
    strncpy(substring, argv[1] + 7, strlen(argv[1]) - 3);

    int n = atoi(substring);

    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    int num;
    LIST myList = createNewList();
    while (fscanf(fp, "%d", &num) != EOF)
    {
        NODE myNode = createNewNode(num);
        myNode->next = myList->head;
        myList->head = myNode;
        myList->count++;
    }
    fclose(fp);

    // Perform some operations on the linked list
    // ...

    // Example operation: Print the elements of the linked list
    // NODE temp = myList->head;
    // while (temp != NULL)
    // {
    //     printf("%d ", temp->ele);
    //     temp = temp->next;
    // }

    struct timeval t1, t2;
    double time_taken;

    gettimeofday(&t1, NULL);
    llSumNTRWrapper(myList);
    gettimeofday(&t2, NULL);
    
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("Non-tail recursive llsum finding took %f seconds to execute\n", time_taken);
    
    gettimeofday(&t1, NULL);
    llSumTRWrapper(myList);
    gettimeofday(&t2, NULL);
    
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("Tail recursive llsum took %f seconds to execute\n", time_taken);

    gettimeofday(&t1, NULL);
    llSumIterWrapper(myList);
    gettimeofday(&t2, NULL);
    
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("Iterative llsum took %f seconds to execute\n", time_taken);
    
    return 0;
}