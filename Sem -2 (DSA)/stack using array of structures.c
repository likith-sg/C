#include<stdio.h>
#include<stdlib.h>

int size = 10;
int top = -1;

struct shelf
{
    char book[100];
};
struct shelf stack[100];

void isFull()
{
    if (top == size - 1)
    {
        printf("Stack Overflow\n");
        exit(1);
    }
}

void isEmpty()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
}

void push(struct shelf book)
{
    isFull();
    top++;
    stack[top] = book;
}

struct shelf pop()
{
    isEmpty();
    struct shelf book = stack[top];
    top--;
    return book;
}

void printStack()
{
    isEmpty();
    printf("Stack: ");
    for (int i = 0; i <= top; i++)
    {
        printf("%s ", stack[i].book);
    }
    printf("\n");
}

int main()
{
    struct shelf book1 = {"Encyclopedia"};
    push(book1);
    printStack();

    struct shelf book2 = {"Harry Potter"};
    push(book2);
    printStack();

    struct shelf book3 = {"French Revolution"};
    push(book3);
    printStack();

    printStack();

    pop();
    printStack();

    return 0;
}
