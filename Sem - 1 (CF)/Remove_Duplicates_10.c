#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    for (int i=0; i<n; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            if(a[i]==a[j])
            {
                n--;

                for(int l=i; l<n; l++)
                {

                    a[l]=a[l+2];
                }
                i-=2;

            }
        }
    }
    for (int i=0; i < n; i++)
    {
        printf("%d",a[i]);
    }

    return 0;
}
