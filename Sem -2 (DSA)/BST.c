#include <stdio.h>
#include <stdlib.h>

struct bst
{
    int data;
    struct bst *left;
    struct bst *right;
};

struct bst* createbst(int data)
{
    struct bst* newbst = (struct bst*)malloc(sizeof(struct bst));
    newbst->data = data;
    newbst->left = NULL;
    newbst->right = NULL;
    return newbst;
}

void insert(struct bst **root, int data)
{
    if (*root == NULL)
    {
        *root = createbst(data);
    }
    else
    {
        if (data <= (*root)->data)
        {
            insert(&((*root)->left), data);
        }
        else
        {
            insert(&((*root)->right), data);
        }
    }
}

struct bst* deletion(struct bst *root, int key)
{
    if (root == NULL)
    {
        return root;
    }

    if (key < root->data)
    {
        root->left = deletion(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deletion(root->right, key);
    }
    else     // key == root->data
    {
        // Case 1: No child or only one child
        if (root->left == NULL)
        {
            struct bst *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct bst *temp = root->left;
            free(root);
            return temp;
        }

        // Case 2: Node with two children
        // Get the inorder successor (smallest in the right subtree)
        struct bst *temp = root->right;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }

        // Copy the inorder successor's data to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deletion(root->right, temp->data);
    }
    return root;
}

// Function to traverse and print the BST (Inorder traversal)
void inorder_traversal(struct bst *root)
{
    if (root != NULL)
    {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

int main()
{
    struct bst *root = NULL;

    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 70);
    insert(&root, 60);
    insert(&root, 80);

    printf("Inorder traversal of the BST: ");
    inorder_traversal(root);
    printf("\n");

    root = deletion(root, 20); // Deleting node with value 20

    printf("Inorder traversal after deletion: ");
    inorder_traversal(root);
    printf("\n");

    return 0;
}
