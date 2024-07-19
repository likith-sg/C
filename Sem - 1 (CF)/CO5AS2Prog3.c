#include <stdio.h>
int main()
{
  int size;
  printf("Enter the size of the array: ");
  scanf("%d", &size);
  int a[size];
  printf("Enter the elements of the array: ");
  for(int i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }
  int n = sizeof(a) / sizeof(a[0]);
  int duplicateElement = -1, count = 0;

  for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
        {
            if (a[i] == a[j])
            {
                duplicateElement = a[i];
                count++;
            }
        }
    }
     if (duplicateElement != -1)
    {
        printf("The duplicate element is %d\n", duplicateElement);
        printf("Total occurrences of the duplicate element: %d\n", count + 1);
    }
    return 0;
}
