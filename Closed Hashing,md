# Closed Hashing

```c
// Hash Tables (Closed Hashing)

#include <stdio.h>
#include <stdbool.h>

#define MAX 10
#define EMPTY   '~'
#define DELETED '!'

typedef char Dictionary[MAX];

// Hash Function (Hard Coded)
int hashBrown(char c) {
    char elements[MAX] = { "abcdefghij" };
    int hash[MAX] = { 3, 9, 4, 3, 9, 0, 1, 3, 0, 3 };

    int i;
    for (i = 0; i < MAX && elements[i] != c; i++) {}
    return hash[i];
}

// Initialize Dictionary
void initDictionary(Dictionary D) {
    for (int i = 0; i < MAX; i++) {
        D[i] = EMPTY;
    }
}

// Display Dictionary
void displayDict(Dictionary D) {
    printf("\n\tINDEX\tELEMENT");
    for (int i = 0; i < MAX; i++) {
        printf("\n\t[%d] :\t", i);
        if (D[i] == EMPTY) {
            printf("EMPTY");
        } else if (D[i] == DELETED) {
            printf("DELETED");
        } else {
            printf("%c", D[i]);
        }
    }
    printf("\n");
}

// isMember Dictionary
bool isMember(Dictionary D, char elem) {
    int i = hashBrown(elem), sl;
    for (sl = 1; sl != MAX && D[i] != elem && D[i] != EMPTY; 
         i = (i + 1) % MAX, sl++) {}

    printf("\n\tThe search length is %d\n", sl);
    return sl != MAX;
}

// Insertion Dictionary
void insertUnique(Dictionary D, char elem) {
    int i = hashBrown(elem), sl;
    for (sl = 1; sl != MAX && D[i] != elem && D[i] != EMPTY && D[i] != DELETED; 
         i = (i + 1) % MAX, sl++) {}

    if (sl != MAX && D[i] != elem) {
        D[i] = elem;
    } else {
        printf("\t%c is already in the dictionary\n", elem);
    }
}

// Deletion Dictionary
void deleteMember(Dictionary D, char elem) {
    int i = hashBrown(elem), sl;
    for (sl = 1; sl != MAX && D[i] != elem && (D[i] != EMPTY || D[i] != DELETED); 
         i = (i + 1) % MAX, sl++) {}

    if (sl != MAX && D[i] == elem) {
        D[i] = DELETED;
    } else {
        printf("\t%c is not found\n", elem);
    }
}

// Get Search Length
int getSearchLength(Dictionary D, char elem) {
    int i = hashBrown(elem), sl;
    for (sl = 1; sl != MAX && D[i] != elem && D[i] != EMPTY; 
         i = (i + 1) % MAX, sl++) {}

    return sl;
}

```
