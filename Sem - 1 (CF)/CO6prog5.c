#include<stdio.h>
#include<string.h>
int main()
{
char str1[100],str2[100];
printf("Enter the first string:");
gets(str1);
printf("Enter the second string:");
gets(str2);
int result=strcmp(str1,str2);
if(result == 0)
{
printf("String is same\n");
}
else if(result > 0)
{
printf("string 1 is lexicographically greater\n");
}
else
{
printf("string 2 is lexicographically greater\n");
}
return 0;
}
