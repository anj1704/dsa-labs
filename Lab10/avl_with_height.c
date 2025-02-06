#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define STACK_SIZE 100

typedef struct node
{
    int value;
    struct node *left;
    struct node *right;
    int height;
} Node;

typedef struct bst
{
    Node *root;
} BST;

BST *new_bst()
{
    BST *bst = malloc(sizeof(BST));
    bst->root = NULL;
    return bst;
}

struct node *new_node(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1; // Height initialized to 1 for leaf nodes
    return newNode;
}

typedef struct Stack
{
    int top;
    Node *data[STACK_SIZE];
} Stack;

Stack *createStack()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = -1;
    return s;
}

Node *top(Stack *s)
{
    if (s->top == -1)
        return NULL;
    return s->data[s->top];
}

bool empty(Stack *s)
{
    return s->top == -1;
}

bool push(Stack *s, Node *v)
{
    if (s->top == STACK_SIZE - 1)
    {
        return false;
    }
    s->data[++s->top] = v;
    return true;
}

Node *pop(Stack *s)
{
    if (s->top == -1)
        return NULL;
    return s->data[s->top--];
}

void freeStack(Stack *s)
{
    free(s);
}

typedef struct Queue
{
    int front;
    int rear;
    Node *data[STACK_SIZE];
} Queue;

Queue *createQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

bool enqueue(Queue *q, Node *element)
{
    if (element == NULL)
    {
        return false;
    }
    q->rear++;
    if (q->rear == STACK_SIZE)
    {
        q->rear = 0;
    }
    if (q->front == -1)
    {
        q->front = 0;
    }
    q->data[q->rear] = element;
    return true;
}

Node *dequeue(Queue *q)
{
    Node *e;
    if (q->front == -1)
    {
        return NULL;
    }
    e = q->data[q->front++];
    if (q->front == STACK_SIZE)
    {
        q->front = 0;
    }
    if (q->front == q->rear + 1)
    {
        q->front = q->rear = -1;
    }
    return e;
}

Node *front(Queue *queue)
{
    return queue->data[queue->front];
}

int size(Queue *queue)
{
    if (queue->front == -1)
    {
        return 0;
    }
    if (queue->front <= queue->rear)
    {
        return queue->rear - queue->front + 1;
    }
    else
    {
        return STACK_SIZE - queue->front + queue->rear + 1;
    }
}

bool isEmpty(Queue *q)
{
    return (q->front == -1 && q->rear == -1);
}

void destroyQueue(Queue *queue)
{
    free(queue);
}

void pre_iter(Node *root)
{
    if (root == NULL)
        return;
    Stack *s = createStack();
    push(s, root);

    while (!empty(s))
    {
        Node *current = pop(s);
        printf("Visited %d\n ", current->value);
        if (current->right != NULL)
            push(s, current->right);
        if (current->left != NULL)
            push(s, current->left);
    }
    freeStack(s);
}

void postiter(Node *root)
{
    if (root == NULL)
        return;
    struct Stack *stack = createStack();
    do
    {
        while (root)
        {
            if (root->right)
                push(stack, root->right);
            push(stack, root);
            root = root->left;
        }
        root = pop(stack);
        if (root->right && top(stack) == root->right)
        {
            pop(stack);
            push(stack, root);
            root = root->right;
        }
        else
        {
            printf("%d ", root->value);
            root = NULL;
        }
    } while (!empty(stack));
}

void traverse_in_order(Node *node)
{
    if (node == NULL)
        return;
    traverse_in_order(node->left);
    printf("%d ", node->value);
    traverse_in_order(node->right);
}

void traverse_pre_order(Node *node)
{
    if (node == NULL)
        return;
    printf("%d ", node->value);
    traverse_pre_order(node->left);
    traverse_pre_order(node->right);
}

void traverse_post_order(Node *node)
{
    if (node == NULL)
        return;
    traverse_post_order(node->left);
    traverse_post_order(node->right);
    printf("%d ", node->value);
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

Node *find_min(BST *bst)
{
    Node *current = bst->root;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
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
{
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
        Node *current = bst->root;
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
        Node *current = bst->root;
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
        Node *current = bst->root;
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

    Node *temp = successor(node);
    node->value = temp->value;
    delete (bst, temp);
    return;
}

void removeHalfNodes(BST *b, Node *n)
{
    if (n == NULL)
    {
        return;
    }
    removeHalfNodes(b, n->left);
    removeHalfNodes(b, n->right);
    Node *c = b->root;
    if (c == NULL)
    {
        return;
    }
    while (c != NULL)
    {
        if (c->left == n || c->right == n)
        {
            break;
        }
        if (n->value < c->value)
        {
            c = c->left;
        }
        else
        {
            c = c->right;
        }
    }
    if (c == NULL)
    {
        return;
    }
    if (c->left == n)
    {
        if (n->left != NULL && n->right == NULL)
        {
            c->left = n->left;
            free(n);
            return;
        }
        if (n->left == NULL && n->right != NULL)
        {
            c->left = n->right;
            free(n);
            return;
        }
    }
    else
    {
        if (n->left != NULL && n->right == NULL)
        {
            c->right = n->left;
            free(n);
            return;
        }
        if (n->left == NULL && n->right != NULL)
        {
            c->right = n->right;
            free(n);
            return;
        }
    }
}

BST *flatten(BST *b)
{
    BST *f = new_bst();
    Node *m = find_min(b);
    while (m != NULL)
    {
        insert(f, m->value);
        m = successor(m);
    }
    return f;
}

// int height(Node* n) {
//     if (n == NULL) {
//         return 0;
//     }
//     int l = height(n->left);
//     int r = height(n->right);
//     if (l > r) {
//         return l + 1;
//     }
//     return r + 1;
// }

void printGivenLevel(Node *root, int level)
{
    if (!root)
    {
        return;
    }
    if (level == 1)
    {
        printf("%d ", root->value);
    }
    else if (level > 1)
    {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}

// void reverseLevel(Node* root) {
//     int h = height(root);
//     for (int i = h; i >= 1; i--) {
//         printGivenLevel(root, i);
//     }
// }

void levelOrder(Node *root)
{
    if (root == NULL)
        return;
    Queue *q = createQueue();
    enqueue(q, root);
    while (!isEmpty(q))
    {
        Node *a = dequeue(q);
        printf("%d ", a->value);
        if (a->left != NULL)
            enqueue(q, a->left);
        if (a->right != NULL)
            enqueue(q, a->right);
    }
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return n->height;
}

int balance_factor(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return height(n->left) - height(n->right);
}

struct node *rotate_right(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;

    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

struct node *rotate_left(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;

    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

struct node *insertAVL(struct node *node, int value)
{
    if (node == NULL)
    {
        return new_node(value);
    }

    if (value < node->value)
    {
        node->left = insertAVL(node->left, value);
    }
    else
    {
        node->right = insertAVL(node->right, value);
    }

    // Update height of current node
    node->height = 1 + max(height(node->left), height(node->right));

    int balance = balance_factor(node);

    // Perform rotations if tree becomes unbalanced
    if (balance > 1 && value < node->left->value)
    {
        return rotate_right(node);
    }
    if (balance < -1 && value >= node->right->value)
    {
        return rotate_left(node);
    }
    if (balance > 1 && value >= node->left->value)
    {
        node->left = rotate_left(node->left);
        return rotate_right(node);
    }
    if (balance < -1 && value < node->right->value)
    {
        node->right = rotate_right(node->right);
        return rotate_left(node);
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

Node *deleteAVL(Node *node, int value)
{
    if (node == NULL)
    {
        // value not found
        return NULL;
    }
    else if (value < node->value)
    {
        // value is in left subtree
        node->left = deleteAVL(node->left, value);
        node->height = 1 + height(node->left) > height(node->right) ? height(node->left) : height(node->right);
    }
    else if (value > node->value)
    {
        // value is in right subtree
        node->right = deleteAVL(node->right, value);
        node->height = 1 + height(node->left) > height(node->right) ? height(node->left) : height(node->right);
    }
    else
    {
        // value is at this node
        if (node->left == NULL && node->right == NULL)
        {
            // node is a leaf
            free(node);
            node = NULL;
        }
        else if (node->left == NULL)
        {
            // node has only right child
            struct node *temp = node;
            node = node->right;
            free(temp);
        }
        else if (node->right == NULL)
        {
            // node has only left child
            struct node *temp = node;
            node = node->left;
            free(temp);
        }
        else
        { // node has both children
            struct node *temp = predecessor(node);
            node->value = temp->value;
            node->left = deleteAVL(node->left, temp->value);
            node->height = 1 + height(node->left) > height(node->right) ? height(node->left) : height(node->right);
        }
    }
    int balance = balance_factor(node);
    // balance factor is left height - right height
    if (balance > 1)
    {
        // left subtree is longer
        if (balance_factor(node->left) >= 0)
        { // LL imbalance
            node = rotate_right(node);
            node->right->height = 1 + (height(node->right->left) >
                                               height(node->right->right)
                                           ? height(node->right->left)
                                           : height(node->right->right));
            node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));
        }

        else
        {

            node->left->left->height = 1 + (height(node->left->left->left) >
                                                    height(node->left->left->right)
                                                ? height(node->left->left->left)
                                                : height(node->left->left->right));
            node->left->height = 1 + (height(node->left->left) >
                                              height(node->left->right)
                                          ? height(node->left->left)
                                          : height(node->left->right));
            node = rotate_right(node);
            node->right->height = 1 + (height(node->right->left) >
                                               height(node->right->right)
                                           ? height(node->right->left)
                                           : height(node->right->right));
            node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));
        }
    }
    else if (balance < -1)
    {
        // right subtree is longer
        if (balance_factor(node->right) <= 0)
        {
            // RR imbalance
            node = rotate_left(node);
            node->left->height = 1 + (height(node->left->left) >
                                              height(node->left->right)
                                          ? height(node->left->left)
                                          : height(node->left->right));
            node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));
        }
        else
        {
            node->right = rotate_right(node->right);
            node->right->right->height = 1 + (height(node->right->right->left) >
                                                      height(node->right->right->right)
                                                  ? height(node->right->right->left)
                                                  : height(node->right->right->right));
            node->right->height = 1 + (height(node->right->left) >
                                               height(node->right->right)
                                           ? height(node->right->left)
                                           : height(node->right->right));
            node = rotate_left(node);
            node->left->height = 1 + (height(node->left->left) >
                                              height(node->left->right)
                                          ? height(node->left->left)
                                          : height(node->left->right));
            node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));
        }
    }
    return node;
}

// Driver program to test above functions
int main()
{
    BST *bst = new_bst();
    // insert(bst, 50);
    // insert(bst, 30);
    // insert(bst, 70);
    // insert(bst, 20);
    // insert(bst, 40);
    // insert(bst, 60);
    // insert(bst, 80);

    // printf("Preorder traversal: ");
    // traverse_pre_order(bst->root);
    // printf("\n");

    // printf("Inorder traversal: ");
    // traverse_in_order(bst->root);
    // printf("\n");

    // printf("Postorder traversal: ");
    // traverse_post_order(bst->root);
    // printf("\n");

    // printf("Level Order traversal: ");
    // levelOrder(bst->root);
    // printf("\n");

    // printf("Reverse Level Order traversal: ");
    // reverseLevel(bst->root);
    // printf("\n");

    // printf("Height of the tree is %d\n", height(bst->root));

    // BST *bst = new_bst();
    Node *r = bst->root;
    r = insertAVL(r, 50);
    r = insertAVL(r, 30);
    r = insertAVL(r, 70);
    r = insertAVL(r, 20);
    r = insertAVL(r, 40);
    r = insertAVL(r, 60);
    r = insertAVL(r, 80);
    traverse_bfs(r);
    printf("\n");
    r = deleteAVL(r, 40);
    printf("\n");
    traverse_bfs(r);

    return 0;
}

// void insertNonRecursive(struct Node **root, int key)
// {
//     struct Node *newNode = newNode(key);
//     if (*root == NULL)
//     {
//         *root = newNode;
//         return;
//     }
//     struct Node *curr = *root;
//     struct StackNode *stack = NULL;
//     while (curr != NULL)
//     {
//         push(&stack, curr);
//         if (key < curr->key)
//             curr = curr->left;
//         else
//             curr = curr->right;
//     }
//     struct Node *parent = pop(&stack);
//     if (key < parent->key)
//         parent->left = newNode;
//     else
//         parent->right = newNode;
//     while (stack != NULL)
//     {
//         curr = pop(&stack);
//         curr->height = 1 + max(height(curr->left), height(curr->right));
//         int balance = getBalance(curr);
//         if (balance > 1 && key < curr->left->key)
//             curr = rightRotate(curr);
//         if (balance < -1 && key > curr->right->key)
//             curr = leftRotate(curr);
//         if (balance > 1 && key > curr->left->key)
//         {
//             curr->left = leftRotate(curr->left);
//             curr = rightRotate(curr);
//         }
//         if (balance < -1 && key < curr->right->key)
//         {
//             curr->right = rightRotate(curr->right);
//             curr = leftRotate(curr);
//         }
//         if (curr->left != NULL)
//             curr->left->height =
//                 1 + max(height(curr->left->left), height(curr->left->right));
//         if (curr->right != NULL)
//             curr->right->height =
//                 1 + max(height(curr->right->left), height(curr->right->right));
//         if (stack != NULL)
//         {
//             parent = stack->node;
//             if (curr->key < parent->key)
//                 parent->left = curr;
//             else
//                 parent->right = curr;
//         }
//         else
//         {
//             *root = curr;
//         }
//     }
// }

// void deleteNonRecursive(struct Node **root, int key)
// {
//     struct Node *curr = *root;
//     struct Node *parent = NULL;
//     struct StackNode *stack = NULL;

//     // Search for the node to delete
//     while (curr != NULL && curr->key != key)
//     {
//         push(&stack, curr);
//         parent = curr;
//         if (key < curr->key)
//             curr = curr->left;
//         else
//             curr = curr->right;
//     }

//     if (curr == NULL)
//         return; // Key not found

//     // Case 1: Node to delete has no children
//     if (curr->left == NULL && curr->right == NULL)
//     {
//         if (parent == NULL)
//         {
//             *root = NULL;
//             free(curr);
//             return;
//         }
//         if (parent->left == curr)
//             parent->left = NULL;
//         else
//             parent->right = NULL;
//         free(curr);
//     }
//     // Case 2: Node to delete has one child
//     else if (curr->left == NULL || curr->right == NULL)
//     {
//         struct Node *child = (curr->left != NULL) ? curr->left : curr->right;
//         if (parent == NULL)
//         {
//             *root = child;
//             free(curr);
//             return;
//         }
//         if (parent->left == curr)
//             parent->left = child;
//         else
//             parent->right = child;
//         free(curr);
//     }
//     // Case 3: Node to delete has two children
//     else
//     {
//         struct Node *succParent = curr;
//         struct Node *succ = curr->right;
//         while (succ->left != NULL)
//         {
//             push(&stack, succ);
//             succParent = succ;
//             succ = succ->left;
//         }
//         curr->key = succ->key;
//         if (succParent == curr)
//             succParent->right = succ->right;
//         else
//             succParent->left = succ->right;
//         free(succ);
//     }

//     while (stack != NULL)
//     {
//         curr = pop(&stack);
//         curr->height = 1 + max(height(curr->left), height(curr->right));
//         int balance = getBalance(curr);
//         if (balance > 1 && getBalance(curr->left) >= 0)
//             curr = rightRotate(curr);
//         if (balance > 1 && getBalance(curr->left) < 0)
//         {
//             curr->left = leftRotate(curr->left);
//             curr = rightRotate(curr);
//         }
//         if (balance < -1 && getBalance(curr->right) <= 0)
//             curr = leftRotate(curr);
//         if (balance < -1 && getBalance(curr->right) > 0)
//         {
//             curr->right = rightRotate(curr->right);
//             curr = leftRotate(curr);
//         }
//         if (curr->left != NULL)
//             curr->left->height =
//                 1 + max(height(curr->left->left), height(curr->left->right));
//         if (curr->right != NULL)
//             curr->right->height =
//                 1 + max(height(curr->right->left), height(curr->right->right));
//         if (stack != NULL)
//         {
//             parent = stack->node;
//             if (curr->key < parent->key)
//                 parent->left = curr;
//             else
//                 parent->right = curr;
//         }
//         else
//         {
//             *root = curr;
//         }
//     }
// }

// struct StackNode
// {
//     struct Node *node;
//     struct StackNode *next;
// };

// void push(struct StackNode **root, struct Node *node)
// {
//     struct StackNode *stackNode = createStackNode(node);
//     stackNode->next = *root;
//     *root = stackNode;
// }

// struct Node *pop(struct StackNode **root)
// {
//     if (*root == NULL)
//         return NULL;
//     struct StackNode *temp = *root;
//     *root = (*root)->next;
//     struct Node *popped = temp->node;
//     free(temp);
//     return popped;
// }
