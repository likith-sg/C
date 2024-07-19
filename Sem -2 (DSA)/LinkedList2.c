#include <stdio.h>
#include <stdlib.h>

// Define a structure for the node
struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at nth position
void insertNodeAtN(struct Node* head, int data, int position)
{
    struct Node* newNode = createNode(data);
    struct Node* temp = head->next;
    int i;
    for (i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL && i < position)
    {
        printf("Invalid position\n");
        return;
    }
    if (temp == NULL)   // Insert at the end
    {
        newNode->prev = head;
        head->prev->next = newNode;
        newNode->next = NULL;
        head->prev = newNode;
    }
    else
    {
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL)
        {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }
}

// Function to delete a node at nth position
void deleteNodeAtN(struct Node* head, int position)
{
    if (head->next == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head->next;
    int i;
    for (i = 1; i < position && temp != NULL; i++)
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
    {
        temp->next->prev = temp->prev;
    }
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
    struct Node *temp = NULL;
    struct Node* current = head->next;
    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL)
    {
        head->prev = head->next;
        head->next = temp->prev;
    }
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
        printf("\n\nDoubly Linked List Operations\n");
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
