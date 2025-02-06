#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

// compile with -lm flag

struct heap {
    int *data;
    int size;
    int capacity;
    int depth;
};
typedef struct heap* Heap;

Heap heap_create()
{
    Heap h = (Heap) malloc(sizeof(struct heap));
    h->data = (int *) malloc(sizeof(int));
    h->size = 0;
    h->capacity = 1;
    h->depth = 0;

    return h;
}

void add_to_tree(Heap h, int element)
{   
    if (h->size >= h->capacity)
    {   
        h->depth++;
        h->capacity = pow(2, h->depth+1) - 1;
        h->data = (int *) realloc(h->data, (h->capacity)*sizeof(int));
        h->data[h->size++] = element;
    }
    else
    {
        h->data[h->size++] = element;
    }
}

int parent(Heap h, int node)
{
    if (h->size < 2) return -1;
    else return (node-1)/2;
    // return (node - 1)/2;
}

int left_child(Heap h, int node)
{
    if (2*node + 1 < h->size) return 2*node + 1;
    else return -1;
    // return 2*node + 1;
}

int right_child(Heap h, int node)
{
    if (2*node + 2 < h->size) return 2*node + 2;
    else return -1;
    // return 2*node + 2;
}

void max_heapify(Heap h, int index)
{
    int left = left_child(h, index);
    int right = right_child(h, index);
    int largest = index;

    if (left < h->size && h->data[left] > h->data[largest])
    {
        largest = left;
    }
    if (right < h->size && h->data[right] > h->data[largest])
    {
        largest = right;
    }
    if (largest != index)
    {
        int temp = h->data[index];
        h->data[index] = h->data[largest];
        h->data[largest] = temp;
        max_heapify(h, largest);
    }
}

// task 3
void build_max_heap(Heap h)
{
    // for (int i = h->size - 1; i > -1; i--)
    // dont need to heapify leaves
    for (int i = h->capacity/2 -1; i > -1; i--)
    {   
        // printf("Iteration %d \n", i);
        max_heapify(h, i);
    }
}

// task 4
int nodes_at_depth(Heap h, int depth)
{
    if (depth < h->depth) return pow(2, depth);
    else if (depth == h->depth) return h->size - pow(2, h->depth) + 1;
    else return 0;
}

void heap_sort(Heap h)
{
    build_max_heap(h);
    int temp = h->size;
    for (int i = h->size - 1; i >= 1; i--)
    {
        int temp = h->data[0];
        h->data[0] = h->data[i];
        h->data[i] = temp;
        h->size = h->size - 1;
        max_heapify(h, 0);
    }
    h->size = temp;
}

void min_heapify(Heap h, int index)
{
    int left = left_child(h, index);
    int right = right_child(h, index);
    int smallest = index;

    if (left < h->size && h->data[left] < h->data[smallest])
    {
        smallest = left;
    }
    if (right < h->size && h->data[right] < h->data[smallest])
    {
        smallest = right;
    }
    if (smallest != index)
    {
        int temp = h->data[index];
        h->data[index] = h->data[smallest];
        h->data[smallest] = temp;
        min_heapify(h, smallest);
    }
}

void build_min_heap(Heap h)
{
    for (int i = h->size - 1; i > -1; i--)
    // dont need to heapify leaves
    // for (int i = h->capacity/2 -1; i > -1; i--)
    {   
        printf("Iteration %d \n", i);
        min_heapify(h, i);
    }
}

// extractMin definition
int extractMin(Heap h)
{
	int deleteItem;

	// Checking if the heap is empty or not
	if (h->size == 0) {
		printf("\nHeap id empty.");
		return -1;
	}

	// Store the node in deleteItem that
	// is to be deleted.
	deleteItem = h->data[0];

	// Replace the deleted node with the last node
	h->data[0] = h->data[h->size - 1];
	// Decrement the size of heap
	h->size--;

	// Call minheapify_top_down for 0th index
	// to maintain the heap property
	min_heapify(h, 0);
	return deleteItem;
}

int main()
{
    Heap h1 = heap_create();
    add_to_tree(h1, 5);
    add_to_tree(h1, 7);
    add_to_tree(h1, 3);
    add_to_tree(h1, 2);
    add_to_tree(h1, 1);
    add_to_tree(h1, 10);
    add_to_tree(h1, 8);
    add_to_tree(h1, 0);
    add_to_tree(h1, 11);
    add_to_tree(h1, 14);

    for (int i = 0; i < h1->size; i++)
    {
        printf(" %d ", h1->data[i]);
    }

    printf("\n");
    printf("Depth = %d\n", h1->depth);
    printf("Capacity = %d\n", h1->capacity);
    printf("Size = %d\n", h1->size);

    // for (int i = 0; i < h1->size; i++)
    // {
    //     printf("\nValue = %d\n", h1->data[i]);
    //     printf("\nParent = %d\n", h1->data[parent(h1, i)]);
    //     printf("\nLeft child = %d\n", h1->data[left_child(h1, i)]);
    //     printf("\nRight child = %d\n", h1->data[right_child(h1, i)]);
    //     printf("\n");
    // }

    // build_max_heap(h1);
    // for (int i = 0; i < h1->size; i++)
    // {
    //     printf(" %d ", h1->data[i]);
    // }
    // printf("\n");
    
    // printf("Depth = %d\n", h1->depth);
    // printf("Capacity = %d\n", h1->capacity);
    // printf("Size = %d\n", h1->size);

    // printf("Number of nodes at depth 2 = %d \n", nodes_at_depth(h1, 2));
    // printf("Number of nodes at depth 3 = %d \n", nodes_at_depth(h1, 3));
    // printf("Number of nodes at depth 4 = %d \n", nodes_at_depth(h1, 4));

    // heap_sort(h1);

    // for (int i = 0; i < h1->size; i++)
    // {
    //     printf(" %d ", h1->data[i]);
    // }
    printf("\n");

    printf("Building a min heap \n");
    build_min_heap(h1);
    for (int i = 0; i < h1->size; i++)
    {
        printf(" %d ", h1->data[i]);
    }
    printf("\n");

    return 0;
}
