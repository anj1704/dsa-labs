#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"
#include "binarySearchTree.h"
#include "linkedlist.h"

BST *new_bst() 
{
    BST* bst = (BST*) malloc(sizeof(BST));
    bst->root = NULL;
    return bst;
}

Node *new_node(int value) 
{
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void traverse_in_order(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    traverse_in_order(node->left);
    printf("%d ", node->value);
    traverse_in_order(node->right);
}

void insert(BST *bst, int value)
{
    Node *node = new_node(value);
    if (bst->root == NULL) 
    {
        bst->root = node;
        return;
    }
    Node *current = bst->root;
    while (current != NULL) 
    {
        if (value < current->value) 
        {
            if (current->left == NULL) 
            {
                current->left = node;
                return;
            }
            current = current->left;
        } 
        else 
        {
            if (current->right == NULL) 
            {
                current->right = node;
                return;
            }
            current = current->right;
        }
    }
}

int search(BST *bst, int key)
{
    Node *current = bst->root;
    while (current != NULL) 
    {
        if (key == current->value) 
        {
            return 1;
        } 
        else if (key < current->value) 
        {
            current = current->left;
        } 
        else 
        {
            current = current->right;
        }
    }
    return 0;
}

// int find_min(Node *node)
int find_min(BST *bst)
{
    // Node *current = node;
    Node *current = bst->root;
    while (current->left != NULL) 
    {
        current = current->left;
    }
    return current->value;
}

// int find_max(Node *node)
int find_max(BST *bst)
{
    // Node *current = node;
    Node *current = bst->root;
    while (current->right != NULL) 
    {
        current = current->right;
    }
    return current->value;
}

Node *predecessor(Node *node)
{   // works only if we use root as the input 
    if (node->left == NULL)
    {
        return NULL;
    }
    Node *current = node->left;
    while (current->right != NULL)
    {
        current = current->right;
    }
    return current;
}

Node *successor(Node *node)
{   // works only if we use root as the input
    if (node->right == NULL)
    {
        return NULL;
    }
    Node *current = node->right;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

void delete(BST *bst, Node *node)
{
    if (node == NULL)
        return;
    if (node->left == NULL && node->right == NULL)
    {
        // Node is a leaf
        Node* current = bst->root;
        while (current != NULL)
        {
            if (current->left == node)
            {
                current->left = NULL;
                break;
            }
            if (current->right == node)
            {
                current->right = NULL;
                break;
            }
            if (node->value < current->value)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        free(node);
        return;
    }
    
    if (node->left == NULL)
    {
        // Node only has right child
        Node* current = bst->root;
        if (current == node)
        {
            bst->root = node->right;
            free(node);
            return;
        }
        while (current != NULL)
        {
            if (current->left == node)
            {
                current->left = node->right;
                break;
            }
            if (current->right == node)
            {
                current->right = node->right;
                break;
            }
            if (node->value < current->value)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        free(node);
        return;
    }

    if (node->right == NULL)
    {
        // Node only has left child
        Node* current = bst->root;
        if (current == node)
        {
            bst->root = node->left;
            free(node);
            return;
        }
        while (current != NULL)
        {
            if (current->left == node)
            {
                current->left = node->left;
                break;
            }
            if (current->right == node)
            {
                current->right = node->left;
                break;
            }
            if (node->value < current->value)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        free(node);
        return;
    }

    // Node has both children
    Node *temp = successor(node);
    node->value = temp->value;
    delete(bst, temp);
    return;
}

// task 1
void traverse_pre_order(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    printf("%d ", node->value);
    traverse_pre_order(node->left);
    traverse_pre_order(node->right);
}

void traverse_post_order(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    traverse_post_order(node->left);
    traverse_post_order(node->right);
    printf("%d ", node->value);
}

void traverse_in_order_alternate(Node *node)
{
    if (node == NULL)
    {
        printf("NULL ");
        return;
    }
    traverse_in_order(node->left);
    printf("%d ", node->value);
    traverse_in_order(node->right);
}

void traverse_pre_order_alternate(Node *node)
{
    if (node == NULL)
    {
        printf("NULL ");
        return;
    }
    printf("%d ", node->value);
    traverse_pre_order(node->left);
    traverse_pre_order(node->right);
}

void traverse_post_order_alternate(Node *node)
{   
    if (node == NULL)
    {
        printf("NULL ");
        return;
    }
    traverse_post_order(node->left);
    traverse_post_order(node->right);
    printf("%d ", node->value);
}

//task 2
BST *constructBST(int *arr, int n)
{
    BST *bst = new_bst();
    for (int i = 0; i < n; i++)
    {
        insert(bst, arr[i]);
    }

    return bst;
}

int maxValue(struct node* node)
{
    if (node == NULL) 
    {
        return 0;
    }
    int leftMax = maxValue(node->left);
    int rightMax = maxValue(node->right);
    int value = 0;
    if (leftMax > rightMax) 
    {
        value = leftMax;
    }  
    else 
    {
        value = rightMax;
    }
    if (value < node->value) 
    {
        value = node->value;
    }
    return value;
}

int minValue(struct node* node)
{
    if (node == NULL) 
    {
        return 1000000000;
    }
    int leftMax = minValue(node->left);
    int rightMax = minValue(node->right);
    int value = 0;
    if (leftMax < rightMax) 
    {
        value = leftMax;
    }
    else 
    {
        value = rightMax;
    }
    if (value > node->value) 
    {
        value = node->value;
    }
    return value;
}

//task 3
int BSTCheck(Node *node)
{   
    if (node == NULL) return 1;
    if (node->left != NULL && maxValue(node->left) > node->value) return 0;
    if (node->right != NULL && minValue(node->right) < node->value) return 0;
    if (!BSTCheck(node->left) || !BSTCheck(node->right)) return 0;
    return 1;
}

int BSTCheckIterative(Node *node)
{   
    // Morris Traversal

    Node *current = node;
    Node *prev = NULL;

    while (current != NULL)
    {   
        // printf("\nIteration ++ \n");
        // printf(" %d \n", current->value);
        if (current->left == NULL)
        {
            // case 1 : No left child, process current node
            if (prev != NULL && prev->value > current->value)
            {
                return 0;
            }
            prev = current;
            current = current->right;
        }
        else
        {
            // case 2 : left child exists, find the predecessor

            Node *pred =  current->left;
            while (pred->right != NULL && pred->right != current)
                pred = pred->right;
            
            if (pred->right == NULL)
            {
                pred->right = current;
                current = current->left;
            }
            else
            {
                // remove threaded link

                // if the threaded link has been established it mean we 
                // have visited the left subtree and need to process the current node
                
                pred->right = NULL;
                // process the current node
                if (prev != NULL && prev->value > current->value)
                    return 0;
                prev = current;
                current = current->right;
            }
        }
    }

    return 1;
}

BST **fileReader(char *name, int length)
{   
    FILE *fptr = fopen(name, "r");
    if (fptr == NULL){

        printf("Error opening file");
        exit(1);

    }

    BST ** bst_arr = (BST**) malloc(length*sizeof(BST*));
    for (int j = 0; j < length; j++)
    {

        int n;
        char *num = (char *) malloc(sizeof(int));
        fscanf(fptr, "%[^,],[", num);
        char *line = (char*) malloc(sizeof(int)); 
        n = atoi(num);

        int *arr = (int*) calloc(n, sizeof(int));
        
        for (int i = 0; i < n-1; i++){

            fscanf(fptr, "%s", line);
            arr[i] = atoi(line);

        }
        fscanf(fptr, "%s]\n", line);
        arr[n-1] = atoi(line);
        
        bst_arr[j] = (BST*) malloc(sizeof(BST));
        bst_arr[j] = constructBST(arr,n);

    }


    fclose(fptr);

    return bst_arr;

}

//task 4
int height(Node *node)
{
    if (node == NULL)
        return -1;
    else
    {
        int lh = height(node->left);
        int rh = height(node->right);

        if (lh > rh) return lh + 1;
        else return rh + 1;
    }
}

//task 5
Node *removeHalfNode(Node *node)
{   
    if (node == NULL) return NULL;
    node->left = removeHalfNode(node->left);
    node->right = removeHalfNode(node->right);

    if (node->left==NULL && node->right==NULL)
        return node;

    if (node->left == NULL)
    {
        Node *new_node = node->right;
        free(node); // To avoid memory leak
        return new_node;
    }

    if (node->right == NULL)
    {
        Node *new_node = node->left;
        free(node); // To avoid memory leak
        return new_node;
    }

    return node;
}

//home exercise 1
void traverse_level_order(Node *node)
{
    Queue *q = createQueue();
    Node *current = node;

    while (current != NULL)
    {   
        printf(" %d ", current->value);
        if (current->left != NULL)
            enqueue(q, current->left);
        if (current->right != NULL)
            enqueue(q, current->right);
        
        current = front(q);
        dequeue(q);
    }
}

//home exercise 2
void traverse_level_order_reverse(Node *node)
{
    Queue *q = createQueue();
    Stack *s = newStack();
    Node *current = node;
    push(s, node->value);
    while (current != NULL)
    {   
        if (current->right != NULL)
        {
            enqueue(q, current->right);
            push(s, current->right->value);
        }
        if (current->left != NULL)
        { 
            enqueue(q, current->left);
            push(s, current->left->value);
        }
        current = front(q);
        dequeue(q);
    }
    while (!isEmptyStack(s))
    {
        printf(" %d ", *top(s));
        pop(s);
    }
}

//task 7
void flattenHelper(Node *node, LIST ll)
{
    if (node == NULL)
    {
        return;
    }
    insertFirst(createNewNode(node->value), ll);
    flattenHelper(node->left, ll);
    flattenHelper(node->right, ll);
}

LIST flatten(BST *bst)
{
    LIST flat = createNewList();
    flattenHelper(bst->root, flat);
    reverse(flat);

    return flat;
}

void flattenInPlace(Node* root)
{   
    // using Morris traversal

    // traverse till root is not NULL
    while (root) {
        // if root->left is not NULL
        if (root->left != NULL) {
            // set curr node as root->left;
            Node* curr = root->left;
            // traverse to the extreme right of curr
            while (curr->right) {
                curr = curr->right;
            }
            // join curr->right to root->right
            curr->right = root->right;
            // put root->left to root->right
            root->right = root->left;
            // make root->left as NULL
            root->left = NULL;
        }
        // now go to the right of the root
        root = root->right;
    }
}

//home exercise 4
void kthSmallestHelper(Node *node, Queue *q)
{
    if (node == NULL) // can also pass k and a counter as an input parameter and check if counter >=k to terminate
    {
        return;
    }
    kthSmallestHelper(node->left, q);
    enqueue(q, node); // instead of enqueue just increment counter and set the k smallest value when counter == k
    kthSmallestHelper(node->right, q);
}

Node *kthSmallest(BST *bst, int k)
{
    Queue *q = createQueue();
    kthSmallestHelper(bst->root, q);
    Node *answer = malloc(sizeof(Node));
    printf(" The %dth smallest element is = ", k);
    while (k--)
    {   
        answer = front(q);
        dequeue(q);
    }
    printf("%d\n", answer->value);
    return answer;
}

//home exercise 5 REFER GFG
void insertInOrder(int v, int u, int *freq, int *arr, int last){

    int j = last - 1;
    
    while(j >= 0 && v > freq[j]){

        freq[j+1] = freq[j];
        arr[j+1] = arr[j];
        j--;
    
    }
    
    freq[j+1] = v;
    arr[j+1] = u;

}

void insertionSort(int *freq, int *arr, int n){

    for (int j = 1; j < n; j++){

        insertInOrder(freq[j], arr[j], freq, arr, j);

    }

}

BST *constructOBST(int *arr, int *freq, int n)
{
    BST *bst = new_bst();
    insertionSort(freq, arr, n);
    for (int i = 0; i < n; i++)
    {
        insert(bst, arr[i]);
    }

    return bst;
}


// Driver program to test the above functions (feel free to play around with this)
int main()
{
    BST *bst = new_bst();
    // insert(bst, 2);
    // insert(bst, 1);
    // insert(bst, 3);
    // insert(bst, 4);
    // insert(bst, 5);
    // insert(bst, 6);
    // insert(bst, 7);
    // insert(bst, 8);
    int *arr = (int*) calloc(8,sizeof(int));
    arr[0] = 5;
    arr[1] = 1;
    arr[2] = 7;
    arr[3] = 4;
    arr[4] = 2;
    arr[5] = 6;
    arr[6] = 3;
    arr[7] = 8;

    bst = constructBST(arr, 8);
    // printf("INORDER TRAVERSAL : \n");
    // traverse_in_order(bst->root);
    // printf("\nPOSTORDER TRAVERSAL : \n");
    // traverse_post_order(bst->root);
    // printf("\nPREORDER TRAVERSAL : \n");
    // traverse_pre_order(bst->root);
    // printf("\nINORDER TRAVERSAL : \n");
    // traverse_in_order_alternate(bst->root);
    // printf("\nPOSTORDER TRAVERSAL : \n");
    // traverse_post_order_alternate(bst->root);
    // printf("\nPREORDER TRAVERSAL : \n");
    // traverse_pre_order_alternate(bst->root);
    // printf("\n");
    // printf("Max = %d\n", find_max(bst));
    // printf("Min = %d\n", find_min(bst));
    // printf("Predecessor of root = %d\n", predecessor(bst->root)->value);
    // printf("Successor of root = %d\n", successor(bst->root)->value);
    // delete(bst, bst->root->left);
    // traverse_in_order(bst->root);
    // printf("\n");
    // delete(bst, bst->root->right);
    // traverse_in_order(bst->root);
    // printf("\n");
    // delete(bst, bst->root);
    // traverse_in_order(bst->root);
    // printf("\n");

    // traverse_in_order(bst->root);
    // printf("\n %d %d\n", bst->root->value, successor(bst->root)->value);


    // BSTCheck(bst->root)?printf("It is a BST!\n"):printf("It is not a BST!\n");
    // BSTCheckIterative(bst->root)?printf("It is a BST!\n"):printf("It is not a BST!\n");
    
    // char *name = "n_test.txt";
    // BST **bst_arr = fileReader(name, 3);

    // for (int i = 0; i < 3; i++)
    // {
    //     printf("this is iteration %d :\n", i);
    //     BSTCheck(bst_arr[i]->root)?printf("It is a BST!\n"):printf("It is not a BST!\n");
    //     BSTCheckIterative(bst_arr[i]->root)?printf("It is a BST!\n"):printf("It is not a BST!\n");
    // }
    // // creating a non BST
    // BST *fake = new_bst();
    // insert(fake, 5);
    // fake->root->left = new_node(6);
    // BSTCheck(fake->root)?printf("It is a BST!\n"):printf("It is not a BST!\n");
    // BSTCheckIterative(fake->root)?printf("It is a BST!\n"):printf("It is not a BST!\n");

    // char *name = "n_integers.txt";
    // BST **bst_arr = fileReader(name, 1000);

    // for (int i = 0; i < 1000; i++)
    // {
    //     printf("\nThis is iteration %d :\n", i);
    //     BSTCheck(bst_arr[i]->root)?printf("It is a BST!\n"):printf("It is not a BST!\n");
    // }

    // printf("Height of the tree is %d\n", height(bst->root));
    
    // //home exercise 1
    // traverse_level_order(bst->root);
    // printf("\n");

    // //home exercise 2
    // traverse_level_order_reverse(bst->root);
    // printf("\n");

    // task 5 testing
    // bst->root = removeHalfNode(bst->root);
    // traverse_in_order(bst->root);
    // char *name = "n_integers.txt";
    // BST **bst_arr = fileReader(name, 10);

    // for (int i = 0; i < 10; i++)
    // {
    //     printf("\nThis is iteration %d :\n", i);
    //     bst_arr[i]->root = removeHalfNode(bst_arr[i]->root);
    //     traverse_in_order(bst_arr[i]->root);
    // }

    // task 7 testing
    // LIST flat = flatten(bst);
    // traverse_pre_order(bst->root);
    // printList(flat);
    // flattenInPlace(bst->root);
    // traverse_in_order(bst->root);

    // home exercise 4
    // kthSmallest(bst, 2);

    // home exercise 5
    // int *a = (int*) malloc(sizeof(int)*5);
    // for (int i = 1; i < 6; i++)
    // {
    //     a[i-1] = i;
    // }

    // int *freq = (int*) malloc(sizeof(int)*5);
    // freq[0] = 3;
    // freq[1] = 7;
    // freq[2] = 1;
    // freq[3] = 2;
    // freq[4] = 5;

    // BST *bsto = constructOBST(a, freq, 5);
    // traverse_level_order(bsto->root);
    // printf("\n");
    // traverse_in_order(bsto->root);
    // printf("\n");
    // traverse_pre_order(bsto->root);
    // printf("\n");
    // traverse_post_order(bsto->root);
    // printf("\n");
    return 0;
}
