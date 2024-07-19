#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

struct Node* push(struct Node* top, int data)
{
    struct Node* newNode = createNode(data);
    if (top != NULL)
        top->next = newNode;
    newNode->prev = top;
    return newNode;
}

struct Node* pop(struct Node* top)
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return top;
    }
    struct Node* temp = top;
    top = top->prev;
    free(temp);
    if (top != NULL)
        top->next = NULL;
    return top;
}

void display(struct Node* top)
{
    printf("Stack: ");
    while (top != NULL)
    {
        printf("%d ", top->data);
        top = top->prev;
    }
    printf("\n");
}

int main()
{
    struct Node* top = NULL;
    int choice, data;

    do
    {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to push: ");
            scanf("%d", &data);
            top = push(top, data);
            break;
        case 2:
            top = pop(top);
            break;
        case 3:
            display(top);
            break;
        case 4:
            printf("Exiting\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    }
    while (choice != 4);

    return 0;
}
