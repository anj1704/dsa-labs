#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

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

void printList(LIST l1)
{
    NODE temp = l1->head;
    printf("[HEAD] ->");
    while(temp!=NULL){

        printf(" %d ->", temp->ele);
        temp = temp->next;

    }
    printf("[NULL]\n");

}

void insertFirst(NODE value, LIST l1){

    value->next = l1->head;
    l1->head = value;
    l1->count++;

}
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1],
           that are greater than key,
           to one position ahead of
           their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void sortList(LIST l1)
{
    int arr[l1->count];
    int i = 0;
    NODE temp = l1->head;
    while (temp != NULL)
    {
        arr[i] = temp->ele;
        i++;
        temp = temp->next;
    }
    insertionSort(arr, i);
    temp = l1->head;
    i = 0;
    while (temp != NULL)
    {
        temp->ele = arr[i];
        i++;
        temp = temp->next;
    }
}

void intervalSort(int arr[], int n, int m)
{
    int i, j;
    // Determine the number of buckets based on the maximum value in the array
    // int buckets = m > n ? n : m;

    // hard coding the value 10
    // int buckets = m/10;
    // possible scheme for number of buckets
    int buckets = sqrt(m);
    LIST b[buckets];
    for(i=0; i<buckets; i++)
    {
        b[i] = createNewList();
    }
    // Put array elements in different buckets
    for(i=0; i<n; i++)
    {
        // Calculate the bucket index based on the value and the number of buckets
        int bucketIndex = (arr[i] * buckets) / (m + 1);
        insertFirst(createNewNode(arr[i]), b[bucketIndex]);
    }
    // Sort individual buckets
    for(i=0; i<buckets; i++)
    {
        sortList(b[i]);
    }
    // Concatenate all buckets (in sequence) into arr[]
    for(i=0, j=0; i<buckets; i++)
    {
        NODE temp = b[i]->head;
        while(temp != NULL)
        {
            arr[j++] = temp->ele;
            temp = temp->next;
        }
    }
}


void printArray(int arr[], int n)
{
    printf("The array is : \n");
    for (int i = 0; i < n; i++)
    {
       printf(" %d", arr[i]);
    }
    printf("\n");
}

int main()
{   
    srand(time(NULL));

    int n, m;

    printf("Enter the number of elements in array and range of numbers\n");
    scanf("%d %d", &n, &m);

    int *arr = (int*) malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % m;
    }

    printArray(arr, n);
    intervalSort(arr, n, m);
    printArray(arr, n);

    return 0;    
}
