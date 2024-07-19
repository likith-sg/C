#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
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
    newNode->next = newNode;
    return newNode;
}

struct Node* enqueue(struct Node* rear, int data)
{
    struct Node* newNode = createNode(data);
    if (rear == NULL)
    {
        return newNode;
    }
    newNode->next = rear->next;
    rear->next = newNode;
    return newNode;
}

struct Node* dequeue(struct Node* rear)
{
    if (rear == NULL)
    {
        printf("Queue is empty\n");
        return rear;
    }
    struct Node* front = rear->next;
    if (front == rear)
    {
        free(front);
        return NULL;
    }
    rear->next = front->next;
    free(front);
    return rear;
}

void display(struct Node* rear)
{
    if (rear == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = rear->next;
    printf("Queue: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    while (temp != rear->next);
    printf("\n");
}

int main()
{
    struct Node* rear = NULL;
    int choice, data;

    do
    {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to enqueue: ");
            scanf("%d", &data);
            rear = enqueue(rear, data);
            break;
        case 2:
            rear = dequeue(rear);
            break;
        case 3:
            display(rear);
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
