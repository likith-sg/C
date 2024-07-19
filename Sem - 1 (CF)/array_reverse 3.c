#include <stdio.h>
int main()
{
    int n, i;
    printf("Enter the size of the array:");
    scanf("%d", &n);

    int a[n];
    printf("The array is:");
    for(i = 0; i <n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("The array in reverse order is:");
    for(i = n-1; i >=0; i--)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
