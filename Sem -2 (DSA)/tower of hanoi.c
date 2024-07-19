#include<stdio.h>
#include<stdlib.h>
int count =0;
void tower(int n, char beg, char aux, char end)
{
if(n <= 0)
{
printf("illegal entry");
}
else if ( n == 1)
{
printf("disc moved from %c rod to %c rod",beg,end);
count++;
}
else
{
tower(n-1,beg,end,aux);
tower(1,beg,aux,end);
tower(n-1,aux,beg,end);
}
}

int main()
{
int n;
char a,b,c;
printf("enter the number of discs:");
scanf("%d",&n);
printf("tower of hanoi of %d discs",n);
tower(n,'a','b','c');
printf("no of steps is %d:",count);
return 0;
}
