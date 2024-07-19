#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* newNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node** head, int data)
{
    struct Node* temp = *head;
    struct Node* newNodePtr = newNode(data);

    if (*head == NULL)
    {
        *head = newNodePtr;
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNodePtr;
}

int EndTraverse(struct Node* head, int n)
{
    struct Node* main_ptr = head;
    struct Node* ref_ptr = head;
    int count = 0;

    if (head != NULL)
    {
        while (count < n)
        {
            if (ref_ptr == NULL)
            {
                printf("%d is greater than the no of nodes in the list\n", n);
                return -1;
            }
            ref_ptr = ref_ptr->next;
            count++;
        }

        while (ref_ptr != NULL)
        {
            main_ptr = main_ptr->next;
            ref_ptr = ref_ptr->next;
        }
        if (main_ptr == NULL)
        {
            printf("%d is greater than the no of nodes in the list\n", n);
            return -1;
        }
        return main_ptr->data;
    }
    printf("List is empty\n");
    return -1;
}

int main()
{
    struct Node* head = NULL;
    int choice, data, n;

    do
    {
        printf("\n1. Insert element\n");
        printf("2. Find Nth node with end traversal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insertNode(&head, data);
            break;
        case 2:
            printf("Enter the value of N: ");
            scanf("%d", &n);
            printf("Value at %dth node from end: %d\n", n, EndTraverse(head, n));
            break;
        case 3:
            printf("Exiting\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    }
    while (choice != 3);

    return 0;
}
