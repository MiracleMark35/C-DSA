### DICT   
  
```cpp
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} *List;

#define MAX 10
typedef List Dictionary[MAX];

// Hash function to determine the index for a given key
int hash(int key) {
    return key % MAX;
}

// Initialize the dictionary
void initialize(Dictionary dict) {
    for (int i = 0; i < MAX; i++) {
        dict[i] = NULL;
    }
}

// Insert a key into the dictionary
void Insert(Dictionary dict, int key) {
    int index = hash(key);
    List newNode = (List)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->next = dict[index];
    dict[index] = newNode;
}

// Delete a key from the dictionary
void Delete(Dictionary dict, int key) {
    int index = hash(key);
    List* trav = &dict[index]; // Pointer to pointer for traversal
    List temp;

    // Traverse the linked list to find the key
    for (; *trav != NULL && (*trav)->data != key; trav = &(*trav)->next) {}

    // If the key was found, delete it
    if (*trav != NULL) {
        temp = *trav;
        *trav = (*trav)->next; // Remove the node from the list
        free(temp); // Free the memory allocated for the node
    } else {
        printf("Key %d not found in the dictionary\n", key);
    }
}

// Check if a key is a member of the dictionary
int Member(Dictionary dict, int key) {
    int index = hash(key);
    List current = dict[index];

    for (; current != NULL; current = current->next) {
        if (current->data == key) {
            return 1; // Key found
        }
    }

    return 0; // Key not found
}

// Function to insert a node into a sorted linked list
void sortedInsert(List* head, int newData) {
    List newNode = (List)malloc(sizeof(struct Node));
    newNode->data = newData;

    // Special case for the head end
    if (*head == NULL || (*head)->data >= newData) {
        newNode->next = *head;
        *head = newNode;
    } else {
        List current = *head;
        // Locate the node before the point of insertion
        while (current->next != NULL && current->next->data < newData) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to create a sorted dictionary
Dictionary* insertSorted(Dictionary main) {
    Dictionary* sortedDict = (Dictionary*)malloc(sizeof(Dictionary));
    initialize(*sortedDict); // Initialize the new dictionary

    for (int i = 0; i < MAX; i++) {
        List trav = main[i];
        while (trav != NULL) {
            sortedInsert(&(*sortedDict)[hash(trav->data)], trav->data);
            trav = trav->next;
        }
    }
    return sortedDict;
}


// Function to display the contents of the dictionary
void display(Dictionary dict) {
    for (int i = 0; i < MAX; i++) {
        List current = dict[i];
        printf("Index %d: ", i);
        for (; current != NULL; current = current->next) {
            printf("%d -> ", current->data);
        }
        printf("NULL\n");
    }
}

// Example usage
int main() {
    Dictionary dict;
    initialize(dict);

    Insert(dict, 5);
    Insert(dict, 15);
    Insert(dict, 25);
    Insert(dict, 35);

    printf("Dictionary after insertions:\n");
    display(dict);

    printf("Checking membership of 15: %d\n", Member(dict, 15));
    printf("Checking membership of 10: %d\n", Member(dict, 10));

    Delete(dict, 15);
    printf("Dictionary after deleting 15:\n");
    display(dict);

    Delete(dict, 100); // Trying to delete a non-existing key
    Dictionary* sortedDict = insertSorted(dict);
    printf("Sorted Dictionary:\n");
    display(*sortedDict);

    return 0;
}
```

 
```
### OPEN HASHING 
```cpp
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 10
#define EMPTY -1
#define DELETED -2

typedef struct node {
  int data;
  struct node* link;
} *SET;

typedef SET DICTIONARY[MAX];

void initDictionary (DICTIONARY main);
int hash            (int elem);
bool isMember       (DICTIONARY main, int find);
void insert         (DICTIONARY main, int newData);
void display        (DICTIONARY main);
void delete         (DICTIONARY main, int delete);

int main(){
  DICTIONARY Portugese;
  initDictionary(Portugese);

  insert(Portugese, 2);
  insert(Portugese, 32);
  insert(Portugese, 11);
  insert(Portugese, 55);
  insert(Portugese, 45);
  insert(Portugese, 49);
  insert(Portugese, 98);
  insert(Portugese, 25);
  insert(Portugese, 1);

  display(Portugese);

  delete(Portugese, 45);
  delete(Portugese, 2);
  delete(Portugese, 11);

  display(Portugese);
}

void initDictionary (DICTIONARY main){
  int x;
  for (x = 0 ; x < MAX ; x++){
    main[x] = NULL;
  }
  printf("Initialized dictionary.\n");
}
int hash            (int elem){
  return elem % 10;
}
bool isMember       (DICTIONARY main, int find){
  SET trav;
  int hashVal = hash(find);
  for (trav = main[hashVal] ; trav != NULL && trav->data != find ; trav = trav->link){};
  return trav != NULL;
}
void insert         (DICTIONARY main, int newData){
  int hashVal = hash(newData);
  SET* trav;
  for (trav = &main[hashVal] ; *trav != NULL ; trav = &(*trav)->link){};
  SET newNode = (SET)malloc(sizeof(struct node));
  if (newNode != NULL){
    newNode->data = newData;
    newNode->link = *trav;
    *trav = newNode;
  }
}
void display        (DICTIONARY main){
  SET trav;
  int x;
  for (x = 0 ; x < MAX ; x++){
    printf("[%d]", x);
    for (trav = main[x] ; trav != NULL ; trav = trav->link){
      printf("->[%d]", trav->data);
    }
    printf("%s\n", (trav != NULL) ? "->NULL" : "");
  }
}
void delete         (DICTIONARY main, int delete){
  SET* trav;
  SET temp;
  int hashVal = hash(delete);
  for (trav = &main[hashVal] ; *trav != NULL && (*trav)->data != delete ; trav = &(*trav)->link){};
  if (*trav != NULL){
    temp = *trav;
    *trav = temp->link;
    free(temp);
    printf("Deleted [%d]\n", delete);
  } else {
    printf("Not a valid number to delete.\n");
  }
}
```

  
### CLOSED HASING 1

```cpp
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5
#define EMPTY -1
#define DELETED -2

typedef int DICTIONARY[MAX];

typedef struct node {
  DICTIONARY A;
  int count;
} SET, *SETptr;

void initDictionary(DICTIONARY main);
int hash(DICTIONARY main, int elem);
bool isMember(DICTIONARY main, int find);
void insert(DICTIONARY main, int newData);
void display(DICTIONARY main);
void delete(DICTIONARY main, int delete);
DICTIONARY* insertSorted(DICTIONARY main);

int main(){
  DICTIONARY Webster;
  DICTIONARY* sortedWebster;
  initDictionary(Webster);
  
  insert(Webster, 3);
  insert(Webster, 3);     // test case: uniqueness
  insert(Webster, 33);    // test case: collision
  insert(Webster, 44);    // test case: displacement
  insert(Webster, 21);    // test case: N\A
  insert(Webster, 93);    // test case: collision
  insert(Webster, 50);    // test case: full dictionary

  delete(Webster, 93);    // test case: delete feature
  display(Webster);

  insert(Webster, 73);    // test case: insert at DELETED

  display(Webster);

  sortedWebster = insertSorted(Webster);
  display(*sortedWebster);
}

void initDictionary(DICTIONARY main){
  int x;
  for (x = 0 ; x < MAX ; x++){
    main[x] = EMPTY;
  }
  printf("Initialized dictionary.\n");
}
int hash(DICTIONARY main, int elem){
  return elem % 10;
}
bool isMember(DICTIONARY main, int find){
  int hashValue = hash(main, find);
  int count;
  int x;
  for (x = hashValue, count = 0 ; count != MAX && main[x] != EMPTY && main[x] != DELETED && main[x] != find ; x = (x + 1) % MAX, count++){};
  return main[x] == find;
}
void insert(DICTIONARY main, int newData){
  int hashValue = hash(main, newData);
  int count;
  if (!isMember(main, newData)){
    for (count = 0 ; count < MAX && main[hashValue] != EMPTY && main[hashValue] != DELETED ; hashValue = (hashValue + 1) % MAX, count++){};
    if (count < MAX){
      main[hashValue] = newData;
      printf("Inserted %d\n", newData);
    } else {
      printf("Your dictionary is full.\n");
    }
  } else {
    printf("Not unique.\n");
  }
}
void display(DICTIONARY main){
  int x;
  printf("HASH TABLE\n");
  printf("%8s|%s\n", "INDEX", "VALUE");
  printf("=============================\n");
  for (x = 0 ; x < MAX ; x++){
    printf("%8d|%8d\n", x, main[x]);
  }
}
void delete(DICTIONARY main, int delete){
  int x;
  for (x = hash(main, delete) ; main[x] != EMPTY && main[x] != DELETED && main[x] != delete; x = (x+1) % MAX){};
  if (isMember(main, delete)){
    main[x] = DELETED;
    printf("Deleted [%d]\n", delete);
  } else {
    printf("The element to be deleted [%d] does not exist.\n", delete);
  }
}
DICTIONARY* insertSorted(DICTIONARY main){
  DICTIONARY* new;
  new = (DICTIONARY*)malloc(sizeof(DICTIONARY));
  if (new != NULL){
    int x,y,z;
    
    for (x = 0 ; x < MAX ; x++){
      for (y = 0 ; y < MAX && main[x] > new[y] ; y++){};
      for (z =)
    }
  }
  return new;
}
```
  
  
### CLOSED HASHING STRUCT  
  
```cpp
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5
#define EMPTY -1
#define DELETED -2

typedef int DICTIONARY[MAX];

typedef struct node {
    DICTIONARY A;
    int count;
} SET, *SETptr;

void initDictionary(SET* main);
int hash(int elem);
bool isMember(SET main, int find);
void insert(SET* main, int newData);
void display(SET main);
void delete(SET* main, int delete);
SET populate(SET main);
void insertSorted(SET* main, int newData);

int main() {
    SET Webster;
    SET sortedWebster;
    initDictionary(&sortedWebster);
    initDictionary(&Webster);

    insert(&Webster, 3);
    insert(&Webster, 3);     // test case: uniqueness
    insert(&Webster, 33);    // test case: collision
    insert(&Webster, 44);    // test case: displacement
    insert(&Webster, 21);    // test case: N/A
    insert(&Webster, 93);    // test case: collision
    insert(&Webster, 50);    // test case: full dictionary

    delete(&Webster, 93);    // test case: delete feature
    display(Webster);

    insert(&Webster, 73);    // test case: insert at DELETED

    display(Webster);

    sortedWebster = populate(Webster);
    display(sortedWebster);

    return 0;
}

void initDictionary(SET* main) {
    int x;
    for (x = 0; x < MAX; x++) {
        main->A[x] = EMPTY;
    }
    main->count = 0;
    printf("Initialized dictionary.\n");
}

int hash(int elem) {
    return elem % 10;
}

bool isMember(SET main, int find) {
    int hashVal;
    int x;

    for (hashVal = hash(find), x = 0; x < MAX && (main.A[hashVal] != EMPTY && main.A[hashVal] != DELETED && main.A[hashVal] != find); hashVal = (hashVal + 1) % MAX, x++) {}

    return main.A[hashVal] == find;
}

void insert(SET* main, int newData) {
    int x, count, hashVal; 
    if (main->count < MAX) {
        if (!isMember(*main, newData)) {
            for (hashVal = hash(newData), count = 0; (main->A[hashVal] != EMPTY && main->A[hashVal] != DELETED) && count < MAX; hashVal = (hashVal + 1) % MAX, count++) {}
            if (count < MAX) {
                main->A[hashVal] = newData;
                printf("Inserted %d.\n", newData);
                main->count++;
            } else {
                printf("No space to insert %d.\n", newData);
            }
        } else {
            printf("%d is not unique.\n", newData);
        }
    } else {
        printf("No space to insert %d.\n", newData);
    }
}

void display(SET main) {
    int x;
    printf("HASH TABLE\n");
    printf("%8s|%s\n", "INDEX", "VALUE");
    printf("=============================\n");
    for (x = 0; x < MAX; x++) {
        printf("%8d|%8d\n", x, main.A[x]);
    }
}

void delete(SET* main, int delete) {
    int hashVal, x;
    if (main->count > 0) {
        for (hashVal = hash(delete), x = 0; x < main->count && main->A[hashVal] != EMPTY && main->A[hashVal] != DELETED && main->A[hashVal] != delete; hashVal = (hashVal + 1) % MAX, x++) {}
        if (main->A[hashVal] == delete) {
            main->A[hashVal] = DELETED;
            main->count--;
            printf("Deleted %d!\n", delete);
        } else {
            printf("Not a valid integer to delete.\n");
        }
    } else {
        printf("No elements in the dictionary.\n");
    }
}

void insertSorted(SET* main, int newData) {
    if (main->count < MAX) { // Check if there is space
        int x, y;
        // Find the position to insert
        for (x = 0; x < main->count && newData > main->A[x]; x++) {}
        // Shift elements to the right to make space
        for (y = main->count; y > x; y--) {
            main->A[y] = main->A[y - 1];
        }
        main->A[x] = newData; // Insert the new element
        main->count++; // Increment the count
        printf("Inserted %d into sorted dictionary.\n", newData);
    } else {
        printf("No space to insert %d into sorted dictionary.\n", newData);
    }
}

SET populate(SET main) {
    SET new;
    initDictionary(&new);
    
    // Using the insertSorted function
    for (int x = 0; x < main.count; x++) {
        if (main.A[x] != EMPTY && main.A[x] != DELETED) { // Only insert valid entries
            insertSorted(&new, main.A[x]);
        }
    }
    
    return new;
}

```
