
#include <stdio.h>
#include <string.h>

int isPalindrome(char str[], int low, int high) {
  if (low < high) {
    if (str[low] != str[high]) {
      return 0;
    }
    return isPalindrome(str, low + 1, high - 1);
  }
  return 1;
}

int main() {
  char str[100];

  printf("Enter a word to check for palindrome: ");
  scanf("%s", str);

  int len = strlen(str);

  if (isPalindrome(str, 0, len - 1)) {
    printf("%s is a palindrome.\n", str);
  } else {
    printf("%s is not a palindrome.\n", str);
  }

  return 0;
}
