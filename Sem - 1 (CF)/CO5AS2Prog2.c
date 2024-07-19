#include <stdio.h>
int main()
{
    int i,n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int  Array[n], oddArray[n], evenArray[n], oddCount = 0, evenCount = 0;
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &Array[i]);

        if (Array[i] % 2 == 0)
        {
            evenArray[evenCount] = Array[i];
            evenCount++;
        }
        else
        {
            oddArray[oddCount] = Array[i];
            oddCount++;
        }
    }
      printf("Odd Array: ");
      for (int i = 0; i < oddCount; i++)
    {
        printf("%d ", oddArray[i]);
    }
      printf("\neven Array: ");
      for (int i = 0; i < evenCount; i++)
    {
        printf("%d ", evenArray[i]);
    }
    return 0;
}
