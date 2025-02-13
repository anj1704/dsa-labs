#include <stdio.h>
#include <stdlib.h>

/*
    DSA Lab Test 2
    28/4/2024
    ANJANEYA BAJAJ
    2022A7PS0164P
*/

// structs for linked list of IDs (integers)
// in the node the integer element repesents the ID of an item
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

// functions associated with linked lists of IDs (integers)
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

void printList(LIST l1)
{
    NODE temp = l1->head;
    printf("[HEAD] ->");
    while(temp != NULL)
    {
        printf(" %d ->", temp->ele);
        temp = temp->next;
    }
    printf(" [NULL]\n");
}

void insertFirst(NODE value, LIST l1)
{
    value->next = l1->head;
    l1->head = value;
    l1->count++;
}

// every SUPER_NODE has a linked list of integers as an element
typedef struct super_node* SUPER_NODE;
struct super_node
{
    LIST ele;
    SUPER_NODE next;
};

// every SUPER_LIST has a chain of SUPER_NODEs
// each SUPER_NODE holds a linked list of IDs
typedef struct super_linked_list* SUPER_LIST;
struct super_linked_list
{
    int count;
    SUPER_NODE head;
};

// functions associated with linked lists of linked lists
SUPER_LIST createNewSuperList()
{
    SUPER_LIST myList;
    myList = (SUPER_LIST) malloc(sizeof(struct super_linked_list));
    myList->count=0;
    myList->head=NULL;
    return myList;
}

SUPER_NODE createNewSuperNode(LIST value)
{
    SUPER_NODE myNode;
    myNode = (SUPER_NODE) malloc(sizeof(struct super_node));
    myNode->ele=value;
    myNode->next=NULL;
    return myNode;
}

void printSuperList(SUPER_LIST l1)
{
    SUPER_NODE temp = l1->head;
    printf("[SUPER HEAD] ->\n");
    while(temp != NULL)
    {
        printList(temp->ele);
        temp = temp->next;
    }
    printf(" \n[SUPER NULL]\n");
}

void insertSuperFirst(SUPER_NODE value, SUPER_LIST l1)
{
    value->next = l1->head;
    l1->head = value;
    l1->count++;
}

// utility function for createData()
// Given an array of integers, its length and a SUPER_LIST
// It creates a linked list of the given array of integers and
// inserts that into the SUPER_LIST
void list_inserter(SUPER_LIST list_of_lists, int *arr, int n)
{  
    LIST l1 = createNewList();
    for (int i = 0; i < n; i++)
    {
        insertFirst(createNewNode(arr[i]), l1);
    }
    insertSuperFirst(createNewSuperNode(l1), list_of_lists);
}

/*
    Question a
    INPUT : None
    OUTPUT : SUPER_LIST
    Creates a SUPER_LIST, inserts given database into it
    and returns it  
*/
SUPER_LIST createData()
{  
    // creating SUPER_LIST
    SUPER_LIST list_of_lists = createNewSuperList();

    // hardcoding database using utility function
    int arr_1[] = {27, 64, 98, 174};
    list_inserter(list_of_lists, arr_1, 4);

    int arr_2[] = {94, 174};
    list_inserter(list_of_lists, arr_2, 2);

    int arr_3[] = {76, 66, 174};
    list_inserter(list_of_lists, arr_3, 3);

    int arr_4[] = {94, 95, 96, 98, 89, 80, 81, 82, 83, 84, 86, 174};
    list_inserter(list_of_lists, arr_4, 12);

    int arr_5[] = {94, 19, 15, 16, 17, 18, 174};
    list_inserter(list_of_lists, arr_5, 7);

    int arr_6[] = {17, 19, 20, 48, 49, 73, 174};
    list_inserter(list_of_lists, arr_6, 7);

    int arr_7[] = {100, 36, 38, 75, 10, 95, 47, 28, 64, 174};
    list_inserter(list_of_lists, arr_7, 10);
   
    int arr_8[] = {99, 90, 98, 92, 94, 87, 174};
    list_inserter(list_of_lists, arr_8, 7);

    int arr_9[] = {76, 94, 5, 6, 97, 98, 99, 100, 174};
    list_inserter(list_of_lists, arr_9, 9);
   
    int arr_10[] = {72, 56, 94, 89, 97, 174};
    list_inserter(list_of_lists, arr_2, 6);

    int arr_11[] = {48, 57, 100, 95, 68, 94, 98, 174};
    list_inserter(list_of_lists, arr_11, 8);

    int arr_12[] = {40, 72, 89, 94, 174};
    list_inserter(list_of_lists, arr_12, 5);

    int arr_13[] = {92, 93, 56, 68, 174};
    list_inserter(list_of_lists, arr_13, 5);

    int arr_14[] = {67, 174};
    list_inserter(list_of_lists, arr_14, 2);

    int arr_15[] = {25, 32, 10, 94, 5, 2, 82, 74, 83, 174};
    list_inserter(list_of_lists, arr_15, 10);

    int arr_16[] = {90, 85, 73, 46, 89, 174};
    list_inserter(list_of_lists, arr_16, 6);

    int arr_17[] = {23, 68, 45, 100, 94, 87, 67, 174};
    list_inserter(list_of_lists, arr_17, 8);

    int arr_18[] = {1, 35, 100, 94, 64, 174};
    list_inserter(list_of_lists, arr_18, 6);

    int arr_19[] = {62, 65, 74, 174};
    list_inserter(list_of_lists, arr_19, 4);

    int arr_20[] = {100, 7, 5, 1, 998};
    list_inserter(list_of_lists, arr_20, 5);
   
    // returning SUPER_LIST with database inserted
    return list_of_lists;
}

// utility function for representData()
// Takes an array as input, returns the index of
// the maximum element in array
int max_index(int *arr, int n)
{
    int max = 0;

    // skipping arr[0] as we will use that in representData()
    // to hold the final answer
    for (int i = 1; i <= n; i++)
    {
        if (arr[max] < arr[i])
        {
            max = i;
        }
    }

    return max;
}

/*
    Question b
    INPUT : SUPER_LIST, int k
    OUTPUT : array of integers
    1...k here represents the range of values of the IDs to sort
    SUPER_LIST contains the database to sort
    An array of size = (k+1) is created - each element of the
    array is the frequency of ID equal to its own index
    After completion of processing, the first element of array
    i.e. arr[0] will contain the required ID
    This array is returned  
*/
int *representData(SUPER_LIST list_of_lists, int k)
{      
    // creating output array C, initialising all elements of C to 0
    int *C = (int*) malloc(sizeof(int)*(k+1));
    for (int i = 0; i <= k; i++)
    {
        C[i] = 0;
    }

    // total number of elements
    int n;

    // reading from the linked list to obtain a frequency array
    SUPER_NODE temp = list_of_lists->head;
    // outer loop traverses through the SUPER_LIST
    while (temp != NULL)
    {
        NODE inner_temp = temp->ele->head;
        // adding the count of each linked list of IDs to overall count
        n += temp->ele->count;

        // Inner loop traverses through every element of the
        // outer list i.e. through the linked list of IDs
        while(inner_temp != NULL)
        {  
            // performing the counting operation
            // incrementing the correct index in C to get frequency
            // of that ID, where ID = index
            C[inner_temp->ele]++;
            inner_temp = inner_temp->next;
        }

        temp = temp->next;
    }

    // calling utility function to get the index of the element
    // with maximum frequency
    // storing returned value as first element of array C
    C[0] = max_index(C, k);

    // returning the array
    return C;
}

/*
    Question c
    INPUT : array of integers
    OUTPUT : integer
    Receives the output of the representData() function as input array
    To obtain the ID of the maximum sold item, access the first
    element of input array
    Print the output and return its value
    Clearly, as we only need to access a single element of an array
    whose index is known,
    time complexity of function : O(1)
*/
int getMax(int *arr)
{  
    printf("Item %d is sold maximum !\n", arr[0]);
    return arr[0];
}

/*
    Question d
    main driver function for program
    Creates a new SUPER_LIST, gets the data using the createData()
    function, receives required data structure from the representData()
    function and gets the final answer from the getMax() function
*/
int main()
{
    SUPER_LIST list_of_lists = createData();
    // here k is the range of values the IDs vary from
    int *A = representData(list_of_lists, 200);
    int answer = getMax(A);

    return 0;
}
