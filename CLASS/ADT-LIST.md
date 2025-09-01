
# Assignment ADT LIST

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100  

typedef struct{
    int elems[MAX];  
    int count;      
} List;


void initListV1(List* L) {
    L->count = 0;   // empty list at the start
}


void insertLast(List* L, int data) {
    if(L->count < MAX) {
        L->elems[L->count] = data;
        L->count++;
    }
}


void deleteLast(List* L) {
    if(L->count > 0) {
        L->count--;   // just decrease count (last element is ignored)
    }
}


int findElem(List L, int data) {
    int i;
    for(i = 0; i < L.count && L.elems[i] != data; i++);
    return i < L.count ? i : -1;  
}


void displayList(List L) {
    int i;
    for(i = 0; i < L.count; i++) {
        printf("L[%d]: %d\n", i, L.elems[i]);
    }
    printf("\n");
}


void insertFirst(List* L, int data) {
    if(L->count < MAX) {
        // shift all elements right by 1
        for(int i = L->count; i > 0; i--) {
            L->elems[i] = L->elems[i - 1];
        }
        L->elems[0] = data;   // put new element at index 0
        L->count++;
    }
}


void deleteFirst(List* L) {
    if(L->count > 0) {
        // shift all elements left
        for(int i = 0; i < L->count - 1; i++) {
            L->elems[i] = L->elems[i + 1];
        }
        L->count--;
    }
}


void deleteElem(List* L, int data) {
    int pos = findElem(*L, data);
    if(pos != -1) {
        for(int i = pos; i < L->count - 1; i++) {
            L->elems[i] = L->elems[i + 1];
        }
        L->count--;
    }
}

void insertSorted(List* L, int data) {
    if(L->count < MAX) {
        int pos = 0;
        // find position where data should go
        while(pos < L->count && L->elems[pos] < data) {
            pos++;
        }
        // shift elements to the right
        for(int i = L->count; i > pos; i--) {
            L->elems[i] = L->elems[i - 1];
        }
        // insert the element
        L->elems[pos] = data;
        L->count++;
    }
}

void insertAtPos(List* L, int data, int pos) {
    // Valid position: must be inside the list and not exceed max size
    if(pos <= L->count && L->count < MAX) {
        // shift elements to the right to make space for the new element
        for(int i = L->count; i > pos; i--) {
            L->elems[i] = L->elems[i - 1];
        }
        // insert at the position
        L->elems[pos] = data;
        L->count++;
    }
}


void deleteAtPos(List* L, int pos) {
    // Valid position: must be inside the list
    if(pos < L->count) {
        // shift elements to the left to overwrite the deleted element
        for(int i = pos; i < L->count - 1; i++) {
            L->elems[i] = L->elems[i + 1];
        }
        L->count--;  // reduce count after deletion
    }
}


int main(void) {
    List listNum;
    initListV1(&listNum); 
    int array[7] = {10, 15, 5, 25, 35 , 40, 45};
    int i;
    printf("Original And Sorted List: \n");
    for(i = 0; i < 7; i++) {
        insertSorted(&listNum, array[i]);
    }

    displayList(listNum);
    printf("Count = %d\n", listNum.count);
    
    printf("Insert Postion: at 3, with 60:\n");
    insertAtPos(&listNum, 60, 3);
    displayList(listNum);
    printf("Count = %d\n", listNum.count);

    printf("Delete Postion 3: with the value is 60\n", 3);
    deleteAtPos(&listNum, 3);
    displayList(listNum);
    printf("Count = %d\n", listNum.count);

    return 0;
}

```
