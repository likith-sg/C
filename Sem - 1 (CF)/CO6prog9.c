#include <stdio.h>
#define SIZE 26
int main()
{
    char str[100];
    int freq[SIZE] = {0};
    int i = 0;
    printf("Enter a string: ");
    gets(str);
    while(str[i] != '\0')
    {
        if(str[i] >= 'a' && str[i] <= 'z')
        {
            freq[str[i] - 'a']++;
        }
        else if(str[i] >= 'A' && str[i] <= 'Z')
        {
            freq[str[i] - 'A']++;
        }
        i++;
    }
    printf("\nFrequency of characters in the string: \n");
    for(i = 0; i < SIZE; i++)
    {
        if(freq[i] != 0)
        {
            printf("%c occurs %d times\n", i + 'a', freq[i]);
        }
    }
    return 0;
}
