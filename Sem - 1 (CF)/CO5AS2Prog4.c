#include <stdio.h>
int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int a[size];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }
    int n = sizeof(a) / sizeof(a[0]);

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        if (a[i] == -1)
        {
            continue;
        }

        for (int j = i + 1; j < n; j++)
        {
            if (a[i] == a[j])
            {
                count++;
                a[j] = -1;
            }
        }

        if (count > 0)
        {
            printf("Element %d is a duplicate and occurs %d times.\n", a[i], count + 1);
        }
    }

    return 0;
}
