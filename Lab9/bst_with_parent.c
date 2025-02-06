#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *left;
    struct node *right;
    struct node *parent;
} Node;

typedef struct bst {
    Node *root;
} BST;

BST *new_bst() 
{
    BST *bst = malloc(sizeof(BST));
    bst->root = NULL;
    return bst;
}

Node *new_node(int value) 
{
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
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

void insert(BST *bst, Node* node)
{
    if (bst->root == NULL)
    {
        bst->root = node;
        return;
    }
    Node *current = bst->root;
    while (current != NULL)
    {
        if (node->value < current->value)
        {
            if (current->left == NULL)
            {
                current->left = node;
                node->parent = current;
                return;
            }
            current = current->left;
        }
        else
        {
            if (current->right == NULL)
            {
                current->right = node;
                node->parent = current;
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

int find_min(BST *bst)
{
    Node *current = bst->root;
    while (current->left != NULL) 
    {
        current = current->left;
    }
    return current->value;
}

int find_max(BST *bst)
{
    Node *current = bst->root;
    while (current->right != NULL) 
    {
        current = current->right;
    }
    return current->value;
}

Node *predecessor(Node *node)
{
    if (node->left == NULL)
    {   
        Node *pred = node->parent;
        while (pred != NULL && node == pred->left)
        {
            node = pred;
            pred = pred->parent;
        }
        return pred;
    }
    Node *current = node->left;
    while (current->right != NULL)
    {
        current = current->right;
    }
    return current;
}

Node *successor(Node *node)
{
    if (node->right == NULL)
    {
        Node *succ = node->parent;
        while (succ != NULL && node == succ->right)
        {
            node = succ;
            succ = succ->parent;
        }
        return succ;
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

// Driver program to test the above functions (feel free to play around with this)
int main()
{
    BST *bst = new_bst();
    insert(bst, new_node(2));
    insert(bst, new_node(1));
    insert(bst, new_node(3));
    insert(bst, new_node(4));
    insert(bst, new_node(5));
    insert(bst, new_node(6));
    insert(bst, new_node(7));
    insert(bst, new_node(8));
    bst->root->left->value = 768;
    traverse_in_order(bst->root);
    printf("\n");
    printf("Max = %d\n", find_max(bst));
    printf("Min = %d\n", find_min(bst));
    printf("Predecessor of root = %d\n", predecessor(bst->root)->value);
    printf("Successor of root = %d\n", successor(bst->root)->value);
    delete(bst, bst->root->left);
    traverse_in_order(bst->root);
    printf("\n");
    delete(bst, bst->root->right);
    traverse_in_order(bst->root);
    printf("\n");
    delete(bst, bst->root);
    traverse_in_order(bst->root);
    printf("\n");

    BSTCheck(bst->root)?printf("It is a BST!\n"):printf("It is not a BST!\n");
    return 0;
}
