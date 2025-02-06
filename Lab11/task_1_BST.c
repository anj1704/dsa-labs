#include<stdio.h>
#include<stdlib.h>

typedef struct node* Node;
struct node{
    int value;
    Node left;
    Node right;
};

typedef struct bt* BT;
struct bt
{
    int size;
    Node root;
};

int memused;

void* myalloc(int size)
{
    memused+=size;
    return malloc(size);
}

void* myrealloc(int old , void* ptr, int size)
{
    memused-=old;
    memused+=size;
    return realloc(ptr, size);
}

BT create_BT()
{
    BT new_BT = (BT)myalloc(sizeof(struct bt));
    new_BT->root = NULL;
    new_BT->size = 0;
    return new_BT;
}

Node create_Node(int value)
{
    Node new_node = (Node)myalloc(sizeof(struct node));
    new_node->left=NULL;
    new_node->right=NULL;
    new_node->value=value;
    return new_node;
}

void add_to_tree(BT bt, int value)
{
    Node new_node = create_Node(value);
    if(bt->size == 0)
    {
        bt->root= new_node;
        bt->size++;
        return;
    }
    int curr_size = bt->size+1;
    int num_bits=0;
    while (curr_size>0)
    {
        num_bits++;
        curr_size/=2;
    }
    curr_size = bt->size+1;
    Node curr = bt->root;
    for (int i = num_bits-2; i >=1; i--)
    {
        int temp = (curr_size>>i)&1;
        if(temp == 1)
        {
            curr=curr->right;
        }
        else
        {
            curr=curr->left;
        }
    }
    int lorr = curr_size&1;
    // printf("val %d \n", curr->value);
    if(lorr==0)
    {
        curr->left = new_node;
    }
    else
    {
        curr->right = new_node;
    }
    bt->size++;
}

void print_queue(Node* node, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", node[i]->value);
    }
    printf("\n");
    
}

void print(BT bt)
{
    printf("Size: %d Space: %d\n" , bt->size, memused);
    if(bt->size==0)
    {
        return;
    }
    Node queue[bt->size];
    int l=0;
    int r=0;
    queue[r] = bt->root;
    r++;
    while(l!=r)
    {
        // print_queue(queue, bt->size);
        Node curr = queue[l];
        l++;
        printf("%d ", curr->value);
        if(curr->right!=NULL)
        {
            queue[r]=curr->left;
            r++;
            queue[r]=curr->right;
            r++;
        }
        else if (curr->left!=NULL)
        {
            queue[r]=curr->left;
            r++;
        }
    }
    printf("\n");
}

int main()
{
    BT h = create_BT();
    print(h);
    add_to_tree(h,0);
    print(h);
    add_to_tree(h,1);
    print(h);
    add_to_tree(h,2);
    print(h);
    add_to_tree(h,3);
    print(h);
    add_to_tree(h,4);
    print(h);
    add_to_tree(h,5);
    print(h);
}
