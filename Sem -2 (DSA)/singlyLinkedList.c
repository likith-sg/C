#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head = NULL;


void insert(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node* current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
    printf("Node inserted successfully.\n");
}

void display()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    while (1)
    {
        int choice;
        printf("\nChoose an operation:\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            int data;
            scanf("%d", &data);
            insert(data);
            display();
            break;
        case 2:
            display();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}
