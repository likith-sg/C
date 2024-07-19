#include <stdio.h>

int fibonacci(int n)
{
    if (n <= 1)
        return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

int fibonacciSum(int n)
{
    int sum = 0;
    for (int i = 0; i <= n; i++)
    {
        sum += fibonacci(i);
    }
    return sum;
}

int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Fibonacci Series up to %d:\n", n);
    for (int i = 0; i <= n; i++)
    {
        printf("%d ", fibonacci(i));
    }

    printf("\nSum of Fibonacci numbers up to %d: %d\n", n, fibonacciSum(n));

    return 0;
}
