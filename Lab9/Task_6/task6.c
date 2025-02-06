#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binarySearchTree.h"
#include "queue.h"

BST *new_bst() 
{
    BST* bst = (BST*) malloc(sizeof(BST));
    bst->root = NULL;
    return bst;
}

Node *new_node(Person value) 
{
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert(BST *bst, Person value)
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
        if (value.height < current->value.height) 
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

BST *constructBST(Person *arr, int n)
{
    BST *bst = new_bst();
    for (int i = 0; i < n; i++)
    {
        insert(bst, arr[i]);
    }

    return bst;
}

void traverse_in_order(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    traverse_in_order(node->left);
    printf(" %d %s %d %d %d \n", node->value.id, node->value.name, node->value.age, node->value.height, node->value.weight);
    traverse_in_order(node->right);
}

void traverse_pre_order(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    printf(" %d %s %d %d %d \n", node->value.id, node->value.name, node->value.age, node->value.height, node->value.weight);
    traverse_pre_order(node->left);
    traverse_pre_order(node->right);
}

Person *fileReader(char *filename, int n)
{
    Person *A = (Person *)malloc(n * sizeof(Person));

    FILE *fp = fopen(filename, "r");

    if (!fp)
    {

        printf("Can't open file\n");
    }
    else
    {

        for (int k = 0; k < n; k++)
        {
            (A + k)->name = (char *)malloc(100 * sizeof(char));
            fscanf(fp, "%d,%[^,],%d,%d,%d", &(A + k)->id, (A + k)->name, &(A + k)->age, &(A + k)->height, &(A + k)->weight);
        }
        fclose(fp);
    }

    return A;
}

void traverse_for_ID(Node *node, int ID, Node *answer)
{   
    if (node == NULL)
    {
        return;
    }
    traverse_for_ID(node->left, ID, answer);    
    if (node && node->value.id == ID)
    {
        answer->value = node->value;
        answer->left = node->left;
        answer->right = node->right;
    }
    traverse_for_ID(node->right, ID, answer);
}

// Queue *search_queue(BST *bst, Person key)
// {
//     Node *current = bst->root;
//     Queue *q = createQueue();
//     while (current != NULL) 
//     {
//         if (key.height == current->value.height && key.id == current->value.id) 
//         {
//             return q;
//         } 
//         else if (key.height < current->value.height) 
//         {   
//             enqueue(q, current);
//             current = current->left;
//         } 
//         else 
//         {   
//             enqueue(q, current);
//             current = current->right;
//         }
//     }
//     return NULL;
// }

// Node *LCA(BST *bst, int ID1, int ID2)
// {
//     Node *one = malloc(sizeof(Node));
//     traverse_for_ID(bst->root, ID1, one);
//     Node *two = malloc(sizeof(Node));
//     traverse_for_ID(bst->root, ID2, two);

//     if (ID1 == ID2) return one;
//     if (one->value.id != ID1 || two->value.id != ID2)
//     {
//         printf("ID not found !\n");
//         return NULL;
//     }
//     else
//     {   
//         Queue *q1 = search_queue(bst, one->value);
//         Queue *q2 = search_queue(bst, two->value);

//         Node *ancestor = NULL;
//         while (front(q1) && front(q2) && front(q1)->value.height == front(q2)->value.height)
//         {
//             ancestor = front(q1);
//             dequeue(q1);
//             dequeue(q2);
//         }

//         return ancestor;
//     }

//     return NULL;
// }

Node *LCABetter(BST *bst, int ID1, int ID2)
{   
    Node *one = malloc(sizeof(Node));
    traverse_for_ID(bst->root, ID1, one);
    Node *two = malloc(sizeof(Node));
    traverse_for_ID(bst->root, ID2, two);

    if (one->value.id != ID1 || two->value.id != ID2)
    {
        printf("ID not found !\n");
        free(one);
        free(two);
        return NULL;
    }
    if (ID1 == ID2) return one;
    else
    {
        Node *current = bst->root;
        Node *prev = current;
        while (current != NULL)
        {   
            prev = current; 
            if (prev->value.id == one->value.id)
            {
                return one;
            }
            if (prev->value.id == two->value.id)
            {
                return two;
            }
            if (one->value.height >= current->value.height && two->value.height < current->value.height)
            {
                return current;
            }
            else if(one->value.height < current->value.height && two->value.height >= current->value.height)
            {
                return current;
            }
            else if (one->value.height >= current->value.height && two->value.height >= current->value.height)
            {
                current = current->right;
            }
            else if (one->value.height < current->value.height && two->value.height < current->value.height)
            {
                current = current->left;
            }
        }
        
        return prev;

    }
}

int main(int argc, char** argv)
{
    char *filename = (char *) malloc(sizeof(char)*strlen(argv[1]));
    filename = argv[1];
    char substring[strlen(filename) - 3];
    strncpy(substring, argv[1] + 3, strlen(argv[1]) - 3);
    int n = atoi(substring);

    Person *A = fileReader(filename, n);
    BST *bst = constructBST(A, n);
    free(A);
    // traverse_in_order(bst->root);
    // traverse_pre_order(bst->root);

    Node *lca = LCABetter(bst, 7, 2);
    if (lca) printf(" The ancestor is :\n%d %s %d %d %d \n", lca->value.id, lca->value.name, lca->value.age, lca->value.height, lca->value.weight);
    
    return 0;
}
