#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "queue.h"
#include "stack.h"

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

void kthSmallestHelper(Node *node, Queue *q)
{
    if (node == NULL)
    {
        return;
    }
    kthSmallestHelper(node->left, q);
    enqueue(q, node);
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

void insertInOrder(int v, int u, int *freq, int *arr, int last){
    // ref gfg
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

// task 1
Node *rotate_left(Node *x)
{
    struct node *y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

Node *rotate_right(Node *y)
{
    struct node *x = y->left;
    y->left = x->right;
    x->right= y;
    return x; 
}

int is_height_balanced(Node *x)
{
    int left = height(x->left);
    int right = height(x->right);

    if (left - right > 1 || right - left > 1) return -1;
    else return left>right ? left : right + 1;
}

Node *insertAVL(Node *node, int value)
{
    if (node == NULL)
    {
        node = new_node(value);

    }
    else if (value < node->value)
    {
        node->left = insertAVL(node->left, value);
    }
    else
    {
        node->right = insertAVL(node->right, value);
    }
    
    int balance = is_height_balanced(node);
    if (balance == -1)
    {
        if (value < node->value)
        {
            if (value < node->left->value)
            {
                // LL imbalance
                node = rotate_right(node);
            }
            else
            {
                // LR imbalance
                node->left = rotate_left(node->left);
                node = rotate_right(node);
            }
        }
        else
        {
            /*
            Complete the code for the following cases:
            RR imbalance
            RL imbalance
            */
            if (value < node->right->value)
            {
                //RL imbalance
                node->right = rotate_right(node->right);
                node = rotate_left(node);
               
            }
            else
            {
                //RR imbalance
                node = rotate_left(node);
            }
        }
    }
    
    return node;
}

void traverse_bfs(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    
    Node *queue[100];
    int front = 0;
    int back = 0;
    queue[back++] = node;
    
    while (front != back)
    {
        Node *current = queue[front++];
        printf("%d ", current->value);
        if (current->left != NULL)
        {
            queue[back++] = current->left;
        }
        if (current->right != NULL)
        {
            queue[back++] = current->right;
        }
    }
}

int AVLCheck(Node *node)
{   
    if (node == NULL)
        return 1;
    if (node->left != NULL && (maxValue(node->left) > node->value || is_height_balanced(node->left) == -1))
        return 0;
    if (node->right != NULL && (minValue(node->right) < node->value || is_height_balanced(node->right) == -1))
        return 0; 
    if (!AVLCheck(node->left) || !AVLCheck(node->right))
        return 0;
 
    return 1;
}

int main()
{
    BST *avl = new_bst();
    avl->root = insertAVL(avl->root, 1);
    avl->root = insertAVL(avl->root, 2);
    avl->root = insertAVL(avl->root, 3);
    avl->root = insertAVL(avl->root, 4);
    avl->root = insertAVL(avl->root, 5);
    avl->root = insertAVL(avl->root, 6);
    avl->root = insertAVL(avl->root, 7);
    avl->root = insertAVL(avl->root, 8);
    avl->root = insertAVL(avl->root, 9);

    traverse_bfs(avl->root);
    printf("\n");

    AVLCheck(avl->root)?printf("It is an AVL tree!\n"):printf("It is not an AVL tree!\n");

    BST *fake_avl = new_bst();
    insert(fake_avl, 6);
    insert(fake_avl, 5);
    insert(fake_avl, 4);
    insert(fake_avl, 3);
    insert(fake_avl, 2);
    insert(fake_avl, 1);

    traverse_bfs(fake_avl->root);
    printf("\n");
    AVLCheck(fake_avl->root)?printf("It is an AVL tree!\n"):printf("It is not an AVL tree!\n");

    // traverse_in_order(avl->root);
    // printf("\n");
    // traverse_post_order(avl->root);
    // printf("\n");
    // traverse_pre_order(avl->root);

    // int* ht=(int*)malloc(sizeof(int));
    // *ht=0;
    // height(avl->root, ht, -1);
    // printf("%d\n", *ht);
    // printf("%d\n", lca(avl, 1, 8));

    // int *arr = (int*) calloc(8,sizeof(int));
    // arr[0] = 2;
    // arr[1] = 1;
    // arr[2] = 3;
    // arr[3] = 4;
    // arr[4] = 5;
    // arr[5] = 6;
    // arr[6] = 7;
    // arr[7] = 8;

    // bst = constructBST(arr, 8);
    // // printf("INORDER TRAVERSAL : \n");
    // // traverse_in_order(bst->root);
    // // printf("\nPOSTORDER TRAVERSAL : \n");
    // // traverse_post_order(bst->root);
    // // printf("\nPREORDER TRAVERSAL : \n");
    // // traverse_pre_order(bst->root);
    // // printf("\nINORDER TRAVERSAL : \n");
    // // traverse_in_order_alternate(bst->root);
    // // printf("\nPOSTORDER TRAVERSAL : \n");
    // // traverse_post_order_alternate(bst->root);
    // // printf("\nPREORDER TRAVERSAL : \n");
    // // traverse_pre_order_alternate(bst->root);
    // // printf("\n");
    // // printf("Max = %d\n", find_max(bst));
    // // printf("Min = %d\n", find_min(bst));
    // // printf("Predecessor of root = %d\n", predecessor(bst->root)->value);
    // // printf("Successor of root = %d\n", successor(bst->root)->value);
    // // delete(bst, bst->root->left);
    // // traverse_in_order(bst->root);
    // // printf("\n");
    // // delete(bst, bst->root->right);
    // // traverse_in_order(bst->root);
    // // printf("\n");
    // // delete(bst, bst->root);
    // // traverse_in_order(bst->root);
    // // printf("\n");

    // // BSTCheck(bst->root)?printf("It is a BST!\n"):printf("It is not a BST!\n");
    // char *name = "n_integers.txt";
    // BST **bst_arr = fileReader(name, 1000);

    // for (int i = 0; i < 1000; i++)
    // {
    //     BSTCheck(bst_arr[i]->root);
    // }

    return 0;
}
