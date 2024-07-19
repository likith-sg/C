#include <stdio.h>
#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1, rear = -1;

int isEmpty()
{
    return front == -1;
}

int isFull()
{
    if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1))
        return 1;
    return 0;
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
    rear = (rear + 1) % MAX_SIZE;
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
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX_SIZE;
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
    int i = front;
    do
    {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX_SIZE;
    }
    while (i != (rear + 1) % MAX_SIZE);
    printf("\n");
    printf("Front position: %d\n", front);
    printf("Rear position: %d\n", rear);
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

//We are using (front == 0 && rear == MAX_SIZE - 1) to check when queue is full where rear is just behind the front.
//we use (front == rear + 1) to check for front > rear
