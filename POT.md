
# HEAP SORT
```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct heap {
    int elem[MAX];
    int count;
} Heap;

// Initialize the heap
void Initialize(Heap *h) {
    h->count = 0;
}

// Insert element and maintain min-heap property
void Insert(Heap *h, int value) {
    if (h->count == MAX) {
        printf("Heap is full.\n");
        return;
    }
    
    h->elem[h->count] = value;
    h->count++;

    // Restore min-heap property by percolating up
    int index = h->count - 1;
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (h->elem[parent] <= h->elem[index])
            break;

        int temp = h->elem[parent];
        h->elem[parent] = h->elem[index];
        h->elem[index] = temp;
        index = parent;
    }
}

// Heapify subtree at given index
void MinHeapify(Heap *h, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < h->count && h->elem[left] < h->elem[smallest])
        smallest = left;
    if (right < h->count && h->elem[right] < h->elem[smallest])
        smallest = right;

    if (smallest != index) {
        int temp = h->elem[index];
        h->elem[index] = h->elem[smallest];
        h->elem[smallest] = temp;
        MinHeapify(h, smallest);
    }
}

// Delete minimum element (root) from heap
int DeleteMin(Heap *h) {
    if (h->count == 0) {
        printf("Heap is empty.\n");
        return -1;
    }

    int min = h->elem[0];
    h->elem[0] = h->elem[h->count - 1];
    h->count--;
    MinHeapify(h, 0);
    return min;
}

// Print heap elements
void PrintHeap(Heap *h) {
    printf("Heap elements: ");
    for (int i = 0; i < h->count; i++) {
        printf("%d ", h->elem[i]);
    }
    printf("\n");
}

// HeapSort using min-heap
void HeapSort(int arr[], int n) {
    Heap h;
    Initialize(&h);

    // Build heap by inserting elements
    for (int i = 0; i < n; i++)
        Insert(&h, arr[i]);

    // Print heap before sorting
    printf("Heap before HeapSort:\n");
    PrintHeap(&h);

    // Extract elements in sorted order
    for (int i = 0; i < n; i++)
        arr[i] = DeleteMin(&h);
}

int main() {
    int arr[] = {6, 7, 4, 3, 1, 2, 5, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    HeapSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

```
