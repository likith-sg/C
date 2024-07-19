#include <stdio.h>
#include <stdlib.h>

// Define a structure for the node
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the circular linked list
void insertNode(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
        newNode->next = newNode; // Circular link to itself
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head; // Circular link to head
    }
}

// Function to delete a node with a given key
void deleteNode(struct Node *head, int key)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *prev = NULL, *current = head;
    while (current->next != head)
    {
        if (current->data == key)
        {
            if (prev == NULL)
            {
                struct Node *last = head;
                while (last->next != head)
                {
                    last = last->next;
                }
                head = head->next;
                last->next = head;
            }
            else
            {
                prev->next = current->next;
            }
            free(current);
            printf("Node with data %d deleted successfully\n", key);
            return;
        }
        prev = current;
        current = current->next;
    }
    if (current->data == key)
    {
        if (prev == NULL)
        {
            head = NULL;
        }
        else
        {
            prev->next = current->next;
        }
        free(current);
        printf("Node with data %d deleted successfully\n", key);
    }
    else
    {
        printf("Node with data %d not found\n", key);
    }
}

// Function to search for an element in the circular linked list
int searchElement(struct Node *head, int key)
{
    if (head == NULL)
    {
        return 0;
    }
    struct Node *temp = head;
    do
    {
        if (temp->data == key)
        {
            return 1;
        }
        temp = temp->next;
    }
    while (temp != head);
    return 0;
}

// Function to reverse the circular linked list
void reverseCircularLinkedList(struct Node *head)
{
    if (head == NULL || head->next == head)
    {
        return;
    }
    struct Node *prev = NULL, *current = head, *next;
    do
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    while (current != head);
    head->next = prev;
    head = prev;
}

// Function to display the circular linked list
void displayList(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    while (temp != head);
    printf("\n");
}

int main()
{
    struct Node *head = NULL;

    int choice, data, key;
    while (1)
    {
        printf("\n\nCircular Linked List Operations\n");
        printf("1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Search Element\n");
        printf("4. Reverse Circular Linked List\n");
        printf("5. Display Circular Linked List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insertNode(head, data);
            break;
        case 2:
            printf("Enter data to delete: ");
            scanf("%d", &data);
            deleteNode(head, data);
            break;
        case 3:
            printf("Enter element to search: ");
            scanf("%d", &key);
            if (searchElement(head, key))
                printf("Element found in the list\n");
            else
                printf("Element not found in the list\n");
            break;
        case 4:
            reverseCircularLinkedList(head);
            printf("Circular Linked List reversed\n");
            break;
        case 5:
            printf("Circular Linked List: ");
            displayList(head);
            break;
        case 6:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
