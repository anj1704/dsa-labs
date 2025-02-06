#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
#include <string.h>

// compile with -lm flag

struct person{
    int id;
    char *name;
    int age;
    int height;
    int weight;
};
typedef struct person person;

struct heap {
    person *data;
    int size;
    int capacity;
    int depth;
};
typedef struct heap* Heap;

Heap heap_create()
{
    Heap h = (Heap) malloc(sizeof(struct heap));
    h->data = (person *) malloc(sizeof(person));
    h->size = 0;
    h->capacity = 1;
    h->depth = 0;

    return h;
}

void add_to_tree(Heap h, person element)
{   
    if (h->size >= h->capacity)
    {   
        h->depth++;
        h->capacity = pow(2, h->depth+1) - 1;
        h->data = (person *) realloc(h->data, (h->capacity)*sizeof(person));
        // h->data[h->size].age = element.age;
        // h->data[h->size].height = element.height;
        // h->data[h->size].weight = element.weight;
        // h->data[h->size].id = element.id;
        // h->data[h->size++].name = element.name;
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

    if (left < h->size && h->data[left].height > h->data[largest].height)
    {
        largest = left;
    }
    if (right < h->size && h->data[right].height > h->data[largest].height)
    {
        largest = right;
    }
    if (largest != index)
    {
        person temp = h->data[index];
        h->data[index] = h->data[largest];
        h->data[largest] = temp;
        max_heapify(h, largest);
    }
}

// task 3
void build_max_heap(Heap h)
{
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
        person temp = h->data[0];
        h->data[0] = h->data[i];
        h->data[i] = temp;
        h->size = h->size - 1;
        max_heapify(h, 0);
    }
    h->size = temp;
}

int main(int argc, char **argv)
{   
    Heap h = heap_create();

    char *filename = (char *) malloc(sizeof(char)*strlen(argv[1]));
    filename = argv[1];

    char substring[strlen(filename) - 3];
    strncpy(substring, argv[1] + 3, strlen(argv[1]) - 3);

    int n = atoi(substring);

    FILE *fp = fopen(filename, "r");

    if (!fp)
    {
        printf("Can't open file\n");
    }
    else
    {
        for (int k = 0; k < n; k++)
        {   
            person p;
            p.name = (char *) malloc(sizeof(char)*20);
            fscanf(fp, "%d,%[^,],%d,%d,%d", &p.id, p.name, &p.age, &p.height, &p.weight);
            add_to_tree(h, p);
            free(p.name);
        }
        fclose(fp);
    }

    struct timeval t1, t2;
    double time_taken;
    gettimeofday(&t1, NULL);
    // Perform the tasks whose execution time is to be measured

    heap_sort(h);

    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("The tasks took %f seconds to execute\n", time_taken);

    FILE *fptr;

    fptr = fopen("heapSortBenchmarks.txt", "a");
    if (fptr == NULL)
    {

        printf("Error opening the file.");
        exit(1);
    }

    fprintf(fptr, "%d,%f\n", n, time_taken);
    fclose(fptr);

    // for (int i = 0; i < h->size; i++)
    // {
    //     printf(" %d ", h->data[i].height);
    // }

    free(h);
    return 0;
    return 0;
}
