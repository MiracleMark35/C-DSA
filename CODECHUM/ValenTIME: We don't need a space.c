#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

char *removeSpace(char string[]) {

     int len = strlen(string);
     char *result = malloc(len + 1); // allocate memory for new string

     int j = 0;

    for(int i = 0 ; i < len; i++){
        if(string[i] != ' '){
            result[j] = string[i];
            j++;
        }
    }
  //  result[j] = '\0'; pwede or not
    return result;
}

int main() {
    char string[MAX];
    char *newString;
    printf("Enter a string: ");
    scanf(" %[^\n]", string);
    newString = removeSpace(string);
    printf("Modified string: %s", newString);
    free(newString);
    return 0;
}
/*
Expected Output:
Enter a string: HELLO   WORLD
Modified string: HELLOWORLD

Actual Output:
Enter a string: HELLO   WORLD
Modified string: HELLOWORLD
*/
