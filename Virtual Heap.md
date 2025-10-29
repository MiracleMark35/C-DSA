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

void deleteLast(VirtualHeap *VH, List *L){
    if (*L != -1) { 
        List temp;
        List* trav;

        if (VH->Node[*L].next == -1) {  
            // Only one element
            temp = *L;
            *L = -1;  
        } else {
            // More than one element
            for (trav = L; VH->Node[VH->Node[*trav].next].next != -1;
                 trav = &VH->Node[*trav].next) {}
            temp = VH->Node[*trav].next;  
            VH->Node[*trav].next = -1;  
        }
        dealloc(VH, temp);  
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
```c
#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP 20
#define EMPTY 0
#define DELETED -1

typedef struct {
    int elem;
    int next;
} NodeType;

typedef struct {
    NodeType Node[MAX_HEAP];
    int avail;
} VirtualHeap;

typedef struct {
    VirtualHeap VH;
    NodeType Node[MAX_HEAP/2];
} Dictionary;

// --- Virtual Heap ---
void initializeVirtualHeap(VirtualHeap *VH) {
    for(int i=MAX_HEAP/2;i<MAX_HEAP;i++){
        VH->Node[i].next=i+1;
        VH->Node[i].elem=EMPTY; // optional
    }
    VH->Node[MAX_HEAP-1].next= -1;
    VH->avail = MAX_HEAP/2;
}

int allocspace(VirtualHeap *VH){
    int temp=VH->avail;
    if(temp!=-1){
        VH->avail = VH->Node[temp].next;
    } 
    return temp;
}

void dealloc(VirtualHeap *VH,int index){
    
    if(index >= 0 &&  index < MAX_HEAP){
    VH->Node[index].next = VH->avail;
    VH->avail= index ;
    
    VH->Node[index].elem=EMPTY; //optional
    }

}

// --- Dictionary ---
void InitializeDICT(Dictionary *D){
    for(int i=0;i< MAX_HEAP/2 ;i++){
        D->Node[i].elem=EMPTY;
        D->Node[i].next=-1; // optional
    }
    initializeVirtualHeap(&D->VH);
}

int hash(int key){ return key % (MAX_HEAP/2); }

void insert(Dictionary *D,int key){
    
    int idx=hash(key);
    
    if(D->Node[idx].elem==EMPTY || D->Node[idx].elem==DELETED){
        D->Node[idx].elem=key;
        D->Node[idx].next=-1;
    } else {
        int newNode= allocspace(&D->VH);
        if(newNode==-1){ printf("No space!\n"); return; }
        D->VH.Node[newNode].elem=key;
        D->VH.Node[newNode].next=D->Node[idx].next;
        D->Node[idx].next=newNode;
    }
}
int search(Dictionary D, int key){
    int hashV = hash(key);

    // check main array first
    if(D.Node[hashV].elem == key) return 1;

    // traverse synonyms in the virtual heap
    int next = D.Node[hashV].next;
    while(next != -1){
        if(D.VH.Node[next].elem == key) break;  // check in virtual heap
        next = D.VH.Node[next].next;
    }

    return next != -1 ? 1 : -1;
}


// --- DELETE ---
void delete(Dictionary *D, int key){
    int idx = hash(key);

 
}


// --- DISPLAY ---
void displayDictionary(Dictionary *D){
    printf("Index | Elem | Next\n");
    printf("------------------\n");
    for(int i=0;i<MAX_HEAP/2;i++){
        printf("%5d | %4d | %4d\n", i,
               D->Node[i].elem==EMPTY ? 0 : D->Node[i].elem,
               D->Node[i].next);
    }
    printf("---- Synonyms ----\n");
    for(int i=MAX_HEAP/2;i<MAX_HEAP;i++){
        if(D->VH.Node[i].elem!=EMPTY)
            printf("%5d | %4d | %4d\n", i,
                   D->VH.Node[i].elem,
                   D->VH.Node[i].next);
    }
    printf("Next available heap node: %d\n", D->VH.avail);
}

// --- MAIN ---
int main(){
    Dictionary D;
    InitializeDICT(&D);

    insert(&D, 3);
    insert(&D, 9);
    insert(&D, 4);
    insert(&D, 53);
    insert(&D, 89);
    insert(&D, 10);
    insert(&D, 13);
    
    displayDictionary(&D);

    

    return 0;
}

```
