#include <stdio.h>
#include <stdlib.h>

// Define a structure for the node
struct Node
{
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at nth position
void insertNodeAtN(struct Node* head, int data, int position)
{
    struct Node* newNode = createNode(data);
    if (position == 1)
    {
        newNode->next = head->next;
        head->next = newNode;
        return;
    }
    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Invalid position\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete a node at nth position
void deleteNodeAtN(struct Node* head, int position)
{
    if (head == NULL || head->next == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    struct Node* prev = NULL;
    for (int i = 1; temp != NULL && i < position; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Invalid position\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Function to search for an element
int searchElement(struct Node* head, int key)
{
    int position = 1;
    struct Node* current = head->next;
    while (current != NULL)
    {
        if (current->data == key)
        {
            return position;
        }
        position++;
        current = current->next;
    }
    return -1; // Element not found
}

// Function to reverse the linked list
void reverseLinkedList(struct Node* head)
{
    struct Node *prev = NULL, *current = head->next, *next;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head->next = prev;
}

// Function to display the linked list
void displayList(struct Node* head)
{
    struct Node* temp = head->next;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct Node* head = createNode(-1); // dummy node

    int choice, data, position, key;
    while (1)
    {
        printf("\n\nLinked List Operations\n");
        printf("1. Insert Node at nth position\n");
        printf("2. Delete Node at nth position\n");
        printf("3. Search Element\n");
        printf("4. Reverse Linked List\n");
        printf("5. Display Linked List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            printf("Enter position to insert: ");
            scanf("%d", &position);
            insertNodeAtN(head, data, position);
            break;
        case 2:
            printf("Enter position to delete: ");
            scanf("%d", &position);
            deleteNodeAtN(head, position);
            break;
        case 3:
            printf("Enter element to search: ");
            scanf("%d", &key);
            position = searchElement(head, key);
            if (position != -1)
                printf("%d found at position %d\n", key, position);
            else
                printf("%d not found in the list\n", key);
            break;
        case 4:
            reverseLinkedList(head);
            printf("Linked list reversed\n");
            break;
        case 5:
            printf("Linked List: ");
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
