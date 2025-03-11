#include <stdio.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createnode(int data)
{
    struct node *a;
    a = (struct node *)malloc(sizeof(struct node));
    a->data = data;
    a->left = NULL;
    a->right = NULL;
    return a;
}
struct node *inopre(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
struct node *deletenode(struct node *root, int key)
{

    if (root == NULL)
    {
        return NULL;
    }

    if (key < root->data)
    {
        root->left = deletenode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deletenode(root->right, key);
    }
    else
    {

        if (root->left == NULL && root->right == NULL)
        {
            printf("Deleting leaf node: %d\n", root->data);
            free(root);
            return NULL;
        }
        else if (root->left == NULL)
        {
            struct node *ptr = root->right;
            free(root);
            return ptr;
        }
        else if (root->right == NULL)
        {
            struct node *ptr = root->left;
            free(root);
            return ptr;
        }
        else
        {
            struct node *ipre = inopre(root);
            root->data = ipre->data;
            root->left = deletenode(root->left, ipre->data);
        }
    }
    return root;
}

void inoder(struct node *root)
{
    if (root != NULL)
    {
        inoder(root->left);
        printf("%d", root->data);
        inoder(root->right);
    }
}
int main()
{
    struct node *p = createnode(8);
    struct node *p1 = createnode(3);
    struct node *p2 = createnode(10);
    struct node *p3 = createnode(1);
    struct node *p4 = createnode(6);
    struct node *p5 = createnode(13);
    struct node *p6 = createnode(4);
    struct node *p7 = createnode(7);
    struct node *p8 = createnode(14);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p4->left = p6;
    p4->right = p7;
    p2->right = p5;
    p5->right = p8;
    printf("In-order traversal before deletion: ");
    inoder(p);
    printf("\n");

    deletenode(p, 8);

    printf("In-order traversal after deletion: ");
    inoder(p);
    printf("\n");

    return 0;
}
