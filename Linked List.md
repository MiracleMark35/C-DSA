

## 1) List Without Header Cell
### Pointer to Pointer to Node (PPN) Traversal

```cpp
#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int elem;
    struct Node* link;
} Node;


Node* createNode(int elem) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->elem = elem;
    newNode->link = NULL;
    return newNode;
}

// Function to insert a node at the end of a list without a header cell using PPN traversal
void insertLast(Node** head, int elem) {
    Node** p = head;
    
    // Traverse to the last node using PPN
    while (*p != NULL) {
        p = &(*p)->link;
    }

    // Insert the new node at the end
    *p = createNode(elem);
}

void displayList(Node* head) {
    Node* p = head;
    while (p != NULL) {
        printf("%d -> ", p->elem);
        p = p->link;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;  // No header cell, head points to the first node

    // Insert elements at the end
    insertLast(&head, 10);
    insertLast(&head, 20);
    insertLast(&head, 30);

    displayList(head);

    return 0;
}
```
## LOOK AHEAD WIHOUT HEAD
#### Or MY FAVORITE
```cpp
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

void printall(Node* head){
    
    Node* curr = head;
    
    while(curr != NULL){
        printf("%d -> ",curr->data);
        curr = curr->next;
    }
    printf("\n");
}


void insertNodes(Node** head, int data){
    
 Node* NewNode = (Node*)malloc(sizeof(Node));
 NewNode->data = data;
 NewNode->next = NULL;
  
  if(*head == NULL){
    *head = NewNode;
 } else{
    Node* curr = *head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = NewNode;
 } 
}

int  main (){
    
    Node* head = NULL;
    
    int size, num;
    
    printf("Enter size: ");
    scanf("%d",&size);
    
    printf("Enter elements: ");
    for( int i = 0 ; i < size; i++){
        int data;
        scanf("%d",&data);
        insertNodes(&head , data);
    }

    printall(head);
   
    return 0;
}
```

### PPN DELETE FIRST OCCURENCE OF DATA

```cpp
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int elem;
    struct Node* link;
} Node;

void insertLast(Node** head, int elem) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->elem = elem;
    newNode->link = NULL;

    Node** p = head;
    
    while (*p != NULL) {
        p = &(*p)->link;
    }
    
    *p = newNode;
}

void deleteElem(Node** head, int data) {
    Node** p = head;
    
    while (*p != NULL && (*p)->elem != data) {
        p = &(*p)->link;
    }
    
    if (*p == NULL) {
        printf("Element Not Found\n");
        return;
    }
    
    Node* temp = *p;
    *p = (*p)->link;
    free(temp);
}

void displayList(Node* head) {
    Node* p = head;
    while (p != NULL) {
        printf("%d -> ", p->elem);
        p = p->link;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;  
    
    int size, delData;
    
    printf("Enter Size of the Linked List: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        printf("Enter Element %d: ", i + 1);
        int data;
        scanf("%d", &data);
        insertLast(&head, data);
    }
    
    displayList(head);
    
    printf("Enter an Element to delete: ");
    scanf("%d", &delData);
    deleteElem(&head, delData);
    
    displayList(head);

    return 0;
}
```
### DELETE ALL OCCURECENCES
```cpp
void deleteAll(Node** head, int elem) {
    Node** p = head;
    
    while (*p != NULL) {
        if ((*p)->elem == elem) {
            Node* temp = *p;
            *p = (*p)->link; // Remove the node by updating the pointer
            free(temp);       // Free the removed node
        } else {
            p = &(*p)->link; // Move to the next node only if no deletion happened
        }
    }
}
```

### MAKENULL(L)
```cpp
void MAKENULL(List *L) {
    Node *current = *L;
    Node *nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    *L = NULL;
}
```
### REMOVEDUPLICATE(head)
```cpp
void removeDuplicates(Node* head) {
    Node *p, *prev, *q;

    p = head;
    while (p != NULL && p->next != NULL) {
        prev = p;
        q = p->next;
        while (q != NULL) {
            if (p->data == q->data) {
                // Duplicate node found; remove it
                prev->next = q->next;
                free(q);  // Free the duplicate node
                q = prev->next;  // Move q to the next node
            } else {
                prev = q;
                q = q->next;
            }
        }
        p = p->next;
    }
}
```

### ARRAY IMPLENTATION  
  
```cpp
#include <stdio.h>

#define MAXLENGTH 100  // Define the maximum length of the list

// Define the list type with an array and the last index
typedef struct {
    int elements[MAXLENGTH];
    int last;  // Index of the last element in the list
} LIST;

// Function to return the end position of the list
int END(LIST *L) {
    return L->last + 1;
}

// Function to return the first position of the list
int FIRST() {
    return 1;
}

// Function to return the next position
int NEXT(int p) {
    return p + 1;
}

// Function to return the previous position
int PREVIOUS(int p) {
    return p - 1;
}

// Function to initialize the list
void MAKENULL(LIST *L) {
    L->last = 0;
}

// Function to insert an element at a given position
void INSERT(int x, int p, LIST *L) {
    if (L->last >= MAXLENGTH - 1) {
        printf("Error: List is full.\n");
        return;
    }
    if (p < 1 || p > L->last + 1) {
        printf("Error: Invalid position.\n");
        return;
    }
    for (int i = L->last; i >= p - 1; i--) {
        L->elements[i + 1] = L->elements[i];
    }
    L->elements[p - 1] = x;
    L->last++;
}

// Function to delete an element at a given position
void DELETE(int p, LIST *L) {
    if (p < 1 || p > L->last) {
        printf("Error: Invalid position.\n");
        return;
    }
    for (int i = p - 1; i < L->last - 1; i++) {
        L->elements[i] = L->elements[i + 1];
    }
    L->last--;
}

// Function to locate an element in the list
int LOCATE(int x, LIST *L) {
    for (int i = 0; i <= L->last; i++) {
        if (L->elements[i] == x) {
            return i + 1;  // Return position (1-based index)
        }
    }
    return END(L);  // Element not found
}

// Function to print the elements of the list
void PRINTLIST(LIST *L) {
    for (int i = 0; i <= L->last; i++) {
        printf("%d ", L->elements[i]);
    }
    printf("\n");
}

int main() {
    LIST myList;
    MAKENULL(&myList);

    int choice, pos, value;

    do {
        printf("\nMenu:\n");
        printf("1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. Locate element\n");
        printf("4. Print list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Insert element
                printf("Enter element to insert: ");
                scanf("%d", &value);
                printf("Enter position to insert at: ");
                scanf("%d", &pos);
                INSERT(value, pos, &myList);
                break;

            case 2:
                // Delete element
                printf("Enter position to delete from: ");
                scanf("%d", &pos);
                DELETE(pos, &myList);
                break;

            case 3:
                // Locate element
                printf("Enter element to locate: ");
                scanf("%d", &value);
                pos = LOCATE(value, &myList);
                if (pos != END(&myList)) {
                    printf("Element %d found at position: %d\n", value, pos);
                } else {
                    printf("Element %d not found in the list.\n", value);
                }
                break;

            case 4:
                // Print list
                printf("List elements: ");
                PRINTLIST(&myList);
                break;

            case 5:
                // Exit
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
```


### PPN MUST USE
```cpp
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} *List;

// Function to insert a node at the end of the list
void insertLastNode(List* L, int data) {
    List* trav;
    List newNode = (List)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*L == NULL) {
        *L = newNode;
    } else {
        for (trav = L; *trav != NULL; trav = &(*trav)->next);
        *trav = newNode;
    }
}

// Function to insert a node at a specific position (0-based index)
void insertAtPosition(List* L, int data, int pos) {
    List* trav;
    List newNode = (List)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (pos == 0) {
        newNode->next = *L;
        *L = newNode;
    } else {
        int i;
        for (trav = L, i = 0; i < pos - 1 && *trav != NULL; trav = &(*trav)->next, i++);
        
        if (*trav != NULL) {
            newNode->next = (*trav)->next;
            *trav = newNode;
        } else {
            free(newNode);
        }
    }
}

// Function to delete a node by data
void Delete(List* L, int x) {
    List* trav;
    List temp;

    for (trav = L; *trav != NULL && (*trav)->data != x; trav = &(*trav)->next);

    if (*trav != NULL) {
        temp = *trav;
        *trav = (*trav)->next;
        free(temp);
    }
}

// Function to delete a node at a specific position (0-based index)
void deleteAtPosition(List* L, int pos) {
    List* trav;
    List temp;

    if (pos == 0 && *L != NULL) {
        temp = *L;
        *L = (*L)->next;
        free(temp);
    } else {
        int i;
        for (trav = L, i = 0; i < pos - 1 && *trav != NULL; trav = &(*trav)->next, i++);
        
        if (*trav != NULL && (*trav)->next != NULL) {
            temp = (*trav)->next;
            (*trav)->next = temp->next;
            free(temp);
        }
    }
}

// Function to insert a node at the beginning
void insertAtBeginning(List* L, int data) {
    List newNode = (List)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *L;
    *L = newNode;
}

// Function to delete the first node
void deleteAtBeginning(List* L) {
    List temp;

    if (*L != NULL) {
        temp = *L;
        *L = (*L)->next;
        free(temp);
    }
}

// Function to delete the last node
void deleteLastNode(List* L) {
    List* trav;
    List temp;

    if (*L == NULL) {
        return;  // List is empty, nothing to delete
    } else if ((*L)->next == NULL) {  // Only one node in the list
        temp = *L;
        *L = NULL;
        free(temp);
    } else {
        for (trav = L; (*trav)->next->next != NULL; trav = &(*trav)->next);
        
        temp = (*trav)->next;
        (*trav)->next = NULL;
        free(temp);
    }
}

// Function to print all nodes in the list
void PrintALL(List L) {
    List curr;
    for (curr = L; curr != NULL; curr = curr->next) {
        printf("%d, ", curr->data);
    }
    printf("\n");
}

// Function to get data at a specific position (0-based index)
int getDataAtPosition(List L, int pos) {
    List trav;
    int i;

    for (trav = L, i = 0; trav != NULL && i < pos; trav = trav->next, i++);

    if (trav != NULL) {
        return trav->data;
    } else {
        printf("Position out of bounds.\n");
        return -1;  // Return an invalid value to indicate error
    }
}

int main() {
    List L = NULL;
    int size, data, Deldata, pos, insertData, position;

    // Example to insert nodes at the end
    printf("Enter size of list: ");
    scanf("%d", &size);
    
    for (int i = 0; i < size; i++) {
        printf("Enter data to insert: ");
        scanf("%d", &data);
        insertLastNode(&L, data);
    }

    // Print the list
    PrintALL(L);

    // Example to delete a node by data
    printf("Enter data to delete: ");
    scanf("%d", &Deldata);
    Delete(&L, Deldata);

    // Print the list after deletion
    PrintALL(L);

    // Example to insert at a specific position
    printf("Enter data to insert at position: ");
    scanf("%d", &insertData);
    printf("Enter position: ");
    scanf("%d", &position);
    insertAtPosition(&L, insertData, position);

    // Print the list after insertion
    PrintALL(L);

    // Example to delete a node at a specific position
    printf("Enter position of node to delete: ");
    scanf("%d", &position);
    deleteAtPosition(&L, position);

    // Print the list after deletion
    PrintALL(L);

    // Example to insert at the beginning
    printf("Enter data to insert at beginning: ");
    scanf("%d", &insertData);
    insertAtBeginning(&L, insertData);

    // Print the list after insertion at beginning
    PrintALL(L);

    // Example to delete the first node
    deleteAtBeginning(&L);

    // Print the list after deleting the first node
    PrintALL(L);

    // Example to delete the last node
    deleteLastNode(&L);

    // Print the list after deleting the last node
    PrintALL(L);

    // Example to get data at a specific position
    printf("Enter position to get data: ");
    scanf("%d", &position);
    int value = getDataAtPosition(L, position);
    if (value != -1) {
        printf("Data at position %d: %d\n", position, value);
    }

    return 0;
}

}
```

### SAME EXERCISE PPN 
```cpp
#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
}*List;

void InsertBefore(List* L, int target_data, int new_data) {
    List* trav;
    
    List newNode = (List)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        return;
    }
    newNode->data = new_data;

    if (*L == NULL) {
        printf("List is empty.\n");
        free(newNode);
        return;
    }

    if ((*L)->data == target_data) {
        newNode->next = *L;
        *L = newNode;
        return;
    }
   
    for (trav = L; *trav != NULL && (*trav)->next != NULL && (*trav)->next->data != target_data; trav = &(*trav)->next) {}
    
    if (*trav != NULL && (*trav)->next != NULL) {
        newNode->next = (*trav)->next;
        (*trav)->next = newNode;
    } else {
        printf("Target data not found in the list.\n");
        free(newNode);
    }
}

void InsertLast(List* L, int new_data){
    List newNode = (List)malloc(sizeof(struct Node));
    if(newNode == NULL){
        return;
    }
    newNode->data = new_data;
    newNode->next = NULL;
    List* trav;
   if(*L == NULL){
       *L = newNode;
   }else{
       for(trav = L; *trav != NULL; trav = &(*trav)->next){}
       *trav = newNode;
   }
    
}

void InsertSorted(List* L, int new_data){
    
    List* trav;
    List newNode = (List)malloc(sizeof(struct Node));
    if(newNode == NULL){
        return;
    }
    newNode->data = new_data;
   
    
    if(*L == NULL || (*L)->data >= newNode->data){
        newNode->next = *L;
        *L = newNode;
    }else{
        for(trav = L; (*trav)->next != NULL && (*trav)->next->data <  newNode->data; trav = &(*trav)->next){}
        newNode->next = (*trav)->next;
        (*trav)->next = newNode;
    }
}

void DeleteAllOccur(List* L, int new_data){
    
    List* trav;
    List temp;
    
    for(trav = L; *trav != NULL; ){
        if((*trav)->data == new_data){
            temp = *trav;
            *trav = (*trav)->next;
            free(temp);
        }else{
            trav = &(*trav)->next;
        }
    }
}

void deleteBEGGINNING(List* L){
    List temp;
    
    if(*L != NULL){
        printf("Deleted Beggining\n");
        temp = *L;
        *L = (*L)->next;
        free(temp);
    }
}

void deletePosition(List* L, int pos){
    List* trav;
    List temp;
    int i;
    
    if(pos == 1  && *L != NULL ){
        temp = *L;
        *L = (*L)->next;
        free(temp);
    }else{
        for(trav = L, i = 1; i < pos - 1 && *trav != NULL; trav = &(*trav)->next ,i++ ){}
        
        if(*trav != NULL && (*trav)->next != NULL){
        temp = (*trav)->next;
        (*trav)->next = temp->next;
        free(temp);
        }
    }
}

void DeleteElem(List* L, int new_data){
    List* trav;
    List temp;
    
    for(trav = L; *trav != NULL && (*trav)->data != new_data; trav = &(*trav)->next){}
    
    if(*trav != NULL){
        temp = *trav;
        *trav = (*trav)->next;
        free(temp);
    }
}

void insertPosition(List* L, int new_data, int pos){
    List* trav;
    int i;
    List newNode = (List)malloc(sizeof(struct Node));
    if(newNode == NULL){
        return;
    }
    newNode->data = new_data;
    newNode->next = NULL;
    
    
    if(pos == 1){
       newNode->next = *L;
       *L = newNode; 
    }else{
    for(trav = L, i = 1; i < pos - 1 && *trav != NULL; trav = &(*trav)->next , i++){}
    
        if(*trav != NULL){
             newNode->next = (*trav)->next;
            (*trav)->next = newNode;
        }else{
            printf("Position not found");
        }
    }
}

void deleteLAST(List* L){
    List temp;
    printf("Deleted Last\n");
    if(*L == NULL){
        return;
    }
    else if( (*L)->next == NULL){
        temp = *L;
        *L = NULL;
        free(temp);
    }else{
        List* trav;
        for(trav = L; (*trav)->next->next != NULL; trav = &(*trav)->next){}
        temp = (*trav)->next;
        (*trav)->next = NULL;
    }
}

void InsertLastUnique(List* L, int new_data){
    List* trav;
    int flag = 1;
    List newNode = (List)malloc(sizeof(struct Node));
    if(newNode == NULL){
        return;
    }
    newNode->data = new_data;
    newNode->next = NULL;
    
    if(*L == NULL){
        *L = newNode;
    }else{
    for(trav = L; *trav != NULL ; trav = &(*trav)->next){
        if((*trav)->data == new_data){
            flag = 0;
        }
    }
    if(flag){
        *trav = newNode;
     }else{
         printf("Number is already int the list\n");
         free(newNode);
     }
    }
}

void InsertFirst(List* L, int new_data){
   
    List newNode = (List)malloc(sizeof(struct Node));
    if(newNode == NULL){
        return;
    }
    newNode->data = new_data;
    newNode->next = *L;
    *L = newNode;
}

void PRINTALL(List L){
    List trav;
    for(trav = L; trav != NULL; trav = trav->next){
        printf("%d",trav->data);
         printf("-> ");
    }
    printf(" NULL\n");
}
int main (){
    
    int size, first, pos, InsertData;
    List L = NULL;
    
    
    printf("Enter Size: ");
    scanf("%d",&size);
    
    for(int i = 0; i < size; i++){
        int data;
        scanf("%d",&data);
        InsertSorted(&L, data);
    }
    
    PRINTALL(L);
     
    printf("Enter First Data: ");
    scanf("%d",&first);
    
    InsertFirst(&L, first);
    
    PRINTALL(L);
    
    deleteBEGGINNING(&L);
    
    PRINTALL(L);
    
    deleteLAST(&L);
    
    PRINTALL(L);
    
    printf("Enter Position to Insert the Data: ");
    scanf("%d",&pos);
    printf("Enter Data to Insert: ");
    scanf("%d",&InsertData);
    insertPosition(&L, InsertData, pos);
    
    PRINTALL(L);
   
    printf("Enter Position to Delete the Node: ");
    scanf("%d",&pos);
    
    deletePosition(&L,pos);
    
    PRINTALL(L);
    
    printf("Enter Data to Delete the Node: ");
    scanf("%d",&InsertData);
    
    DeleteElem(&L, InsertData);
    
    PRINTALL(L);
    
    printf("Enter Data to Delete the Nodes: ");
    scanf("%d",&InsertData);
    DeleteAllOccur(&L, InsertData);
    
    PRINTALL(L);
    
    printf("Enter Unique Data to insert: ");
    scanf("%d",&InsertData);
    InsertLastUnique(&L, InsertData);
    
    PRINTALL(L);
    
    return 0;
}
```

### VIRTUAL HEAP

![update.next](update.next.png)  

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
            temp = *L;
            *L = -1;  
        } else {
       
            for (trav = L; VH->Node[VH->Node[*trav].next].next != -1; trav = &VH->Node[*trav].next) {}
            temp = VH->Node[*trav].next;  
            VH->Node[*trav].next = -1;  
        }
        dealloc(VH, temp);  
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

  
