#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

void Insert(int data, int pos)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    if (pos == 1)
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

void Print()
{
    struct Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int Search(int data)
{
    struct Node* temp = head;
    int pos = 1;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            printf("Data %d found at position %d\n", data, pos);
            return pos;
        }
        temp = temp->next;
        pos++;
    }
    printf("Data %d not found\n", data);
    return -1;
}

void Delete(int node_pos)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    if (node_pos == 1)
    {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
        return;
    }

    for (int i = 1; temp != NULL && i < node_pos; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

int main()
{
    int choice, data, pos, node_pos;

    do
    {
        printf("1. Insert\n");
        printf("2. Print\n");
        printf("3. Search\n");
        printf("4. Delete\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            printf("Enter position to insert: ");
            scanf("%d", &pos);
            Insert(data, pos);
            break;
        case 2:
            Print();
            break;
        case 3:
            printf("Enter data to search: ");
            scanf("%d", &data);
            Search(data);
            break;
        case 4:
            printf("Enter position to delete: ");
            scanf("%d", &node_pos);
            Delete(node_pos);
            break;
        case 5:
            printf("Exiting\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    }
    while (choice != 5);

    return 0;
}
