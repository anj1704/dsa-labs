#ifndef BS
#define BS

// use this for avl.c
// typedef struct node {
//     int value;
//     struct node *left;
//     struct node *right;
// } Node;

// typedef struct bst {
//     Node *root;
// } BST;

typedef struct node {
    int value;
    int height;
    struct node *left;
    struct node *right;
} Node;

typedef struct bst {
    Node *root;
} BST;

#endif
