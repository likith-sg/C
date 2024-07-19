#include <stdio.h>

int main()
{
    int size, i, min, max;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if(size == 0)
    {
        printf("-1\n");
        return 0;
    }
    else if(size < 10 || size > 30)
    {
        printf("Size of the array should be between 10 - 30\n");
        return 0;
    }

    int a[size];
    printf("Enter the elements of the array separated by space: ");
    for(i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }

    min = max = a[0];
    for(i = 1; i < size; i++)
    {
        if(a[i] < min)
        {
            min = a[i];
        }
        if(a[i] > max)
        {
            max = a[i];
        }
    }

    printf("Minimum element in the array: %d\n", min);
    printf("\n");
    printf("Maximum element in the array: %d\n", max);

    return 0;
}
