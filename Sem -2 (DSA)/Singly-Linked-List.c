#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void insert(struct Node** head, int dataAdd)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = dataAdd;
    temp->next = *head;
    *head = temp;
}

void displayList(struct Node* node)
{
    while (node != NULL)
    {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node* head = NULL;
    int choice, data;

    do
    {
        printf("1. Insert data at the beginning\n");
        printf("2. Display linked list\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insert(&head, data);
            printf("Data inserted successfully.\n");
            break;
        case 2:
            printf("Linked list: ");
            displayList(head);
            break;
        case 3:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Please enter again.\n");
        }
    }
    while (choice != 3);

    return 0;
}
