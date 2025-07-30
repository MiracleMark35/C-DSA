# Simple Stack


# Stack Linked List *Stack

```c
// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

// Define node structure linked list version sa stack
typedef struct Node{
    int data;
    struct Node* next;
} *Stack;


int IsEmpty (Stack top){ // function to check if the stack is empty
    return top == NULL;  // Return true if the stack top is NULL
}

// initialize stack
void Init(Stack* top){
    *top = NULL;
}

// Push an Element onto the stack
void Push(Stack* top, int data){
    Stack newNode = (Stack)malloc(sizeof(struct Node));
    if(!newNode){ // (newnode == NULL) // Safety Feature 
              printf("Memory allocation failed\n");
              return;
    }
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

void Pop(Stack* top) {
    if (!IsEmpty(*top)) {  // Pass the stack top directly to IsEmpty
        Stack temp = *top;
        *top = (*top)->next;
        free(temp);
    } else {
        printf("Stack underflow\n");
    }
}

int Peek(Stack* top) {
    if (IsEmpty(*top)) {  // Pass the stack top directly to IsEmpty
        printf("Stack is empty\n");
        return -1;  // Return a sentinel value to indicate an error
    }
    return (*top)->data;
}



void display(Stack* top){
    if (IsEmpty(*top)) {  // Pass the stack top directly to IsEmpty
        printf("Stack is empty\n");
    }
    Stack temp = *top;
    while (temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
  
Stack top;
Init(&top);
display(&top);

    int poppedData;

 // Push 6 elements onto the stack
for (int i = 0; i < 6; i++) {
    printf("Enter the data to push: ");
    int data;
    scanf("%d", &data);
    Push(&top, data);
    display(&top); 
}


printf("Remove/ Pop an element from the stack\n");
// Pop an element from the stack
Pop(&top);
printf("Main Stack\n");
display(&top);  // Display the stack after popping
    
// Peek at the top element
poppedData = Peek(&top);  // Pass stack top directly
if (poppedData != -1) {
        printf("Top element is %d\n", poppedData);
}

    

    return 0;
}
```
# Stack Midterm Quiz

![Premid](Images/Premid.png)
