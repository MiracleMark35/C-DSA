
# HEAP SORT
```c
void PrintHeap(Heap *h) {
    printf("Heap elements: ");
    for (int i = 0; i < h->count; i++) {
        printf("%d ", h->elem[i]);
    }
    printf("\n");
}

void HeapSort(int arr[], int n) {
    Heap h;
    Initialize(&h);

    // Build a min-heap from the array
    for (int i = 0; i < n; i++) {
        Insert(&h, arr[i]);
    }

    // Print the heap before sorting
    printf("Heap before HeapSort:\n");
    PrintHeap(&h);

    // Extract elements from the heap in sorted order
    for (int i = 0; i < n; i++) {
        arr[i] = DeleteMin(&h);
    }
}

```
