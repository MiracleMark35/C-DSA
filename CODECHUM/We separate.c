#include <stdio.h>

// Function to print an array
void printArray(int arr[], int count) {
    printf("{");
    for (int i = 0; i < count; i++) {
        printf("%d", arr[i]);
        if (i < count - 1) {
            printf(", ");
        }
    }
    printf("}");
}

// Function to filter numbers based on parity of the first element
int filterParity(int original[], int n, int result[]) {
    int count = 0;
    int firstParity = original[0] % 2; // 0 if even, 1 if odd

    for (int i = 0; i < n; i++) {
        if (original[i] % 2 == firstParity) {
            result[count++] = original[i];
        }
    }
    return count; // return number of elements in result
}

int main() {
    int n;

    printf("Enter how many values: ");
    scanf("%d", &n);

    int original[n], result[n];

    for (int i = 0; i < n; i++) {
        printf("Enter the element %d: ", i + 1);
        scanf("%d", &original[i]);
    }

    int newCount = filterParity(original, n, result);

    printf("Original ");
    printArray(original, n);
    printf("\n");

    printf("New ");
    printArray(result, newCount);
    printf("\n");

    return 0;
}
/*
  Enter how many values: 5
Enter the element 1: 1
Enter the element 2: 2
Enter the element 3: 3
Enter the element 4: 4
Enter the element 5: 5
Original {1, 2, 3, 4, 5}
New {1, 3, 5}

*/
