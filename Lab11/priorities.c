#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct heap {
    int *data;
    int size;
    int capacity;
    int depth;
};

typedef struct heap* Heap;

Heap heap_create()
{
    Heap h = malloc(sizeof(struct heap));
    h->data = malloc(sizeof(int));
    h->capacity = 1;
    h->depth = 0;
    return h;
}

void add_to_heap(Heap h, int element)
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

void insert(Heap h, int value)
{
    add_to_heap(h, value);
    // Complete the function here
    for (int i = h->capacity/2 -1; i >= 0; i-- )
    {
        max_heapify(h, i);
    }
    // max_heapify(h, h->size - 1);
    return;
}

int maximum(Heap h)
{
    if (h->size == 0)
        return -1;    // -1 denotes that the heap is empty
    else
        return h->data[0];
}

int extract_maximum(Heap h)
{
    int max = maximum(h);
    // Complete the function here
    h->data[0] = h->data[h->size - 1];
    h->size--;
    max_heapify(h, 0);
    
    return max;
}

void increase_key(Heap h, int x, int k) {
    h->data[x] = k;
    while (x > 0 && h->data[parent(h, x)] < h->data[x]) {
        int temp = h->data[x];
        h->data[x] = h->data[parent(h, x)];
        h->data[parent(h, x)] = temp;
        x = parent(h, x);
    }
}

int main() {
    
    Heap h1 = heap_create();
    insert(h1, 5);
    insert(h1, 7);
    insert(h1, 3);
    insert(h1, 2);
    insert(h1, 1);
    insert(h1, 10);
    insert(h1, 8);
    insert(h1, 0);
    insert(h1, 11);
    insert(h1, 14);

    printf("Initial Max-Heap: ");
    for (int i = 0; i < h1->size; i++) {
        printf("%d ", h1->data[i]);
    }
    printf("\n");

    printf("Maximum element: %d\n", maximum(h1));

    printf("Extracting maximum elements: ");
    while (h1->size > 0) {
        printf("%d ", extract_maximum(h1));
    }
    printf("\n");

    insert(h1, 5);
    insert(h1, 7);
    insert(h1, 3);
    insert(h1, 2);
    insert(h1, 1);
    insert(h1, 10);
    insert(h1, 8);
    insert(h1, 0);
    insert(h1, 11);
    insert(h1, 14);

    increase_key(h1, 3, 20);
    printf("After increasing key at index 3 to 20: ");
    for (int i = 0; i < h1->size; i++) {
        printf("%d ", h1->data[i]);
    }
    printf("\n");

    return 0;
}
