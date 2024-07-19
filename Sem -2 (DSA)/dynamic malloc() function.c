#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;
    int n;

    printf("Enter the number of variables : ");
    scanf("%d", &n);

    ptr = (int *)malloc(n * sizeof(int));

    if (ptr == NULL)
    {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    printf("Memory allocation successful.\n");

    for (int i = 0; i < n; i++)
    {
        printf("Address of variable %d: %p\n", i + 1, (void *)(ptr + i));
    }

    free(ptr);

    return 0;
}
