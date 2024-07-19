#include <stdio.h>
int main()
{
    int n,element,low,mid,high;
    scanf("%d",&n);
    int a[n];
    for (int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&element);
    if(n<=1000000)
    {
        low=0;
        high=n-1;

        while(low<=high)

        {
            mid=(low+high)/2;
            if(a[mid]<element)
            {
                low=mid+1;
            }
            else if(a[mid]==element)
            {
                printf("%d",mid);
                break;
            }
            else
            {
                high=mid-1;
            }
        }
        if(low>high)
        {
            return 0;
        }
    }

    return 0;
}
