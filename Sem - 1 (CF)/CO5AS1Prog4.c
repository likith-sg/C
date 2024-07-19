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
     float average;
     average = sum/n;
    printf("The sum of the elements is:%d\n",sum);
    printf("The average of the elements is:%f\n",average);
    return 0;
}
