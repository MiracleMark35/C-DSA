
# Char Version

```c
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>



typedef struct node{
    char elem;
    struct node* next;
} *charList;




charList insertLast(charList* L , char data){
    charList newNode = (charList)malloc(sizeof(struct node));
    if(!newNode){
        exit; // i know this is a joke
    }
    newNode->elem = data;
    newNode->next = NULL;
    
    charList* trav;
    
    for(trav = L; *trav != NULL; trav = &(*trav)->next);
    
    *trav = newNode;
    
    return *L;
}

bool findElem(charList L, char dataToFind){
    
    charList trav;
    
    if(L == NULL){
      printf("The List is EMpty\n");
      return false;
    }
    
    for(trav = L; trav != NULL && trav->elem != dataToFind; trav = trav->next);
    
    return trav != NULL ? true : false;
}

void display(charList L){
    
    
    charList trav;
    
    if(L == NULL){
        printf("List is Empty\n");
        return;
    }
    for(trav = L; trav != NULL; trav = trav->next){
        printf("%c -> ", trav->elem);
    }
    printf("NULL\n");
}


void init(charList* L){
    *L = NULL;
}
int main(){
    
    charList L;
    init(&L);
    
    int count;
    char data, findThatElem;
    
    printf("How many Data YOu WIll INSERT: ");
    scanf("%d",&count);
    
    for(int i = 0; i < count; i++){
        printf("Enter a Character [%d]: ", i + 1);
        scanf(" %c",&data);
        L = insertLast(&L, data);
    }
    
    display(L);
    
    
    printf("Enter a Character to Find: ");
    scanf(" %c", &findThatElem);
    
    int result = findElem(L, findThatElem );
    
    result ? printf("TRUE") : printf("False");

    return 0;
}
```

# String Version
```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 50   // make bigger for longer strings

typedef struct node {
    char elem[MAX];
    struct node* next;
} *charList;

charList insertLast(charList* L , char data[]) {
    charList newNode = (charList)malloc(sizeof(struct node));
    strcpy(newNode->elem, data);
    newNode->next = NULL;

    charList* trav;
    for(trav = L; *trav != NULL; trav = &(*trav)->next);
    *trav = newNode;

    return *L;
}

bool findElem(charList L, char dataToFind[]) {
    charList trav;

    if(L == NULL) {
        printf("The List is Empty\n");
        return false;
    }

    for(trav = L; trav != NULL && strcmp(trav->elem, dataToFind) != 0; trav = trav->next);

    return trav != NULL ? true : false;
}

void display(charList L) {
    charList trav;

    if(L == NULL) {
        printf("List is Empty\n");
        return;
    }

    for(trav = L; trav != NULL; trav = trav->next) {
        printf("%s -> ", trav->elem);
    }
    printf("NULL\n");
}

void init(charList* L) {
    *L = NULL;
}

int main() {
    charList L;
    init(&L);

    int count;
    char data[MAX], findThatElem[MAX];

    printf("How many Data You Will INSERT: ");
    scanf("%d", &count);
    getchar(); // consume leftover newline from scanf

    for(int i = 0; i < count; i++) {
        printf("Enter a String [%d]: ", i + 1);
        scanf(" %[^\n]", data); // read full line until newline
        L = insertLast(&L, data);
    }

    display(L);

    printf("Enter a String to Find: ");
    scanf(" %[^\n]", findThatElem);

    bool result = findElem(L, findThatElem);
    printf("%s\n", result ? "TRUE" : "FALSE");

    return 0;
}
```
