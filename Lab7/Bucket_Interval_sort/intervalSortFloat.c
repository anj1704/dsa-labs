#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node* NODE;
struct node
{
    float ele;
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
void sortList(LIST l1){
    NODE temp1 = l1->head;
    float temp;
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
void printArray(float arr[], int n)
{
    printf("The array is : \n");
    for (int i = 0; i < n; i++)
    {
       printf(" %lf", arr[i]);
    }
    printf("\n");
}
void intervalSort(float arr[], int n)
{
    int i, j;
    // Create n empty buckets
    
    LIST b[n];
    for(i=0; i<n; i++)
    {
        b[i] = createNewList();
    }
    // Put array elements in different buckets
    for(i=0; i<n; i++)
    {
        insertFirst(createNewNode(arr[i]), b[(int)(n*arr[i])]);
    }
    // Sort individual buckets
    for(i=0; i<n; i++)
    {
        sortList(b[i]); // sortList() function has to be implemented
    }
    // Concatenate all buckets (in sequence) into arr[]
    for(i=0, j=0; i<n; i++)
    {
        NODE temp = b[i]->head;
        while(temp != NULL)
        {
            arr[j++] = temp->ele;
            temp = temp->next;
        }
    }
}
int main()
{   
    srand(time(NULL));

    int n;

    printf("Enter the number of elements in array and range of numbers\n");
    scanf("%d", &n);

    float *arr = (float*) malloc(sizeof(float)*n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = (float) (rand() % 100) / 100;
    }

    printArray(arr, n);
    intervalSort(arr, n);
    printArray(arr, n);

    return 0;    
}
