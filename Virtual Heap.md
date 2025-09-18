# VIRTUAL HEAP

![update.next](Images/Screenshot%202025-07-30%20192213.png)  

```cpp
#include <stdio.h>

#define MAX_HEAP 10

typedef struct {
    char elem;
    int next;
} NodeType;

typedef struct {
    NodeType Node[MAX_HEAP];
    int avail;
} VirtualHeap;

typedef int List;  

void initializeVirtualHeap(VirtualHeap *VH) {
    // Initialize the heap nodes
    for (int i = 0; i < MAX_HEAP - 1; i++) {
        VH->Node[i].next = i + 1;  // Link nodes in the free list
    }
    VH->Node[MAX_HEAP - 1].next = -1;  // End of the free list
    VH->avail = 0;  // Start with the first node as available
}

int allocspace(VirtualHeap *VH) {
    int temp = VH->avail;  // Get the index of the first available cell
    if (temp != -1) {      // Check if there is available space
        VH->avail = VH->Node[temp].next;  // Update avail to point to the next available cell
    }
    return temp;  // Return the index of the allocated cell (or -1 if no space was available)
}

void dealloc(VirtualHeap *VH, int index) {
    // Check if the index is valid
    if (index >= 0 && index < MAX_HEAP) {
        // Add the node back to the free list
        VH->Node[index].next = VH->avail;  // Link the deallocated node to the current free list
        VH->avail = index;  // Update the avail pointer to the new free node
    } else {
        printf("Invalid index for deallocation.\n");
    }
}

void insertLast(VirtualHeap *VH, char elem, List *L) {
    int newIndex = allocspace(VH);  // Allocate space for the new node

    if (newIndex != -1) {
        // Initialize the new node
        VH->Node[newIndex].elem = elem;
        VH->Node[newIndex].next = -1;  // New node will be the last node
        // Traverse to the end of the list using a for loop
        List *trav;
        for (trav = L; *trav != -1; trav = &VH->Node[*trav].next) {}
        // Insert the new node at the end
        *trav = newIndex;
    } else {
        printf("No available space to insert the new node.\n");
    }
}

void insertFirst(VirtualHeap *VH, char elem, List *L) {
    int newIndex = allocspace(VH);  // Allocate space for the new node
    if (newIndex != -1) {
        // Initialize the new node
        VH->Node[newIndex].elem = elem;
        VH->Node[newIndex].next = *L;  // New node points to the current first node
        // Insert the new node at the beginning
        *L = newIndex;
    } else {
        printf("No available space to insert the new node.\n");
    }
}

void deleteElement(VirtualHeap *VH, char elem, List *L) {
    List *trav, temp;
    // Traverse the list to find the node to delete
    for (trav = L; *trav != -1 && VH->Node[*trav].elem != elem; trav = &VH->Node[*trav].next) {}
    // If we found the node to delete
    if (*trav != -1) {
        temp = *trav;  // Node to delete
        *trav = VH->Node[temp].next;  // Bypass the node to delete
        // Link deleted node back to free list
        dealloc(VH, temp);
    }
}

void deleteAllOccurrences(VirtualHeap *VH, char elem, List *L) {
    List *trav, temp;
    // Traverse the list to find and delete all occurrences of the element
    for (trav = L; *trav != -1; ) {
        // Check if the current node contains the element to delete
        if (VH->Node[*trav].elem == elem) {
            temp = *trav;  // Node to delete
            *trav = VH->Node[temp].next;  // Bypass the node to delete
            // Link deleted node back to free list
            dealloc(VH, temp);
        } else {
            // Move to the next node if no deletion occurred
            trav = &VH->Node[*trav].next;
        }
    }
}

void deleteFirst(VirtualHeap *VH, List *L) {
    List temp;
    if (*L != -1) { 
        temp = *L;  
        *L = VH->Node[temp].next;  
        dealloc(VH, temp);  
    }
}

void deleteLast(VirtualHeap *VH, List *L) {
    if (*L != -1) {   // list not empty
        List temp;
        List *trav;

        if (VH->Node[*L].next == -1) {
            // Case 1: Only one node in the list
            temp = *L;
            *L = -1;  
        } else {
            // Case 2: More than one node
            for (trav = L; VH->Node[*trav].next != -1; trav = &VH->Node[*trav].next) {
                if (VH->Node[VH->Node[*trav].next].next == -1) {
                    break; // stop when the *next node* is the last
                }
            }
            temp = VH->Node[*trav].next;   // last node index
            VH->Node[*trav].next = -1;     // unlink it
        }
        dealloc(VH, temp);  // return to free list
    } else {
        printf("List is empty.\n");
    }
}

 
void InitializeList(List* head) {
    *head = -1;
}

void printList(VirtualHeap VH, List L) {
    List trav;
    
    for (trav = L; trav != -1; trav = VH.Node[trav].next) {
        printf("%c -> ", VH.Node[trav].elem);
    }
    printf("NULL\n");
}


int main() {
  
    
    VirtualHeap VH;
    List head;
    
    InitializeList(&head);
    initializeVirtualHeap(&VH);
    
    int size;
    
    printf("Enter Size: ");
    scanf("%d",&size);
    
    for(int i = 0 ; i < size; i++){
        char elem;
        scanf(" %c",&elem);
        insertLast(&VH, elem, &head);
    }
    
    printList(VH, head);
    
    deleteFirst(&VH, &head);
    printList(VH, head);
    deleteLast(&VH, &head);
    printList(VH, head);
    return 0;
}
```
