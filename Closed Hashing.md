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

# TWO SUM

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define MAX 0XA

/*********************************/
/*    USER-DEFINED DATA TYPES    */
/*********************************/
typedef struct {
    int key;
    int value;
} KeyValuePair;

typedef KeyValuePair Dictionary[MAX];

typedef enum {
    EMPTY = -999999,
    DELETED = -1000000
} DictStatus;

/*********************************/
/*       HELPER FUNCTIONS        */
/*********************************/
void initDict(Dictionary D);
int hash(int key);

/*********************************/
/*          YOUR TASKS           */
/*********************************/
int* twoSum(int sum, int arr[], int size, int *retSize);
void insert(Dictionary D, int key, int value);
int getValue(Dictionary D, int key);

int main() {
    int size;
    printf("Enter size: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter elements in the array (unique): ");
    for (int i = 0; i < size; i++) scanf("%d", arr + i);

    int sum;
    printf("Enter sum: ");
    scanf("%d", &sum);

    int retSize;
    int *sumIndices = twoSum(sum, arr, size, &retSize);
    printf("Indices of elements adding up to %d are: ", sum);

    for (int i = 0; i < retSize; i++) printf("%d%s", sumIndices[i], (i + 1 == retSize) ? "" : " & ");

    return 0;
}

/*********************************/
/*       HELPER FUNCTIONS        */
/*********************************/
void initDict(Dictionary D) {
    for(int i = 0; i < MAX; i++) {
        D[i].key = EMPTY;
    }
}

int hash(int key) {
    return abs(key) % MAX;
}


/*********************************/
/*          YOUR TASKS           */
/*********************************/

void insert(Dictionary D, int key, int value) {
    // Implementation here...
  int hashValue = hash(key);
  for(int i = 0 ; i < MAX; i++){
    int probe = (hashValue + i) % MAX;
    if(D[probe].key == EMPTY || D[probe].key == DELETED){
      D[probe].key = key;
      D[probe].value = value;
      return;
    }
  }
}


// Function that returns indices of 
// two numbers that add up to `sum`
int* twoSum(int sum, int arr[], int size, int *retSize) {
    Dictionary D;
    initDict(D);

    // Implementation here...
  for(int i = 0;  i < size; i++){
    int complement = sum - arr[i];
    int hashValues = hash(complement);
   //  int probe = (i + hashValues) % MAX;

    for(int j = 0; j < size; j++){
      int probe = (j + hashValues) % MAX;
      if(D[probe].key == EMPTY) break;
      
       if(D[probe].key == complement){
      int* newArr = malloc(2 * sizeof(int));
      newArr[0] = D[probe].value;
      newArr[1] = i;
      
      if(newArr[0] > newArr[1]){
        int temp = newArr[0];
        newArr[0] = newArr[1];
        newArr[1] = temp;
      }
    *retSize = 2;
      return newArr;
    }
    }
   
      insert(D, arr[i], i);
    
  }
  return NULL;
}
// Function that inserts a key-value
// pair into the Dictionary
// Function that returns the value based on the passed key
// Function returns -1 if key is not in the dictionary
int getValue(Dictionary D, int key) {
    // Implementation here...
   int hashValue = hash(key);
  for(int i = 0 ; i < MAX; i++){
    int probe = (hashValue + i) % MAX;
    if(D[probe].value == EMPTY ) return -1;
    if(D[probe].key == key) return D[probe].value;
  }
  return -1;
}

```

# LEssons in TWO SUM
```c
void initDict(Dictionary D) {
    for(int i = 0; i < MAX; i++) {
        D[i].key = EMPTY;   // ✅ Direct access to enum value
        D[i].key = Stat.EMPTY;   // ❌ Wrong: You don't access enums through a variable
//EMPTY and DELETED are now constants.
    }
}
```
# 1. Why do we need a second loop in the twoSum function?

Because this is closed hashing with linear probing.

When we insert a number, we calculate its hash index.

If that slot is already taken, we shift forward (+1, +2, etc.) to find an empty space.

So when searching, we also need to probe (check forward) in case the value we want got stored in a different slot due to collision.

✅ Without the loop, you would only check one position.

# 2. What is the difference between key and value?
```c
typedef struct {
    int key;
    int value;
} KeyValuePair;
```

| Part    | What it stores                                    |
| ------- | ------------------------------------------------- |
| `key`   | The array number you're storing (example: arr[i]) |
| `value` | The index of that number in the original array    |


Key = value of the number (like 3, 5, 7...)

Value = index where this number is located in the array

Why do we need both?
✅ Because when we find the match for sum - arr[i], we want to return the indices, not the actual numbers.

Array: {3, 5, 7, 2}, sum = 9

| i (index) | arr[i] | Inserted in Dictionary as |
| --------- | ------ | ------------------------- |
| 0         | 3      | key = 3, value = 0        |
| 1         | 5      | key = 5, value = 1        |
| 2         | 7      | key = 7, value = 2        |
| 3         | 2      | key = 2, value = 3        |
