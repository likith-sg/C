#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

void Insert(char data)
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

    struct Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void ReverseName()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    printf("Name in reverse order: ");
    while (temp != NULL)
    {
        printf("%c", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main()
{
    char name[100];
    printf("Enter your name: ");
    scanf("%s", name);

    for (int i = 0; i < strlen(name); i++)
    {
        Insert(name[i]);
    }

    ReverseName();

    return 0;
}
