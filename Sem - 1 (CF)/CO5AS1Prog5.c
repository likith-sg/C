#include <stdio.h>

int main()
{
    int size, i, smallest, largest;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int a[size];
    printf("Enter the elements of the array:");
    for(i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }

    smallest = largest = a[0];
    for(i = 1; i < size; i++)
    {
        if(a[i] < smallest)
        {
            smallest = a[i];
        }
        if(a[i] > largest)
        {
            largest = a[i];
        }
    }

    printf("smallest element in the array: %d\n", smallest);
    printf("largest element in the array: %d\n", largest);
    return 0;
}
