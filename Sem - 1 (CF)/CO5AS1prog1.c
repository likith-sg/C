#include<stdio.h>
int main()
{
int i,n;
printf("Enter the size of the array:");
scanf("%d",&n);

if(n<=0)
{
    printf("-1\n");
}
else if(n>0 && n<100)
{
     int a[n];
     for(i = 0; i < n; i++)
     {
         scanf("%d",&a[i]);
     }
     for(i = 0; i < n; i++)
     {
         printf("%d ",a[i]);
     }
}
return 0;
}
