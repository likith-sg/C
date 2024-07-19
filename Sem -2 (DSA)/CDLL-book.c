#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book
{
    char bookname[100];
    int qty;
    float price;
    struct Book *prev;
    struct Book *next;
};

struct CDLL
{
    struct Book *head;
};

void insert(struct CDLL *list, char name[], int qty, float price)
{
    struct Book *newBook = (struct Book*)malloc(sizeof(struct Book));
    strcpy(newBook->bookname, name);
    newBook->qty = qty;
    newBook->price = price;

    if (list->head == NULL)
    {
        list->head = newBook;
        newBook->next = newBook;
        newBook->prev = newBook;
    }
    else
    {
        struct Book *last = list->head->prev;
        newBook->next = list->head;
        list->head->prev = newBook;
        newBook->prev = last;
        last->next = newBook;
    }
    printf("Book inserted successfully\n");
}

void delete(struct CDLL *list, int pos)
{
    if (list->head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Book *temp = list->head;
    int count = 1;

    if (pos == 1)
    {
        if (temp->next == temp)
        {
            free(temp);
            list->head = NULL;
        }
        else
        {
            struct Book *last = temp->prev;
            last->next = temp->next;
            temp->next->prev = last;
            if (temp == list->head)
                list->head = temp->next;
            free(temp);
        }
        printf("Book deleted successfully\n");
        return;
    }

    while (count < pos && temp->next != list->head)
    {
        temp = temp->next;
        count++;
    }

    if (count == pos)
    {
        struct Book *prevNode = temp->prev;
        prevNode->next = temp->next;
        temp->next->prev = prevNode;
        free(temp);
        printf("Book deleted successfully\n");
    }
    else
    {
        printf("Invalid position\n");
    }
}

void search(struct CDLL *list, char name[])
{
    if (list->head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Book *temp = list->head;
    int pos = 1, found = 0;

    do
    {
        if (strcmp(temp->bookname, name) == 0)
        {
            printf("Book found at position %d\n", pos);
            printf("Name: %s, Quantity: %d, Price: %.2f\n", temp->bookname, temp->qty, temp->price);
            found = 1;
            break;
        }
        temp = temp->next;
        pos++;
    }
    while(temp != list->head);

    if (!found)
        printf("Book not found\n");
}

void display(struct CDLL *list)
{
    if (list->head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Book *temp = list->head;
    printf("Books in the list:\n");
    do
    {
        printf("Name: %s, Quantity: %d, Price: %.2f\n", temp->bookname, temp->qty, temp->price);
        temp = temp->next;
    }
    while(temp != list->head);
}

void findTotalBooks(struct CDLL *list)
{
    if (list->head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Book *temp = list->head;
    int count = 0;
    do
    {
        count++;
        temp = temp->next;
    }
    while(temp != list->head);

    printf("Total number of books: %d\n", count);
}

void findAverageCost(struct CDLL *list)
{
    if (list->head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Book *temp = list->head;
    float totalCost = 0;
    int count = 0;
    do
    {
        totalCost += temp->price;
        count++;
        temp = temp->next;
    }
    while(temp != list->head);

    float avgCost = totalCost / count;
    printf("Average cost of books: %.2f\n", avgCost);
}

int main()
{
    struct CDLL cdll = {NULL};
    int choice;
    char input[100];
    char name[100];
    int qty, pos;
    float price;

    do
    {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Find Total Books\n");
        printf("6. Find Average Cost\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%d", &choice);

        switch(choice)
        {
        case 1:
            printf("Enter book name: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';
            printf("Enter quantity: ");
            fgets(input, sizeof(input), stdin);
            sscanf(input, "%d", &qty);
            printf("Enter price: ");
            fgets(input, sizeof(input), stdin);
            sscanf(input, "%f", &price);
            insert(&cdll, name, qty, price);
            break;
        case 2:
            printf("Enter position to delete: ");
            fgets(input, sizeof(input), stdin);
            sscanf(input, "%d", &pos);
            delete(&cdll, pos);
            break;
        case 3:
            printf("Enter book name to search: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';
            search(&cdll, name);
            break;
        case 4:
            display(&cdll);
            break;
        case 5:
            findTotalBooks(&cdll);
            break;
        case 6:
            findAverageCost(&cdll);
            break;
        case 7:
            printf("Exiting program\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    }
    while(choice != 7);

    return 0;
}
