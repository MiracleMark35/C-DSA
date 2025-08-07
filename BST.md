## BST without TRAV   

  ```cpp
#include <stdio.h>
#include <stdlib.h>

// Definition of the TreeNode structure
typedef struct TreeNode {
  int data;
  struct TreeNode *left;
  struct TreeNode *right;
} *TreeNode;

// Function to insert data into the tree
TreeNode insert(TreeNode root, int data) {
  if (root == NULL) {
      root = (TreeNode)malloc(sizeof(struct TreeNode));
      if (root == NULL) {
          fprintf(stderr, "Memory allocation failed\n");
          exit(EXIT_FAILURE);
      }
      root->data = data;
      root->left = NULL;
      root->right = NULL;
      return root;
  }
  
  if (data < root->data) {
      root->left = insert(root->left, data);
  } else if (data > root->data) {
      root->right = insert(root->right, data);
  }
  
  return root;
}

// Function for inorder traversal
void inorderTraversal(TreeNode root) {
  if (root == NULL) { return; }
  inorderTraversal(root->left);
  printf("%d ", root->data);
  inorderTraversal(root->right);
}

// Function for preorder traversal
void preorderTraversal(TreeNode root) {
  if (root == NULL) { return; }
  printf("%d ", root->data);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

// Function for postorder traversal
void postorderTraversal(TreeNode root) {
  if (root == NULL) { return; }
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  printf("%d ", root->data);
}

// Function to delete a node from the tree
TreeNode deleteNode(TreeNode root, int data) {
  if (root == NULL) {
      return root;
  }

  if (data < root->data) {
      root->left = deleteNode(root->left, data);
  } else if (data > root->data) {
      root->right = deleteNode(root->right, data);
  } else {
      if (root->left == NULL) {
          TreeNode temp = root->right;
          free(root);
          return temp;
      } else if (root->right == NULL) {
          TreeNode temp = root->left;
          free(root);
          return temp;
      }

      TreeNode temp = root->right;
      while (temp && temp->left != NULL) {
          temp = temp->left;
      }
      root->data = temp->data;
      root->right = deleteNode(root->right, temp->data);
  }

  return root;
}

// Function to delete the maximum node and return its value
int deleteMax(TreeNode* root) {
  if (*root == NULL) {
      return -1;
  }

  TreeNode parent = NULL;
  TreeNode current = *root;

  while (current->right != NULL) {
      parent = current;
      current = current->right;
  }

  int maxValue = current->data;

  if (current->left == NULL) {
      if (parent == NULL) {
          *root = NULL;
      } else {
          parent->right = NULL;
      }
  } else {
      if (parent == NULL) {
          *root = current->left;
      } else {
          parent->right = current->left;
      }
  }

  free(current);
  return maxValue;
}

// Function to delete the minimum node and return its value
int deleteMin(TreeNode* root) {
  if (*root == NULL) {
      return -1;
  }

  TreeNode parent = NULL;
  TreeNode current = *root;

  while (current->left != NULL) {
      parent = current;
      current = current->left;
  }

  int minValue = current->data;

  if (current->right == NULL) {
      if (parent == NULL) {
          *root = NULL;
      } else {
          parent->left = NULL;
      }
  } else {
      if (parent == NULL) {
          *root = current->right;
      } else {
          parent->left = current->right;
      }
  }

  free(current);
  return minValue;
}

int main() {
  TreeNode root = NULL;
  root = insert(root, 50);
  insert(root, 30);
  insert(root, 20);
  insert(root, 40);
  insert(root, 70);
  insert(root, 60);
  insert(root, 80);

  printf("Inorder traversal: ");
  inorderTraversal(root);
  printf("\n");

  printf("Preorder traversal: ");
  preorderTraversal(root);
  printf("\n");

  printf("Postorder traversal: ");
  postorderTraversal(root);
  printf("\n");

  printf("Deleting 20\n");
  root = deleteNode(root, 20);
  printf("Inorder traversal after deleting 20: ");
  inorderTraversal(root);
  printf("\n");

  int maxValue = deleteMax(&root);
  printf("Deleted max value: %d\n", maxValue);
  printf("Inorder traversal after deleting max value: ");
  inorderTraversal(root);
  printf("\n");

  int minValue = deleteMin(&root);
  printf("Deleted min value: %d\n", minValue);
  printf("Inorder traversal after deleting min value: ");
  inorderTraversal(root);
  printf("\n");

  return 0;
}

```

  
## BST with TRAV V1
  ```cpp
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Binary Search Tree Node definition
typedef struct node {
    int elem;              // Element value
    struct node* LC;      // Pointer to left child
    struct node* RC;      // Pointer to right child
} *BST;

// Function prototypes
void Init(BST *main);
void Insert(int newData, BST *main);
bool Member(int findMe, BST main);
void Preorder(BST main);
void Inorder(BST main);
void Postorder(BST main);
void DeleteMin(BST *main);
void DeleteMax(BST *main);
void Delete(BST *main, int node);

int main() {
    BST Mango;
    Init(&Mango);  // Initialize the BST

    // Insert values into the BST
    Insert(10, &Mango);
    Insert(5, &Mango);
    Insert(14, &Mango);
    Insert(7, &Mango);
    Insert(12, &Mango);
    Insert(18, &Mango);
    Insert(11, &Mango);
    Insert(15, &Mango);

    // Display the BST in different orders
    printf("Preorder:\n");
    Preorder(Mango);
    printf("\nInorder:\n");
    Inorder(Mango);
    printf("\nPostorder:\n");
    Postorder(Mango);

    // Check for membership of specific values
    printf("\nMember %d = %d\n", 5, Member(5, Mango));
    printf("Member %d = %d\n", 15, Member(15, Mango));
    printf("Member %d = %d\n", 20, Member(20, Mango));
    printf("Member %d = %d\n", 10, Member(10, Mango));

    // Delete the minimum and maximum values
    DeleteMin(&Mango);
    DeleteMax(&Mango);

    // Delete a specific node
    Delete(&Mango, 14);

    // Display the BST after deletions
    printf("Inorder after deletions:\n");
    Inorder(Mango);
    printf("\n");

    return 0;
}

// Initialize the BST
void Init(BST *main) {
    *main = NULL;  // Set the main BST pointer to NULL
    printf("Initialized BST.\n");
}

// Insert a new value into the BST
void Insert(int newData, BST *main) {
    BST *trav;  // Pointer to traverse the tree
    BST newNode = (BST)malloc(sizeof(struct node)); // Create new node

    if (newNode != NULL) {
        newNode->LC = newNode->RC = NULL; // Initialize left and right children
        newNode->elem = newData; // Set the element

        // Find the correct location to insert the new node
        for (trav = main; *trav != NULL; trav = (newData < (*trav)->elem) ? &(*trav)->LC : &(*trav)->RC) {}

        *trav = newNode; // Insert the new node at the found location
        printf("Inserted %d successfully.\n", newData);
    }
}

// Preorder traversal of the BST
void Preorder(BST main) {
    if (main != NULL) {
        printf("%d ", main->elem); // Visit the root
        Preorder(main->LC); // Traverse left
        Preorder(main->RC); // Traverse right
    }
}

// Inorder traversal of the BST
void Inorder(BST main) {
    if (main != NULL) {
        Inorder(main->LC); // Traverse left
        printf("%d ", main->elem); // Visit the root
        Inorder(main->RC); // Traverse right
    }
}

// Postorder traversal of the BST
void Postorder(BST main) {
    if (main != NULL) {
        Postorder(main->LC); // Traverse left
        Postorder(main->RC); // Traverse right
        printf("%d ", main->elem); // Visit the root
    }
}

// Check if a value exists in the BST
bool Member(int findMe, BST main) {
    while (main != NULL && main->elem != findMe) {
        main = (findMe < main->elem) ? main->LC : main->RC; // Traverse the tree
    }
    return (main != NULL); // Return true if found, false otherwise
}

// Delete the minimum value from the BST
void DeleteMin(BST *main) {
    BST *trav = main;
    while ((*trav)->LC != NULL) { // Traverse to the leftmost node
        trav = &(*trav)->LC;
    }
    // Get the node to delete and adjust pointers
    BST temp = *trav;
    *trav = (*trav)->RC; // Remove the node
    free(temp); // Free memory
    printf("Deleted min of BST.\n");
}

// Delete the maximum value from the BST
void DeleteMax(BST *main) {
    BST *trav = main;
    while ((*trav)->RC != NULL) { // Traverse to the rightmost node
        trav = &(*trav)->RC;
    }
    // Get the node to delete and adjust pointers
    BST temp = *trav;
    *trav = (*trav)->LC; // Remove the node
    free(temp); // Free memory
    printf("Deleted max of BST.\n");
}

// Delete a specific node from the BST
void Delete(BST *main, int node) {
    if (*main == NULL) {
        printf("Node %d not found for deletion.\n", node);
        return; // Node not found
    }
    if (node < (*main)->elem) { // Node to delete is in the left subtree
        Delete(&(*main)->LC, node);
    } else if (node > (*main)->elem) { // Node to delete is in the right subtree
        Delete(&(*main)->RC, node);
    } else { // Node found
        BST temp = *main;

        // Case 1: No children
        if (temp->LC == NULL && temp->RC == NULL) {
            *main = NULL; // Remove the node
        }
        // Case 2: One child
        else if (temp->LC == NULL) {
            *main = temp->RC; // Replace with right child
        } else if (temp->RC == NULL) {
            *main = temp->LC; // Replace with left child
        }
        // Case 3: Two children
        else {
            // Find the in-order successor (smallest in the right subtree)
            BST successor = temp->RC;
            while (successor->LC != NULL) {
                successor = successor->LC;
            }
            temp->elem = successor->elem; // Replace value with successor's value
            Delete(&temp->RC, successor->elem); // Delete the successor
        }
        free(temp); // Free the memory of the deleted node
        printf("Deleted node %d from BST.\n", node);
    }
}
```

  
## BST with TRAV V2    
  
```cpp
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Binary Search Tree Node definition
typedef struct node {
    int elem;              // Element value
    struct node* LC;       // Pointer to left child
    struct node* RC;       // Pointer to right child
} *BST;

// Function prototypes
void Init(BST *main);
void Insert(int newData, BST *main);
bool Member(int findMe, BST main);
void Preorder(BST main);
void Inorder(BST main);
void Postorder(BST main);
void DeleteMin(BST *main);
void DeleteMax(BST *main);
void Delete(BST *main, int node);

int main() {
    BST Mango;
    Init(&Mango);  // Initialize the BST

    // Insert values into the BST
    Insert(10, &Mango);
    Insert(5, &Mango);
    Insert(14, &Mango);
    Insert(7, &Mango);
    Insert(12, &Mango);
    Insert(18, &Mango);
    Insert(11, &Mango);
    Insert(15, &Mango);

    // Display the BST in different orders
    printf("Preorder:\n");
    Preorder(Mango);
    printf("\nInorder:\n");
    Inorder(Mango);
    printf("\nPostorder:\n");
    Postorder(Mango);

    // Check for membership of specific values
    printf("\nMember %d = %d\n", 5, Member(5, Mango));
    printf("Member %d = %d\n", 15, Member(15, Mango));
    printf("Member %d = %d\n", 20, Member(20, Mango));
    printf("Member %d = %d\n", 10, Member(10, Mango));

    // Delete the minimum and maximum values
    DeleteMin(&Mango);
    DeleteMax(&Mango);

    // Delete a specific node
    Delete(&Mango, 14);

    // Display the BST after deletions
    printf("Inorder after deletions:\n");
    Inorder(Mango);
    printf("\n");

    return 0;
}

// Initialize the BST
void Init(BST *main) {
    *main = NULL;  // Set the main BST pointer to NULL
    printf("Initialized BST.\n");
}

// Insert a new value into the BST
void Insert(int newData, BST *main) {
    BST* trav;
    BST newNode = (BST)malloc(sizeof(struct node));
    if(newNode != NULL){
        newNode->elem = newData;
        newNode->LC = NULL;
        newNode->RC = NULL;
        
        for(trav = main; *trav != NULL; trav = (newData < (*trav)->elem ?  &(*trav)->LC: &(*trav)->RC )){}
        
        *trav = newNode;
    
        printf("Inserted %d successfully.\n", newData);
    } 
}

// Preorder traversal of the BST
void Preorder(BST main) {
    if (main != NULL) {
        printf("%d ", main->elem);
        Preorder(main->LC);
        Preorder(main->RC);
    }
}

// Inorder traversal of the BST
void Inorder(BST main) {
    if (main != NULL) {
        Inorder(main->LC);
        printf("%d ", main->elem);
        Inorder(main->RC);
    }
}

// Postorder traversal of the BST
void Postorder(BST main) {
    if (main != NULL) {
        Postorder(main->LC);
        Postorder(main->RC);
        printf("%d ", main->elem);
    }
}

// Check if a value exists in the BST
bool Member(int findMe, BST main) {
    while (main != NULL && main->elem != findMe) {
        main = (findMe < main->elem) ? main->LC : main->RC;
    }
    return (main != NULL);
}

// Delete the minimum value from the BST
void DeleteMin(BST *main) {
    if (*main == NULL) {
        printf("BST is empty, cannot delete min.\n");
        return;
    }
    
    BST *trav = main;
    BST temp;
    while ((*trav)->LC != NULL) {
        trav = &(*trav)->LC;
    }
    
    temp = *trav;
    *trav = (*trav)->RC;
    
    free(temp);
    printf("Deleted min of BST.\n");
}

// Delete the maximum value from the BST
void DeleteMax(BST *main) {
    if (*main == NULL) {
        printf("BST is empty, cannot delete max.\n");
        return;
    }
    
    BST *trav = main;
    BST temp;
    
    while ((*trav)->RC != NULL) {
        trav = &(*trav)->RC;
    }
    
    temp = *trav;
    *trav = (*trav)->LC;
    
    free(temp);
    printf("Deleted max of BST.\n");
}

// Delete a specific node from the BST
void Delete(BST *main, int node) {
    if (*main == NULL) {
        printf("Node %d not found for deletion.\n", node);
        return;
    }

    BST *trav = main;
    BST temp;

    // Search for the node to delete
    while (*trav != NULL && (*trav)->elem != node) {
        trav = (node < (*trav)->elem) ? &(*trav)->LC : &(*trav)->RC;
    }

    if (*trav == NULL) {
        printf("Node %d not found for deletion.\n", node);
        return;
    }

    // Case 1: Node with only one child or no child
    if ((*trav)->LC == NULL) {
        temp = *trav;
        *trav = (*trav)->RC;
        free(temp);
    } else if ((*trav)->RC == NULL) {
        temp = *trav;
        *trav = (*trav)->LC;
        free(temp);
    } 
    // Case 2: Node with two children
    else {
        BST *succ = &(*trav)->RC;
        while ((*succ)->LC != NULL) {
            succ = &(*succ)->LC;
        }
        (*trav)->elem = (*succ)->elem;
        temp = *succ;
        *succ = (*succ)->RC;
        free(temp);
    }

    printf("Deleted node %d from BST.\n", node);
}
```

  
