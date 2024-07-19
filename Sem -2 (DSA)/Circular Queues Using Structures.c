#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

struct Queue
{
    int items[MAX_SIZE];
    int front, rear;
};

void initializeQueue(struct Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

void enqueue(struct Queue *q, int value)
{
    if ((q->rear + 1) % MAX_SIZE == q->front)
    {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->items[q->rear] = value;
}

int dequeue(struct Queue *q)
{
    if (q->front == -1)
    {
        printf("Queue is empty\n");
        return -1;
    }
    int item = q->items[q->front];
    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % MAX_SIZE;
    }
    return item;
}

void display(struct Queue q)
{
    if (q.front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are:\n");
    int i = q.front;
    do
    {
        printf("%d ", q.items[i]);
        i = (i + 1) % MAX_SIZE;
    }
    while (i != (q.rear + 1) % MAX_SIZE);
    printf("\n");
}

int main()
{
    struct Queue q;
    initializeQueue(&q);

    int choice, value;

    do
    {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to enqueue: ");
            scanf("%d", &value);
            enqueue(&q, value);
            break;
        case 2:
            printf("Dequeued element: %d\n", dequeue(&q));
            break;
        case 3:
            display(q);
            break;
        case 4:
            printf("Exit.\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    }
    while (choice != 4);

    return 0;
}
