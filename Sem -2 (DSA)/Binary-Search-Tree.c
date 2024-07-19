#include <stdio.h>
#include <stdlib.h>

struct BST
{
    int data;
    struct BST *left;
    struct BST *right;
};

struct BST* createNode(int data)
{
    struct BST* newNode = (struct BST*)malloc(sizeof(struct BST));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct BST* insert(struct BST *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }

    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }

    return root;
}

struct BST* search(struct BST *root, int data)
{
    if (root == NULL || root->data == data)
    {
        return root;
    }

    if (root->data < data)
    {
        return search(root->right, data);
    }

    return search(root->left, data);
}

void InOrder(struct BST *root)
{
    if (root == NULL)
    {
        return;
    }
    InOrder(root->left);
    printf(" %d ",root -> data);
    InOrder(root->right) ;
    return;
}

void PreOrder(struct BST *root)
{
    if (root == NULL)
    {
        return;
    }
    printf(" %d ", root->data);
    PreOrder(root->left);
    PreOrder(root->right);
    return;
}

void PostOrder(struct BST *root)
{
    if (root == NULL)
    {
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    printf(" %d ", root->data);
    return;
}

void Min(struct BST *root, int *min)
{
    if (root == NULL)
    {
        return;
    }

    if (root->data < *min)
    {
        *min = root->data;
    }

    Min(root->left, min);
    Min(root->right, min);
}

void Max(struct BST *root, int *max)
{
    if (root == NULL)
    {
        return;
    }

    if (root->data > *max)
    {
        *max = root->data;
    }

    Max(root->left, max);
    Max(root->right, max);
}

int main()
{
    struct BST* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    InOrder(root);
    printf("InOrder \n");
    PreOrder(root);
    printf("PreOrder \n");
    PostOrder(root);
    printf("PostOrder \n");
    int searchKey = 60;
    printf("\n");
    int min = root -> data;
    Min(root,&min);
    printf("min is:%d \n",min);
    int max = root -> data;
    Max(root,&max);
    printf("max is:%d \n",max);
    struct BST* result = search(root, searchKey);

    if (result != NULL)
    {
        printf("%d Found in the BST\n", searchKey);
    }
    else
    {
        printf("%d Not found in the BST\n", searchKey);
    }
    return 0;
}
