#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

struct QueueElement
{
    int type;
    int intValue;
    float floatValue;
    char charValue;
};

struct Queue
{
    struct QueueElement elements[MAX_SIZE];
    int front;
    int rear;
};

int size = 0;
void initializeQueue(struct Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

void enqueue(struct Queue *q, struct QueueElement item)
{
    if (q->rear == MAX_SIZE - 1)
    {
        printf("Queue is full.\n");
        return;
    }
    q->rear++;
    q->elements[q->rear] = item;
    if (q->front == -1)
        q->front = 0;
    size++;
}

struct QueueElement dequeue(struct Queue *q)
{
    struct QueueElement item = q->elements[q->front];
    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front++;
    }
    size--;
    return item;
}

void displayQueue(struct Queue q)
{
    if (q.front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements:\n");
    for (int i = q.front; i <= q.rear; i++)
    {
        printf("Type: %d, Value: ", q.elements[i].type);
        switch (q.elements[i].type)
        {
        case 1:
            printf("%d\n", q.elements[i].intValue);
            break;
        case 2:
            printf("%f\n", q.elements[i].floatValue);
            break;
        case 3:
            printf("%c\n", q.elements[i].charValue);
            break;
        }
    }
}

int main()
{
    struct Queue q;
    initializeQueue(&q);

    int choice;
    struct QueueElement item;

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
            printf("Enter the type (1: int, 2: float, 3: char): ");
            scanf("%d", &item.type);
            switch (item.type)
            {
            case 1:
                printf("Enter an integer value: ");
                scanf("%d", &item.intValue);
                break;
            case 2:
                printf("Enter a float value: ");
                scanf("%f", &item.floatValue);
                break;
            case 3:
                printf("Enter a character value: ");
                scanf(" %c", &item.charValue);
                break;
            default:
                printf("Invalid type\n");
                continue;
            }
            enqueue(&q, item);
            displayQueue(q);
            break;
        case 2:
            if (q.front == q.rear)
            {
                printf("Queue is empty.\n");
            }
            else
            {
                item = dequeue(&q);
                printf("Dequeued element: ");
                switch (item.type)
                {
                case 1:
                    printf("%d\n", item.intValue);
                    break;
                case 2:
                    printf("%f\n", item.floatValue);
                    break;
                case 3:
                    printf("%c\n", item.charValue);
                    break;
                }
                displayQueue(q);
            }
            break;
        case 3:
            displayQueue(q);
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
