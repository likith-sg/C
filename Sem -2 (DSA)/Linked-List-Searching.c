#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void Insert(int x, int pos)
{
    if (pos < 1)
    {
        printf("Invalid position\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    if (pos == 1)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node* temp = head;
    for (int i = 0; i < pos - 2 && temp != NULL; ++i)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

int Search(int item)
{
    struct Node* temp = head;
    int pos = 1;
    while (temp != NULL)
    {
        if (temp->data == item)
        {
            printf("Item found in the list at position %d\n", pos);
            return 1;
        }
        temp = temp->next;
        pos++;
    }
    return 0;
}

void Display()
{
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice, x, pos, searchItem;

    do
    {
        printf("1. Insert element\n");
        printf("2. Display\n");
        printf("3. Search\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to insert: ");
            scanf("%d", &x);
            printf("Enter position to insert: ");
            scanf("%d", &pos);
            Insert(x, pos);
            break;
        case 2:
            Display();
            break;
        case 3:
            printf("Enter item to search: ");
            scanf("%d", &searchItem);
            if (!Search(searchItem))
            {
                printf("Item not found in the list.\n");
            }
            break;
        case 4:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        }

    }
    while (1);

    return 0;
}
