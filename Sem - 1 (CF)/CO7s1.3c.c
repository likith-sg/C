
#include <stdio.h>
#include <string.h>

int isAnagram(char str1[], char str2[]) {
  int count1[256] = {0};
  int count2[256] = {0};

  int len1 = strlen(str1);
  int len2 = strlen(str2);

  if (len1 != len2) {
    return 0;
  }

  for (int i = 0; i < len1; i++) {
    count1[str1[i]]++;
    count2[str2[i]]++;
  }

  for (int i = 0; i < 256; i++) {
    if (count1[i] != count2[i]) {
      return 0;
    }
  }

  return 1;
}

int main() {
  char str1[] = "hello";
  char str2[] = "olleh";

  if (isAnagram(str1, str2)) {
    printf("The strings %s and %s are anagrams.\n", str1, str2);
  } else {
    printf("The strings %s and %s are not anagrams.\n", str1, str2);
  }

  return 0;
}
