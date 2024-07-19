#include<stdio.h>
int main()
{
    int n;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    int a[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    int sum=0;
    for(int i=0; i<n; i++)
    {
        sum += a[i];
    }
    printf("The sum of the elements is:%d",sum);
    return 0;
}
