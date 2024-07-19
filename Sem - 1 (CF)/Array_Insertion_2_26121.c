#include <stdio.h>
int main()
{
    int n, p;

    scanf("%d", &n);

    if (n >= 0 && n < 100)
    {
        int *arr = (int *)malloc(n * sizeof(int));

        scanf("%d", &p);

        for (int i = 0; i < p; i++)
        {
            scanf("%d", &arr[i]);
        }

        for (int i = p; i < n; i++)
        {
            arr[i] = 0;
        }

        int num, d, temp, s = 0;

        scanf("%d", &num);

        temp = num;

        while (temp > 0)
        {
            d = temp % 10;
            s = s + d;
            temp /= 10;
        }

        if (s > n)
        {
            for (int i = 0; i < n; i++)
            {
                printf("%d\n", arr[i]);
            }
        }
        else
        {
            for (int i = n - 1; i >= s; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[s - 1] = num;

            for (int i = 0; i < n; i++)
            {
                printf("%d\t", arr[i]);
            }
        }

        free(arr);
    }

    return 0;
}
