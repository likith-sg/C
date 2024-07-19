void revlinkedlist(struct Node* head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        struct Node* prev = NULL;
        struct Node* current = head;
        struct Node* next_node = NULL;

        printf("Reversed Linked List: ");

        while (current != NULL)
        {
            next_node = current->next;
            current->next = prev;
            prev = current;
            current = next_node;
        }

        head = prev;

        while (head != NULL)
        {
            printf("%d", head->data);
            if (head->next != NULL)
            {
                printf(" -> ");
            }
            head = head->next;
        }
        printf("\n");
    }
}
}
