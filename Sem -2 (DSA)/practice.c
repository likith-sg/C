#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_SIZE 100

struct Stack {
    char items[MAX_SIZE];
    int top;
};

void initialize(struct Stack *s) {
    s->top = -1;
}

bool isFull(struct Stack *s) {
    return s->top == MAX_SIZE - 1;
}

bool isEmpty(struct Stack *s) {
    return s->top == -1;
}

void push(struct Stack *s, char value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
    } else {
        s->top++;
        s->items[s->top] = value;
    }
}

char pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1; // indicating stack underflow
    } else {
        return s->items[s->top--];
    }
}

char peek(struct Stack *s) {
    if (isEmpty(s)) {
        return -1; // indicating stack is empty
    } else {
        return s->items[s->top];
    }
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

void conversion(char infix[], char postfix[]) {
    struct Stack operators;
    initialize(&operators);
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        if (isdigit(infix[i])) {
            postfix[j++] = infix[i++];
        } else if (infix[i] == '(') {
            push(&operators, infix[i++]);
        } else if (infix[i] == ')') {
            while (peek(&operators) != '(') {
                postfix[j++] = pop(&operators);
            }
            pop(&operators); // Remove '(' from the stack
            i++;
        } else {
            while (!isEmpty(&operators) && precedence(infix[i]) <= precedence(peek(&operators))) {
                postfix[j++] = pop(&operators);
            }
            push(&operators, infix[i++]);
        }
    }

    while (!isEmpty(&operators)) {
        postfix[j++] = pop(&operators);
    }

    postfix[j] = '\0';
}

int evaluatePostfix(char postfix[]) {
    struct Stack operands;
    initialize(&operands);
    int i = 0;

    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            push(&operands, postfix[i] - '0');
        } else {
            int operand2 = pop(&operands);
            int operand1 = pop(&operands);
            switch (postfix[i]) {
                case '+':
                    push(&operands, operand1 + operand2);
                    break;
                case '-':
                    push(&operands, operand1 - operand2);
                    break;
                case '*':
                    push(&operands, operand1 * operand2);
                    break;
                case '/':
                    push(&operands, operand1 / operand2);
                    break;
            }
        }
        i++;
    }
    return pop(&operands);
}

void input(char infix[]) {
    printf("Enter infix expression: ");
    fgets(infix, MAX_SIZE, stdin);
}

void display(char postfix[]) {
    printf("Postfix expression: %s\n", postfix);
}

int main() {
    char infix[MAX_SIZE];
    input(infix);
    char postfix[MAX_SIZE];
    conversion(infix, postfix);
    display(postfix);

    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}
