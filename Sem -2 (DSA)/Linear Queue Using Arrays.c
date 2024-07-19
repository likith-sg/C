#include <stdio.h>
#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1, rear = -1;

int isFull()
{
    return rear == MAX_SIZE - 1;
}

int isEmpty()
{
    return front == -1 || front > rear;
}

void enqueue(int value)
{
    if (isFull())
    {
        printf("Queue is full.\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = value;
}

int dequeue()
{
    if (isEmpty())
    {
        printf("Queue is empty.\n");
        return -1;
    }
    int dequeued = queue[front];
    front++;
    return dequeued;
}

void display()
{
    if (isEmpty())
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
    enqueue(1);
    display();

    enqueue(2);
    display();

    enqueue(3);
    display();

    dequeue();
    display();

    enqueue(4);
    display();

    dequeue();
    display();

    dequeue();
    display();

    return 0;
}
