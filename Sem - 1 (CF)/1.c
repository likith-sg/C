#include <stdio.h>
int main()
{
    int i,grades[5],sum=0;
    float average;
    for (i=0; i<5; i++)
    {
        printf("Enter grade %d:",i+1);
        scanf("%d",&grades[i]);
        sum += grades[i];
    }
    average = (float)sum / 5;
    printf("Grades: ");
    for (i = 0; i < 5; i++)
    {
        printf("%d ", grades[i]);
    }
    printf("\nSum: %d\n", sum);
    printf("Average: %f\n", average);

    return 0;
}
