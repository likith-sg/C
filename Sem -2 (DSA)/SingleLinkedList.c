#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* createNode(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertion(struct Node** head, int value, int position)
{
    struct Node* newNode = createNode(value);
    if (position == 1)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else
    {
        struct Node* temp = *head;
        for (int i = 1; i < position - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            printf("Position overbound\n");
        }
        else
        {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

void deletion(struct Node** head, int position)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        struct Node* temp = *head;
        if (position == 1)
        {
            *head = (*head)->next;
            free(temp);
        }
        else
        {
            struct Node* prev = NULL;
            for (int i = 1; i < position && temp != NULL; i++)
            {
                prev = temp;
                temp = temp->next;
            }
            if (temp == NULL)
            {
                printf("Position overbound\n");
            }
            else
            {
                prev->next = temp->next;
                free(temp);
            }
        }
    }
}

void revlinkedlist(struct Node* head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        struct Node* prev = NULL;
        struct Node* current = head;
        struct Node* next_node = NULL;

        printf("Reversed Linked List: ");

        while (current != NULL)
        {
            next_node = current->next;
            current->next = prev;
            prev = current;
            current = next_node;
        }

        head = prev;

        while (head != NULL)
        {
            printf("%d", head->data);
            if (head->next != NULL)
            {
                printf(" -> ");
            }
            head = head->next;
        }
        printf("\n");
    }
}

void print(struct Node* head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        struct Node* temp = head;
        printf("Linked List: ");
        while (temp != NULL)
        {
            printf("%d", temp->data);
            temp = temp->next;
            if (temp != NULL)
            {
                printf(" -> ");
            }
        }
        printf("\n");
    }
}

int main()
{
    struct Node* head = NULL;
    int choice, value, position, searchValue, searchPosition;

    do
    {
        printf("\n1. Insert at position\n");
        printf("2. Delete at position\n");
        printf("3. reverse linked list\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            printf("Enter position to insert: ");
            scanf("%d", &position);
            insertion(&head, value, position);
            break;
        case 2:
            printf("Enter position to delete: ");
            scanf("%d", &position);
            deletion(&head, position);
            break;
        case 3:
            revlinkedlist(head);
            break;
        case 4:
            print(head);
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    }
    while (choice != 5);

    return 0;
}
