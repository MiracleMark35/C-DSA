# SET     
  
### typedef SET [MAX]                                                               
  ```cpp
#include <stdio.h>
#include <stdbool.h>

#define Max 10                                 
typedef int SET[Max];

// Initialize the set
void initSet(SET set) {
    for (int i = 0; i < Max; i++) {
        set[i] = -1; // Empty spots
    }
}

// Display the set
void displaySet(SET set) {
    printf("{ ");
    for (int i = 0; i < Max; i++) {
        if (set[i] != -1) {
            printf("%d ", set[i]);
        }
    }
    printf("}\n");
}

// Check if an element is a member
bool member(SET set, int elem) {
    for (int i = 0; i < Max; i++) {
        if (set[i] == elem) {
            return true;
        }
    }
    return false;
}

// Insert into the set
void insertSet(SET set, int elem) {
    if (member(set, elem)) {
        return; // Element already in the set
    }
    for (int i = 0; i < Max; i++) {
        if (set[i] == -1) { // Find an empty spot
            set[i] = elem;
            return;
        }
    }
}

// Delete an element
void deleteElement(SET set, int elem) {
    for (int i = 0; i < Max; i++) {
        if (set[i] == elem) {
            set[i] = -1; // Mark as deleted
            return;
        }
    }
}

// Union of two sets
void setUnion(SET set1, SET set2, SET resultSet) {
    initSet(resultSet); // Initialize result set
    for (int i = 0; i < Max; i++) {
        if (set1[i] != -1) {
            insertSet(resultSet, set1[i]);
        }
    }
    for (int i = 0; i < Max; i++) {
        if (set2[i] != -1) {
            insertSet(resultSet, set2[i]);
        }
    }
}

// Intersection of two sets
void setIntersection(SET set1, SET set2, SET resultSet) {
    initSet(resultSet);
    for (int i = 0; i < Max; i++) {
        if (set1[i] != -1 && member(set2, set1[i])) {
            insertSet(resultSet, set1[i]);
        }
    }
}

// Difference of two sets
void setDifference(SET set1, SET set2, SET resultSet) {
    initSet(resultSet);
    for (int i = 0; i < Max; i++) {
        if (set1[i] != -1 && !member(set2, set1[i])) {
            insertSet(resultSet, set1[i]);
        }
    }
}

// Test the functions
int main() {
    SET set1, set2, resultSet;

    initSet(set1);
    initSet(set2);

    // Insert elements into set1
    insertSet(set1, 1);
    insertSet(set1, 2);
    insertSet(set1, 3);

    // Insert elements into set2
    insertSet(set2, 2);
    insertSet(set2, 3);
    insertSet(set2, 4);

    // Display the sets
    printf("Set 1: ");
    displaySet(set1);
    printf("Set 2: ");
    displaySet(set2);

    // Perform union
    setUnion(set1, set2, resultSet);
    printf("Union of Set 1 and Set 2: ");
    displaySet(resultSet);

    // Perform intersection
    setIntersection(set1, set2, resultSet);
    printf("Intersection of Set 1 and Set 2: ");
    displaySet(resultSet);

    // Perform difference
    setDifference(set1, set2, resultSet);
    printf("Difference of Set 1 and Set 2 (Set 1 - Set 2): ");
    displaySet(resultSet);

    // Delete element
    deleteElement(set1, 2);
    printf("Set 1 after deleting 2: ");
    displaySet(set1);

    return 0;
}
```

  
  
  
  

  ```cpp
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct cell {
    char elem;
    struct cell* next;
} ctype, *Set;

// Function to initialize the set
void initSet(Set* s) {
    *s = NULL;
}

bool member(Set s, char elem) {
    Set trav;
    for (trav = s; trav != NULL; trav = trav->next) {
        if (trav->elem == elem) return true;  // Element found
    }
    return false;  // Element not found
}

// Function to display the elements of the set
void displaySet(Set s) {
    Set trav;
    for (trav = s; trav != NULL; trav = trav->next) {
        printf("%c ", trav->elem);
    }
    printf("\n");
}

// Function to find the minimum element in the set
char MIN(Set s) {
    if (s == NULL) {
        return '\0';  // Return null character if set is empty
    }
    char min = s->elem;
    Set trav;
    for (trav = s; trav != NULL; trav = trav->next) {
        if (trav->elem < min) {
            min = trav->elem;
        }
    }
    return min;
}

// Function to find the maximum element in the set
char MAX(Set s) {
    if (s == NULL) {
        return '\0';  // Return null character if set is empty
    }
    char max = s->elem;
    Set trav;
    for (trav = s; trav != NULL; trav = trav->next) {
        if (trav->elem > max) {
            max = trav->elem;
        }
    }
    return max;
}

// Function to check if two sets are equal
bool EQUAL(Set a, Set b) {
    Set trav;
    for (trav = a; trav != NULL; trav = trav->next) {
        if (!member(b, trav->elem)) {
            return false;  // Sets are not equal
        }
    }
    for (trav = b; trav != NULL; trav = trav->next) {
        if (!member(a, trav->elem)) {
            return false;  // Sets are not equal
        }
    }
    return true;  // Sets are equal
}

// Function to check if an element is a member of the set

// Function to insert an element into the set (no duplicates allowed)
void insert(Set* s, char elem) {
    if (member(*s, elem)) {
        return; // Element already in the set, no duplicates allowed
    }

    Set newNode = (Set)malloc(sizeof(ctype));
    newNode->elem = elem;
    newNode->next = NULL;

    Set* trav;

    if (*s == NULL) {
        *s = newNode;
    } else {
        for (trav = s; *trav != NULL; trav = &(*trav)->next) {}

        *trav = newNode;
    }
}

// Function to delete an element from the set
void delete(Set* s, char elem) {
    Set* trav;
    Set temp;
    for (trav = s; *trav != NULL && (*trav)->elem != elem; trav = &(*trav)->next) {}
    if (*trav != NULL) {
        temp = *trav;
        *trav = (*trav)->next;
        free(temp);
    }
}

// Function for union of two sets, returns a pointer to the resulting set
Set* setUnion(Set a, Set b) {
    Set* result = (Set*)malloc(sizeof(Set));
    initSet(result);

    Set trav;
    for (trav = a; trav != NULL; trav = trav->next) {
        insert(result, trav->elem);
    }

    for (trav = b; trav != NULL; trav = trav->next) {
        insert(result, trav->elem);
    }

    return result;
}

// Function for intersection of two sets
Set* intersection(Set a, Set b) {
    Set* result = (Set*)malloc(sizeof(Set));
    if (result == NULL) {
        return NULL;
    }
    initSet(result);

    Set trav;
    for (trav = a; trav != NULL; trav = trav->next) {
        if (member(b, trav->elem)) {
            insert(result, trav->elem);
        }
    }

    return result;
}

// Function for the difference between two sets
Set* difference(Set a, Set b) {
    Set* result = (Set*)malloc(sizeof(Set));
    if (result == NULL) {
        return NULL;
    }
    initSet(result);

    Set trav;
    for (trav = a; trav != NULL; trav = trav->next) {
        if (!member(b, trav->elem)) {
            insert(result, trav->elem);
        }
    }

    return result;
}

// Test the functions
int main() {
    Set setA, setB;
    Set* resultSet;

    // Initialize sets
    initSet(&setA);
    initSet(&setB);

    // Insert elements into set A
    insert(&setA, 'a');
    insert(&setA, 'b');
    insert(&setA, 'c');

    // Insert elements into set B
    insert(&setB, 'b');
    insert(&setB, 'd');

    // Display sets
    printf("Set A: ");
    displaySet(setA);
    printf("Set B: ");
    displaySet(setB);

    // Union of A and B
    resultSet = setUnion(setA, setB);
    printf("Union of A and B: ");
    displaySet(*resultSet);
    free(resultSet);  // Free the memory allocated for the result

    // Intersection of A and B
    resultSet = intersection(setA, setB);
    printf("Intersection of A and B: ");
    displaySet(*resultSet);
    free(resultSet);  // Free the memory allocated for the result

    // Difference A - B
    resultSet = difference(setA, setB);
    printf("Difference A - B: ");
    displaySet(*resultSet);
    free(resultSet);  // Free the memory allocated for the result

    // Delete element 'b' from set A
    delete(&setA, 'b');
    printf("Set A after deleting 'b': ");
    displaySet(setA);

    return 0;
}


```

### SET UNIUN SORTED  AND INSERT LAST

```cpp
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node* link;
} *SET;

SET UnionSorted(SET A, SET B);
void insertLast(SET* A, int newData);
void displaySet(SET A);

int main() {
  SET A = NULL;
  insertLast(&A, 1);
  insertLast(&A, 3);
  insertLast(&A, 5);
  insertLast(&A, 6);

  SET B = NULL;
  insertLast(&B, 1);
  insertLast(&B, 2);
  insertLast(&B, 3);
  insertLast(&B, 4);
  insertLast(&B, 7);

  // A = {1, 3, 5, 6}
  // B = {1, 2, 3, 4, 7}

  SET C = UnionSorted(A, B);
  displaySet(C);
}

SET UnionSorted(SET A, SET B) {
  SET C = NULL;
  SET* Cptr = &C;

  while (A != NULL || B != NULL) {
    int newData;
    if (A == NULL) {
      newData = B->data;
      B = B->link;
    } else if (B == NULL) {
      newData = A->data;
      A = A->link;
    } else if (A->data < B->data) {
      newData = A->data;
      A = A->link;
    } else if (B->data < A->data) {
      newData = B->data;
      B = B->link;
    } else {
      newData = A->data;
      A = A->link;
      B = B->link;
    }

    // Create and append the new node
    SET newNode = (SET)malloc(sizeof(struct node));
    if (newNode != NULL) {
      newNode->data = newData;
      newNode->link = NULL;
      *Cptr = newNode;
      Cptr = &newNode->link;
    }
  }
  return C;
}

void insertLast(SET* A, int newData) {
  SET* trav;
  for (trav = A; *trav != NULL; trav = &(*trav)->link);
  
  SET newNode = (SET)malloc(sizeof(struct node));
  if (newNode != NULL) {
    newNode->data = newData;
    newNode->link = NULL;
    *trav = newNode;
  }
}

void displaySet(SET A) {
  for (SET trav = A; trav != NULL; trav = trav->link) {
    printf("[%d]->", trav->data);
  }
  printf("NULL\n");
}
```
  
  
### ARRAY UID 1  
  
```cpp
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

// Reminder that returning an elemsay is not allowed.

// typedef int SET[MAX];
typedef struct node {
  int *elems;
  int count;
} SET;

//* Utility Functions
void initSet(SET *main);
void displaySet(SET main, char name);

//* Main Functions
SET *setUnion(SET A, SET B);
SET *unionSorted(SET A, SET B);
SET *intersectionSorted(SET A, SET B);
SET *differenceSorted(SET A, SET B);

int main() {
  SET A = {NULL, 0};
  SET B = {NULL, 0};
  // The reason why we declare it as a pointer to a SET variable is because we
  // want it to point to the address returned from SET operations. Plus, you
  // cannot return elemsay themselves. What you can do is return the address
  // pointing to the first element of an elems.
  SET *C;

  // int A_ARR[MAX] = {1, 3, 5, 7, 9};
  // int B_ARR[MAX] = {2, 4, 6, 8, 10};
  int A_ARR[MAX] = {1, 3, 5, 7, 9};
  int B_ARR[MAX] = {2, 3, 6, 7, 9};
  A.elems = A_ARR;
  B.elems = B_ARR;
  A.count = 5;
  B.count = 5;

  displaySet(A, 'A');
  displaySet(B, 'B');

  C = intersectionSorted(A, B);
  displaySet(*C, 'C');

  // C = differenceSorted(A, B);
  // displaySet(*C, 'C');
  // C = unionSorted(A, B);
  // displaySet(*C, 'C');
}

//* Utility Functions
void initSet(SET *main) {
  main = (SET *)calloc(sizeof(SET), 1);
  printf("initSet()\n");
}
void displaySet(SET main, char name) {
  int x;
  printf("SET %c:\n", name);
  printf("{");
  for (x = 0; x < main.count; x++) {
    if (x > 0) {
      printf(",");
    }
    printf("%d", main.elems[x]);
  }
  printf("}\n");
}

//* Main Functions
SET *setUnion(SET A, SET B);
SET *unionSorted(SET A, SET B) {
  // 1 2 4 7
  // 2 4 5 8
  // 1 2 4 5 7 8

  int A_INDEX = 0;
  int B_INDEX = 0;
  SET *C = (SET *)calloc(sizeof(SET), 1);
  if (C != NULL) {
    C->elems = (int *)malloc(sizeof(int) * MAX);
    C->count = 0;
    if (C->elems != NULL) {

      while (A_INDEX < A.count && B_INDEX < B.count) {
        if (A_INDEX == MAX) {
          C->elems[C->count] = B.elems[B_INDEX];
          B_INDEX++;
          C->count++;
        } else if (B_INDEX == MAX) {
          C->elems[C->count] = A.elems[A_INDEX];
          A_INDEX++;
          C->count++;
        } else if (A.elems[A_INDEX] < B.elems[B_INDEX]) {
          C->elems[C->count] = A.elems[A_INDEX];
          A_INDEX++;
          C->count++;
        } else if (B.elems[B_INDEX] < A.elems[A_INDEX]) {
          C->elems[C->count] = B.elems[B_INDEX];
          B_INDEX++;
          C->count++;
        } else {
          C->elems[C->count] = A.elems[A_INDEX];
          A_INDEX++;
          B_INDEX++;
          C->count++;
        }
        if (C->count == MAX) {
          C->elems = (int *)realloc(C->elems, sizeof(int) * MAX * 2);
        } 
      }
    }
  }
  return C;
}
// SET *intersectionSorted(SET A, SET B) {
//   SET *C = (SET *)calloc(sizeof(SET), 1);
//   C->count = 0;

//   if (C == NULL) {
//     exit(EXIT_FAILURE);
//   } else {
//     C->elems = (int*)malloc(sizeof(int)*MAX);
//     if (C->elems != NULL){
//       int A_idx = 0, B_idx = 0;

//       while (A_idx < A.count && B_idx < B.count) {
//         if (A.elems[A_idx] < B.elems[B_idx]) {
//           A_idx++;
//         } else if (A.elems[A_idx] > B.elems[B_idx]) {
//           B_idx++;
//         } else {
//           C->elems[C->count] = A.elems[A_idx];
//           A_idx++;
//           B_idx++;
//           C->count++;
//         }
//       }
//     }
//   }

//   return C;
// }
SET *intersectionSorted(SET A, SET B){
  SET *C = (SET*)calloc(sizeof(SET),1);
  if (C != NULL){
    C->count = 0;
    C->elems = (int*)malloc(sizeof(int)*MAX);
    if (C->elems != NULL){
      int A_INDEX = 0;
      int B_INDEX = 0;
      while (A_INDEX < A.count || B_INDEX < B.count){
        if (A.elems[A_INDEX] < B.elems[B_INDEX]){
          A_INDEX++;
        } else if (B.elems[B_INDEX] < A.elems[A_INDEX]){
          B_INDEX++;
        } else {
          C->elems[C->count] = A.elems[A_INDEX];
          A_INDEX++;
          B_INDEX++;
          C->count++;
        }
      }
    }
  }
  return C;
}
SET *differenceSorted(SET A, SET B) {
  // 1257
  // 2589
  // 17
  int A_INDEX = 0;
  int B_INDEX = 0;
  SET *C = (SET *)calloc(sizeof(SET), 1);
  if (C != NULL) {
    while (A_INDEX < A.count) {
      // if A < B, place A element to C
      if (A.elems[A_INDEX] < B.elems[B_INDEX]) {
        C->elems[C->count] = A.elems[A_INDEX];
        C->count++;
        A_INDEX++;
        // if B < A, increment B index
      } else if (B.elems[B_INDEX] < A.elems[A_INDEX]) {
        B_INDEX++;
        // if A == B, increment both indexes
      } else {
        A_INDEX++;
        B_INDEX++;
      }
    }
  }
  return C;
}
```
  
  
### LINKED LIST  
  
```cpp
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
  int data;
  struct node* link;
} *SET;

SET UnionSorted(SET A, SET B);
void insertLast(SET* A, int newData);
void displaySet(SET A);

int main(){
  SET A = NULL;
  insertLast(&A,1);
  insertLast(&A,3);
  insertLast(&A,5);
  insertLast(&A,6);

  SET B = NULL;
  insertLast(&B,1);
  insertLast(&B,2);
  insertLast(&B,3);
  insertLast(&B,4);
  insertLast(&B,7);

  // A = {1,3,5,6}
  // B = {1,2,3,4,7}

  SET C = UnionSorted(A,B);
  displaySet(C);
}

SET UnionSorted(SET A, SET B){
  SET C = NULL;
  SET* Cptr = &C;
  while (A != NULL || B != NULL){
    SET newNode = (SET)malloc(sizeof(struct node));
    if (newNode != NULL){
      if (A == NULL && B != NULL){
        newNode->data = B->data;
        newNode->link = NULL;
        *Cptr = newNode;
        Cptr = &newNode->link;

        B = B->link;
      } else if (B == NULL && A != NULL){
        newNode->data = A->data;
        newNode->link = *Cptr;
        *Cptr = newNode;
        Cptr = &newNode->link;

        A = A->link;
      } else if (A->data < B->data){
        newNode->data = A->data;
        newNode->link = *Cptr;
        *Cptr = newNode;
        Cptr = &newNode->link;

        A = A->link;
      } else if (B->data < A->data){
        newNode->data = B->data;
        newNode->link = *Cptr;
        *Cptr = newNode;
        Cptr = &newNode->link;

        B = B->link;
      } else {
        newNode->data = A->data;
        *Cptr = newNode;
        Cptr = &newNode->link;

        A = A->link;
        B = B->link;
      }
    }
  }
  return C;
}


void insertLast(SET* A, int newData){
  SET* trav;
  for (trav = A ; *trav != NULL ; trav = &(*trav)->link){};
  SET newNode = (SET)malloc(sizeof(struct node));
  if (newNode != NULL){
    newNode->data = newData;
    newNode->link = NULL;
    *trav = newNode;
  }
}

void displaySet(SET A){
  SET trav;
  for (trav = A ; trav != NULL ; trav = trav->link){
    printf("[%d]->", trav->data);
  }
}
```
  
  
### 
  
  
```cpp
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct node {
  int arr[MAX];
  int ctr;
} SET;

void displaySet(SET main);

SET *intersection(SET A, SET B);

int main(void) {
  SET A = {{1, 2, 3, 4, 5}, 5};
  SET B = {{3, 4, 5, 6, 7}, 5};
  SET *C = intersection(A, B);

  displaySet(A);
  displaySet(B);
  displaySet(*C);

  return 0;
}

void displaySet(SET main) {
  printf("{");

  for (int x = 0; x < main.ctr; ++x) {
    if (x > 0) {
      printf(", ");
    }

    printf("%d", main.arr[x]);
  }

  printf("}\n");
}

SET *intersection(SET A, SET B) {
  SET *C = (SET *)calloc(sizeof(SET), 1);

  if (!C) {
    exit(EXIT_FAILURE);
  }

  int A_idx = 0, B_idx = 0;

  while (A_idx < A.ctr && B_idx < B.ctr) {
    if (A.arr[A_idx] < B.arr[B_idx]) {
      A_idx++;
    } else if (A.arr[A_idx] > B.arr[B_idx]) {
      B_idx++;
    } else {
      C->arr[C->ctr++] = A.arr[A_idx];
      A_idx++;
      B_idx++;
    }
  }

  return C;
}
```
