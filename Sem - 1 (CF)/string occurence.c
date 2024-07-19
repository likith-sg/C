#include <stdio.h>

int main() {
    char inputString[100];
    char targetLetter;
    printf("Enter a string: ");
    fgets(inputString, sizeof(inputString), stdin);


    printf("Enter the letter to count: ");
    scanf(" %c", &targetLetter);

    int occurrences = 0;

    for (int i = 0; inputString[i] != '\0'; ++i) {
        if (inputString[i] == targetLetter) {
            ++occurrences;
        }
    }
    printf("The letter '%c' appears %d times in the string.\n", targetLetter, occurrences);
    return 0;
}
