#include <stdio.h>
int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int a1[n], a2[n];
    printf("Enter %d elements for a1:\n", n);

    for (int i = 0; i < n; i++)
    {
     scanf("%d", &a1[i]);
    }
    for (int i = 0; i < n; i++)
    {
     a2[i] = a1[i];
    }
    printf("Elements in a2 copied from a1:\n ");
    for (int i = 0; i < n; i++)
    {
     printf("%d ", a2[i]);
    }
    return 0;
}
