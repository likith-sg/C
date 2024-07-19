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
    newNode->next = NULL;
    return newNode;
}

struct Node* enqueue(struct Node* rear, int data)
{
    struct Node* newNode = createNode(data);
    if (rear == NULL)
        return newNode;
    rear->next = newNode;
    return newNode;
}

struct Node* dequeue(struct Node* front)
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return front;
    }
    struct Node* temp = front;
    front = front->next;
    free(temp);
    return front;
}

void display(struct Node* front)
{
    printf("Queue: ");
    while (front != NULL)
    {
        printf("%d ", front->data);
        front = front->next;
    }
    printf("\n");
}

int main()
{
    struct Node* front = NULL;
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
            if (rear == NULL)
                front = rear = enqueue(rear, data);
            else
                rear = enqueue(rear, data);
            break;
        case 2:
            front = dequeue(front);
            if (front == NULL)
                rear = NULL;
            break;
        case 3:
            display(front);
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
