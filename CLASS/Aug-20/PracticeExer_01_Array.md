# Char VERSION

```c

#include <stdio.h>
#include <stdbool.h>

#define MAX 10   // maximum size of the array

// charList is now array-based with characters
typedef struct {
    char elem[MAX];  // store characters
    int count;       // current number of elements
} charList;

// Function specification: findElem
bool findElem(charList L, char X) {
    int i;
    for (i = 0; i < L.count && L.elem[i] != X; i++);
    return (i < L.count) ? true : false;
}

// Display the list
void display(charList L) {
    if (L.count == 0) {
        printf("List is empty\n");
        return;
    }
    for (int i = 0; i < L.count; i++) {
        printf("%c", L.elem[i]);
        if (i < L.count - 1)
            printf(" -> ");
    }
    printf(" -> NULL\n");
}

int main() {
    charList L;     // Declare a variable of type charList
    L.count = 0;    // Initialize list as empty

    int rep;
    char data, findData;

    printf("Enter How Many Characters to Enter (max %d): ", MAX);
    scanf("%d", &rep);

    for (int i = 0; i < rep && L.count < MAX; i++) {
        printf("Enter %d Character: ", i + 1);
        scanf(" %c", &data); // note the space before %c to skip whitespace
        L.elem[L.count] = data;
        L.count++;
    }

    display(L);

    printf("Enter Character to Find: ");
    scanf(" %c", &findData);

    bool result = findElem(L, findData);
    printf("Result is: %s\n", result ? "true" : "false");

    return 0;
}
```

# NUMBER VERSION


```c
#include <stdio.h>
#include <stdbool.h>

#define MAX 10   // maximum size of the array

// A) Definition of datatype charList
typedef struct {
    int elem[MAX];  // array to store elements
    int count;      // current number of elements
} charList;

// B) Function specification: findElem
// Function header
bool findElem(charList L, int X) {
    int i;
    for (i = 0; i < L.count && L.elem[i] != X; i++);
    return (i < L.count) ? true : false;
}

// Function to display the list
void display(charList L) {
    if (L.count == 0) {
        printf("List is empty\n");
        return;
    }
    for (int i = 0; i < L.count; i++) {
        printf("%d", L.elem[i]);
        if (i < L.count - 1)
            printf(" -> ");
    }
    printf(" -> NULL\n");
}

int main() {
    charList L;     // Declare a variable of type charList
    L.count = 0;    // Initialize list as empty

    int rep, data, findData;

    printf("Enter How Many to Enter (max %d): ", MAX);
    scanf("%d", &rep);

    // Insert elements into the array-based list
    for (int i = 0; i < rep && L.count < MAX; i++) {
        printf("Enter %d Data: ", i + 1);
        scanf("%d", &data);
        L.elem[L.count] = data;
        L.count++;
    }

    display(L);

    // Function call
    printf("Enter Data to Find: ");
    scanf("%d", &findData);

    bool result = findElem(L, findData); // Function call
    printf("Result is: %s\n", result ? "true" : "false");

    return 0;
}
```
