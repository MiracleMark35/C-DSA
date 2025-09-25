# Open Hasing

```c
// Hash Tables (Open Hashing)

typedef struct node {
    int data;
    struct node* next;
} *SET;

typedef SET Dictionary[MAX];

// Hash Function Dictionary (Can Vary)
int hashBrown(int key) {
    int sum = 0;
    while (key != 0) {
        sum += (key % 10);
        key /= 10;
    }
    return sum % MAX;
}

// Initialize Dictionary
void initDictionary(Dictionary D) {
    for (int i = 0; i < MAX; i++) {
        D[i] = NULL;
    }
}

// Display Dictionary
void displayDict(Dictionary D) {
    printf("\n\tSET\tELEMENTS");
    for (int i = 0; i < MAX; i++) {
        printf("\n\t[%d] : \t", i);
        if (D[i] != NULL) {
            for (SET temp = D[i]; temp; temp = temp->next) {
                printf("%d ", temp->data);
            }
        } else {
            printf("Empty");
        }
    }
}

// isMember Dictionary
bool isMember(Dictionary D, int elem) {
    int key = hashBrown(elem);
    for (SET temp = D[key]; temp && temp->data != elem; temp = temp->next) {}
    return temp != NULL;
}

// Insert Unique Dictionary
void insertUnique(Dictionary D, int num) {
    int key = hashBrown(elem);
    SET* trav;
    for (trav = &D[key]; *trav && (*trav)->data < num; trav = &(*trav)->next) {}
    if (*trav == NULL || (*trav)->data != num) {
        SET temp = (SET) malloc(sizeof(struct node));
        if (temp != NULL) {
            temp->data = num;
            temp->next = *trav;
            *trav = temp;
        }
    } else {
        printf("\t%d is already in the set.\n", num);
    }
}

// Delete Member Dictionary
void deleteMember(Dictionary D, int elem) {
    int key = hashBrown(elem);
    SET *trav, temp;
    for (trav = &D[key]; *trav && (*trav)->data != num; trav = &(*trav)->next) {}
    if (trav != NULL) {
        temp = *trav;
        *trav = temp->next;
        free(temp);
    } else {
        printf("\t%d does not exist in the set.\n", num);
    }
}

```
