#ifndef BS
#define BS

typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} Node;

typedef struct bst {
    Node *root;
} BST;

#endif
