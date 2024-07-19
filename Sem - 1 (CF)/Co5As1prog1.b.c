#include<stdio.h>
int main()
{
    int a[10];
    printf("Enter 10 elements:");
    for(int i=0; i<10; i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0; i<10; i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
