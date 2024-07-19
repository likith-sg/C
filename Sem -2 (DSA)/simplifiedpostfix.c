#include <stdio.h>

int size = 10;
int stack[10];
int top = -1;

void isFull()
{
    if (top == size - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
}

void isEmpty()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return;
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

void reverseStack()
{
    int auxStack[size];
    int auxTop = -1;

    // Empty the original stack and push elements into the auxiliary stack
    while (top != -1)
    {
        auxStack[++auxTop] = pop();
    }

    // Refill the original stack with elements from the auxiliary stack
    for (int i = 0; i <= auxTop; i++)
    {
        push(auxStack[i]);
    }
}

int main()
{
    push(7);
    printStack();

    push(6);
    printStack();

    push(9);
    printStack();

    reverseStack();
    printf("Reversed ");
    printStack();

    peek();
    printStack();

    return 0;
}
