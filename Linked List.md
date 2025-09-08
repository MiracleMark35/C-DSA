

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

### Pointer to Pointer to Node (PPN) Traversal Partt 2
```c
#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int elem;
    struct node* link;
} *Node;   // Shorter syntax (no need to write *)

Node createNode(int data){
    Node newNode = (Node)malloc(sizeof(Node));
    newNode->elem = data;
    newNode->link = NULL;
    return newNode;
}

void insertBeginning(Node* head, int data){
    Node temp = createNode(data);
    temp->link = *head;
    *head = temp;
    
}

void deleteBeginning(Node* head){
    *head = (*head)->link; // MISTAKE !!!  *head  =  &(*head)->link → is the address of the link field itself, not the node it points to
    
    // *head = &(*head)->link;  will update the head to the next node 
}

void insertLast(Node* head, int data){
    Node* temp =  head;    
    
    // head is a Node (struct node*)

    // temp is a Node* (struct node**)

    // You're saying: "let temp point to head" — which is correct for modifying the list
    
    
    
    while(*temp != NULL){    // *temp gives us the actual node pointer,     //*temp != NULL checks if there is a node there.
        temp = &(*temp)->link;   //  &(*temp)->link gives us the address of the next link field — perfect for insertion.
    } //(*temp)->link accesses the link field of that node 
    //&(*temp)->link takes the address of that link field.
    *temp = createNode(data);   //*temp is the actual pointer to the current node (Node).
} //*temp is the pointer at the current position in the list (which is NULL at this point, the end).

    //*temp = createNode(data); sets that NULL link to point to the new node.


void displayList(Node head) {
    Node p = head;
    while (p != NULL) {
        printf("%d -> ", p->elem);
        p = p->link;
    }
    printf("NULL\n");
}

int main() {
    Node head = NULL;  // No header cell, head points to the first node     // Node* head = NULL; // This is a pointer to a Node* (so double pointer in disguise!)
                                                                            // Node* head = NULL;  You are passing a copy of the head pointer into the function.
                                                                            // Node* head = NULL;  You are passing a copy of the head pointer into the function.
                                                                            // insertLast(head, 30);  // Passing just a copy of the pointer
    // Insert elements at the end
    insertLast(&head, 10);  // You pass the address of head, so changes reflect in main()
    insertLast(&head, 20);
    insertLast(&head, 30);   
    insertBeginning(&head, 5);
    deleteBeginning(&head);
    displayList(head); //No need for &head because you're not modifying the pointer or the structure of the list.

    return 0;
}


```
# Why do we use this PPN style?
 Using Node* temp (i.e., pointer to a pointer to node):

Makes it easy to insert at the head of the list or anywhere without special cases.

Avoids needing a "prev" pointer or manual head handling.

It’s a powerful trick in pointer-based linked list manipulation.


| Expression               | Meaning                                            | Correct? |
| ------------------------ | -------------------------------------------------- | -------- |
| `(*head)->link`          | The next node                                      | ✅ Yes    |
| `&(*head)->link`         | Address of the `link` field (i.e. Node\*\*)        | ❌ No     |
| `*head = (*head)->link`  | Head now points to the next node                   | ✅ Yes    |
| `*head = &(*head)->link` | Invalid type — trying to assign address of pointer | ❌ No     |



| Expression       | Meaning                                                 |
| ---------------- | ------------------------------------------------------- |
| `head`           | pointer to the first node (`0x3000`)                    |
| `*head`          | the actual Node struct at `0x3000`                      |
| `head->link`     | the next node (`NULL` in this case)                     |
| `(*head).link`   | same as above (another syntax)                          |
| `&head`          | address of the pointer variable itself (e.g., `0x4000`) |
| `&(*head)->link` | address of the `link` field **inside the node**         |



| Expression       | Value / Address                   | Can it update the actual node? | Explanation                                                                                                                        |
| ---------------- | --------------------------------- | ------------------------------ | ---------------------------------------------------------------------------------------------------------------------------------- |
| `head`           | `0x3000`                          | ❌ No                           | This is just the pointer itself. If you assign `head = NULL;`, it only changes the pointer locally, **not the node** it points to. |
| `*head`          | Struct at `0x3000`                | ✅ Yes                          | This is the **node itself**. You can update its contents like `(*head).elem = 20;`                                                 |
| `head->link`     | `NULL` (or next node)             | ✅ Yes                          | You can write `head->link = newNode;` to change what this node points to next.                                                     |
| `&head`          | Address of the pointer (`0x4000`) | ✅ Yes, but indirect            | This is used when you want to **modify the pointer itself** (e.g., change where `head` points), like in `insertLast(&head, ...)`   |
| `(*head).link`   | Same as `head->link`              | ✅ Yes                          | Just another way to access the `link` field.                                                                                       |
| `&(*head)->link` | Address inside node               | ✅ Technically                  | Gives the address of the `link` field, which you can use if you want a pointer to it specifically.                                 |

## LOOK AHEAD WIHOUT HEAD
#### 
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

# Summary

| Operation                                           | Use `Node*` or `Node**`? | Why                                         |
| --------------------------------------------------- | ------------------------ | ------------------------------------------- |
| Traversing and freeing all nodes (`deleteAll`)      | `Node*` ✅                | Just walk and free                          |
| Inserting or deleting specific nodes (modify links) | `Node**` ✅               | Need to update links via pointer-to-pointer |

### Make NULL or DELETE ALL

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

  
