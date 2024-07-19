#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char ch)
{
    if (top == MAX_SIZE - 1)
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = ch;
}

char pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

char peek()
{
    if (top == -1)
    {
        printf("Stack is Empty\n");
        exit(1);
    }
    return stack[top];
}

int precedence(char ch)
{
    switch(ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}

int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

void infixToPostfix(char *exp)
{
    char postfix[MAX_SIZE];
    int i, j;
    for (i = 0, j = -1; exp[i]; i++)
    {
        if (isOperand(exp[i]))
        {
            postfix[++j] = exp[i];
        }
        else if (exp[i] == '(')
        {
            push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            while (top != -1 && peek() != '(')
            {
                postfix[++j] = pop();
            }
            if (top == -1)
            {
                printf("Invalid Expression\n");
                exit(1);
            }
            pop();
        }
        else
        {
            while (top != -1 && precedence(exp[i]) <= precedence(peek()))
            {
                postfix[++j] = pop();
            }
            push(exp[i]);
        }
    }
    while (top != -1)
    {
        if (peek() == '(')
        {
            printf("Invalid Expression\n");
            exit(1);
        }
        postfix[++j] = pop();
    }
    postfix[++j] = '\0';
    printf("Postfix Expression: %s\n", postfix);
}

int main()
{
    char exp[MAX_SIZE];
    printf("Enter an infix expression: ");
    fgets(exp, MAX_SIZE, stdin);
    infixToPostfix(exp);
    return 0;
}
