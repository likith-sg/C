#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

// Define a structure for a node in the linked list
struct Node
{
    int key;
    int value;
    struct Node *next;
};

// Define a structure for the hash table
struct HashTable
{
    struct Node *buckets[TABLE_SIZE];
};

// Function to create a new node
struct Node *createNode(int key, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the hash table
struct HashTable *initializeHashTable()
{
    struct HashTable *hashTable = (struct HashTable *)malloc(sizeof(struct HashTable));
    if (hashTable == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashTable->buckets[i] = NULL;
    }
    return hashTable;
}

// Function to compute the hash value
int hash(int key)
{
    return key % TABLE_SIZE;
}

// Function to insert a key-value pair into the hash table
void insert(struct HashTable *hashTable, int key, int value)
{
    int index = hash(key);
    struct Node *newNode = createNode(key, value);
    if (hashTable->buckets[index] == NULL)
    {
        hashTable->buckets[index] = newNode;
    }
    else
    {
        struct Node *temp = hashTable->buckets[index];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to delete a key-value pair from the hash table
void delete(struct HashTable *hashTable, int key)
{
    int index = hash(key);
    struct Node *current = hashTable->buckets[index];
    struct Node *prev = NULL;
    while (current != NULL && current->key != key)
    {
        prev = current;
        current = current->next;
    }
    if (current == NULL)
    {
        printf("Key not found\n");
        return;
    }
    if (prev == NULL)
    {
        hashTable->buckets[index] = current->next;
    }
    else
    {
        prev->next = current->next;
    }
    free(current);
    printf("Key-value pair with key %d deleted successfully\n", key);
}

// Function to search for a key in the hash table
void search(struct HashTable *hashTable, int key)
{
    int index = hash(key);
    struct Node *current = hashTable->buckets[index];
    while (current != NULL)
    {
        if (current->key == key)
        {
            printf("Key %d found, value: %d\n", key, current->value);
            return;
        }
        current = current->next;
    }
    printf("Key not found\n");
}

// Function to display the hash table
void displayHashTable(struct HashTable *hashTable)
{
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        printf("Bucket %d:", i);
        struct Node *temp = hashTable->buckets[i];
        while (temp != NULL)
        {
            printf(" (%d, %d)", temp->key, temp->value);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Function to resize the hash table
struct HashTable *resize(struct HashTable *hashTable, int newSize)
{
    struct HashTable *newHashTable = initializeHashTable();
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        struct Node *temp = hashTable->buckets[i];
        while (temp != NULL)
        {
            insert(newHashTable, temp->key, temp->value);
            temp = temp->next;
        }
    }
    printf("Hash Table resized\n");
    return newHashTable;
}

int main()
{
    struct HashTable *hashTable = initializeHashTable();

    int choice, key, value;
    while (1)
    {
        printf("\n\nHash Table Operations\n");
        printf("1. Insert Key-Value Pair\n");
        printf("2. Delete Key-Value Pair\n");
        printf("3. Search for Key\n");
        printf("4. Resize Hash Table\n");
        printf("5. Display Hash Table\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter key and value to insert: ");
            scanf("%d %d", &key, &value);
            insert(hashTable, key, value);
            break;
        case 2:
            printf("Enter key to delete: ");
            scanf("%d", &key);
            delete(hashTable, key);
            break;
        case 3:
            printf("Enter key to search: ");
            scanf("%d", &key);
            search(hashTable, key);
            break;
        case 4:
            printf("Enter new size for hash table: ");
            scanf("%d", &value);
            hashTable = resize(hashTable, value);
            break;
        case 5:
            displayHashTable(hashTable);
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
