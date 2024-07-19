#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    int n;
    printf("Enter the integer:");
    scanf("%d", &n);
    sprintf(str,"%d",n);
    printf("The string from integer is %s",str);
    return 0;
}
