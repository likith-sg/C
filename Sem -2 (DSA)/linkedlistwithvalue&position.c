#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertion(struct Node** head, int data, int position) {
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = data;

    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        printf("Data inserted at position %d successfully.\n", position);
        return;
    }

    struct Node* temp = *head;
    for (int i = 1; temp != NULL && i < position - 1; ++i) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("Data inserted at position %d successfully.\n", position);
}

void deletion(struct Node** head, int position) {
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;
    if (position == 1) {
        *head = temp->next;
        free(temp);
        printf("Node deleted from position %d successfully.\n", position);
        return;
    }

    struct Node* prev = NULL;
    for (int i = 1; temp != NULL && i < position; ++i) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Node deleted from position %d successfully.\n", position);
}

int search(struct Node* head, int key) {
    int position = 1;
    while (head != NULL) {
        if (head->data == key) {
            return position;
        }
        head = head->next;
        position++;
    }
    return -1; // Element not found
}

void displayList(struct Node* node) {
    if (node == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked list: ");
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position, key, searchResult;

    do {
        printf("\n1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Search element\n");
        printf("4. Display linked list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                insertion(&head, data, position);
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deletion(&head, position);
                break;
            case 3:
                printf("Enter the element to search: ");
                scanf("%d", &key);
                searchResult = search(head, key);
                if (searchResult != -1) {
                    printf("Element found at position %d.\n", searchResult);
                } else {
                    printf("Element not found.\n");
                }
                break;
            case 4:
                displayList(head);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter again.\n");
        }
    } while (choice != 5);

    return 0;
}
