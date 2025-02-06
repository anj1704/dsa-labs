#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct heap
{
    int *data;
    int size;
    int capacity;
    int depth;
};

typedef struct heap *Heap;

Heap heap_create()
{
    Heap h = malloc(sizeof(struct heap));
    h->data = malloc(sizeof(int));
    h->size = 0;
    h->capacity = 1;
    h->depth = 0;
    return h;
}

void add_to_heap(Heap h, int value)
{
    if (h->size >= h->capacity)
    {
        h->depth++;
        h->capacity = pow(2, h->depth + 1) - 1;
        h->data = (int *)realloc(h->data, (h->capacity) * sizeof(int));
        h->data[h->size++] = value;
    }
    else
    {
        h->data[h->size++] = value;
    }
}

int parent(Heap h, int node)
{
    return (node - 1) / 2;
}

int left_child(Heap h, int node)
{
    return (2 * node + 1);
}

int right_child(Heap h, int node)
{
    return (2 * node + 2);
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

int minimum(Heap h)
{
    if (h->size == 0)
        return -1; // -1 denotes that the heap is empty
    else
    {
        return h->data[0];
    }
}

int extract_minimum(Heap h)
{
    int min = minimum(h);
    h->data[0] = h->data[h->size - 1];
    h->size--;
    min_heapify(h, 0);
    return min;
}

void decrease_key(Heap h, int x, int k)
{
    h->data[x] = k;
    int i = x;
    while (i != 0 && h->data[parent(h, i)] > h->data[i])
    {
        int temp = h->data[i];
        h->data[i] = h->data[parent(h, i)];
        h->data[parent(h, i)] = temp;
        i = parent(h, i);
    }
}

void printHeap(Heap h)
{
    for (int i = 0; i < h->size; i++)
    {
        printf("%d ", h->data[i]);
    }
    printf("\n");
}

Heap build_min_heap(int *a, int n)
{
    Heap h = heap_create();
    for (int i = 0; i < n; i++)
    {
        add_to_heap(h, a[i]);
    }
    for (int i = (h->capacity / 2) - 1; i >= 0; i--)
    {
        min_heapify(h, i);
    }
    return h;
}

int main()
{
    int a[10] = {11, 42, 53, 23, 44, 144, 76, 87, 90, 964};
    Heap h = build_min_heap(a, 10);

    printHeap(h);

    decrease_key(h, 3, 10);

    printHeap(h);

    printf("Minimum elements in ascending order: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", extract_minimum(h));
    }
    printf("\n");

    return 0;
}
