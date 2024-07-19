#include <stdio.h>
int main()
{
    int n,p,element;
    scanf("%d",&n);
    if(n==0)
    {
        printf("-1");
        return 0;
    }
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&p);
    if(p==0||p>n)
    {
        printf("-1");
        return 0;
    }
    scanf("%d",&element);
    n++;
    for(int i=n-1;i>=p;i--)
    {
        a[i]=a[i-1];
    }
    a[p-1]=element;
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }

    return 0;
}
