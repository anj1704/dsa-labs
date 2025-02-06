#ifndef BS
#define BS

typedef struct person
{
    int id;
    char *name;
    int age;
    int height;
    int weight;
} Person;

typedef struct node {
    Person value;
    struct node *left;
    struct node *right;
} Node;

typedef struct bst {
    Node *root;
} BST;

#endif
