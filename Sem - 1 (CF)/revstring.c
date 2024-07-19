#include <stdio.h>
#include <string.h>

// Function declaration
void reverseString(char *str);

int main() {
    char inputString[100];

    // Input a string
    printf("Enter a string: ");
    fgets(inputString, sizeof(inputString), stdin);

    // Function call
    reverseString(inputString);

    // Output the reversed string
    printf("Reversed string: %s\n", inputString);

    return 0;
}

// In-place string reversal function definition
void reverseString(char *str) {
    int length = strlen(str);
    for (int i = 0, j = length - 1; i < j; ++i, --j) {
        // Swap characters without using a temporary array
        str[i] ^= str[j];
        str[j] ^= str[i];
        str[i] ^= str[j];
    }
}
