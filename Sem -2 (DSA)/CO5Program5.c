#include <stdio.h>

int size = 10;
int stack[10];
int top = -1;

void isFull()
{
    if (top == size - 1)
    {
        printf("Stack Overflow\n");
    }
}

void isEmpty()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
    }
}

int peek()
{
    return stack[top];
}

void push(int value)
{
    isFull();
    top++;
    stack[top] = value;
}

int pop()
{
    isEmpty();
    int value = stack[top];
    top--;
    return value;
}

void printStack()
{
    isEmpty();
    printf("Stack: ");
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main()
{
    push(7);
    printStack();

    pop();
    printStack();

    push(6);
    printStack();

    push(9);
    printStack();

    pop();
    printStack();

    return 0;
}
