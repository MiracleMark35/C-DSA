### Bit Victor Implementation

```cpp
#include <stdio.h>
#include <stdbool.h>

#define Max 10

typedef int Set[Max];

// Function to initialize the set
void initSet(Set s) {
    for (int i = 0; i < Max; i++) {
        s[i] = 0;  // Initialize all elements to 0 (not present)
    }
}

// Function to check if an element is a member of the set
bool MEMBER(Set s, int elem) {
    return elem >= 0 && elem < Max && s[elem] == 1;  // Return true if the element is present
}

// Function to insert an element into the set
void INSERT(Set s, int elem) {
    if (elem >= 0 && elem < Max) {
        s[elem] = 1;  // Set the corresponding index to 1 (present)
    }
}

// Function to delete an element from the set
void DELETE(Set s, int elem) {
    if (elem >= 0 && elem < Max) {
        s[elem] = 0;  // Set the corresponding index to 0 (not present)
    }
}

// Function to display the elements of the set
void displaySet(Set s) {
    printf("{ ");
    for (int i = 0; i < Max; i++) {
        if (s[i] == 1) {
            printf("%d ", i);  // Print the index if it is present
        }
    }
    printf("}\n");
}

int main() {
    Set mySet;

    initSet(mySet);

    // Insert elements into the set
    INSERT(mySet, 1);
    INSERT(mySet, 3);
    INSERT(mySet, 5);

    // Display the set
    printf("Set: ");
    displaySet(mySet);

    // Check membership
    printf("Is 3 a member? %s\n", MEMBER(mySet, 3) ? "Yes" : "No");
    printf("Is 2 a member? %s\n", MEMBER(mySet, 2) ? "Yes" : "No");

    // Delete an element
    DELETE(mySet, 3);
    printf("Set after deleting 3: ");
    displaySet(mySet);

    return 0;
}
```
 ```cpp
#include <stdio.h>
#include <stdlib.h>
#define MAX 8

typedef char SET[MAX]; // Define a SET type as an array of MAX elements.

void displaySet(SET main);
void displayBits(SET main);
void insertElem(SET* main, char index); // Pass SET as a pointer to modify the original.
void deleteElem(SET* main, char index); // Pass SET as a pointer to modify the original.
SET* setUnion(SET A, SET B);
SET* setIntersection(SET A, SET B);
SET* setDifference(SET A, SET B);

int main() {
    SET A = {0}; // Initialize set A with all elements set to 0.
    SET B = {0}; // Initialize set B with all elements set to 0.
    SET *C; // Pointer for storing results of set operations.

    // Insert elements into set A
    insertElem(&A, 3); // Pass the address of A
    insertElem(&A, 5); // Pass the address of A
    insertElem(&A, 0); // Pass the address of A
    insertElem(&A, 6); // Pass the address of A

    // Insert elements into set B
    insertElem(&B, 4); // Pass the address of B
    insertElem(&B, 5); // Pass the address of B
    insertElem(&B, 1); // Pass the address of B
    insertElem(&B, 0); // Pass the address of B

    // Display set A
    printf("SET A\n");
    displaySet(A);
    displayBits(A);

    // Display set B
    printf("\nSET B\n");
    displayBits(B);
    displaySet(B);

    // Perform set union and display results
    printf("\nA U B\n");
    C = setUnion(A, B);
    displayBits(*C);
    displaySet(*C);
    free(C); // Free memory allocated for C.

    // Perform set intersection and display results
    printf("\nA ∩ B\n");
    C = setIntersection(A, B);
    displayBits(*C);
    displaySet(*C);
    free(C); // Free memory allocated for C.

    // Perform set difference and display results
    printf("\nA - B\n");
    C = setDifference(A, B);
    displayBits(*C);
    displaySet(*C);
    free(C); // Free memory allocated for C.

    return 0;
}

SET* setUnion(SET A, SET B) {
    SET *C = (SET*)malloc(sizeof(SET)); // Allocate memory for set C.
    int x;

    if (C != NULL) { // Check if allocation was successful.
        for (x = 0; x < MAX; x++) {
            (*C)[x] = A[x] | B[x]; // Perform bitwise OR for union.
        }
    }
    return C; // Return the pointer to the result set.
}

SET* setIntersection(SET A, SET B) {
    SET *C = (SET*)malloc(sizeof(SET)); // Allocate memory for set C.
    int x;

    if (C != NULL) { // Check if allocation was successful.
        for (x = 0; x < MAX; x++) {
            (*C)[x] = A[x] & B[x]; // Perform bitwise AND for intersection.
        }
    }
    return C; // Return the pointer to the result set.
}

SET* setDifference(SET A, SET B) {
    SET *C = (SET*)malloc(sizeof(SET)); // Allocate memory for set C.
    int x;

    if (C != NULL) { // Check if allocation was successful.
        for (x = 0; x < MAX; x++) {
            (*C)[x] = A[x] & ~B[x]; // Perform bitwise AND with negation for difference.
        }
    }
    return C; // Return the pointer to the result set.
}

void displaySet(SET main) {
    int x;

    for (x = 0; x < MAX; x++) {
        if (main[x] == 1) { // Check if the bit is set.
            printf("%d ", x); // Print the index if it is set.
        } else {
            printf("  "); // Print space for unset bits.
        }
    }
    printf("\n");
}

void displayBits(SET main) {
    int x;

    for (x = 0; x < MAX; x++) {
        printf("%d ", main[x] == 1 ? 1 : 0); // Display 1 or 0 for each bit.
    }
    printf("\n");
}

void insertElem(SET* main, char index) { // Modify original set via pointer.
    if (index < MAX) {
        (*main)[index] = 1; // Set the bit at the given index.
    }
}

void deleteElem(SET* main, char index) { // Modify original set via pointer.
    if (index < MAX) {
        (*main)[index] = 0; // Clear the bit at the given index.
    }
}

```

# Sir Booby VAriation 1

```c
#include <stdio.h>
#include <stdbool.h>

// Initialize the set to 0
void initialize(unsigned char *set) {
    *set = 0;
}

// Insert an element into the set
void insert(unsigned char *set, int element) {
    if (element < 0 || element > 7) {
        printf("Error: Element %d out of range.\n", element);
        return;
    }
    *set |= (1 << element);
}

// Delete an element from the set
void delete(unsigned char *set, int element) {
    if (element < 0 || element > 7) {
        printf("Error: Element %d out of range.\n", element);
        return;
    }
    *set &= ~(1 << element);
}

// Find if an element exists in the set
bool find(unsigned char set, int element) {
    if (element < 0 || element > 7) {
        printf("Error: Element %d out of range.\n", element);
        return false;
    }
    return (set & (1 << element)) != 0;
}

// Union of two sets
unsigned char unionSet(unsigned char A, unsigned char B) {
    return A | B;
}

// Intersection of two sets
unsigned char intersection(unsigned char A, unsigned char B) {
    return A & B;
}

// Difference of two sets (A - B)
unsigned char difference(unsigned char A, unsigned char B) {
    return A & (~B);
}

// Display the set
void display(unsigned char set) {
    printf("{");
    bool first = true;
    for (int i = 0; i < 8; i++) {
        if (find(set, i)) {
            if (!first) {
                printf(", ");
            }
            printf("%d", i);
            first = false;
        }
    }
    printf("}\n");
}

// Example usage
int main() {
    unsigned char A, B, C;

    initialize(&A);
    initialize(&B);

    insert(&A, 1);
    insert(&A, 6);
    printf("Set A: ");
    display(A);

    insert(&B, 3);
    insert(&B, 6);
    insert(&B, 7);
    printf("Set B: ");
    display(B);

    C = unionSet(A, B);
    printf("Union: ");
    display(C);

    C = intersection(A, B);
    printf("Intersection: ");
    display(C);

    C = difference(A, B);
    printf("Difference (A-B): ");
    display(C);

    delete(&A, 1);
    printf("Set A after deleting 1: ");
    display(A);

    return 0;
}

```

# Sir Bobby  Varration 3
```c
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 8

typedef bool Set[ARRAY_SIZE];





void initialize(Set set) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        set[i] = false;  // clear all elements
    }
}


void insert(Set set, int element) {
    if (element < 0 || element >= ARRAY_SIZE) return;  // safety check
    set[element] = true;
}



void delete(Set set, int element) {
    if (element < 0 || element >= ARRAY_SIZE) return;  // safety check
    set[element] = false;
}



bool find(Set set, int element) {
    if (element < 0 || element >= ARRAY_SIZE) return false; // safety check
    return set[element];
}


void unionSet(Set A, Set B, Set C) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        C[i] = A[i] || B[i];  // true if either A or B has it
    }
}




void intersection(Set A, Set B, Set C) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        C[i] = A[i] && B[i];  // true if both A and B have it
    }
}




void difference(Set A, Set B, Set C) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        C[i] = A[i] && !B[i];  // true if in A and NOT in B
    }
}

void displayBitVersion(Set set) {
    printf("{");
    bool first = true;
    for (int i = 0; i < ARRAY_SIZE; i++) {
             if (!first) printf(", ");
       set[i] ? printf("1") : printf("0");
            first = false;
        
    }
    printf("}\n");
}



void display(Set set) {
    printf("{");
    bool first = true;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (set[i]) {
            if (!first) printf(", ");
            printf("%d", i);
            first = false;
        }
    }
    printf("}\n");
}


int main() {
    Set A, B, C;

    initialize(A);
    initialize(B);
    initialize(C);

    insert(A, 0);
    insert(A, 2);
    insert(A, 7);

    insert(B, 2);
    insert(B, 4);
    insert(B, 5);

    printf("Set A: "); display(A); // {0, 2, 7}
    printf("Set B: "); display(B); // {2, 4, 5}

    unionSet(A, B, C);
    printf("Union: "); display(C);  // {0, 2, 4, 5, 7}

    intersection(A, B, C);
    printf("Intersection: "); display(C); // {2}

    difference(A, B, C);
    printf("Difference: "); display(C);   // {0, 7}

    delete(A, 0);
    delete(A, 7);
    printf("A after deletion: "); display(A); // {2}

    printf("Find 2 in A? %s\n", find(A, 2) ? "Yes" : "No"); // Yes
    printf("Find 0 in A? %s\n", find(A, 0) ? "Yes" : "No"); // No

    return 0;
}

```

# Simple Bit Vector

```c
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef int SET[MAX];


SET *makeBitVector (int arr[]);
void displayVector (SET S);
void deletePos (SET S, int pos);
SET *myUnion (SET A, SET B);
SET *myIntersection (SET A, SET B);
SET *myDifference (SET A, SET B);

int main () {
    int mArr[5] = {3, 2, 0, 8, 10};
    SET *mBV;                                      
    SET bvZ = {0,0,1,1,0,1,0,1,0};

    printf("00. Make Bit Vector (arr to bv)\n");
    printf("\tFrom integer array {3, 2, 5, 8, 10} to Bit Vector\n");
    mBV = makeBitVector (mArr);
    printf("\tSET mBV = ");
    displayVector (*mBV);

    printf("\n\n01. Delete Bits From the Bit Vector\n");
    deletePos (*mBV, 3);
    printf("\tSET mBV = ");
    displayVector (*mBV);
    deletePos (*mBV, 1);
    printf("\n\tSET mBV = ");
    displayVector (*mBV);

    printf("\n\n\t<< UID >>\n\tSET mBV = ");
    displayVector (*mBV);
    printf("\n\tSET bvZ = ");
    displayVector (bvZ);

    printf("\n\n02. Union of Two Sets\n");
    SET *F = myUnion (*mBV, bvZ);
    printf("\t  UNION = ");
    displayVector (*F);

    printf("\n\n03. Intersection of Two Sets\n");
    F = myIntersection (*mBV, bvZ);
    printf("\t  INTER = ");
    displayVector (*F);

    printf("\n\n04. Difference of Two Sets\n");
    F = myDifference ( bvZ, *mBV);
    printf("\t  DIFFERENCE = ");
    displayVector (*F);

    printf("\n\n");
    return 0;
}

// function definitions
SET *makeBitVector (int arr[]) {
    SET *temp = calloc(1, sizeof(SET)); // zero all bits automatically
    
    // for(int i = 0; i < MAX; i++){ /// this can be good also
    //     (*temp)[i] = 0;
    // } 
        for(int i = 0; i < 5; i++){
            if(arr[i] < MAX){
                (*temp)[arr[i]] = 1;
            }
        }
    
     
    return temp;
}

void displayVector (SET S) {
    int x;
    for (x = 0; x < MAX; ++x) {
        printf("%d", S[x]);
        if (x < MAX-1) {
            printf(" ");
        }
    }
}

void deletePos (SET S, int pos) { 
    if (pos < MAX && pos >= 0) {
        S[pos-1] = 0; // depends on the user input 
    }
}

SET *myUnion (SET A, SET B) {
    SET *temp = malloc(sizeof(SET));   // no need to initalize
        for (int i = 0; i < MAX; i++) {
             (*temp)[i]  = A[i] || B[i]; // this will handle all the 0's'and 1's
        }

    return temp;
}

SET *myIntersection (SET A, SET B) {
     SET *temp = malloc(sizeof(SET));
        for (int i = 0; i < MAX; i++) {
             (*temp)[i]  = A[i] && B[i];
        }

    return temp;
}

SET *myDifference (SET A, SET B) {
     SET *temp = malloc(sizeof(SET));
     
        for (int i = 0; i < MAX; i++) {
             (*temp)[i]  = A[i] && !B[i];
        }

    return temp;
}
```
