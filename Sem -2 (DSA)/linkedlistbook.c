#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 100

struct book
{
    int qty;
    float price;
    char bookname[size];
    struct book* next;
};

struct book* createbook(int qty, float price, const char bookname[])
{
    struct book* newbook = (struct book*)malloc(sizeof(struct book));
    if (newbook == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newbook->qty = qty;
    newbook->price = price;
    strcpy(newbook->bookname, bookname);
    newbook->next = NULL;
    return newbook;
}

void insertion(struct book* head, int qty, float price, const char bookname[], int position)
{
    struct book* newbook = createbook(qty, price, bookname);
    if (newbook == NULL)
    {
        printf("Failed to create book node\n");
        return;
    }

    if (position == 1)
    {
        newbook->next = head->next;
        head->next = newbook;
        return;
    }

    struct book* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position\n");
        free(newbook);
        return;
    }

    newbook->next = temp->next;
    temp->next = newbook;
}

void deletion(struct book* head, int position)
{
    if (head == NULL || head->next == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct book* temp = head;
    struct book* prev = NULL;
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

int searchElement(struct book* head, const char* key)
{
    int position = 1;
    struct book* current = head->next;
    while (current != NULL)
    {
        if (strcmp(current->bookname, key) == 0)
        {
            return position;
        }
        position++;
        current = current->next;
    }
    return -1;
}

void reverseLinkedList(struct book* head)
{
    struct book *prev = NULL, *current = head->next, *next;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head->next = prev;
}

void displayList(struct book* head)
{
    if (head->next == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Linked List:\n");
    struct book* temp = head->next;
    while (temp != NULL)
    {
        printf("Book: %s, Quantity: %d, Price: %.2f\n", temp->bookname, temp->qty, temp->price);
        temp = temp->next;
    }
}

void freeList(struct book* head)
{
    struct book* temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void findTotalBooks(struct book* head)
{
    int totalBooks = 0;
    struct book* temp = head->next;
    while (temp != NULL)
    {
        totalBooks++;
        temp = temp->next;
    }
    printf("Total number of books: %d\n", totalBooks);
}

void findAverageCost(struct book* head)
{
    if (head->next == NULL)
    {
        printf("Empty\n");
        return;
    }

    float totalCost = 0;
    int totalBooks = 0;
    struct book* temp = head->next;
    while (temp != NULL)
    {
        totalCost += temp->price;
        totalBooks++;
        temp = temp->next;
    }
    printf("Average cost: $%.2f\n", totalCost / totalBooks);
}

int main()
{
    struct book* head = createbook(-1, 0.0, "Dummy Head");

    int choice, qty, position;
    float price;
    char bookname[size];
    while (1)
    {
        printf("1. Insert Node at nth position\n");
        printf("2. Delete Node at nth position\n");
        printf("3. Search Element\n");
        printf("4. Reverse Linked List\n");
        printf("5. Display Linked List\n");
        printf("6. Find Total Books\n");
        printf("7. Find Average Cost\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter bookname to insert: ");
            getchar();
            fgets(bookname, size, stdin);
            bookname[strcspn(bookname, "\n")] = '\0';
            printf("Enter quantity to insert: ");
            scanf("%d", &qty);
            printf("Enter price to insert: ");
            scanf("%f", &price);
            printf("Enter position to insert: ");
            scanf("%d", &position);
            insertion(head, qty, price, bookname, position);
            break;
        case 2:
            printf("Enter position to delete: ");
            scanf("%d", &position);
            deletion(head, position);
            break;
        case 3:
            printf("Enter element to search: ");
            getchar();
            fgets(bookname, size, stdin);
            bookname[strcspn(bookname, "\n")] = '\0';
            position = searchElement(head, bookname);
            if (position != -1)
                printf("%s found at position %d\n", bookname, position);
            else
                printf("%s not found in the list\n", bookname);
            break;
        case 4:
            reverseLinkedList(head);
            printf("Linked list reversed\n");
            break;
        case 5:
            displayList(head);
            break;
        case 6:
            findTotalBooks(head);
            break;
        case 7:
            findAverageCost(head);
            break;
        case 8:
            printf("Exiting\n");
            freeList(head);
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
