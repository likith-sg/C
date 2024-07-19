#include <stdio.h>
#define MAX_SIZE 10

struct Stack
{
    int data[MAX_SIZE];
    int top;
};

void initialize(struct Stack *s)
{
    s->top = -1;
}

int isFull(struct Stack *s)
{
    return s->top == MAX_SIZE - 1;
}

int isEmpty(struct Stack *s)
{
    return s->top == -1;
}

void push(struct Stack *s, int item)
{
    if (isFull(s))
    {
        printf("Stack Overflow!\n");
        return;
    }
    s->top++;
    s->data[s->top] = item;
    printf("Element %d pushed onto the stack.\n", item);
    display(s);
}

void pop(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow!\n");
        return;
    }
    printf("Element %d popped from the stack.\n", s->data[s->top]);
    s->top--;
    display(s);
}

void display(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack: ");
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

int main()
{
    struct Stack s;
    initialize(&s);

    int choice;
    int element;
    while (1)
    {
        printf("1.Push\n2.Pop\n3.Display\n4.Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to push onto the stack: ");
            scanf("%d", &element);
            push(&s, element);
            break;
        case 2:
            pop(&s);
            break;
        case 3:
            display(&s);
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
