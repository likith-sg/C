#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack
{
    char items[MAX_SIZE];
    int top;
};


void initialize(struct Stack *s)
{
    s->top = -1;
}

int isEmpty(struct Stack *s)
{
    return s->top == -1;
}

int isFull(struct Stack *s)
{
    return s->top == MAX_SIZE - 1;
}

void push(struct Stack *s, char c)
{
    if (isFull(s))
    {
        printf("Stack Overflow!\n");
        exit(1);
    }
    s->items[++(s->top)] = c;
}

char pop(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow!\n");
        exit(1);
    }
    return s->items[(s->top)--];
}

int precedence(char op)
{
    if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

void infixToPostfix(char *exp)
{
    struct Stack s;
    initialize(&s);
    char postfix[MAX_SIZE];
    int j = 0;

    for (int i = 0; exp[i]; i++)
    {
        if ((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z'))
        {
            postfix[j++] = exp[i];
        }
        else if (exp[i] == '(')
        {
            push(&s, exp[i]);
        }
        else if (exp[i] == ')')
        {
            while (!isEmpty(&s) && s.items[s.top] != '(')
            {
                postfix[j++] = pop(&s);
            }
            if (isEmpty(&s) || s.items[s.top] != '(')
            {
                printf("Invalid Expression!\n");
                exit(1);
            }
            else
            {
                pop(&s);
            }
        }
        else
        {
            while (!isEmpty(&s) && precedence(exp[i]) <= precedence(s.items[s.top]))
            {
                postfix[j++] = pop(&s);
            }
            push(&s, exp[i]);
        }
    }

    while (!isEmpty(&s))
    {
        postfix[j++] = pop(&s);
    }

    postfix[j] = '\0';

    printf("Postfix Expression: %s\n", postfix);
}

int main()
{
    char infix[MAX_SIZE];
    printf("Enter an infix expression: ");
    fgets(infix, MAX_SIZE, stdin);
    infix[strcspn(infix, "\n")] = '\0';
    printf("Infix Expression: %s\n", infix);
    infixToPostfix(infix);
    return 0;
}
